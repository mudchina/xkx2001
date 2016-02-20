//Cracked by Roath
// cimu.c 辟邪剑法「刺心」之技
// wzfeng@XKX 99 9 

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "pixie_superskill.c"

void remove_effect(object target,int parry_skill);



int perform(object me, object target)
{
        string msg,perform_name;
		
        object weapon;
		
		
        int  ap, dp,damage;
        if( !target ) target = offensive_target(me);

       	if(me->query("canuse_cixin")!=1)
			    return notify_fail("什么？\n");

		if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「刺心」之技只能在战斗中对敌人使用。\n");
		if(!living(target))
			return notify_fail("对付昏迷的人还需「刺心」?\n");

        if(me->query_temp("pixie/guimei") <=0 )
                return notify_fail("你没有施展鬼魅身法，不能使出「刺心」。\n");

        if( me->query("neili") <= 500)
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 500 )
                return notify_fail("你的精力不够！\n");


        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("空手如何「刺心」？？\n");

/*        if( (string)weapon->query("id") != "xiuhua zhen" && 
            (string)weapon->query("id") != "qijue zhen" )
                 return notify_fail("你没有趁手的兵器，不能施展「刺心」绝技。\n");
*/
        if( ( (int)me->query_skill("pixie-jian", 1)) < 180 )
                return notify_fail("你的辟邪剑法不够娴熟，无法使出「刺心」。\n");

		if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("你没有将辟邪剑法运在身法上，很难接近对手。\n");	
		
        //if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
		perform_name="pixie-cixin";

		ap = me->query_skill("sword")/2;
		dp = target->query_skill("dodge")/2;
		
		if(random(me->query("dex")>15)||(random(me->query("int")>15)))
		{
			ap+=ap;
		}
		if(me->query("qi")<me->query("max_qi")/7)
			ap=ap*2;
		if(me->query("combat_exp")<(target->query("combat_exp")/3))
			ap=1;

		weapon = me->query_temp("weapon");
		msg="";

		//do super perform
		
		damage=me->query_skill("pixie-jian",1)*(random(5)+5);
		if(me->query_skill("pixie-jian",1)>400)
		damage=damage*2;
		if(!do_prepare_superskill(perform_name,me,target,ap,dp))
		
		{
			
		    if(target->query_temp("pixie/cimu"))
		 {
			msg = HIW "\n趁$n双目失明之时，$N一声冷笑，使出辟邪剑法「刺心」之技。\n"NOR;
			ap=ap+random(ap);
			damage=damage+damage/5;
		}
			msg += HIB "$N轻摇腰肢，身影飘动，幻化出无数诡异人影。突然一影飞出，袭向$n。\n"NOR;
		if( wizardp(me) &&me->query("env/pixie_test"))
		{
				printf(HIC"ap=%d\tdp=%d\n"NOR,ap,dp);
				
		}

        if( random(ap+dp) < dp||(random(7)==0))
        {
                msg += HIG"$n听得劲风扑面，知道是$N施展凌厉杀着，赶紧收住攻势，一个斜翻，险险的避开这一招。\n" NOR;
		                me->start_busy(2 + random(1));

				me->delete_temp("pixie_performtime");

        }
        else
			if(!target->query_temp("pixie/cixin")
				&&random(target->query_temp("pixie_times/cixin"))>1
				&&random(target->query_int())>random(me->query_int()))
				{
				msg += HIG"$p先前已见过此招，心中略有防备，一个斜翻，已然躲过。\n" NOR;
				me->start_busy(3 + random(1));
				me->delete_temp("pixie_performtime");

				}
			else
			{
					msg += HIR "$n知觉身前劲风扑来，便知大事不妙，紧接着心口一阵剧痛，已被$N刺中。\n"NOR;	
					//damage=me->query_skill("pixie-jian",1)*(random(5)+5);
					target->set_temp("pixie/cixin",1);
					target->add_temp("pixie_times/cixin",1 );
					target->add("eff_qi",-damage);
					target->add("qi",-damage);
					target->add("jingli",-damage/2);
					if(target->query("eff_qi")<=0)
					{
						target->set("eff_qi",0);
						target->unconcious();
					}
					if(target->query("qi")<=0)
						{
						target->set("qi",0);
						target->unconcious();
					}
			
					if(target->query("jingli")<=0)
						target->unconcious();
						
					set_perform(me,perform_name);
   				    me->start_busy(2 + random(1));


			}
		}
                                        if(!me->query_temp("pixie_noop"))
                                        call_out("checking_pixieflg", 1, me, target);
                                        
                                        me->add("neili", -100+random(200));
                                        me->add("jingli", -100+random(200));
										message_vision(msg, me, target);
                  return 1;
}
