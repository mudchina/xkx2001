//Cracked by Roath
// Room: /d/dali/hongts1.c

inherit ROOM;

void create()
{
	set("short", "宏圣寺塔");
	set("long", @LONG
这里是宏圣寺塔内部，四面墙壁上都辟有佛龛，龛内置佛像。抬头上望，可
以看到中心柱、葫芦顶、伞盖、相轮及莲花座托等。伞盖成八角形，角上挂有风
铎。
LONG);
	set("exits", ([
		"up" : __DIR__"hongts2.c",
		"down" : __DIR__"hongtj.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int current_jingli, current_dodge;

	current_jingli = me->query("jingli");
	if (dir == "up" && current_jingli >40)
	{
		me->set("jingli",current_jingli-random(30));
		me->improve_skill("dodge", random(10));
		write("你爬上一层楼，有些累了。\n");
	}
	else if (dir == "up" && current_jingli <= 40)
	{
		write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
		me->unconcious();
		return notify_fail("");
	}
	return ::valid_leave(me, dir);
}

