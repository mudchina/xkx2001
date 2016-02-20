//Cracked by Roath
//01-01-01 wsky

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int second_hit(object me, object target);
int duo(object me, object target);
int duo2(object me, object target);
int end_att(object me);


int perform(object me, object target)
{
        object weapon;
        mapping myfam;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「断云」只能对战斗中的对手使用。\n");
	        
        if( me->query_skill_mapped("strike") != "sanhua-juding" )
                return notify_fail("你所用的并非三花聚顶掌！\n");
        
        if( (int)me->query_skill("xiantian-gong",1) < 150 )
                return notify_fail("你先天功修为不足！\n");
                
        if( (int)me->query_skill("taoism",1) < 150 )
                return notify_fail("你道学修为修为不足！\n");

	//if(me->query_temp("weapon")->query("name")!="拂尘")
	//	return notify_fail("你只能运用拂尘才能施展开。\n");;

        if( me->query_skill("duanyun-bian",1) < 150 )
                return notify_fail("你的「断云鞭法」修为不足！\n");

	if( me->query_skill("whip",1) < 150 )
                return notify_fail("你的鞭法的基本功不扎实！\n");
        
        if( me->query_con() < 40 )
                return notify_fail("你的根骨太差！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够使用「断云」！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够使用「断云」！\n");     
        
        if(me->query("combat_exp")/2>me->query("shen"))
        	return notify_fail("你的侠义正气太低，无法控住心中的邪念，使此招无益有损。\n");
        
        if(me->query("class")!="taoist" && me->query_skill("taoism",1)<300)
        	return notify_fail("运用「断云」需要心无暇，绝五欲杂念。\n");
        
        if(me->query_temp("duanyun"))
        	return notify_fail("你正在使用「断云」绝招。\n");
        
        message_vision(HIW"\n$N心中平和，渐渐将断云鞭法使得圆转如意，手中"+(me->query_temp("weapon")->query("name"))+HIW"在内力摧动下闪出点点银光，有如云彩将$n逐渐包围在其中。\n\n"NOR,me,target);
        
        me->set_temp("duanyun",1);
        
        me->add("neili",-me->query_skill("whip")/2);
        me->add("jingli",-me->query_skill("whip")/3);
        
        remove_call_out("second_hit");
        call_out("second_hit", 3, me, target);        
 
 	return 1;       
}

