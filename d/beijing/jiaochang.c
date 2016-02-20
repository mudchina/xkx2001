//Cracked by Roath
// Room: /d/beijing/jiaochang.c

inherit ROOM;
#include "beijing_defs.h"

void create()
{
        set("short", "校场");
        set("long", @LONG
这里是侍卫们练功的地方，广场四周有不少侍卫们在扎马，
站桩，侍卫教头在中间巡视，不时的指点他们。两边厢房是侍卫
们吃饭睡觉的地方，往里是总管办公之处。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "east"  : __DIR__"shiwei_shitang",
        "west"  : __DIR__"shiwei_junying",
        "north"  : __DIR__"shiwei_office",
        "out" : __DIR__"shiweiying",
        ]));

        set("objects", ([
        __DIR__"npc/shiwei4":1,
        __DIR__"npc/shiwei5":1,
        __DIR__"npc/shiwei_jiaotou":1,
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
