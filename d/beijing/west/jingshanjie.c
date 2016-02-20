//Cracked by Roath
// Room: /d/beijing/west/jingsanjie.c

inherit ROOM;

void create()
{
	set("short", "景山街");
	set("long", @LONG
这是一条位于鼓楼西南面的背街，十分僻静冷落，路上几乎见不
到什麽行人，东北面鼓楼大街喧哗声不时传到这里来。街东边有一间
小庙，上有几个大字『火神庙』。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"gulou",
  "east" : __DIR__"huoshenmiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
