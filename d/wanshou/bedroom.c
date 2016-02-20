//Cracked by Roath
// /d/wanshou/bedroom.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "卧室");
        set("long", @LONG
这是万兽山庄弟子休息的地方，窗上挂着厚重的窗帘，屋内的
光线昏暗，屋内依次摆着若干卧榻，几个同门正在榻上休息。
LONG
        );

        set("no_fight", "1");
        set("no_steal", "1");
        set("sleep_room",1);
        set("exits", ([
                "west" : __DIR__"houting",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
void init()
{
add_action("do_get", "get");
}
int do_get(string arg)  
{
        object obj;

        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
                write("你不能搬动玩家的身体。\n");
                return 1;
        }
        else
                return 0;
} 

