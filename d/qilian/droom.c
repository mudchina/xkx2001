//Cracked by Roath
//wzfeng 99 11
#include "room.h"

inherit ROOM;
int do_save(string arg);
void create()
{
        set("short", "小厢房");
        set("long", @LONG
    这是一个构造精巧，极为讲究的女性闺房。东首放置一张梳妆台，上面
摆满了大家闺秀用的各种胭脂水粉，西边的衣架上挂满罗裙花布。一阵极为刺鼻
胭脂味飘来，有一种说不出的难受。 
LONG
        );
                      set("exits",([ 
                  "out" : __DIR__"zhengtang",

                ]));
        set("objects", ([
            __DIR__"npc/dfbb" : 1,
        ]));

        set("cost", 1);
	    set("invalid_startroom", 1);
        set("no_fight", "1");
		setup();
 
}

init()
{
	add_action("do_save",  "save");

}

int do_save(string arg)
{
        object me = this_player();
        tell_object(me, "你不能在此处存盘！\n");
        return 1;
}
