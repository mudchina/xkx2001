//Cracked by Roath
// Room: /d/quanzhou/weiyuan.c

inherit ROOM;

void create()
{
	set("short", "威远楼");
	set("long", @LONG
这是泉州的北门城楼，青石筑成两层楼台坚固异常，巍峨宽阔的拱行城门
上方镂着「泉州」两个红漆大字。城墙上贴着一张官府告示(gaoshi)。过了此
门就是北边蜿蜒崎岖的清源山区了。
LONG
	);
	set("item_desc", ([ ]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/bing" : 2,
  __DIR__"npc/wujiang" : 1,
]));
	set("cost", 1);
	set("outdoors", "quanzhou");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu6",
  "south" : __DIR__"citong_n1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
