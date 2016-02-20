//Cracked by Roath
// Room: /d/xiangyang/huilang1.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
白石栏杆围绕著回廊，栏外绿树成荫，隐约可见园中景致。回
廊顺着屋宇向东南延伸，东北两边各有一间厢房。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 5, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wofang2",
  "east" : __DIR__"wofang1",
  "southeast" : __DIR__"huilang2",
  "west" : __DIR__"huajing2",
]));

	setup();
	replace_program(ROOM);
}
