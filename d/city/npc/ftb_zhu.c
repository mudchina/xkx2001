//Cracked by Roath
// npc: /d/city/npc/ftb_zhu.c
// Chu 2/10/99

#include <ansi.h>
inherit NPC;
#include "/clone/obj/npc_setup.h"
#include "/d/REGIONS.h"

#define JOB_SERVER "/clone/obj/job_server"
#define TRAVERSER  "/clone/obj/traverser"
#define MAPDB "/clone/obj/mapdb"
#define MAX_ROOM 64
#define JOB_NAME "ftb_search"

string *rooms;
int room_num;
int is_exact_dist;
string ask_job();
string ask_cike();
string ask_freq();
string random_chat();

void create()
{
	int exp, force;

        set_name("程金斧", ({ "cheng jinfu", "bangzhu", "cheng" }) );
        set("gender", "男性" );
	set("title", "斧头帮帮主");
        set("age", 32);
        set("long",  "此人乃是斧头帮开帮帮主, 武功颇为了得.\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", -1);
	exp = 500000;
 

        set("attitude", "friendly");
 	set("inquiry", ([
		"斧头帮" : "斧头帮乃是江湖闻名的大帮会, 现下有些工作, 你可愿意干?\n",
		"工作" : (: ask_job :),
		"job"  : (: ask_job :),
		"刺客"  : (: ask_cike :),
		"帮忙" : (: ask_freq :),
		"助拳"  : (: ask_freq :)
	]));

	set_skills("shaolin", 500000, 100);
	set_hp(170);   // about level 170
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	rooms = allocate(MAX_ROOM);
  	seteuid(getuid());
 	set("chat_chance", 50);
	set("chat_msg", (: random_chat :));
}

// traverser: 0: continue, 1: prune, -1: done
int visit_room(string room_path, mapping t_info, mapping r_info, int dist) {

    if (t_info["dist"] > dist) return 1; // prune
    if (!stringp(t_info["dir"])) return 0;
    if (strsrch(t_info["dir"], "out_sea") == 0) return 1; // don't go out sea

    if (is_exact_dist && (t_info["dist"] < dist)) return 0;

    rooms[room_num] = room_path;
    room_num++;
    if (room_num >= MAX_ROOM) return -1; // done
    return 0;
}

int init() {
    object *obs, me=this_object();
 
    obs = filter_array(children("/d/city/npc/ftb_zhu"), (: clonep :));
    if (sizeof(obs) > 1) {
	message("vision", me->name(1)+"急急忙忙地离开了.\n", environment(me), me);
	destruct(me);
	return 0;
    }
}

// returns the file path of target room
string find_target_room(object traverser, int dist) {
    object mapdb;
    string room_path;
    
    // simply get a ramdon room path
    mapdb = find_object(MAPDB);
    if (! objectp(mapdb))         mapdb = new(MAPDB);
    if (! objectp(mapdb))         return 0;

    mapdb->restore();
    room_path = mapdb->query_random_room_path();
    if (strsrch(room_path, "/d/beijing/")==0 ||
        strsrch(room_path, "/d/island/")==0 ||
        strsrch(room_path, "/d/taohua/")==0 ||
        strsrch(room_path, "/d/shenlong/")==0 ||
        strsrch(room_path, "/u/")==0 ||
        strsrch(room_path, "/d/wizard/")==0 ||
        strsrch(room_path, "/d/xiakedao/")==0) return 0;
    return room_path;
}

// returns the killer
object put_object(string room_path, object player) {
    object room, killer;

    room = find_object(room_path);
    if (!room) room=load_object(room_path);
    if (!room) {
  	printf("BUG: could not load room %s\n", room_path);
	return 0;
    }
    // killer will self-destruct in 10 minutes
    killer=new("/d/city/npc/ftb_killer");
    killer->set_status(player);
    killer->move(room);
    message("vision", killer->name(1)+"快步走了过来.\n", room, killer);
    return killer;
}

