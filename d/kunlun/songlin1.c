//Cracked by Roath
// Room: /d/mingjiao/songlin1.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "松林");
	set("long", @LONG
此处松林极为茂密，阳光被松枝遮住，甚是昏暗，看来已没有道路了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"shanjiao1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
