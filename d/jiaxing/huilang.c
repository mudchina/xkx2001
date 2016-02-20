//Cracked by Roath
// Jay 8/9/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "回廊");
        set("long", @LONG
回廊西面一个月洞门(door)，门额上写着「琴心」两字，以蓝色
琉璃砌成，笔致苍劲，门下一条清幽的花径，花径鹅卵石上生满青苔。
屋前屋後七八株苍松夭矫高挺，遮得四下里阴沉沉的。
LONG
        );
        set("exits", ([
		"west" : __DIR__"qinshi",
		"east" : __DIR__"shushi",
		"south" : __DIR__"mzqianting"
	]));

        set("item_desc", ([
		"door" : "门上似乎并未上锁。\n", 
        ]));

	set("objects", ([
		"/d/city/obj/stone" : 1,
	]));
        set("no_clean_up", 0);


        create_door("west","月洞门","east", DOOR_CLOSED);

	set("cost", 1);
	setup();
        replace_program(ROOM);
}
