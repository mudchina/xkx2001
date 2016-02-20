//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "学馆");
        set("long", @LONG
一间简朴的私塾，房间里摆着一些桌椅，墙上供着至圣先师孔夫
子像。一张书案放在屋子的一头，案上摆着几本翻开了的〖三字经〗、
〖百家姓〗和一把戒尺。
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"nanyang",
        ]));
	set("objects",([
                "/d/city/npc/xiucai" : 1,
        ]));

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        me->set_temp("mark/朱", 0);
        return 1;
}
