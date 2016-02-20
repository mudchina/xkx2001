//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "武师睡房");
	set("long", @LONG
这是白驼山庄武师们平日休息的睡房，窗外可以望见远方沙丘起伏，
辽阔的大漠一望无际。房中摆设着木制的桌椅，一排盖着白布被的木床列
在墙边。
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	    "east" : __DIR__"changlang4",
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
	object me;
	
	me = this_player();

	seteuid(getuid());

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if (me->query("family/family_name") != "白驼山") {
		write("你不是白驼山的人，不能睡在这儿！\n");
		return 1;	
	}
	if (me->query("family/generation") > 3 ){
		write("这是武师们的睡房，下人不能睡在这里。\n");
		return 1;
		}
	if (me->query("family/generation") < 3 ){
		write("你贵为少主，怎能睡武师们的睡房？\n");
		return 1;
		}
	return 0;
}
