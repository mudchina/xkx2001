//Cracked by Roath
// room: liang.c

#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","金刚座");
       set("long", @LONG
你踩在金刚座上，密集金刚的脸庞近在咫尺，对着你默默微笑。
LONG
     );
        set("exits", ([
                "down" : __DIR__"hongdian",
        ]));       
	set("objects", ([
                __DIR__"obj/klguan" : 1,
                __DIR__"obj/rtlian" : 1,
                __DIR__"obj/lubo" : 1,
        ]));
	set("cost", 1);
        setup();
}

