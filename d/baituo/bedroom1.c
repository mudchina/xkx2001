//Cracked by Roath
// 白驼改版
// maco 2/17/2000
#include <room.h>

inherit ROOM;
void wakeup(object me, object where);

void create()
{
	set("short", "少主睡房");
	set("long", @LONG
这里是白驼山少主所睡的厢房，房里锦帏绣被，珠帘软帐，柜架上
摆满了珍奇古玩，红烛高烧，墙边挂着蜀锦文囊，囊上用白丝线绣着一
只骆驼。睡房中时常有少主的姬妾在此侍候，都是各方搜罗来的佳丽，
是个温柔乡。
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	    "southeast" : __DIR__"changlang3",
	]));
	set("objects", ([
	    __DIR__"npc/shiji" : 1,
	 ]) );
	set("cost", 1);
	setup();
}
void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object shiji, me, where;
	
	me = this_player();
	where = environment(me);

	seteuid(getuid());

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if (me->query("family/family_name") != "白驼山") {
		write("你不是白驼山的人，不能睡在这儿！\n");
		return 1;	
	}
	if (me->query("family/master_id") != "ouyang feng" ){
		if(shiji = present("shi ji", environment(me))) {
			message_vision("$N正想爬上床去睡觉，忽然被$n给拉住了後领。\n"
			"$n瞪了$N一眼，骂道："+RANK_D->query_rude(me)+"，这可是少主的房间，你有什麽资格睡在这儿？\n\n", me, shiji);
			me->move("/d/baituo/changlang3");
			tell_object(me,"\n你被侍姬从少主睡房里轰了出来。\n");
			message("vision",me->query("name") + "灰头土脸地从少主睡房里走了出来，嘴里一阵喃喃咒骂。\n", environment(me), me);
			return 1;
		}
		else {
		write("这是少主的房间，可不是你的身分能睡的！\n");
		return 1;
		}
	}
	write("你往床上一躺，一名侍姬过来替你脱靴解带，服侍得十分周到。\n");
	write("侍姬替你盖上锦被，不一会儿，你就进入了梦乡。\n");
	me->set_temp("block_msg/all",1);
	message_vision("$N躺在床上，一名侍姬在旁服侍，不一会儿，$N就进入了梦乡。\n",me);

	where->add_temp("sleeping_person", 1);
	
	me->set_temp("sleeped",1);

	me->set("disable_type", "<睡梦中>");
	me->set_temp("disabled", 1);
	me->disable_commands();
	me->enable_commands();

	call_out("wakeup",random(60 - me->query("con")), me, where);
	call_out("wakeup",3, me, where);
	return 1;
}

void wakeup(object me, object where)
{
	int sp, new_hp;
	object shiji;
	sp = 10 - (int)me->query_condition("sleep");

	new_hp = (int)me->query("qi");
	new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_qi") ) new_hp = me->query("eff_qi");
	me->set("qi", new_hp);
	
	new_hp = (int)me->query("jing");
	new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_jing") ) new_hp = me->query("eff_jing");
	me->set("jing", new_hp);

	new_hp = (int)me->query("jingli");
	new_hp += ((int)me->query("max_jingli") - new_hp)*sp/5;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_jingli") ) new_hp = me->query("max_jingli");
	me->set("jingli", new_hp);

	new_hp = (int)me->query("neili");
	new_hp += ((int)me->query("max_neili") - new_hp)*sp/12;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
	me->set("neili", new_hp);
	
	if (living(me)) return;

	me->enable_player();
	while( environment(me)->is_character() )
		me->move(environment(environment(me)));
	me->apply_condition("sleep", 5 + random(3));

	if(environment(me) == where)
	{
		message_vision("$N一觉醒来，由侍姬服侍着穿好衣物，精力充沛地活动了一下筋骨。\n",me);
		me->set_temp("block_msg/all", 0);
		write("你一觉醒来，侍姬服侍着你穿戴整齐，只觉精力充沛，该活动一下了。\n");

	}
	else {
		message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
		me->set_temp("block_msg/all", 0);
		write("你一觉醒来，只觉精力充沛。该活动一下了。\n");
	}
	where->add_temp("sleeping_person", -1);
	setup();
}
