//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov68.c

inherit ROOM;

void create()
{
	set("short", "竹楼下");
	set("long", @LONG
台夷人喜居竹林深处，房舍自然少不了用竹子搭成，竹为梁，竹为墙，竹楼
建的相当精致。下层基本上只是四根柱子架空的，既可以作兽圈，也为了防蛇。
一架竹梯通向上层的房舍。
LONG);
	set("objects", ([
		__DIR__"npc/niu" : 1,
		]));
	set("exits", ([
		"up" : __DIR__"minov69",
		"east" : __DIR__"minov66",
		]));
	set("area", "武定镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
