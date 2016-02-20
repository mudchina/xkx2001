//Cracked by Roath
// wuzhuan.c 奇门五转

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int i, extra;

        if( me->query_temp("wuzhuan") )
                return notify_fail("你正在运用「奇门五转」心法！\n");

        if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("你所用的内功与「奇门五转」心法相悖！\n");

        if( me->query_skill("bitao-xuangong", 1) < 90 )
                return notify_fail("你的内功修为火候未到，还未领悟「奇门五转」！\n");

        if( me->query("neili") < 600 )
                return notify_fail("你的内力不够，劲力不足以施展「奇门五转」！\n");
        
        if( me->query_skill("qimen-dunjia", 1) < 120 )
                return notify_fail("你的奇门遁甲修为不够，还未领悟「奇门五转」！\n");

        msg = HIG "$N脸上青气大盛，脚下缓缓踩着九宫八卦方位，头顶冒出腾腾白气，";
        msg += "四面隐隐传来潮涌之声，碧涛玄功已发挥到极致！\n"NOR;
        me->add("neili", -200);
        me->add("jingli", -100);
        
/*
        if( me->is_fighting() ) {
        msg += HIB "$N一声长啸，脚下踩着奇门步法，趋前抢后，尤如天神行法，";
        msg += "鬼魅遁影，瞬间只见数十个身影飞射而出，游走不定！\n"NOR;
        }
*/

        extra = (int)me->query_skill("qimen-dunjia",1);
        me->add_temp("apply/dodge", extra/5);
        me->add_temp("apply/dexerity", extra/10);
        me->add_temp("apply/speed", extra/30);

        me->set_temp("wuzhuan", 1);
        me->set_temp("wuzhuan_hit", extra/60 + random(2));

	if(me->query_temp("wuzhuan_hit") > 4)
	me->set_temp("wuzhuan_hit",4);
	
        call_out("remove_effect", extra/3, me, extra);

        message_vision(msg, me);

        return 1;
}

void remove_effect(object me, int extra)
{
        if (!me) return;
        me->add_temp("apply/dodge", -extra/5);
        me->add_temp("apply/dexerity", -extra/10);
        me->add_temp("apply/speed", -extra/30);

        me->delete_temp("wuzhuan_hit");
        me->delete_temp("wuzhuan");
        message_vision(CYN"$N只觉真气运转不畅，不得不放慢步法，调息吐纳。\n"NOR,me);
}
