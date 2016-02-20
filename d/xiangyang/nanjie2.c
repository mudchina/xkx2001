//Cracked by Roath
// Room: /d/xiangyang/nanjie2.c

inherit ROOM;

void create()
{
	set("short", "南街");
	set("long", @LONG
你走在整洁宽大的青石大道上，路上的行人稀稀，不见其繁华。南去不
远便可出护国门，西面是襄阳集兵点将所在，平时有些士兵在操练。东边是陈
侯巷。
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huguo",
  "east" : __DIR__"chenhou",
  "north" : __DIR__"nanjie1",
  "west" : __DIR__"djtai",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
