//Cracked by Roath
// Room: nanshi.c 华山男弟子休息室
// qfy July 7, 1996 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "男弟子休息室");
        set("long", @LONG
这是华山男弟子的休息室。窗明几净，摆设简单。靠墙设有几张木床，
近门处放着一张桌子。西边连着走廊，北边则是练功房。
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
	    "west" : __DIR__"zoulang",
	    "north" :  __DIR__"liangong1",
	]));

	create_door("north", "竹门", "south", DOOR_CLOSED);
	create_door("west", "木门", "east", DOOR_CLOSED);

	set("cost", 0);
        setup();
	//replace_program(ROOM);
}
/*
void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}

int do_exercise(string arg)
{
        object me = this_player();

        tell_object(me, "别人沉睡的打憨声吵着你，使你不能静下心来打坐！\n");
        return 1;
}

int do_practice(string arg)
{
        object me = this_player();

        tell_object(me, "房里杂物太多，地方不够宽畅，你使不开手脚来练习！\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();

        tell_object(me, "别人沉睡的打憨声吵着你，使你不能静下心来研读！\n");
        return 1;
}
*/
int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);

        if ( dir == "west" || dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }

        return ::valid_leave(me, dir);
}
