//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov28.c

inherit ROOM;

void create()
{
	set("short", "大杆栏");
	set("long", @LONG
依着一棵大榕树，摆夷人在此建了一座相当大的杆栏。下层这里有一满圈的
十几头牛羊。旁边的楼梯修得颇宽。看来这里是本地的体面人家。
LONG);
	set("objects", ([
		__DIR__"npc/goat.c" : 3,
		__DIR__"npc/niu.c" : 2,
		]));
	set("exits", ([
		"west" : __DIR__"minov27",
		"up" : __DIR__"minov29",
		]));
	set("area", "阳宗镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
