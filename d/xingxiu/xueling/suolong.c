//Cracked by Roath
// Ssy

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"锁龙桥"NOR);
        set("long", @LONG
由此北上便是天山雪岭，相传有苍龙途径此处，因暴雪极寒冻僵
而死，化为石桥一座。实际上此桥乃是天工匠成，决非人力所能造就
的。再往北只见一片莽莽，不知能否继续前行。
LONG
        );
        set("exits", ([
                "southdown" : "/d/xingxiu/tianchi",
                "northup" : __DIR__"snow1",
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


