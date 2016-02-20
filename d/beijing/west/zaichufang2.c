//Cracked by Roath
// Room: /d/beijing/west/zaichufang2.c

inherit ROOM;

void create()
{
	set("short", "宰牲房");
	set("long", @LONG
这里是宰杀祭祀用的牲畜的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"huanqiu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
