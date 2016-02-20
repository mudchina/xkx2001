//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov35.c

inherit ROOM;

void create()
{
	set("short", "星云湖畔");
	set("long", @LONG
星云湖又名小镜湖，方圆有十数里。东靠玉霞山，碧水清澈，风光妩媚，乃
是大理东部名景。明月之夜，皎洁的月光映照湖面，风拂水波，摇曳生姿，如繁
星落入湖中，晶亮如云，故名之。在此远眺湖之东南岸，可见青青翠竹，似有房
舍隐在其中。
LONG);
	set("exits", ([
		"eastup" : __DIR__"minov36",
		"north" : __DIR__"minov34",
		]));
	set("area", "步雄部");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
