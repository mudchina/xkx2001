//Cracked by Roath
// Room: zoulang.c 走廊
// qfy July 7, 1996.

#include <room.h>
inherit ROOM;

void reset();

void create()
{
    set("short", "走廊");
    set("long", @LONG
这里是西向走廊的尽头，南边的房间便女弟子的休息室。西边远望过
去是一片片包裹在白云里的崇峻峭壁，隐约可见有条瀑布自峰顶一泻而下，
景色气象万千。
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang4",
	"south" : __DIR__"nushi",
    ]));

    create_door("south", "木门", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
//    replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "男性" && dir == "south" && !wizardp(me) )
		return notify_fail("看清楚点，那是女弟子休息室！\n");

	return ::valid_leave(me, dir);
}
