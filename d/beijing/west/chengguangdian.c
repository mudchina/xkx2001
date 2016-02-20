//Cracked by Roath
// Room: /d/beijing/west/chengguangdian.c

inherit ROOM;

void create()
{
	set("short", "承光殿");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"beihaiqianmen",
  "north" : __DIR__"yonganqiao",
  "west" : __DIR__"beihaidaqiao",
  "east" : __DIR__"hubianxiaodao7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
