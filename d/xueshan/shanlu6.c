//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
山路越走越窄，能隐隐望见前方又分出了几条叉路。
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shanlu5",
		"westup" : __DIR__"shanlu2",
		"southup" :__DIR__"shanlu7",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
