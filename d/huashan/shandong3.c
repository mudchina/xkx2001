//Cracked by Roath
// shandong3.c 山洞
// qfy 96/6/30

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这是一个小山洞，洞里家具一应俱备。
LONG
        );

	set("exits", ([
                "out" : __DIR__"yelin3",
        ]));

	set("objects", ([
		CLASS_D("huashan") + "/buping" : 1,
	]));

	set("cost", 2);
        setup();
}
