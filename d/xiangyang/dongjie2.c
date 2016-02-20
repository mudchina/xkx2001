//Cracked by Roath
// Room: /d/xiangyang/dongjie2.c

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long", @LONG
从这南北通着襄阳城最繁华的荆州街，路旁叫卖的小贩也逐渐多了起来。东
北不远是一间给来去赶路的旅客停步歇息的客栈。延着青石大道再向东走不远便
是东新门。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
        set("coordinates", ([ "x" : 3, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"dongxin",
  "west" : __DIR__"dongjie1",
  "northeast" : __DIR__"majiu",
  "north" : __DIR__"jzjie1",
  "south" : __DIR__"jzjie4",
]));

	setup();
	replace_program(ROOM);
}
