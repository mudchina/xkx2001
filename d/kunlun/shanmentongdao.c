//Cracked by Roath
// Room: /d/mingjiao/shanmentongdao.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山门通道");
	set("long", @LONG
这是一条长长的山间通道，由下而上盘旋延伸。大路由青石铺成，不
时的有来往教众与你擦肩而过。两旁是高耸的山岩，几棵怪松龙盘而上。
眺目远望，只见对面山峰被云雾困锁，看不真切。
LONG
	);
	set("outdoors", "mingjiao");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"shijie2",
  "northwest" : __DIR__"shijie1",
  "southdown" : __DIR__"damen",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
