//Cracked by Roath
// Room: /d/beijing/east/shouhuangdian.c

inherit ROOM;

void create()
{
	set("short", "寿皇殿");
	set("long", @LONG
这里陈列了皇家列祖列宗的画像。四周点着长明灯。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"guoyuan",
  "north" : __DIR__"dianmen",
  "east" : __DIR__"guandedian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