// returns total number of killers put
int put_objects(object traverser, object player, string target_room_path, 
	int range, int num) {
    int i, total;
    string room_path;
    object *obj_list;

    // traverse and gather all rooms in range
    room_num = 0;
    is_exact_dist = 0;
    traverser->traverse(target_room_path, (: visit_room :), range);

    if (room_num <= 0)  {
	printf("ERROR: no object rooms found in range %d of %s\n", range, target_room_path);
	return 0;
    }
    obj_list = allocate(num);
    for (i=0; i<num; i++) {
        room_path = rooms[random(room_num)];
	if (objectp(obj_list[total]=put_object(room_path, player))) {
	    total++;
	}
    }
    if (total == 0) {
 	printf("BUG: couldn't put objects at all.\n");
	return 0;
    }
    player->set(JOB_NAME+"/obj_list", obj_list);
    return total;
}

void adjust_rate() {
    object js;
    int exp_limit, pot_limit, last_job;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
	printf("BUG: please report: job_server.c could not be cloned\n");
	return;
    }

    exp_limit = js->get_exp_limit_func(JOB_NAME);
    pot_limit = js->get_pot_limit_func(JOB_NAME);
    last_job = (int)js->get_job_data_func(JOB_NAME, "last_job");
    js->set_job_data_func(JOB_NAME, "last_job", time());

    if (time() - last_job > 1200) {  // nobody does job for 20 min
	// increase 600 exp/hour, so 10 hour nobody do job, it's 6K/h
	exp_limit += (time()-last_job)*600/3600;   
	pot_limit += (time()-last_job)*60/3600;   
	if (exp_limit > 10000) exp_limit = 10000;	    // cap
	if (pot_limit > 1000) pot_limit = 1000;
    }
    exp_limit -= exp_limit/1000;
    if (exp_limit < 3000) exp_limit = 3000;	// exp/hour

    pot_limit = exp_limit/10;

    js->set_exp_limit_func(JOB_NAME, exp_limit);
    js->set_pot_limit_func(JOB_NAME, pot_limit);
    js->save();
    destruct(js);
}

// return: >0 ok, 0 fail
int assign_job(object player) {
    string target_room_path;
    object js, traverser;
    int ret, num, dist, range;
    int exp_limit, pot_limit, last_job, raising;

    traverser = new (TRAVERSER);
    if (!objectp(traverser)) {
        printf("BUG: %s cannot be cloned\n", TRAVERSER);
 	return 0;
    }

    // find a target room
    dist = 10+random(10);
    range = 4+random(6);
    num = 1+random(range/2); 

    target_room_path = find_target_room(traverser, dist);
    ret=0;
    while ( ret < 100 && ! target_room_path) {
   	ret++;
	target_room_path = find_target_room(traverser, dist);
    }
    if (!target_room_path) {
	printf("BUG: cannot find target room. Try ask again.\n");
	return 0;
    }

    // put the target npcs in the rooms
    ret = put_objects(traverser, player, target_room_path, range, num);
    destruct(traverser);

    if (ret > 0) {

	player->set(JOB_NAME+"/target_room", target_room_path);
	player->set(JOB_NAME+"/range", range);
	player->set(JOB_NAME+"/obj_num", ret);
	JOB_SERVER->start_job(player, JOB_NAME);
    }
    return ret;
}

string get_room_msg(string room_path) {
    string room_msg, *dirs;
    object room;
    mapping exits;
    int i;

    room = find_object(room_path);
    if (!objectp(room)) room = load_object(room_path);
    if (!objectp(room)) {
	printf("BUG: room %s is missing\n", room_path);
	return 0;
    }
    room_msg = room->query("short");
    // get the room names around target_room
    exits = room->query("exits");
    dirs = keys(exits);
    if (sizeof(dirs) > 1) {
	room_msg += "(该处靠近";
	for (i=0; i<sizeof(dirs); i++) {
	    if (i>2) break;
	    room_path = exits[dirs[i]];
	    room = find_object(room_path);
	    if (!objectp(room)) room=load_object(room_path);
	    if (objectp(room)) {
		if (i>0) room_msg += ", ";
		room_msg += room->query("short");
	    }
	}
	room_msg += ")";
    }
    return room_msg;
}

