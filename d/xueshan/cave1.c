//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "洞口");
        set("long", @LONG
山谷里积雪被拢成几个雪堆，这里时常有人扫除积雪。你
前面的峭壁下隐隐约约有一个山洞。
LONG
        );
        set("exits", ([
                "west" : __DIR__"shangu1",
                "enter" : __DIR__"cave2",
        ]));
	set("objects", ([
                "/kungfu/class/xuedao/baoxiang": 1,
        ]));



	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
