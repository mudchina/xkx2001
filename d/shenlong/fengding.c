//Cracked by Roath
// 峰顶 /d/shenlong/fengding
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "峰顶");
        set("long", @LONG
这是神龙岛的最高峰，但是却很是宽敞。站在峰顶，极目远眺，但见四周
均是蔚蓝的天空、茫茫的大海。你突然觉得自己是多么的渺小，犹如沧海之一
粟。旁边一群神龙教众在巡逻着，偶尔不怀好意地朝你瞧几眼。西面是长廊，
南面是下山的山道，往北有一条通向后山的小路，路很小，似乎走的人不多。
LONG
        );
	set("cost", 4);

        set("exits", ([
		"northdown" : __DIR__"houshan",
		"southdown" : __DIR__"shandao",
                "east" : __DIR__"changlang",
        ]));

        set("objects", ([
           //     "/kungfu/class/shenlong/chilong" : 1,
                "/kungfu/class/shenlong/hesheng" : 1,
           //      "/d/shenlong/npc/chi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

