//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "不狼坡");
        set("long", @LONG
山势越来越凶险，遍是齐腰杂草，连山狼也不便行动，唯见山野兔和
几只苍鹰翱翔於空。往西北四十余里，可遥见一岭，蜿蜒连绵数百里，满
眼翠绿，名大通岭。
LONG
        );
        set("exits", ([
                "south" : __DIR__"bulang-po",
                "northwest" : __DIR__"datong-ling",
        ]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
