//Cracked by Roath
// /d/wanshou/forest0.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "密林");
        set("long", @LONG
这一片树林树木茂密，遮天蔽日，有如树海，无边无际。黑暗
中就会有什么鬼魅突如其来，将你攫去似的。你面对着这一片广阔
无边、阴沉黑暗的树林不由一阵胆寒，看来还是赶快退出去的好。
LONG
        );
        set("exits", ([
				"north" : __DIR__"forest"+(random(3)+1),
				"northeast" : __DIR__"shijie",
				"southdown" : __DIR__"shanjiao",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir =="northeast" ) {

            if (!myfam || myfam["family_name"] != "万兽山庄"){
                return notify_fail("那里的树林太密了，走不过去。\n");
			}
        }
        return ::valid_leave(me, dir);
}

