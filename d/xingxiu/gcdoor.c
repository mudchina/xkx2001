//Cracked by Roath
// Room: /d/xingxiu/gcdoor.c
// Date: June 30, 96   Jay
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "迷宫洞口");
	set("long", @LONG
转过了一排树木，只见对面一座石山上嵌着两扇铁铸的大门(door)。
门上铁锈斑斑，显是历时已久的旧物。
LONG
	);
	switch(random(2)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1,
				  "/d/xingxiu/npc/spider2" : 1]));
                break;
        default:
                set("objects", ([ "/d/xingxiu/npc/spider2" : 1]));
                break;
	}
	set("item_desc", ([
		"door" : "门上似乎并未上锁。\n",
	]));

	set("exits", ([
		"southeast" : __DIR__"shangu",
                "enter" : __DIR__"gcmaze1",
	]));
	create_door("enter","大铁门","out",DOOR_CLOSED);

	set("cost", 1);
	setup();
	set("outdoors", "xingxiu");
	replace_program(ROOM);
}

