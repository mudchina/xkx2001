//Cracked by Kafei
// Room: /d/dali/tianlong4.c

inherit ROOM;

void create()
{
	set("short", "僧舍");
	set("long", @LONG
一个空荡荡的房间，四角上有四个老僧正在闭目凝思。
西面墙上有一扇竹门。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tianlong3.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
