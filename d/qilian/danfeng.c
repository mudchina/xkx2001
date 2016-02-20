//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "丹凤坪");
        set("long", @LONG
眼前豁然开阔，但见白鹿戏水于清溪之畔，漫谷山花，艳丽夺目。
正中有一石洞，据传曾有凰飞于此，破山成洞，静卧三月，产得一雏，
通体血红，百鸟来贺，是以得名。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"mine",
                "north" : __DIR__"xiaolu8",
        ]));
	set("objects", ([
                "/kungfu/class/xueshan/darba" : 1,
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
      //  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (dir =="enter" ) {
            if (present("darba", environment(me)))
                return notify_fail("达而巴一下子挡住你，大吼一声：臭贼，也敢窥探我的宝物！\n");
	return 1;
	}
	return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
