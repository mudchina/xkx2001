//Cracked by Roath
// Room: /d/beijing/west/beihaidaqiao.c

inherit ROOM;

void create()
{
	set("short", "北海大桥");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"beihaiximen",
  "east" : __DIR__"chengguangdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
