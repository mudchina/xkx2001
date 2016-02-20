//Cracked by Roath
// Room: /d/mingjiao/shenwei.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "神威门");
	set("long", @LONG
一座高大的牌坊耸立在你面前，牌坊上书三个鎏金大字“神威门”，
教人一见便觉气势不凡。此处居于光明顶的北麓，北上便是明教厚土旗的
校场厅堂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"yongdao",
  "northeast" : __DIR__"shandao42",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
