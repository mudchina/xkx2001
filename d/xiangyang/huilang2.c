//Cracked by Roath
// Room: /d/xiangyang/huilang2.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
白石栏杆围绕著回廊，栏外绿树成荫，隐约可见园中景致。回
廊顺着屋宇向南延伸，通向一列客房。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 6, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"huilang1",
  "south" : __DIR__"kefang",
]));

	setup();
	replace_program(ROOM);
}
