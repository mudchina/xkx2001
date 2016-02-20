//Cracked by Roath

// Room: /d/beijing/shiweiying.c

inherit ROOM;
#include "beijing_defs.h"

void create()
{
        set("short", "侍卫营大门");
        set("long", @LONG
这里是京城侍卫们的地盘。大门虽然不如王公大臣府第的豪华
阔绰，可也是毫不含糊的。侍卫们平日鱼肉乡里，京城百姓走到这儿
可都是小心谨慎，见了侍卫们就陪笑脸。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "enter"  : __DIR__"jiaochang",
        "out" : __DIR__"dongzhidajie",
        ]));

        set("objects", ([
        __DIR__"npc/shiwei3":2,
        ]));
 
        set("no_clean_up", 0);
        set("cost", 2);
 
        setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "enter") {
	if (!IS_SHIWEI(me) && !wizardp(me)) {
	    if (present("shiwei", environment(me))) {
		return notify_fail("门边的侍卫伸手把你给拦住了。\n");
	    }
	}
    }
    return ::valid_leave(me, dir);
}
