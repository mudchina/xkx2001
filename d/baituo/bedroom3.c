//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是一间摆设简单的房间，白驼山庄中的家丁、婢女等下人都在
这里休息。地上铺着十几张床铺，因为是自己睡觉的地方，所以家丁
、婢女们也都打扫得挺干净。
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	    "northeast" : __DIR__"changlang4",
	]));

	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object me, where;
	
	me = this_player();
	where = environment(me);

	seteuid(getuid());

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if (me->query("family/family_name") != "白驼山") {
		write("你不是白驼山的人，不能睡在这儿！\n");
		return 1;	
	}
	if (me->query("family/generation") < 4 ){
		write("这是下人睡觉的地方，武师们有更好的地方睡。\n");
		return 1;
		}
	if (me->query("family/generation") < 3 ){
		write("你贵为少主，何必睡下人们的睡房？\n");
		return 1;
		}
	me->apply_condition("sleep", 2 + random(2));
	return 0;
}
