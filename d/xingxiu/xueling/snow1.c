//Cracked by Roath
// Ssy

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"雪岭"NOR);
        set("long", @LONG
寒风呼哮，你极目望去，唯有一片白茫茫的大雪，你不禁起了一
丝寒意。    
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"suolong",
                "northup" : __DIR__"snow2",
        ]));
        set("cost", 1);
        set("outdoors", "tianshan");
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "northup") {
                me->add("jing", -30);
                me->add("jingli", -30);
		message_vision(HIR"$N顶风冒雪，努力往上攀登。\n"NOR, me);

        }
        return 1;
}
