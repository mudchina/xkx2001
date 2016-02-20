//Cracked by Roath
// /d/changbai/xuedi.h

#include <ansi.h>

void init()
{
        object me = this_player();
        int qi = me->query("qi");
        int myforce = (int)me->query_skill("force", 1);

        if( !present("pi qiu", me) && myforce < 100 ) { 
                message_vision(HIR"\n一股刺骨的寒风吹过，$N只觉得浑身的血液都快被冻住了！\n"NOR, me);
//              write("看来不穿一件保暖的外衣，一定会被冻死的！\n");
                if( (int)me->query("neili") > 3 ) {
                        if( myforce >= 30 )
                                me->improve_skill("force", random(10));
                        me->add("neili", -3);
                } else  me->set("qi", qi*2/3);
        }
}          
