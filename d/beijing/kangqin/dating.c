//Cracked by Roath
// Room: /d/beijing/kangqin/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是大厅，豪华气派
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"tianjing",
  "north" : __DIR__"zhongmen",
  "west" : __DIR__"zhoulang2",
  "east" : __DIR__"zhoulang1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
