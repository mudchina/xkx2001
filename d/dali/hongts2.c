//Cracked by Roath
// Room: /d/dali/hongts2.c
// Bug Fix By Mantian Nov,11,2000

inherit ROOM;

int do_study(string);

void create()
{
	set("short", "宏圣寺塔");
	set("long", @LONG
这里是宏圣寺塔内部，四面墙壁上都辟有佛龛，龛内置佛像。西面塔壁由模
印砖所砌，上面用梵，汉文刻了阴形文的“阿众佛灭正保咒”。
LONG);
	set("exits", ([
		"down" : __DIR__"hongts1.c",
		]));
	setup();
	set("cost", 3);
	set("no_clean_up", 0);
}
void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
}
int do_study(string arg)
{
	object me = this_player();

	if (!arg || arg != "brick") return 0;

	if ( (int)me->query_skill("literate", 1) < 1)
	{ 
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}

	if ( (int)me->query_skill("buddhism", 1) < 100)
	{
		if ( me->query("jing", 1) > 50)
		{ 
			me->receive_damage("jing", 30);
			message_vision("$N正专心研读模印砖上的「阿众佛灭正保咒」。\n", me);
		}
		else
		{
			message_vision("$N累的看不下模印砖上的「阿众佛灭正保咒」。\n", me);
			return 1;
		}
		me->improve_skill("buddhism", me->query("int"));
		write("你对着模印砖上的「阿众佛灭正保咒」琢磨了一回儿心得。\n");
		return 1;
	}
	write("你对着模印砖瞧了一回儿，发现上面所说的佛理太过浅显，对你来说已毫无意义了。\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	int current_jingli, current_dodge;

	current_jingli = me->query("jingli");
	if (dir == "down" && current_jingli >10)
	{
		me->set("jingli",current_jingli-random(20));
		me->improve_skill("dodge", random(10));
		write("你爬上一层楼，有些累了。\n");
	}
	else if (dir == "down" && current_jingli <= 10)
	{
		write("你累得走不动了，忽然眼冒金星，晕了过去。\n");    
		me->unconcious();
		return notify_fail("");
	}
	return ::valid_leave(me, dir);
}
