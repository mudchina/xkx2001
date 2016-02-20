//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov88.c

inherit ROOM;

void create()
{
	set("short", "川西山路");
	set("long", @LONG
你走在川西山间的一条土路上。此间属古蜀境内，地势甚高，可山势相对较
平缓。西面可见白雪皑皑的青藏高原群山，向南一路穿越山陵直通向云南大理。
附近山间有些乌夷人的村落。
LONG);
	set("exits", ([
		"northup" : __DIR__"minov89",
		"southdown" : __DIR__"minov87",
		]));
	set("area", "乌弄城");
	set("cost", 4);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
