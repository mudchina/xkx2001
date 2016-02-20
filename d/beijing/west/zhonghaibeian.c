//Cracked by Roath
// Room: /d/beijing/west/zhonghaibeian.c

inherit ROOM;

void create()
{
	set("short", "中海北岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hubianxiaodao1",
  "north" : __DIR__"beihaiqianmen",
  "east" : __DIR__"hubianxiaodao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