int second_hit(object me, object target){

	int ap, dp, damage;
	string str;

	me->delete_temp("duanyun",1);
	
	if(me->is_fighting()){
	
		message_vision(HIY"\n$N内力鼓荡，一声清哮声中，向$n猛地发出三招，瞬时间鞭上银光陡散，风声大作。\n"NOR, me, target);

		me->add("jiali", me->query_skill("whip",1)/5);
		//me->add_temp("apply/strength", me->query_str());
		me->add_temp("apply/attack",me->query_skill("whip",1));
		me->add_temp("apply/damage",me->query_skill("whip",1));
		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
		me->add("jiali", -me->query_skill("whip",1)/5);
		me->add_temp("apply/attack",-me->query_skill("whip",1));
		me->add_temp("apply/damage",-me->query_skill("whip",1));
		
		//printf("\n");
		me->add("jiali", me->query_skill("whip",1)/5);
		//me->add_temp("apply/strength", me->query_str());
		me->add_temp("apply/attack",me->query_skill("whip",1));
		me->add_temp("apply/damage",me->query_skill("whip",1));
		
		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		
		me->add("jiali", -me->query_skill("whip",1)/5);
		me->add_temp("apply/attack",-me->query_skill("whip",1));
		me->add_temp("apply/damage",-me->query_skill("whip",1));
		//me->add_temp("apply/strength", -me->query_str());
		
		ap=me->query("combat_exp")/100+me->query_skill("whip",1)+me->query("neili");
		dp=target->query("combat_exp")/100+target->query_skill("whip",1)+target->query("neili");
		
		message_vision(HIY"\n两招过后，$N招数一变，手中"+me->query_temp("weapon")->query("name")+HIY"在空中划了一个弧线，向$n击落。\n"NOR,me,target);
		
		if(random(ap)>dp/2){
		
			message_vision(HIR"\n只听见$n一声惨叫，"+me->query_temp("weapon")->query("name")+HIR"已经打在$n肩头，鲜血溅了一地。\n\n"NOR, me, target);
			
			damage=me->query_skill("duanyun-bian",1)*(random(6)+3);
			
			if (damage<500) damage=500;
				if (damage>2000) damage=2000;
			
			if(wizardp(me))
				printf("damage======%d", damage);
			
			target->add("qi", -damage);
       			target->add("eff_qi", -random(damage));				
		
			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
			
		} else if(random(ap)>dp/3 && objectp(target->query_temp("weapon")) && me->is_fighting() && random(4)==1){
			
			message_vision(HIG"\n$n见敌人招势凶猛，忙举起手中"+target->query_temp("weapon")->query("name")+HIG"招架。\n", me, target);
			message_vision(HIW"\n$N鞭梢微扬，已经将$n手中的"+target->query_temp("weapon")->query("name")+HIW"卷住，两人同时运力回夺。\n"NOR, me, target);
			
			me->start_busy(3);
			target->start_busy(3);
		
			remove_call_out("duo");
 		        call_out("duo", 3, me, target);        
 		        
 		        return 1;
 			
		} else if(random(ap)>dp/3 && !objectp(target->query_temp("weapon")) && me->is_fighting() && random(4)==1){
		
			message_vision(HIG"\n$n身随意转，微微一晃已经将鞭梢抓住，两人同时运力回夺。\n"NOR,me,target);
			
			me->start_busy(3);
			target->start_busy(3);
		
			remove_call_out("duo2");
 		        call_out("duo2", 3, me, target);        
 		        
 		        return 1;
		
		} else if(random(ap)>random(dp)) {
		
			message_vision(HIY"\n$n见此招来势凶猛，大骇之下向后跳开。\n"NOR, me, target);		
		
			message_vision(HIG"\n$N一击不中，身子一转，反手又是一招，猛地向$n打去。\n"NOR,me,target);
		
			//me->add_temp("apply/strength", me->query_str());
			me->add_temp("apply/attack",me->query_skill("whip",1));
			me->add_temp("apply/damage",me->query_skill("whip",1));
						
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		
			me->add_temp("apply/attack",-me->query_skill("whip",1));
			me->add_temp("apply/damage",-me->query_skill("whip",1));
			//me->add_temp("apply/strength", -me->query_str());
		
		} else
			message_vision(HIY "\n$n见此招来势凶猛，忙向后跃开。\n"NOR,me,target);        			
		
		me->start_busy(2+random(2));
	} else 
		message_vision(HIY "\n$N见战势已必，长长的吸了一口气，将内力收回。\n"NOR, me);
		
		remove_call_out("second_hit");
		remove_call_out("end_att");
		call_out("end_att", 2, me);
				
		return 1;
}


int end_att(object me){
	
	if (!me->is_fighting()){
		me->set_temp("apply/attack",0);
		me->set_temp("apply/damage",0);
		
	}

	return;

}


