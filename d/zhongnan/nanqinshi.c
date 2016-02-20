//Cracked by Roath
// road: /zhongnan/nanqinshi.c
// by sdong July, 1998

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "男厢房");
        set("long", @LONG
这ㄦ是男厢房，打埽的极是干净。虽然布置简单，却也给人一种温暖
的感觉。房中几张木床和一张桌子，几个弟子正在蒙头大睡。往西是演武
厅。
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
		 "west" : __DIR__"liangong1",
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

        if ( dir == "west" || dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }

        return ::valid_leave(me, dir);
}