string tell_job(object player) {
    int start_time, used_time, rate, exp_rate, obj_num, kill_num, range;
    int i, sacrifice;
    string num_msg, range_msg, room_msg, region;
    object gold, killer, *obj_list;

    start_time = JOB_SERVER->get_start_time(player, JOB_NAME);
    obj_num = player->query(JOB_NAME+"/obj_num");
    kill_num = player->query(JOB_NAME+"/kill_num");
    range = player->query(JOB_NAME+"/range");
    used_time = time()-start_time;

    // case 1: over time
    if (used_time >= 1200) { // 20 min
	JOB_SERVER->abort_job(player, JOB_NAME);
  	command("kick "+player->query("id"));
	player->delete(JOB_NAME);
  	return "去了这么久才回来, 人家早得手啦.";
    }

    // case 2: just got assignment
    if (player->query(JOB_NAME+"/kill_num") == 0) {
	if (time()-player->query(JOB_NAME+"/last_ask_time") < 10) {
	    // avoid flooding
	    return;
	}
	if (player->query(JOB_NAME+"/last_ask_time") > 0) { // not first time
	    command("say 我早就告诉过你了:");
	}
	player->set(JOB_NAME+"/last_ask_time", time());
	room_msg = player->query(JOB_NAME+"/target_room");
	if ( strsrch(room_msg, "/d/") != 0        
        ||  undefinedp(region = region_names[explode(room_msg, "/")[1]]))
                region = "";

	room_msg = get_room_msg(room_msg);
	
	num_msg = CHINESE_D->chinese_number(obj_num);
	range_msg = CHINESE_D->chinese_number(range);

	command("say 听说有"+num_msg+"个家伙想对本帮不利.");
	command("say 据说他们已经到了"+region+room_msg+"方圆"+range_msg+"里之内.");
	return "麻烦"+RANK_D->query_respect(player)+"去查一查, 若真是刺客便替本帮主除却了吧.";
    }

    // case 3: done job, reward:
    // rate depends on three things:
    //    range   : larger range, higher rate
    //    kill_num: percentage of obj_num
    //    time    :     the shorter the better
    // if you quickly kill one, then pot rate is high
    // if you kill all but slower, pot rate drops, but exp rate raise

    rate = 50+range*5;   // range 4-10 
    if (used_time < 60) used_time = 60; // impossible to finish in 1 min

    // Assume you spend 1 min to find the places,
    // use 2 min to kill each one
    if (range > 5)  { // give some extra time if the searching range is large
	rate = rate * (60+obj_num * (120+10*(range-5))) / used_time;  
    }else {
	rate = rate * (60+obj_num * 120) / used_time;  
    }

    rate = rate * (95+random(10)) / 100;    // random factor
    if (obj_num < 1)  exp_rate = 0;
    else exp_rate = rate * kill_num * kill_num / (obj_num*obj_num);

    // sacrifice: How many times this player effectively died from this 
    // job. The more he died, the more reward he gets now
    // 10: bonus 20%
    // 30: bonus 100%  This should be very rare already.
	
	// edit by mantian may/2/2001
	// 40: bonus 200%
	// 50: player recive enough bonus, so reset sacrifice 
	// remove 50 and 100 when sacrifice over or = 50 reset bonus

    sacrifice = (int)player->query("futou_bang/sacrifice");
    if (sacrifice > 50) player->delete("futou_bang/sacrifice");
    if (sacrifice < 10) sacrifice *= 2;
    else if (sacrifice < 30) sacrifice = sacrifice*4-20;
    else if (sacrifice > 40) sacrifice = sacrifice*8-120;
    else sacrifice = 5;

    rate += sacrifice;
    exp_rate += sacrifice;

    // Finally: we slow down top highhands over 6M
    if (player->query("combat_exp") > 6000000) {
        exp_rate = exp_rate * 5000000 / player->query("combat_exp");
    }

    // Gaibang player can use midao, so give fewer reward
    if (player->query("family/family_name") == "丐帮") {
	rate = rate * 2 / 3;
	exp_rate = exp_rate *2 / 3;
    }

    // adjust exp_limit depending on how frequent job is done
    adjust_rate();
    JOB_SERVER->reward(player, JOB_NAME, exp_rate, rate);

    if (rate >= 50) {
	gold=new("/clone/money/gold");
	if (objectp(gold)) {
	    if (rate > 150)  {
		gold->set_amount(5); 
	    }else {
		gold->set_amount(rate/30);
	    }
	    gold->move(player);
	    message_vision("$N交给$n几锭黄金\n", this_object(), player);
	}
    }
    if (random(exp_rate) > 90) {
	player->add("max_neili", 1);
	player->add("eff_jingli", 1);
    }

    command("say 好样的, 斧头帮就靠你这样的大才啊!\n");
    command("thumb "+player->query("id"));

    // destruct the killers that hasn't been killed
    obj_list = player->query(JOB_NAME+"/obj_list");
    for (i=0; i<obj_num; i++) {
	killer = obj_list[i];
	if (objectp(killer)) {
	    message("vision", killer->name(1)+"急急忙忙地离开了.\n", environment(killer), killer);
	    destruct(killer);
	}
    }
    player->delete(JOB_NAME);
    return "一点小意思, 请笑纳.";
}

