//Cracked by Roath
//Cracked by Kafei
// bidu.c


#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗精？找死吗？\n");

        if ((int)me->query_skill("douzhuan-xingyi", 1) < 40)
                return notify_fail("你的斗转星移功力不够。\n");
        if( (int)me->query("jingli") < 50 )
                return notify_fail("你的精力不够。\n");
        if( (int)me->query("jingli") < 300 )
                return notify_fail("你的精力不够。\n");

        if( (int)me->query("eff_jing") >= (int)me->query("max_jing"))
                return notify_fail("你现在不须要疗精！\n");

        write( HIW "你默运内功,逼出一些毒质,感觉好多了。\n" NOR);
        message("vision",
                HIW + me->name() + "忍住疼痛，割开一个伤口，用内功逼出一丝毒质。\n" NOR,
                environment(me), me);

        me->receive_curing("jing", (int)me->query_skill("force")/2 );
        me->add("neili", -30);
        me->receive_wound("qi", 5);
        me->set("jiali", 0);

        return 1;
}
