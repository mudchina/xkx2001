//Cracked by Roath
// jinzhongzhao
// modified by aln 4 / 98
//remodied by xiaojian on March 20, 2000
#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int i, extra;

/*
        if( !me->is_fighting() )
                return notify_fail("金刚不坏体神功只能对战斗中的对手使用。\n");
*/

        if( me->query_temp("jinzhongzhao") )
                return notify_fail("你正在运用金刚不坏体神功！\n");

        if( (int)me->query_temp("jingang") ) 
                return notify_fail("你正在运用金刚伏魔的外家神通，功力未够，无法同时运用金刚不坏体神功。\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi")
                return notify_fail("你所用的内功与金刚不坏体神功相悖！\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 160 )
                return notify_fail("你的内功修为火候未到，还未领悟金刚不坏体神功！\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 200 )
                return notify_fail("你的般若掌火候未到，还未练成金刚不坏体神功！\n");

        if( me->query("neili") < 2000 )
                return notify_fail("你的内力不够，劲力不足以施展金刚不坏体神功！\n");
        
        message_vision(
        HIY"$N双手合十，梵唱之声不绝于耳，面上宝相庄严，隐隐似有精光流转，"
        "身上袈裟无风自动，不带丝毫霸气，正是佛门不传之秘金刚不坏体神通！\n"NOR,me);
        me->add("neili", -300);
        me->add("jingli", -100);

        me->start_busy(3);
        
        extra = me->query_skill("force");
        me->set_temp("jinzhongzhao", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/2);

        return 1;
}

void remove_effect(object me)
{	
	if (me->query_temp("jinzhongzhao")) {
        me->delete_temp("jinzhongzhao");
        tell_object(me, YEL"\n你只觉真气运转不畅，不得不散去护体真气，调息吐纳。\n"NOR);
}
}

