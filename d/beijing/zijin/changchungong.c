//Cracked by Roath
// Room: /d/beijing/zijincheng/changchungong.c

inherit ROOM;

void create()
{
	set("short", "长春宫");
	set("long", @LONG
这原本是后妃们居住的地方。但当今皇上年纪尚轻，尚未婚配。
因此偌大一间屋子里空空荡荡，没什么东西。只有几个太监偶尔来
打扫一下。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yiqingshuwu",
  "south" : __DIR__"tiyuandian",
  "east" : __DIR__"yikungong",
]));

	setup();
	replace_program(ROOM);
}
