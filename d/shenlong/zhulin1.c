//Cracked by Roath
//竹林1 /d/shenlong/zhulin1
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "竹林");
        set("long", @LONG
面前是一片翠绿的竹林，这儿安静多了。偶尔有几个人走过，似乎都诚惶
诚恐的样子，你不由得吸了一口气，把挂在嘴边的话又咽了回去。南面是一个
竹房，北面又是一片竹林，东面是一所竹堂。
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "enter" : __DIR__"qianlong",
                "west" : __DIR__"shibanlu",
                "south" : __DIR__"yaofang",
                "north" : __DIR__"zhulin2",
        ]));

        set("objects", ([
                "/kungfu/class/shenlong/yin" : 1,
                "/d/shenlong/npc/huang": 1,
        ]));

        set("cost", 1);

        setup();

        replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{

        if( (int)me->query("sg/exp") < 5000 && dir == "north" ) 
                return notify_fail("后面是本教长老练功的秘处，你还是请回吧。\n");

        return ::valid_leave(me, dir);
}
*/
