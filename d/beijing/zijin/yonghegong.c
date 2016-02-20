//Cracked by Roath
// Room: /d/beijing/zijincheng/yonghegong.c

inherit ROOM;

void create()
{
	set("short", "永和宫");
	set("long", @LONG
东六宫之一,这是明清两代后妃们居住的地方.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tongshunzhai",
  "west" : __DIR__"gzxd9",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
