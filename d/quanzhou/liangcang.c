//Cracked by Roath
// liangcang.c 粮仓
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "粮仓");
	set("long", @LONG
粮仓是所占地宽广的库房，堆放着堆积如山的军粮，逢到旱涝灾年也做济
灾之用。由于仓广人少，经常引起匪徒的窥视。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"mixiang",
		"south" : __DIR__"citong_e1",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{
        if ( objectp(present("wu jiang",environment(me))) && dir == "northeast" )
                return notify_fail("武将大喝道：都督有令，闲杂人等不能由此经过！\n");

        if ( objectp(present("guan bing",environment(me))) && dir == "northeast" )
                return notify_fail("官兵大喝道：都督有令，闲杂人等不能由此经过！\n");

        return ::valid_leave(me, dir);
}

