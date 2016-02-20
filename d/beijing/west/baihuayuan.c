//Cracked by Roath
// Room: /d/beijing/west/baihuayuan.c

inherit ROOM;

void create()
{
	set("short", "百花园");
	set("long", @LONG
这里种满了名花异草，尤以月季为盛。一花未谢，一花
又开。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shibanlu1",
  "east" : __DIR__"penshuichi",
  "southwest" : __DIR__"xitianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
