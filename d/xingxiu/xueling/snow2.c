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
                "southdown" : __DIR__"snow1",
                "northup" : __DIR__"snow3",
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
		message_vision(HIR"突然间风小了很多，$N放眼四周，发现自己已经到了天山雪岭的颠峰。\n"NOR, me);

        }
        return 1;
}
