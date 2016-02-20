//Cracked by Roath
// Room: fushou2.c 福寿庵休息室

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "福寿庵休息室");
        set("long", @LONG
这是福寿庵接待峨嵋女侠们的休息室，峨嵋女弟子回山之前通常在此借宿
一宿，好备足体力上山。房内摆有一张长桌，靠墙设有几张木床。
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
	    "southdown" : __DIR__"fushou3",
	]));

	create_door("southdown", "木门", "northup", DOOR_CLOSED);

	set("cost", 0);
        setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);

        if ( dir == "southdown" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }

        return ::valid_leave(me, dir);
}
