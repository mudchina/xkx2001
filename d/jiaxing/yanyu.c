//Cracked by Roath
// Room: /d/quanzhou/yanyu.c
// Date: May 23, 96   Jay

inherit ROOM;

void create()
{
	set("short", "烟雨楼");
	set("long", @LONG
烟雨楼建在南湖中心的一个小岛上。南湖终年不断的水气把它
笼罩得迷迷蒙蒙的。楼内是家饭店。
LONG
	);

	set("exits", ([
                "north" : __DIR__ "nanhu1",
	]));

	set("outdoors", "quanzhou");
        set("objects", ([
            __DIR__"npc/xiaoer" : 1,
	    __DIR__"npc/hai" : 1,
	    __DIR__"npc/xiaoguizi" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

