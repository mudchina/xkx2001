//Cracked by Roath
// Room: /d/beijing/zijincheng/jingyanggong.c

inherit ROOM;

void create()
{
	set("short", "景阳宫");
	set("long", @LONG
东六宫之一,这是明清两代后妃们居住的地方.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yushufang",
  "west" : __DIR__"gzxd10",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
