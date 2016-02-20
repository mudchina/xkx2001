//Cracked by Roath
// Room: /d/beijing/kangqin/fotang.c

inherit ROOM;

void create()
{
	set("short", "佛堂");
	set("long", @LONG
这是一间精致的佛堂。窗格雕花。正中一尊佛像，香案上烧着几柱香。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"mishi",
  "west" : __DIR__"garden2",
]));
	set("no_clean_up", 0);

	set("objects",([
                "/d/beijing/npc/puren.c":1,
        ]));

	setup();
	replace_program(ROOM);
}
