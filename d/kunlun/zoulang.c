//Cracked by Roath
// Room: /d/mingjiao/zoulang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条静悄悄的走廊，偶尔看见几名洪水旗教众匆忙地穿行此地。
从这里向北便是洪水旗的后堂，东边隐有阵阵寒气逼来。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"houtang",
  "south" : __DIR__"hdating",
  "east" : __DIR__"cangshui",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
