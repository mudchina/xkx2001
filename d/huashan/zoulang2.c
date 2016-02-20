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
走廊向东伸延过去。旁边有一大丛翠茂的竹子，环境十分清幽。不远
处边是华山男弟子的休息室。
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang3",
	"west" : __DIR__"zoulang1",
	"south" : __DIR__"liangong1",
    ]));

    create_door("south", "木门", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    replace_program(ROOM);
}