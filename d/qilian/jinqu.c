//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "空房间");
        set("long", @LONG
一个空荡荡的房间，有一块留言牌。
LONG
        );
        set("exits", ([
                "east" : __DIR__"xingtang",
        ]));
//       set("objects", ([
 //               __DIR__"obj/xjjling" : 1,
//	]));

	set("cost", 0);
        setup();
        replace_program(ROOM);
}
