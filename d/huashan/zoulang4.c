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
走廊向西伸延过去。旁边有一大片盛开的花朵，随风摇曳，散发阵阵
幽香。不远处边是华山女弟子的休息室。
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang1",
	"west" : __DIR__"zoulang5",
	"south" : __DIR__"liangong2",
    ]));

    create_door("south", "木门", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    replace_program(ROOM);
}