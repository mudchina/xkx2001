//Cracked by Roath
// helper functions
#include <localtime.h>
#include <room.h>
#include <ansi.h>
#include "/d/beijing/beijing_defs.h"

#define START_ROOM "/d/beijing/tianqiao"

static int *kill_base_a = ({5, 5, 5, 5, 5, 5, 5});
static int *job_upgrade_a = ({100, 200, 400, 800, 1000, 1200, 200});
int job_upgrade_num(int rank) {return job_upgrade_a[rank];}

static int *speed_base_a = ({500, 800, 1000, 1500, 1800, 2200, 2500});
int speed_base(int rank) { return speed_base_a[rank]; }
static int *exp_base_a = ({20000, 50000, 100000, 200000, 
	    400000, 700000, 1000000});
static string *RANK_NAME = ({
    "城门千总",
    "城门守备",
    "骁骑营佐领",
    "侍卫营参领",
    "侍卫营一等侍卫",
    "副都统",
    "都统",
});
static string *DEPT_NAME = ({
	"骁骑营",
	"侍卫营",
});
string dept_name(int dept) { return DEPT_NAME[dept]; }
string rank_name(int rank) { return RANK_NAME[rank]; }
string player_title(object player) {
    int rank = SHIWEI_LEVEL(player);
    if (rank < 5) {
	return RANK_NAME[rank];
    }else{
	return player->query("bingbu/dept")+RANK_NAME[rank];
    }
}

static string *JUEWEI_NAME = ({
    "云骑尉",
    "骑都尉",
    "三等轻车都尉", "二等轻车都尉", "一等轻车都尉",
    "三等男爵", "二等男爵", "一等男爵",
    "三等子爵", "二等子爵", "一等子爵",
    "三等伯爵", "二等伯爵", "一等伯爵",
    "三等侯爵", "二等侯爵", "一等侯爵",
    "三等公爵", "二等公爵", "一等公爵",
});
string juewei_name(int job_total) { 	
    if ((job_total/50) >= sizeof(JUEWEI_NAME)) {
	return JUEWEI_NAME[sizeof(JUEWEI_NAME)-1];
    }
    return JUEWEI_NAME[job_total/50]; 
}

static int *SUICONG_MAX = ({
    0, 0, 0, 1, 2, 3, 4,
});
int suicong_max(int rank) {return SUICONG_MAX[rank]; }

static int *RANK_POSITION_NUM = ({36, 24, 18, 12, 8, 4, 2});
int rank_position_num(int rank) { return RANK_POSITION_NUM[rank];}
int rank_upgrade_num(int rank) {return job_upgrade_a[rank];}
int pending_time() {return 1296000; }

// 5 years
// int tuiyi_pending_time = 1296000;
// for debugging, only 1 min
int tuiyi_pending_time = 60;

object *obj_in_env(string file, object env)
{
    object *obs, *result;
    object ob;
    int n=0;

    obs = filter_array(children(file), (: clonep :));
    foreach (ob in obs) {
        if (environment(ob) == env)
	    result[n++] = ob;
    }
    if (n > 0) return result;
    return 0;
}

object *obj_with_me(string file, object me)
{
    return obj_in_env(file, environment(me));
}

object clone_with_limit(string file, int max)
{
    object *obs;

    obs = filter_array(children(file), (: clonep :));
    if (sizeof(obs) >= max) return 0;
    return new(file);
}

object clonehere_with_limit(object room, string file, int max)
{
    object *obs, ob;

    obs = filter_array(children(file), (: clonep :));
    if (sizeof(obs) >= max) return 0;
    ob = new(file);
    ob->move(room);
    return ob;
}

int shichen()
{
    string ev = NATURE_D->outdoor_room_event();

    switch (ev) {
	case "event_dawn" : 
	    return 4;
	case "event_sunrise" :
	    return 8;
	case "event_morning" :
	    return 10;
	case "event_noon" :
	    return 13;
	case "event_afternoon" :
	    return 16;
	case "event_evening" :
	    return 19;
	case "event_night":
	    return 21;
	default:
	case "event_midnight":
	    return 0;
    }
}

int is_night_shift()
{
    int sc = shichen();
    if (sc < 8 || sc >= 19) return 1;
    return 0;
}
int is_sunrise() { return shichen()-8; }
int is_sunset() { return shichen()-19; }
int is_dark_time() 
{
    int sc = shichen();
    if (sc == 0 || sc == 21) return 1;
    return 0;
}

object find_mizheng()
{
    object room, mizheng;

    seteuid(getuid());
    if (! (room = find_object("/d/beijing/bingbuyamen"))){
	room = load_object("/d/beijing/bingbuyamen");
    }
    mizheng = present("mi zheng", room);
    if (! mizheng) {
	write("BUG: 请告诉负责北京的巫师：job_reward: mizheng=0.\n");
	return 0;
    }
    return mizheng;
}

