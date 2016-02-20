//Cracked by Roath
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me,object target)
{
        if (target != me)
                return notify_fail("散功对他人毫无作用！\n");

        if (!(me->query_temp("jinzhongzhao")))
                return notify_fail("你并没有运用金刚不坏体神功！\n");
	if( (int)me->query_temp("jingang") ) 
                return notify_fail("你正在运用金刚伏魔的外家神通，无法散去金刚不坏体神功。\n");

        if (me->query_skill("hunyuan-yiqi",1) < 100)
                return notify_fail("你的混元一气功修为火候不够，对于金刚不坏体神功无法运用自如！\n");
	if (me->query_skill("force",1) < 100)
                return notify_fail("你的内功修为火候不够，对于金刚不坏体神功无法运用自如！\n");
	if (me->query_skill("buddhism",1) < 100)
                return notify_fail("你的禅宗心法修为火候不够，对于金刚不坏体神功无法运用自如！\n");
        if (me->query("max_neili")<2500
                || me->query("neili") < me->query("max_neili")/10)
                return notify_fail("你的内力不够,无法散去金刚不坏体神功！\n");
        
        message("vision", HIC "\n"+me->query("name")+"双掌合十，强运内息，呼出一口气，将金刚不坏体神功缓缓散去。\n\n" NOR, environment(me), me);
        tell_object(me, HIW "\n你双掌合十，强运内息，将护体神功散去。\n\n" NOR);

        me->delete_temp("jinzhongzhao");

        me->add("neili", -200);

        return 1;
}