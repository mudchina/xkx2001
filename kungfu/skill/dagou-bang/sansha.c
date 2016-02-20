//Cracked by Roath
///kungfu/skill/dagou-bang/sansha.c 三记杀招
// fear 01/2000

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
		int tempatt;
        int skill;
        int mybili;
        int busytime;
		string* msgpfm,msg;
        string weapon;
        int damage;
        string *limb, type, result, str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("三记杀招只能对战斗中的对手使用。\n");
		
        if( me->query_temp("sansha_busy") )
                return notify_fail("你气息翻腾，运转不畅，使不出三记杀招！\n");

		if( me->query("family/family_name") != "丐帮" )
			return notify_fail("你不是丐帮弟子不能使用三记杀招？\n");

        if( target->is_busy() ) 
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

		if( me->query("rank") < 9)
			return notify_fail("你的级别不够，没有资格使用三记杀招！\n");

		weapon = me->query_temp("weapon");
		if( weapon->query("skill_type") != "stick" )
                return notify_fail("你手中无棒，如何使得三记杀招？\n");

        if( me->query_skill_mapped("stick") != "dagou-bang" )
                return notify_fail("你所用的并非打狗棒，不能施展三记杀招！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                                         return notify_fail("你所用的并非混天气功，施展不出三记杀招！\n");

        if( me->query_skill("force") < 300 )
                return notify_fail("你的混天气功火候未到，无法施展三记杀招！\n");

        if( me->query_skill("stick") < 300 )
                return notify_fail("三记杀招需要精湛的打狗棒方能有效施展！\n");

        if(me->query_int() < 32)
                return notify_fail("你的悟性不够，无法使出三记杀招！\n");

        if( me->query("neili") <= 200 )
                return notify_fail("你的内力不够使用三记杀招！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够使用三记杀招！\n");
		
		msgpfm = ({
			"$N怒喝一声，横过"+ weapon->name()+HIG"一搭，借势跃起，人未至，棒先到，凌虚下击，连施三下杀手！",
			"$N转过"+ weapon->name()+HIG"，刷刷刷连进三棒，棒法快捷无伦，都是打狗棒法中的杀招！",
			"$N突然飞出"+ weapon->name()+HIG"，迎面劈向$n，这棒连戳三下，竟在霎时之间分点$p胸口三处大穴！",
			"$N横棒挥出，变守为攻，发挥出打狗棒法中的攻手，连进了三记杀招！",
			});
		
		msg = HIG"\n"+ msgpfm[random(sizeof(msgpfm))] +"\n" NOR;
		message_vision(msg, me, target);

        skill = me->query_skill("stick");
        mybili = me->query_str();
        busytime = (skill/60) + (mybili/20) ;
        
        if(skill>400)skill=400;
        me->add_temp("apply/attack", (mybili * skill / 40));
		tempatt = mybili * skill / 40 ;
        me->set_temp("sansha",1);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->set_temp("restore",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack",-tempatt);

        call_out("remove_effect", busytime, me);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
		{
			damage = (mybili * (10 + (int)me->query_skill("stick")/60) ) ;
            if(damage > 1500) damage = 1500;
            if(damage < 300) damage = 300;

			target->receive_damage("qi", damage,  me);
            target->receive_wound("qi", (int)me->query_skill("stick"), me);
            target->start_busy(1);

			limb = target->query("limbs");
            type = "瘀伤";

			msgpfm = ({
			"“噗”的一下，这最后一棒出其不意的正中$N的"+limb[random(sizeof(limb))]+"，$P不由得惨叫一声，大感狼狈。",
			"只听“啊”的一声惨叫，这一棒重重的打在$N"+limb[random(sizeof(limb))]+"，$P立时感半身发麻，脸上已是全无血色。",
			});
	
			msg = HIG"\n"+ msgpfm[random(sizeof(msgpfm))] +"\n" NOR;
			message_vision(msg, target, me);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);
        }
        else if(   random( target->query_str() ) >  mybili *2/3 )
        {
                message_vision(HIY"$N见棒势如风，赶紧守住门户，$n竟然一时难以攻入，棒招便感变化不灵。\n\n"NOR, target,me );
                me->start_busy(3+(skill/100)+random(mybili/10));
//                me->receive_damage("qi", 10+random(20), me);
//                str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
//                message_vision("($N"+str+")\n", me);
        }
        else
        {
                message_vision(HIY "\n$N大惊，但见"+ weapon->name()+HIY"来势如风，挡无可挡，闪无可闪，只得向后避开了这招。\n\n" NOR,  target,me);
                target->start_busy(1+random(2));
                me->start_busy(1+random(2));
        }

        me->delete_temp("sansha");
        me->add("neili", -150);
        me->add("jingli", -100);
        me->start_busy(1+random(2) );
        me->set_temp("sansha_busy", 1); 

        return 1;
}


void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("sansha_busy");
        tell_object(me, HIY"\n你调息片刻，内力运转已恢复顺畅。\n"NOR); 
}
