//Cracked by Roath
// Room: /d/beijing/west/longzheting.c

inherit ROOM;

void create()
{
	set("short", "龙泽亭");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"chengxiangting",
  "west" : __DIR__"yongruiting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
