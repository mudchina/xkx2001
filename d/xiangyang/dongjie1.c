//Cracked by Roath
// Room: /d/xiangyang/dongjie1.c

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long", @LONG
这是一条宽阔的青石板道，直向东西延伸过去。两旁冷冷清清，路上甚是清
洁。南面一座庄严的府院，红漆大门上挂着块横匾，上面写着“安抚使府”四个
烫金大字，门前站着不少护卫。向北望去，可以瞧见高耸的更楼。
LONG
	);
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 1, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"dongjie2",
  "west" : __DIR__"guangc",
  "south" : __DIR__"anfushi",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
