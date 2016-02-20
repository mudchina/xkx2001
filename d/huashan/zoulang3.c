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
这里是走廊的尽头，南边连着的房间便是男弟子的休息室。东边却是
一片险峻的悬崖。放眼望去，犹如置身云海之间，另人胸怀大畅。
LONG
    );

    set("exits", ([
	"west" : __DIR__"zoulang2",
	"south" : __DIR__"nanshi",
    ]));

    create_door("south", "木门", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
//    replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "女性" && dir == "south" && !wizardp(me) )
		return notify_fail("看清楚点，那是男弟子休息室！\n");

	return ::valid_leave(me, dir);
}