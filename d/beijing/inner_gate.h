//Cracked by Roath
// Room: /d/beijing/inner_gate.h

#include "/d/beijing/beijing_defs.h"

string look_gaoshi();
int do_guard();
int gen_killer();
int do_pancha(string id);
void reward_shiwei(int rank, object player);

string look_gaoshi()
{
    return "九门提督谕：出入内城百姓一概验明身份，\n" + 
	"形迹可疑者送有司审理，拒捕格杀勿论。\n";
}

void create()
{
	set("short", GATE_DESC_SHORT);
	set("gate_name", GATE_DESC_SHORT);
	set("is_inner_gate", 1);
	set("long", GATE_DESC_LONG);
	set("exits", GATE_EXITS);

	set("objects", GATE_OBJECTS);

	set("item_desc", ([
	"gaoshi" : (: look_gaoshi :), 
]));
	set("outdoors", "beijing");
	set("cost", 3);
	setup();
	remove_call_out("gen_killer");
	call_out("gen_killer", 10);
}

void init()
{
    object player = this_player(), me = this_object();

    add_action("do_guard", "guard");
    add_action("do_pancha", "pancha");
    
    if (! IS_SHIWEI(player)) {
 	player->set_temp("pancha_stage", 1);
	call_out("remove_need_pancha", 5, player);
    }
}

void remove_need_pancha(object player)
{
    if (player->query_temp("pancha_stage") == 1)
	player->delete_temp("need_pancha");
}

void reward_shiwei(int rank, object player)
{
    int kill_num = player->query_temp("kill_num");
    int fail_num = player->query_temp("fail_num");

    message_vision("城门的钟敲了两下，$N的换班时间到了。\n", player);
    player->delete_temp("start_job_time");
    player->delete_temp("can_pancha");
    player->delete_temp("fail_num");
    player->delete_temp("kill_num");
    HELPER->job_reward (player, rank, kill_num, fail_num);
}

void gen_killer()
{
    object env = this_object();
    object *killers ;
    object *inv, killer;
    int    i, shiwei_present = 0;

    remove_call_out("gen_killer");
    call_out("gen_killer", 10);

    killers = HELPER->obj_in_env("/d/beijing/npc/killer2.c", env);
    inv = all_inventory(env);
    for (i=sizeof(inv)-1; i>=0; i--) {
        if (userp(inv[i]) && living(inv[i]) && 
	    IS_SHIWEI(inv[i]) && inv[i]->query_temp("can_pancha")){
	    if (HELPER->is_night_shift()) {
		if (SHIWEI_LEVEL(inv[i]) == 2) {	
		    reward_shiwei(2, inv[i]);
		}else{
		    shiwei_present++;
		}
	    } else {
		if (SHIWEI_LEVEL(inv[i]) == 3) {
		    reward_shiwei(3, inv[i]);
		}else{
		    shiwei_present++;
		}
	    }
        }
    }

    if (shiwei_present == 0) return;

    if (HELPER->is_night_shift()) {
	if (killers) return;
	killer = new("/d/beijing/npc/killer2.c");
	killer->move(env);
	killer->upgrade(3);
	message_vision("$N快步走了过来。\n", killer);
    }else {
	if (killers) return;
	killer = new("/d/beijing/npc/killer2.c");
	killer->move(env);
	message_vision("$N快步走了过来。\n", killer);
    }
    return;
}

int do_guard()
{
    object player = this_player();
    if (! IS_SHIWEI(player)) return 0;

    if (SHIWEI_LEVEL(player) > 3)
        return notify_fail("你已经不用守城门啦。\n");
    if (player->query_temp("can_pancha"))
	return notify_fail("你已经在守门了。\n");

    if (!player->query_temp("current_job"))
	return notify_fail("你得先去问问多大人，你今天值班的地方是那儿？\n");
    if (player->query_temp("current_job") != query("gate_name"))
 	return notify_fail("这里不是你要守的地方。快去"+
	    player->query_temp("current_job")+"吧。\n");
    if (SHIWEI_LEVEL(player) == 2 && HELPER->is_sunrise() != 0) {
	player->delete_temp("current_job");
	return notify_fail("辰时已过你才来城门，今天就不用你守了！\n");
    }

    if (SHIWEI_LEVEL(player) == 3 && HELPER->is_sunset() != 0) {
	player->delete_temp("current_job");
	return notify_fail("戌时已过你才来城门，今天就不用你守了！\n");
    }

    player->delete_temp("current_job");
    player->set_temp("start_job_time", time());
    player->set_temp("can_pancha", 1);
    player->set_temp("fail_num", 0);
    player->set_temp("kill_num", 0);
    message_vision(
	"$N一叉腰，对身旁的官兵道：今天看本官如何查问过往闲人。\n", 
	player);
    tell_object(player, "你可以盘查 (pancha) 过往行人。\n");
    return 1;
}