int duo(object me, object target){

	int amount1, amount2;
	
	if( !target || !me->is_fighting(target) ) return;

        if( !living(me) || me->is_ghost() ) return;

        if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	if((me->query("neili")<(me->query_skill("force",1)*15) || target->query("neili")<(target->query_skill("force",1)*15))){
	
		if(me->query("neili")>target->query("neili")){
		
			message_vision(HIG"\n$N运足了气力，猛地将"+me->query_temp("weapon")->query("name")+HIG"向后一拉，将$n手中的"+target->query_temp("weapon")->query("name")+HIG"拉得脱手而出，掉在了地上。\n"NOR,me,target);

			message_vision(HIG"\n$N顺手就是一招，向$n击去。"NOR,me,target);

			me->add("jiali", me->query_skill("whip",1));
			me->add_temp("apply/attack",me->query_skill("whip",1));
			me->add_temp("apply/damage",me->query_skill("whip",1));
		
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
			//printf("\n");
					
			me->add("jiali", -me->query_skill("whip",1));
			me->add_temp("apply/attack",-me->query_skill("whip",1));
			me->add_temp("apply/damage",-me->query_skill("whip",1));
					
			target->query_temp("weapon")->move(environment(me));
		
			target->start_busy(2+random(3));
		} else {
	
			message_vision(HIG"\n$n运足了气力，猛地将"+target->query_temp("weapon")->query("name")+HIG"向后一拉，将$N手中的"+me->query_temp("weapon")->query("name")+HIG"拉得脱手而出，掉在了地上。\n"NOR,me,target);
			
			me->query_temp("weapon")->move(environment(me));
		
			me->start_busy(2+random(3));
		}
	
	} else {
	
		message_vision(WHT"\n只见$N和$n运足了内力用力回夺自己的兵刃，两人的衣服在内力鼓荡下如遇骤风。\n"NOR, me, target);
		
		amount1=me->query_skill("force",1);
		amount2=target->query_skill("force",1);
		
		if(random(amount1)>random(amount2)){
			message_vision(YEL"\n只见$n身子一晃，似乎有些支持不住。\n"NOR, me, target);
			target->add("neili",-amount1);
		} else {
		
			message_vision(YEL"\n只见$N身子一晃，似乎有些支持不住。\n"NOR, me, target);
			me->add("neili",-amount2);
		}
		me->add("neili", -50);
		target->add("neili", -50);
		
		me->start_busy(4);
		target->start_busy(4);
		
		remove_call_out("duo");
 		call_out("duo", 3, me, target);        
 		        
 		return 1;
	}
	remove_call_out("duo");
	return 1;
}

int duo2(object me, object target){
	
	int amount1, amount2;

	if( !target || !me->is_fighting(target) ) return;

        if( !living(me) || me->is_ghost() ) return;

        if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	if((me->query("neili")<(me->query_skill("force",1)*15) || target->query("neili")<(target->query_skill("force",1)*15))){

		if(me->query("neili")>target->query("neili")){
		
			message_vision(HIG"\n$N运足了气力，猛地将"+me->query_temp("weapon")->query("name")+HIG"夺回，顺手就是一招，向$n击去。"NOR,me,target);

			me->add("jiali", me->query_skill("whip",1));
			me->add_temp("apply/attack",me->query_skill("whip",1));
			me->add_temp("apply/damage",me->query_skill("whip",1));
		
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
			//printf("\n");
					
			me->add("jiali", -me->query_skill("whip",1));
			me->add_temp("apply/attack",-me->query_skill("whip",1));
			me->add_temp("apply/damage",-me->query_skill("whip",1));
		
			target->start_busy(random(3));
		
		} else {
	
			message_vision(HIG"\n$n运足了气力，猛地将$N手中的"+me->query_temp("weapon")->query("name")+HIG"拉得脱手而出，掉在了地上。\n"NOR,me,target);

			me->query_temp("weapon")->move(environment(me));
		
			me->start_busy(2+random(3));
		}
	
	} else {
		
		message_vision(WHT"\n只见$N和$n运足了内力用力回夺，两人的衣服在内力鼓荡下如遇骤风。\n"NOR, me, target);
		
		amount1=me->query_skill("force",1);
		amount2=target->query_skill("force",1);
		
		if(random(amount1)>random(amount2)){
			message_vision(YEL"\n只见$n身子一晃，似乎有些支持不住。\n"NOR, me, target);
			target->add("neili",-amount1);
		} else {
		
			message_vision(YEL"\n只见$N身子一晃，似乎有些支持不住。\n"NOR, me, target);
			me->add("neili",-amount2);
		}
		me->add("neili", -50);
		target->add("neili", -50);
		
		me->start_busy(4);
		target->start_busy(4);
		
		remove_call_out("duo2");
 		call_out("duo2", 3, me, target);        
 		        
 		return 1;
	}

	remove_call_out("duo2");
	return 1;
}