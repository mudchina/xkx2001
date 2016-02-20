//Cracked by Roath
// Room: baoguo3.c 保国寺禅房

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "报国寺禅房");
        set("long", @LONG
这是报国寺的禅房，峨嵋男弟子回山之前通常在此借宿一宿，好备足
体力上山。房内摆有一张长桌，靠墙设有几张木床。
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
	    "east" : __DIR__"baoguo1",
	]));

	set("cost", 0);
        setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);

        if ( dir == "west" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }

        return ::valid_leave(me, dir);
}
