//Cracked by Roath
//pifeng 披风杖
//by wsky, 20/08/00

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me);

int second_hit(object me, object target);

int perform(object me, object target)
{
        string weapon, str;
        int skill, bonus, damage;
	mapping myfam;

        if( !target ) target = offensive_target(me);

	if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派") && me->query("id")!="wsky")
	          return notify_fail("只有星宿弟子利用本门秘传内功方能使用披风杖法。\n");

	if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("披风杖法只能对战斗中的对手使用。\n");

	if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过内力，无法施展披风杖法！\n");

        if( me->query_temp("pifeng",1))
                return notify_fail("你已在使用披风杖法！\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("你所用的并非化功大法，无法施展披风杖法！\n");

        if( me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("你的化功大法火候未到，无法施展披风杖法！\n");

	if( me->query_skill_mapped("parry") != "tianshan-zhang" )
                return notify_fail("你没有将天山杖法运用于招架中，无法施展披风杖法！\n");

        if( me->query_skill("tianshan-zhang",1) < 150 )
                return notify_fail("你的天山杖法修为不足，还不会使用披风杖法！\n");

        skill =  ( me->query_skill("tianshan-zhang")
                + me->query_skill("force") ) / 5;

        if( me->query("neili") <= skill*3 )
                return notify_fail("你的内力不够使用披风杖法！\n");
        if( me->query("jingli") <= skill )
                return notify_fail("你的精力不够使用披风杖法！\n");
        if( me->query("jing") <= skill )
                return notify_fail("你的精不够使用披风杖法！\n");

        weapon = me->query_temp("weapon");

        skill = me->query_skill("parry",1)+random(me->query_skill("tianshan-zhang",1));
        
        if(skill>450) skill=450;

	me->set_temp("apply/speed", me->query_temp("apply/speed",1)+skill);
        me->set_temp("apply/parry", skill);
	me->set_temp("apply/dodge", skill);
	me->set_temp("apply/defence", skill);
	me->set_temp("apply/attack",  skill);
	
	if (wizardp(me)) {
		printf("------------>my skill=%d", skill);
	}
	
        message_vision(HIW "\n\n$N战到酣处，身子一摆，大喝一声，将"+(me->query_temp("weapon"))->query("name")+HIW"高高举起，使劲向$n击出一招。\n\n"NOR, me, target);
        
        me->add_temp("apply/attack", skill/2);       
        me->add_temp("apply/damage", skill/2);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -150);
        me->add("jingli", -50);
        
        me->add_temp("apply/attack", -(skill/2));
        me->add_temp("apply/damage", -(skill/2));
        
        if (me->query("tianshan")==1) {
        
        	me->add("neili", -350);
        	me->add("jingli", -250);
                
		message_vision(HIW "\n\n$N一招卜必，次招又至，"+(me->query_temp("weapon"))->query("name")+HIW"在内力催动下现出耀眼光芒。\n\n"NOR, me, target);
        	message_vision(HIB "$N趁$n躲闪杖招之际，一声清哮，伸左掌向$n的胸口按去。\n"NOR,me,target);
        	if((me->query("combat_exp")/3)>random(target->query("combat_exp"))){
        		message_vision(HIR "\n$n一声闷哼，胸口中掌，同时内力飞泄而出。\n"NOR,me,target);        			
        		damage=random(-me->query("shen"));
        		if (damage>1000) damage=1000;
       				if (damage<500) damage=500;        		
        		target->add("qi", -damage);
        		target->add("eff_qi", -random(damage));
        		target->add("neili", -me->query_skill("force",1)*(3+random(2)));
        		me->add("neili", random(me->query_skill("force",1)*(3+random(2))));
        		if (wizardp(me)) {
				printf("------------>my damage=%d\n", damage);
			}	
			
			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
        
        	} else {
        		message_vision(HIY "\n$n看出其中有诈，忙向后跃开。\n"NOR,me,target);        			
        	}
        
        	remove_call_out("second_hit");
        	call_out("second_hit", 3+random(5), me, target);
        	//me->start_call_out( (: call_other, __FILE__, "second_hit", me, target :), 3+random(3) );
        }
             
        message_vision(HIY "\n\n$N紧跟着退后一步，将"+(me->query_temp("weapon"))->query("name")+HIY"使得虎虎生风，紧紧地护住全身上下各处要害。\n\n" NOR, me, target);
        
        me->set_temp("pifeng",1);
        
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query_skill("tianshan-zhang",1)/10 );
        return 1;
}

int second_hit(object me, object target){
	int damage;
	string str;
	
	if (me->query_temp("pifeng")==1 && me->is_fighting()){
	
		me->add("neili", -100);
       		me->add("jingli", -50);
                
		message_vision(HIY "\n\n$N浅运内力，口中念念有词，突然间杖交左手，伸右掌向$n按去。\n"NOR, me, target);
     
        	
       		if((me->query("combat_exp")/3*2)>random(target->query("combat_exp"))){
       			message_vision(HIR "\n$n一声闷哼，胸口中掌，同时内力飞泄而出。\n"NOR,me,target);        			
       			damage=random(-me->query("shen"));
       			if (damage>500) damage=500;
       				if (damage<500) damage=500;       			
       			target->add("qi", -damage);
       			target->add("eff_qi", -random(damage));
       			target->add("neili", -me->query_skill("force",1)*(2+random(2)));
       			me->add("neili", random(me->query_skill("force",1)*(3+random(2))));
       			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
       			if (wizardp(me)) {
				printf("------------>my damage=%d", damage);
			}	
       		} else {
       			message_vision(HIY "\n$n看出其中有诈，忙向后跃开。\n"NOR,me,target);        			
       		}
       		
       		if (wizardp(me)){
       			printf("again.............\n");
       		}

       		remove_call_out("second_hit");
       		call_out("second_hit", 5+random(5), me, target);
       		//me->start_call_out( (: call_other, __FILE__, "second_hit", me, target :), 3+random(3) );	
       	
	}

       	return 1;
        
}

int remove_effect(object me)
{
        me->set_temp("apply/parry", 0);
	me->set_temp("apply/attack", 0);
	me->set_temp("apply/dodge", 0);
	me->set_temp("apply/damage",  0);
	me->set_temp("apply/speed", 0);
	me->set_temp("apply/defence", 0);
	me->delete_temp("pifeng");
	if(me->query_temp("fresh")==1) me->add_temp("apply/armor", -500);
	if(me->is_fighting()){
        	message_vision(HIY "\n$N微觉疲惫，只好将将狂舞中的杖法放慢下来。\n"NOR, me);
	} else message_vision(HIY "\n$N长长的吸了一口气，将内力收回。\n"NOR, me);
        return 0;
}


