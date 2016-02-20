//Cracked by Roath
// Room: /d/beijing/zijincheng/neiyoumen.c

inherit ROOM;

void create()
{
	set("short", "内右门");
	set("long", @LONG
这是通往养心殿和西六宫的重要门户,由此往里是皇帝和后妃们
居住的地方.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"qianqingmen",
  "north" : __DIR__"tongdao1",
  "west" : __DIR__"yangxindian",
  "east" : __DIR__"yuehuamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
