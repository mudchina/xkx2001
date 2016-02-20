//Cracked by Roath
// Room: /d/xiangyang/xiaoshitai.c

inherit ROOM;

void create()
{
	set("short", "校士场");
	set("long", @LONG
你站在阅兵大校场上，见一队队兵马在台下操练。每一营由一名总兵统带，
排练操演，果然是盔甲鲜明，衣袍灿烂；金鼓震天，戈戟参地；四面八方，各分
队伍；旌旗蔽彩，人马腾空。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lianwuc",
  "eastup" : __DIR__"guloud",
  "north" : __DIR__"xijie2",
  "southeast" : __DIR__"djtai",
]));

	setup();
	replace_program(ROOM);
}
