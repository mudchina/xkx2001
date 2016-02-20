//Cracked by Roath
// Room: /d/xiangyang/tulu3.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这条路本是城门外的官道，但因连年乱战，兵事不断，以至官府也忘修整。
路上高低不平，随处可见那马蹄车轮踏出的坑坑洼洼。一到雨季，这被雨水一
冲，更变得泥泞不堪。
LONG
	);
        set("coordinates", ([ "x" : -8, "y" : 0 ]) );
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "westup" : __DIR__"tanxi",
  "southeast" : __DIR__"tulu2",
  "east" : __DIR__"tulu1",
]));

	setup();
	replace_program(ROOM);
}
