//Cracked by Roath
// Room: /d/beijing/zijincheng/yikungong.c

inherit ROOM;

void create()
{
	set("short", "翊坤宫");
	set("long", @LONG
这是明清两代后妃们居住的地方.清代慈禧太后住储秀宫时,每
逢重大节日都要在这里接受妃嫔们的朝拜.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"changchungong",
  "north" : __DIR__"tihedian",
  "east" : __DIR__"tongdao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
