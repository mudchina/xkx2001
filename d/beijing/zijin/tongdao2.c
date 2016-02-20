//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao2.c

inherit ROOM;

void create()
{
	set("short", "通道");
	set("long", @LONG
这是一条大青石铺成的宽敞通道,可供宫中车马通过,两侧是数
丈高的围墙,令人感到庄严肃穆.

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yikungong",
  "north" : __DIR__"tongdao3",
  "south" : __DIR__"tongdao1",
  "east" : __DIR__"longfumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