string ask_job() {
    object player;

    player = this_player();
    if (player->query("combat_exp") < 10000) return 0;
    if (player->query("combat_exp") > 11000000) return 0;  
     //temporiarly disabled job for over 11m players - by xQin
    // until overflow bug is fixed, currently if the player is over somewhere between 
   //10.5m to 11m, NPC exp will overflow and approach zero.
    if (JOB_SERVER->get_start_time(player, JOB_NAME) > 0) {
	return tell_job(player);
    }
    if (assign_job(player)) return tell_job(player);

    return "BUG: assign_job failed";
}

string ask_cike() {
    int exp_limit;

    exp_limit = JOB_SERVER->get_exp_limit(JOB_NAME);
    if (exp_limit > 9000) {
  	command("shout");
	return "唉, 最近刺客猖獗, 本帮长老多有被害, 连本帮主都差点被刺.";
    }else if (exp_limit > 8000) {
  	command("sigh");
	return "这个... 最近刺客时有行动, 幸好还没把本帮主给伤了.";
    }else if (exp_limit > 7000) {
  	command("nod");
	return "多亏江湖朋友们助拳, 最近刺客有所收敛.";
    }else if (exp_limit > 6000) {
  	command("hehehe");
	return "这多好朋友们来帮忙, 哪里还能有多少刺客.";
    }else if (exp_limit > 5000) {
  	command("haha");
	return "君不见本帮好生兴旺, 就算偶尔有个把刺客, 也从没得过手啊.";
    }else if (exp_limit > 4000) {
  	command("yawn");
	return "这都哪辈子的事了, 还来问. 如今斧头帮离一统天下也没多远了, 还能有刺客?";
    }else {
  	command("en");
	return "斧头帮一统天下, 想杀谁也不用行刺吧?";
    }
}

string ask_freq() {

    int last_job, len, sacrifice;

    sacrifice = (int)this_player()->query("futou_bang/sacrifice");
    if (sacrifice > 0) {
        tell_object(this_player(), "");
    }

    last_job = (int)JOB_SERVER->get_job_data_func(JOB_NAME, "last_job");
    len = time()-last_job;
    if (len > 3600) {
	command("sigh");
	return "许久没见江湖朋友们赏脸了.";
    }else if (len > 1200) {
	command("bow");
	return "江湖朋友们时有来助拳的, 本帮主真是感激不尽.";
    }else {
	command("thumb");
	return "江湖朋友们极是抬举, 斧头帮不日一统天下!";
    }
}

int random_chat() {

    switch (random(200)) {
    case 0:
        command("say 本帮自开山立派以来经历多少风风雨雨, 本帮主自当奋发图强.");
	return 1;
    case 1:
        command("say 大丈夫战死沙场, 马革那个什么尸, 原是英雄本色.");
	return 1;
    case 2:
        command("say 俗话说, 吃得苦中苦, 方为人上人, 哪个成名好汉不是这么过来的.");
	return 1;
    case 3:
        command("say 近来天气总他妈的不放晴, 是不是有什么灾祸要临头?");
	return 1;
    case 4:
        command("say 本帮主最爱的是硬汉, 为本帮出生入死的英雄.");
	return 1;
    case 5:
        command("say 天下大势, 这个是合久必分分久必合, 但看你能否抓住机会.");
	return 1;
    case 6:
        command("say 想当初老子刚出道时, 还不是见山拜山见佛拜佛?");
	return 1;
    case 7:
        command("say 人生得意须尽欢哪.");
	return 1;
    case 8:
        command("say 人生得意须尽欢哪.");
	return 1;
    default:
	return 0;
    }
    return 1;
}

#include "/clone/obj/npc_setup.c"
