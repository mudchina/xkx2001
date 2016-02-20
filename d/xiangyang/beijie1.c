//Cracked by Roath
// Room: /d/xiangyang/beijie1.c

inherit ROOM;

void create()
{
	set("short", "北街");
	set("long", @LONG
你走在宽大整齐的北大街上，却发现路旁店铺并不是很多。冷冷清清的街道
上偶尔有行人匆匆忙忙的走过。南边是一个较大的广场，那是襄阳城的中心。往
西可通往襄阳积粮所在，东边是一座更楼。
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gengloux",
  "south" : __DIR__"guangc",
  "north" : __DIR__"beijie2",
  "west" : __DIR__"jicang",
]));
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
