//Cracked by Roath
// Room: /d/beijing/west/zaichufang1.c

inherit ROOM;

void create()
{
	set("short", "宰牲房");
	set("long", @LONG
这里是宰杀祭祀用的牲畜的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"qiniandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
