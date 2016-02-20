//Cracked by Roath
// Room: /d/beijing/zijincheng/cininggong.c

inherit ROOM;

void create()
{
	set("short", "慈宁宫");
	set("long", @LONG
这里是皇太后居住的地方，地上铺着厚厚的地毯。正中有一道珠
帘。平时若未得太后宣召，是不能随便进入的。旁边是一座非常美丽
的花园。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shoukanggong",
  "north" : __DIR__"dafotang",
  "south" : __DIR__"ciningmen",
  "east" : __DIR__"longzongmen",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