void reply_pancha(object obj, object shiwei)
{
    int exp = obj->query("combat_exp");
    int min_exp = 150000;

    if (exp < 50000) obj->set_temp("pancha_stage", 4);
    if (HELPER->is_night_shift()) min_exp = min_exp * 2;
    if (random(exp) > min_exp) obj->set_temp("pancha_stage", 4);

    if (exp < 50000 && obj->query_temp("pancha_stage")==4){
	message_vision("$N低声答道：小人进城观光，请大人高抬贵手。\n", obj);
	message_vision("$N笑道：好吧，慢慢逛吧。\n", shiwei);
	return;
    }
    if (obj->query_temp("pancha_stage")==4){
	message_vision("$N答道：在下有公干在身，请大人放行。\n", obj);
	message_vision("$N道：不敢，请。\n", shiwei);
	return;
    }

    if (exp < 400000) {
	message_vision("$N嘿嘿嘿笑了两声，道：小人想进城干点勾当。\n", obj);
	message_vision("$N一言不发，陡然向$n发难。\n", obj, shiwei);
    } else  {
	message_vision("$N冷笑了两声，道：你管的着么？\n", obj);
	message_vision("$N大喝一声，狗贼给我让道！\n", obj);
    }
    obj->set_temp("pancha_stage", 3);
    obj->kill_ob(shiwei);
    shiwei->kill_ob(obj);
}

int do_pancha(string name)
{
    object me = this_player(), obj;
    
    if (! me->query_temp("can_pancha"))
	return 0;

    if (! name || name=="" )
        return notify_fail("你想盘查谁？\n");
    
    if (!objectp(obj = present(name, environment(me))))
         return notify_fail("这里没有这个人。\n");

    if (!obj->is_character() || obj->is_corpse())
         return notify_fail("看清楚点，这不是活人。\n");

    if (!living(obj))
	return notify_fail("等他醒了再说吧。\n");

    message_vision("$N对着$n看了两眼，慢吞吞的说道：干什么的呀？\n",
        me, obj);
    obj->set_temp("pancha_stage", 2);
    remove_call_out("reply_pancha");
    call_out("reply_pancha", 2, obj, me);
    return 1;
}

int valid_leave(object me, string dir)
{
    object *inv;
    int i, stage, fail_num, shiwei_present=0;
    
    if (IS_SHIWEI(me) && me->query_temp("can_pancha"))
	return notify_fail("你还没完成守门的任务呢，怎么能离开？\n");

    stage=query_temp("pancha_stage");
    switch (stage) {
    case 2:	// shiwei is pancha me, waiting for me to reply
	return notify_fail("守门侍卫正在盘查你呢。\n");

    case 1: 	// we need to wait for shiwei to pancha us
    case 3:     // we are killing shiwei
	// find all shiwei present
	inv = all_inventory(environment(me));
	for (i=sizeof(inv)-1; i>=0; i--) {
	    if (userp(inv[i]) && living(inv[i]) && 
		inv[i]->query_temp("can_pancha") &&
		IS_SHIWEI(inv[i]) ) {	// found a shiwei
		if (stage==1){  	// can't leave yet
		    return notify_fail(inv[i]->query("name")+
			    "指了指你道，你等会儿，我还得查查你呢。\n");
		}
		fail_num = inv[i]->query_temp("fail_num");
		inv[i]->set_temp("fail_num", fail_num+1);
	    }
	}
	if (stage == 3) { // escaped
	    message_vision("$N趁着侍卫们不注意，溜了！\n", me);
	}
	me->delete_temp("pancha_stage");
	return ::valid_leave(me, dir);
    case 0:	// ok, we can leave now
    default:
	return ::valid_leave(me, dir);
    }
}


