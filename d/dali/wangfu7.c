//Cracked by Roath
// Room: /d/dali/wangfu7.c

inherit ROOM;

void create()
{
	set("short", "承光壁");
	set("long", @LONG
这是一道石壁，上面刻有九龙戏珠图，九龙张牙舞爪，神态各不相同。东边
尊玉佛，高一点五米，由一整块白玉雕刻而成。又有一只玉碗，直径一点五米，
由一整块黑玉雕刻而成。外面雕有海龙及海兽。
LONG);
	set("exits", ([
		"south" : __DIR__"wangfu6.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	object me;
	me = this_player();
	if ( !arg || ( arg != "wall" ) ) return notify_fail("什么？\n");
	if ( (int)me->query("neili") < 100)	return notify_fail ("你试着往墙上爬去，可是手脚无力，爬不上去。\n");
	if ( (int)me->query("jingli") < 60)	return notify_fail ("你试着往墙上爬去，可是手脚无力，爬不上去。\n");
	if ( (int)me->query("combat_exp") <15000)
	{
		me->receive_damage("qi", 50, "从墙上滚了下来摔死了");
		me->receive_wound("qi",  50, "从墙上滚了下来摔死了");
		message_vision("$N只觉得手上一松，... 啊...！\n", me);
		tell_object(me, "你从墙上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n");
		message("vision", "只见" + me->query("name") + "从墙上骨碌碌地滚了下来，躺在地上半天爬不起来！\n", environment(me), me);
		return 1;
	}
	me->add("jingli", (-1)*random(50), "体力不支而亡");
	me->add("neili", (-1)*random(50));
	message_vision("$N正在手脚并用的往照壁上爬去。\n", me);
	switch( random(3) ) 
	{
		case 0:
				if ( (int)me->query_skill("finger", 1) < 100)
				{
					me->improve_skill("finger", me->query("str"));
					write("你手脚并用的爬了一阵墙，似乎觉得指尖有些酸疼。\n");
					me->set_temp("wall_climbed",1);
                }
		case 1:
				if ( (int)me->query_skill("force", 1) < 100)
				{
					me->improve_skill("force", me->query("con"));
					write("你手脚并用的爬了一阵墙，似乎觉得体能有些长进。\n");
					me->set_temp("wall_climbed",1);
				}
		case 2:
					if ( (int)me->query_skill("dodge", 1) < 100)
				{
					me->improve_skill("dodge", me->query("dex"));
					write("你手脚并用的爬了一阵墙，似乎觉得行动灵活了些。\n");
					me->set_temp("wall_climbed",1);
				}
	}
	if ( !me->query_temp("wall_climbed") )
	{
		write("你觉得爬得起来不费吹灰之力。\n");
	}
	return 1;
}
