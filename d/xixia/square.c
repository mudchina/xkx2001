//Cracked by Roath
// Room: /d/xixia/square.c

inherit ROOM;

void create()
{
	set("short", "皇宫广场");
	set("long", @LONG
这里是皇宫里的广场，中间是一条宽阔的青石板路，路的两边是
铠甲鲜明的武士，十步一岗，五步一哨，个个手持长枪大戟，端的气
势非凡，西夏的军力由此可见一斑。南边是皇宫正门，北面就是议事
大殿。殿门口有两口大铜缸，储满了清水。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ysdian",
]));
	set("objects", ([
		__DIR__"npc/shiwei" : 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
