//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov38.c

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
这是一小块普通的水田，附近有溪流流过，灌溉十分方便。围绕农田的是一
片片桑林，摆夷人采桑、养蚕，纺织相当精致的丝织品。西边有所民居。
LONG);
	set("objects", ([
		__DIR__"npc/niu.c" : 1,
		__DIR__"npc/bynong.c" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov34",
		"west" : __DIR__"minov39",
		]));
	set("area", "步雄部");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
