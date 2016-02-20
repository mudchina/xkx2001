//Cracked by Roath
// cimu.c 辟邪剑法「刺足」之技
// wzfeng@XKX 99 9 

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "pixie_superskill.c"
void remove_effect(object target,int dodge_skill);
int perform(object me, object target)
{
        string msg,perform_name;
		
        object weapon;
		
        int  ap, dp,cizu_busy,dodge_skill;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「刺足」之技只能在战斗中对敌人使用。\n");
		if(!living(target))
			return notify_fail("对付昏迷的人还需「刺足」?\n");


        if( (int)target->query_temp("pixie/cizu") )
                return notify_fail(target->name() +"已被你刺中双足要害！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 300 )
                return notify_fail("你的精力不够！\n");


        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("空手如何「刺足」？？\n");

/*        if( (string)weapon->query("id") != "xiuhua zhen" && 
            (string)weapon->query("id") != "qijue zhen" )
                 return notify_fail("你没有趁手的兵器，不能施展「刺足」绝技。\n");
*/

        if( ( (int)me->query_skill("pixie-jian", 1)) < 100 )
                return notify_fail("你的辟邪剑法不够娴熟，无法使出「刺足」绝技。\n");

		if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("你没有将辟邪剑法运在身法上，很难接近对手。\n");	
		
        //if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
		perform_name="pixie-cizu";
		ap = me->query_skill("sword");
		dp = target->query_skill("dodge");
		if(me->query("dex")>19)
		{
			ap+=ap;
		}
		if(me->query("combat_exp")<(target->query("combat_exp")/3))
			ap=1;

		weapon = me->query_temp("weapon");
		msg="";
		dodge_skill=target->query_skill("dodge");
		if(dodge_skill<=0)
			dodge_skill=0;
		
		//根据身法的高低来决定刺足的时间。
		if(me->query("dex")>22&&me->query("dex")>target->query("dex"))
			cizu_busy=me->query_dex();
		else
			cizu_busy=me->query_dex()/2;

		//do super perform
		if(!do_prepare_superskill(perform_name,me,target,ap,dp))
		{
		    if(target->query_temp("pixie/cimu"))
		 {
			msg = HIB "\n趁$n双目失明之时，$N一声尖笑，使出辟邪剑法「刺足」之技。\n"NOR;
			ap=ap+random(ap);
		}
			if(me->query_temp("pixie/guimei") >0 )
                    {
                    msg += HIB "$N的身影犹如鬼魅一般，刹那间变得灵幻异常。\n"NOR;
                    ap=ap+random(ap);
                    }

		msg += HIB "$N突然一个矮身，眨眼间飘到$n身前，手中"+weapon->query("name")+"连刺$n双足要穴。\n"NOR;

		
		if( wizardp(me) &&me->query("env/pixie_test"))
		{
				printf(HIC"ap=%d\tdp=%d\n"NOR,ap,dp);
				printf(HIC"cizu_busy=%d\n"NOR,cizu_busy);
		}

        if( random(ap+dp) < dp )
        {
				msg += HIG "$n闻有异动，知是$N施展怪招，忙提气向空中跃起，接着一个翻身，落在远处。\n"NOR;	
	            me->start_busy(1 + random(1));
   					me->delete_temp("pixie_performtime");
        }
        else
			if(!target->query_temp("pixie/cimu")
				&&random(target->query_temp("pixie_times/cizu"))>1+random(10)
				&&random(target->query_int())>random(me->query_int()))
				{
				msg += HIG"$p先前已见过此招，心中略有防备，当即向后急退，避开这一招。\n" NOR;
				me->start_busy(1 + random(1));
				me->delete_temp("pixie_performtime");
				}
			else
			{
					msg += HIR "$n知觉身前劲风扑来，知道大事不秒，惊慌中只觉双足一麻，接着下身失去知觉。\n"NOR;	
					target->add_temp("apply/dodge",  -dodge_skill);
					target->set_temp("pixie/cizu",1);
					target->set_temp("cannot_move",1);
					target->set_temp("cannot_move_msg","你双足要穴被刺中，哪里还能移动半步。");
					target->add_temp("pixie_times/cizu",1 );
					target->add("eff_qi",-(random((int)me->query_skill("pixie-jian"))*4/3));
					       if( userp(me) )
					{
					target->set_temp("cizu_power", dodge_skill);
                    target->apply_condition("b_cizu",1+(int)(cizu_busy/15));
					
					}
					else
  	                	me->start_call_out( (: call_other, __FILE__, "remove_effect", target, dodge_skill :), cizu_busy);

					set_perform(me,perform_name);
   				    me->set_temp("pixie_performtime",5);

			//		me->start_call_out( (: call_other, __FILE__, "remove_effect", target, dodge_skill :), cizu_busy);
					me->start_busy(1 + random(2));
		}
		
		}
		if(!me->query_temp("pixie_noop"))
		call_out("checking_pixieflg", 1, me, target);
		
		me->add("neili", -50);
		me->add("jingli", -50);
		message_vision(msg, me, target);
                  return 1;
}
void remove_effect(object target,int dodge_skill)
{
		        if( !target ) return;
			target->add_temp("apply/dodge",  dodge_skill);
			target->delete_temp("pixie/cizu");
			target->delete_temp("pixie_times/cizu");
			target->delete_temp("cannot_move");
			target->delete_temp("cannot_move_msg");

	        if(target->is_fighting())
			message_vision(HIG"$N终于冲开下身穴道，双足行动恢复正常。\n");
			return;
}