//Cracked by Roath
// Room: /d/beijing/zijincheng/neizuomen.c

inherit ROOM;

void create()
{
	set("short", "内左门");
	set("long", @LONG
这是通往东六宫的重要门户,由此往里是皇帝和后妃们居住的地方.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rijingmen",
  "north" : __DIR__"tongdao4",
  "east" : __DIR__"zhaigong",
  "southwest" : __DIR__"qianqingmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
