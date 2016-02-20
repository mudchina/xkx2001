//Cracked by Roath
// Room: /d/beijing/west/beihaiximen.c

inherit ROOM;

void create()
{
	set("short", "北海西门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"beihaixian",
  "west" : __DIR__"fuchengmenjie",
  "east" : __DIR__"beihaidaqiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
