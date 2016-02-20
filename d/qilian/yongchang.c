//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "永昌");
        set("long", @LONG
永昌以北是一片大沙漠，再往北就是蒙古了，永昌就建在戈壁滩上。
孤零零一座城堡独立沙中，一股凄凉之情不由在你心中油然而生。
LONG
        );
        set("exits", ([
                "south" : __DIR__"zhuti",
                "north" : __DIR__"gebi",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
