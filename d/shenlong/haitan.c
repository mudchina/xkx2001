//Cracked by Roath
// 海滩 /d/shenlong/haitan
// aln 4 / 98

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "海滩");
        set("long", @LONG
但见岸上树木苍翠，长长的海滩望不到尽头，尽是雪白的细沙，四处一片
寂静，听不见一点声音，西面是大海，东面仿拂有一座山峰，两旁是望不到尽
头的海滩。
LONG
        );

	set("exits", ([
		"east" : __DIR__"shanlu1",
		"south" : __DIR__"haitan",
                "west" : __DIR__"beach",
		"north" : __DIR__"haitan",
        ]));
	set("cost", 2);

        setup();
 //       replace_program(ROOM);
}

void init()
{
        object me = this_player();
        int damage;

        if( interactive(me = this_player()) 
        && !(me->query("sg/spy") || me->query("family/family_name") == "神龙教")
        &&  random((int)me->query_skill("dodge")) < 80 ) {
                message_vision( HIR "$N的眼前突然出现一个无底的深渊...$N掉入了陷阱之中。\n" NOR, me);
                message_vision( HIR "陷阱中的钢板突然冒出许多锋利的钢针，深深地扎入了$N的身体中...\n" NOR, me);

                damage = 100000 / ( 100 + (int)me->query_skill("force"));
                me->receive_wound("qi", damage + random(damage), "被扎死了");
                me->receive_damage("qi", damage + random(damage), "被扎死了");

                me->apply_condition("snake_poison", 50 + random(50) +
                        me->query_condition("snake_poison"));
        }
}









