//Cracked by Roath
// Room: /d/beijing/kangqin/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是康亲王府的厨房，进门右手处一排并列了八，九口大锅。左边则是排放了各种准备好了的半成品，只等着下锅了。							LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"garden.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
