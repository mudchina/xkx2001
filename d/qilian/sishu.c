//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "学馆");
        set("long", @LONG
一间简陋的私塾，四壁皆空，屋子中摆满了学生从自己家里抬来的方
桌、长凳。一张书案放在屋子的一头，案上摆着几本翻开了的〖三字经〗、
〖百家姓〗和一把戒尺。至圣先师孔老夫子的石刻拓片侧身像贴在书案的
後面。
LONG
        );
        set("exits", ([
                "south" : __DIR__"gulang",
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
