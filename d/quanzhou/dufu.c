//Cracked by Roath
// dufu.c 都督府
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "都督府");
	set("long", @LONG
这是泉州都督的府邸。泉州都督掌管泉州的海陆兵权，控制着西洋广大海
域，管辖当时最强大的远洋水师，乃一等一重要的官职。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"duxiang",
		"south" : __DIR__"mixiang",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("wu jiang",environment(me))) && dir == "south" )
		return notify_fail("武将大喝道：都督有令，闲杂人等不能由此经过！\n");

	if ( objectp(present("guan bing",environment(me))) && dir == "south" )
		return notify_fail("官兵大喝道：都督有令，闲杂人等不能由此经过！\n");

	return ::valid_leave(me, dir);
}