void job_reward(object player, int rank, int kill_num, int fail_num)
{
    object mizheng ;
    int *speed_cur_a, *pos_ratio_a;

    int exp_reward, job_finish, exp_player;
    int speed_cur, speed_base, pos_ratio, kill_base, exp_base, job_upgrade;
    int kill_finish, rate;
    float kill_ratio, ftemp_a, ftemp_b;

    // sanity check 
    if (!player || rank<0 || rank>6 || kill_num < 0 || fail_num < 0) {
	write("BUG: 请告诉负责北京的巫师：job_reward sanity check.\n");
	return;
    }

    player->add("bingbu/job_total", 1);
    player->add("bingbu/job_rank"+rank, 1);
    player->add("bingbu/job_cur", 1);
    player->add("bingbu/job_lazy", 1);

    mizheng = find_mizheng();
    if (! mizheng) return;

    pos_ratio_a = mizheng->pos_ratio();
    speed_cur_a = mizheng->query("speed_cur");
    
    speed_base = speed_base_a[rank];
    speed_cur = speed_cur_a[rank];
    pos_ratio = pos_ratio_a[rank];
    kill_base = kill_base_a[rank];
    exp_base = exp_base_a[rank];
    job_upgrade = job_upgrade_a[rank];

    exp_player = player->query("combat_exp");
    job_finish = player->query("bingbu/job_rank"+rank);

    switch (rank) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
	kill_finish = kill_num - fail_num;
	if (kill_finish < 0) kill_finish = 0;
  	break;
    }

    /* position fullness */        
    if (pos_ratio > 50) {  /* too many players */
	if (speed_cur*100/speed_base > 70) {
	    speed_cur -= pos_ratio*speed_base/1000;
	}
    }else{			/* too few players */
	if (speed_cur*100/speed_base < 140) {
	    speed_cur += (100-pos_ratio)*speed_base/1000;
	}
    }
      
    /* kill numbers and player exp take effect */
    if (exp_player > exp_base) {
	kill_finish = kill_finish*exp_base/exp_player;
    }

    ftemp_a = kill_finish;
    ftemp_b = kill_base;
    kill_ratio=ftemp_a/ftemp_b;
    if (kill_ratio > 1.0){
       /* I hope log and floating point numbers work */
       kill_ratio = 1.0+0.1*sqrt(kill_ratio); 
       if (kill_ratio > 1.4) kill_ratio=1.40;
    }

    /* primary reward: I wish the mixed float/int arithmetic is all right */
    exp_reward = speed_cur * kill_ratio / 2; /* half hour job */
	
    if (job_finish > 2*job_upgrade) {
	exp_reward = exp_reward * job_upgrade / (job_finish-job_upgrade);
    }
	
    exp_reward = exp_reward * (95+random(10))/200;  // each job is 15 min
    player->add("combat_exp", exp_reward);
    player->add("potential",  exp_reward/10);
 
    if (player->query("id") != "chu") {	// no need to log my testing
	log_file("beijing/reward",
	    sprintf("%s : %s得了 %d 点经验。kill_num=%d, fail_num=%d\n",
	    ctime(time()), player->name(), exp_reward, 
	    kill_num, fail_num));
    }
    tell_object(player, "你的经验增加了 "+exp_reward+" 点！\n", exp_reward);
    if (player->query("id") == "chu") { // tell me more details
	tell_object(player, "speed_cur = "+speed_cur+"\n");
	tell_object(player, "job_finish = "+job_finish+"\n");
	tell_object(player, "kill_finish = "+kill_finish+"\n");
	tell_object(player, "kill_ratio = "+kill_ratio+"\n");
    }

    speed_cur_a[rank] = speed_cur;
    mizheng->set("speed_cur", speed_cur_a);
    mizheng->save();
}


// must be called from an npc object
int random_walk()
{
        mapping exits, doors;
        string *dirs, dir, last_room, this_room;
	object me = this_object();
        object here = environment(me);

	if ( strsrch(base_name(here), "/d/beijing") != 0) {
                message("vision", me->name() + 
		    "急急忙忙地离开了。\n", here, me);
                me->move(START_ROOM);
                message("vision", me->name() + "走了过来。\n",
		    here, me);
        }

        if( !objectp(here) 
        || me->is_fighting() || me->is_busy()
        || !mapp(exits = here->query("exits")) 
        || me->query("jingli") < me->query("max_jingli") / 2 ) return 0;

        dirs = keys(exits);

        if( mapp(doors = here->query_doors()) ) {
                dirs += keys(doors);
        }
        if( sizeof(dirs) == 0 ) return 0;

        dir = dirs[random(sizeof(dirs))];
        if( stringp(last_room = me->query_temp("last_room"))
        &&  sizeof(dirs) > 1 && exits[dir] == last_room ) {
                dirs -= ({dir});
                dir = dirs[random(sizeof(dirs))];
        }

        if( mapp(doors) && !undefinedp(doors[dir])
        && (doors[dir]["status"] & DOOR_CLOSED) )
                command("open " + dir);
        command("go " + dir);
        me->set_temp("last_room", this_room);

        return 1;
}
