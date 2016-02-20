//Cracked by Roath
//01-01-01 wsky

//再拆数招，尹志平左剑平刺，右掌正击，同时左腿横扫而出，
//正是全真派中的“三连环”绝招。

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        int addon, ap, dp, damage, count, limit, limit2;
        string str;
        object weapon;
        
        weapon=me->query_temp("weapon");
                              
        if(!target ) target = offensive_target(me);

        if(!target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「三连环」只能对战斗中的对手使用。\n");
                
        if (!me->query("quanzhen/lianhuan"))
        	return notify_fail("你现在还不能使用三连环绝技！\n");
        
        if (me->query_skill("sword",1)<150)
        	return notify_fail("你的基本功还不够扎实。\n");
        	
        if (me->query_skill("quanzhen-jian",1)<180)
        	return notify_fail("你的全真剑法修为不够。\n");
        	
 	if( me->query_skill_mapped("sword") != "quanzhen-jian" )
                return notify_fail("你所用的并非全真剑法。\n");
                
        if( me->query("neili") <= 350 )
                return notify_fail("你的内力不够使用「三连环」！\n");
        if( me->query("jingli") <= 250 )
                return notify_fail("你的精力不够使用「三连环」！\n");    
        
        if( me->query_skill_mapped("strike") != "sanhua-juding" )
                return notify_fail("你所用的并非三花聚顶掌，不能施展「三连环」！\n");

        if( me->query_skill_prepared("strike") != "sanhua-juding" )
                return notify_fail("你所备的并非三花聚顶掌，不能施展「三连环」！\n");
        
        me->add("quanzhen/lh_count",1);
        
        if (me->query("quanzhen/lh_count")>40)
        	me->set("quanzhen/lh_count",1);
        
        me->add("neili", -350);
        me->add("jingli",-250);
        me->start_busy(3);
                        
        count=me->query("quanzhen/lh_count");
        limit=450;
        if (count<=10) tell_object(me, HIG"\n\n你精神抖擞，内力充沛，出招格外凌厉。\n\n"NOR);
        if (count>10 && count<=30) {
        	tell_object(me, HIG"\n\n你反复使用〖三连环〗，招数已经没有以前凌厉，担仍然咄咄逼人。\n\n"NOR);
        	limit=250;
        }
        if (count>30) {
        	tell_object(me, HIG"\n\n你使用太多次〖三连环〗，精力涣散，招数已经失去了原有的凌厉。\n\n"NOR);
        	limit=100;
        }
        
        addon=random((int)me->query_skill("sword",1)+(int)me->query_skill("quanzhen-jian",1))+(int)me->query_skill("kick", 1);
        
        if (addon<150) addon=150;
        if (addon>limit) addon=limit;
                
        message_vision(HIR"拆得数招，$N左剑平刺，右掌正击，同时左腿横扫而出，正是全真派中的“三连环”绝招。\n"NOR,me,target);
/*        
        me->add_temp("apply/strength", addon);
        me->add_temp("apply/damage", addon);
        me->add_temp("apply/attack", addon);
*/                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        
        weapon->unequip(); 
        
	if( me->query_skill_prepared("strike") == "sanhua-juding" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("strike");
        }        	
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        
        if( me->query_temp("restore") ) me->prepare_skill("strike", "sanhua-juding");
/*        
        me->add_temp("apply/strength", -addon);
        me->add_temp("apply/attack", -addon);
        me->add_temp("apply/damage", -addon);
*/        
        weapon->wield();
        
        ap=me->query("combat_exp")/1000+me->query_skill("sword",1)+me->query_skill("kick",1);
        dp=target->query("combat_exp")/1000+target->query_skill("parry",1);
        
        if(me->query_skill("kick",1)>50) message_vision(HIY,me,target);
        message_vision("\n$N身法一变，唰地一腿，贴地向$n横扫而出，只带得地上尘土飞扬。\n"NOR,me,target);
        
        if(random(ap)>dp/2){
        
        	damage=me->query_skill("quanzhen-jian",1)*(random(6)+3);
	
		message_vision(HIR"\n只见$n躲闪不及，已经被$N一腿扫中，惨叫声中，向后跌出丈许。\n"NOR, me, target);
					
		if (damage<500) damage=500;
		
		if (limit==100) damage=200;	
			
		if(wizardp(me))
			printf("damage======%d\naddon=======%d\n", damage, addon);
			
		target->add("qi", -damage);
       		target->add("eff_qi", -random(damage));				
		
		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		message_vision("($N"+str+")\n", target);

	      	target->start_busy(3);
        } else {
        	message_vision(HIY"\n$n见此招来势凶猛，向后一跃，轻巧地躲了开去。\n"NOR,me,target);
        	if(limit==100)
        	{
        		message_vision(HIR"\n$N用力过猛，收势不住，“哎哟”一声，摔了一交。\n"NOR,me,target);
        		me->add("eff_qi", -random(400));
        		str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
				message_vision("($N"+str+")\n", me);
			}
			
			me->start_busy(2);
		}
		
		return 1;
}