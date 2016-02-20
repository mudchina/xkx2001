//Cracked by Roath
// Room: /d/beijing/west/baihoutang.c

inherit ROOM;

void create()
{
	set("short", "后堂");
	set("long", @LONG
这是白家大宅的后堂，地上散落着一些未烧尽的纸钱，四周散
放着一些挽联，一阵冷风从门口吹进来，不由得使人寒毛直竖。几
盏灵灯散发出昏黄的灯光，看上去十分凄凉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lingtang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
