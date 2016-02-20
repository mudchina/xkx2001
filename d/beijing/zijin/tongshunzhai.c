//Cracked by Roath
// Room: /d/beijing/zijincheng/tongshun.c

inherit ROOM;

void create()
{
	set("short", "同顺斋");
	set("long", @LONG
这里是永和宫南边的一间小偏殿．地方不大，但布置得十分雅致，
打扫得也相当整洁．一股沉香之气在室内若有若无的盘旋缭绕，令人
昏昏欲睡．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yonghegong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
