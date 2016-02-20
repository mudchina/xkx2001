//Cracked by Roath
// xiaolu2.c 林间小径
// by Xiang
// Modified by xQin 2/00
// xQin 11/00

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", GRN"林间小径"NOR);
        set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶
声和鸟鸣声，听不到别的动静。南面似乎有一条后山小路。
LONG
        );

        set("exits", ([
                "south" : __DIR__"zhulin",
                "northeast" : __DIR__"xiaolu1",
        ]));
/*                set("objects", ([
                CLASS_D("wudang")+"/qingfeng": 1,
                CLASS_D("wudang")+"/mingyue": 1,
        ]));
*/

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
