//Cracked by Roath
// Room: /d/dali/guandao6.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条蜿蜒崎岖的山间土路，是由中原通向大理的官道。此处属川南，向
西南去的盘山路通上云贵山区，继而可达南昭大理国，此去向北不远就是蜀中名
川——峨嵋山。
LONG);
	set("exits", ([
		"northeast" : "/d/emei/shijie1",
		"southwest" : __DIR__"guandao5",
		]));
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
