//Cracked by Roath
// Jay 8/9/96
#include "room.h"
inherit ROOM;

void create()
{
        set("short", "琴室");
        set("long", @LONG
房中一阵檀香，一床(bed)一几，陈设简单，床上挂了纱帐，甚
是陈旧，已呈黄色。几上放着一张瑶琴。东面是一个月洞门(door)，
通向梅庄的後回廊。
LONG
        );
        set("exits", ([
		"east" : __DIR__"huilang",
	]));

	set("objects", ([
		__DIR__"npc/huang" : 1,
		__DIR__"npc/obj/yaoqin" : 1,
	]));
        set("item_desc", ([
                "bed" : "普普通通的一张床。\n",
		"door" : "门上似乎并未上锁。\n",
        ]));
        create_door("east","月洞门","west", DOOR_CLOSED);

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    if (dir=="enter") {
	say (me->name()+"走进暗洞。黄钟公又把暗门关起来。\n");
	me->set_temp("new_valid_dest", "/d/jiaxing/didao1");
	delete("exits/enter");
	me->set_temp("huang",0);
	me->set_temp("danqing",0);
	me->set_temp("tubiweng",0);
	me->set_temp("heibai",0);
	return 1;
    }
    return ::valid_leave(me, dir);
}



