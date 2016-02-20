//Cracked by Roath
// Room: /d/xiangyang/jzjie2.c

inherit ROOM;

void create()
{
	set("short", "荆州街");
	set("long", @LONG
这是荆州街的中段，也是襄阳为数不多的大集市。路旁的事物花花绿绿、
琳琅满目，多年的战火并未使襄阳的商者完全湮灭。路上的行人南腔北调，显是
自四方接踵而至。西去是襄阳的北街。
LONG
	);
        set("coordinates", ([ "x" : 3, "y" : 4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"jzjie3",
  "west" : __DIR__"beijie2",
  "south" : __DIR__"jzjie1",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
