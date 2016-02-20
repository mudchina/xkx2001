//Cracked by Roath
//Kane

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "清音洞");
	set("long", @LONG
这是清音洞内洞，潮湿异常，洞顶水珠颗颗坠下，滴在地面的小水洼中，
叮咚做响。这里光线太暗，大概需要火折照明。
LONG
	);

                set("exits", ([
                "east" : __DIR__"neidong",
                "south" : __DIR__"neidong",
                "west" : __DIR__"neidong",
                "north" : __DIR__"neidong",
                ]));

        set("cost", 15);
	setup();
//	replace_program(ROOM);
}

void init()
{
   add_action("do_use","use");
}

int do_use(string arg)
{
    object me = this_player();

    if( !arg || arg=="" ) return 0;
    if (!present("fire", me))  return 0;
    if( arg=="fire" ) {
	write("借着火光映照，你走出洞外。\n");
     	me->move(__DIR__"qingyin");
	}
    return 1;
}

int valid_leave(object me, string dir)
{
	int kar;

	kar = 80 - me->query("kar");

	if(random(kar) == 1) {
		write("你走得精疲力尽，终于到了洞外。\n");
		me->move(__DIR__"qingyin");
		return 1;
	}

	return ::valid_leave(me,dir);
}
