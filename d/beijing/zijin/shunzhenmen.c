//Cracked by Roath
// Room: /d/beijing/zijincheng/shunzhenmen.c

inherit ROOM;

void create()
{
	set("short", "顺贞门");
	set("long", @LONG
这是御花园北面的正门，在清朝，平时是关着的，皇帝、皇后、
妃嫔出入时，随时启闭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shenwumen",
  "south" : __DIR__"yuhuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
