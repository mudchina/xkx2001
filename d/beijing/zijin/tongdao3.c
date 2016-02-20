//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao3.c

inherit ROOM;

void create()
{
	set("short", "通道");
	set("long", @LONG
这是一条大青石铺成的宽敞通道,可供宫中车马通过,两侧是数
丈高的围墙,令人感到庄严肃穆.

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"kunningmen",
  "south" : __DIR__"tongdao2",
  "west" : __DIR__"chuxiugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
