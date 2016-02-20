//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "私塾");
        set("long", @LONG
这是村里的一所简陋的私塾，乡下孩童便在此上课。老秀才也是村里的人，
平时除教学外，也帮村子里的老乡亲写读信件，是以非常得人尊敬。私塾里摆设
简单，由几张方桌，数张凳子，将就凑合起来，倒是书架上满满都是书籍，看来
老秀才也确实是有几分墨水。
LONG
        );
        set("exits", ([
                "east" : __DIR__"sroad2",
        ]));
	set("objects",([
                "/d/city/npc/xiucai" : 1,
        ]));

	set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/朱", 0);
        return 1;
}
