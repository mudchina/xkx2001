//Cracked by Roath
//  /k/kungfu/sanyin-zhua/sanyin.c 三阴化功
// wsky 7/3/00

/*
    “丁春秋挥右拳挡住他拳头，跟着左拳猛力拍出。玄难中毒后转身不灵，难以
闪避，只得挺右手相抵。到此地步，已是高后比拼真力，玄难心下暗惊：“我决不
能跟他比拼内力！”但若拳上上不使内力，对方内力震来，立时便是脏腑碎裂，明
知已着了道儿，却不得不运内力抵挡。这一运劲，但觉内力源源不绝的向外飞散，
再也凝聚不起。
*/



#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myexp, targexp, damage, skill, merand, targrand, targneili,time,i;
	string str,*limb,type;
	mapping myfam;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("三阴化功只能对战斗中的对手使用。\n");

	if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派") && me->query("id")!="wsky" && me->query("futou_bang/sacrifice")<30)
	          return notify_fail("只有星宿弟子利用本门秘传内功方能使用三阴化功。\n");

        if( target->query_temp("huagong") )
                return notify_fail("对手内力已经被化去，不需要再化了！\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("空手才能施展三阴化功！\n");

        if( me->query_skill_mapped("claw") != "sanyin-zhua" )
                return notify_fail("你所用的并非三阴蜈蚣爪，不能施展三阴化功！\n");

        if( me->query_skill_prepared("claw") != "sanyin-zhua" )
                return notify_fail("你所备的并非三阴蜈蚣爪，不能施展三阴化功！\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("你所用的并非三阴蜈蚣爪，施展不出三阴化功！\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("你化功大法修为太差，不能运用三阴化功！\n");

        if( me->query_skill("sanyin-zhua",1) < 120 )
                return notify_fail("你三阴蜈蚣爪修为太差，不能运用三阴化功！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够使用三阴化功！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够使用三阴化功！\n");     
        if( me->query("jing") <= 200 )
                return notify_fail("你的精不够使用三阴化功！\n");

        message_vision(HIB"$N挥右拳挡住$n拳头，跟着左爪猛力向$n抓去。\n\n"NOR, me,target);

        myexp = me->query("combat_exp");
        targexp = target->query("combat_exp");
        skill = me->query_skill("huagong-dafa",1);
        
        merand   = random((myexp/1000)*(me->query_skill("force")/10));
        targrand = (myexp/1000)*(target->query_skill("dodge")/10)/3;

        if(merand>targrand) {

                message_vision(HIW"$n转身不灵，难以闪避，只得挺右手相抵。到此地步，已是高手比拼真力。\n\n"NOR,me,target);
                tell_object(me, HIG"你潜运内功，将对手的内力化去。\n"NOR); 
                tell_object(target, HIR"你心下暗惊，但觉内力源源不绝的向外飞散，再也凝聚不起。\n\n"NOR);      
                target->set_temp("huagong", 1);
                target->add("neili",-skill*2);
                targneili=target->query("neili");
                if(!userp(target)) {
                        target->set("neili", 0);
                }
                target->add_temp("apply/damage", -skill/10);
                target->add_temp("apply/parry", -skill/20);
		target->add_temp("apply/armor_vs_force", -skill/6);
        	target->add_temp("apply/speed", -skill/6);
	        target->add_temp("apply/defense",  -skill/2);
                target->set("jiali",0);
                target->start_busy(random(2)+1);                
                
        }                      
        else 
        {       
                me->start_busy(random(3)+1);    
                message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, me, target);
                tell_object(me, HIY"你心中暗想：“糟糕，竟然被这"+RANK_D->query_rude(target)+"看破了。”\n\n"NOR);
                me->add("neili",-250);
                return 1;
        }
		
		time=skill/12;
		if(time<5) time=5;
		if(time>20) time=20;
        
                if(userp(target)) call_out("remove_effect", time, me, target, targneili, skill); 
                        else call_out("remove_effect", time, me, target, targneili, skill);

        return 1;
}

private int remove_effect(object me, object target, int neili, int skill)
{
        target->delete_temp("huagong");
        if(!userp(target)) {
                target->set("neili",neili);
        }
        target->add_temp("apply/damage", skill/10);
        target->add_temp("apply/parry", skill/20);
	target->add_temp("apply/armor_vs_force", skill/6);
        target->add_temp("apply/speed", skill/6);
	target->add_temp("apply/defense",  skill/2);
        message_vision(HIG"慢慢的，$n觉得漫散的内力又一丝丝地聚回丹田。\n\n"NOR,me,target);
        return 1;
}
