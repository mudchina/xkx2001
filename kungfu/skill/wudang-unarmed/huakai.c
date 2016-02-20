//Cracked by Roath
// huakai.c 绵掌之「花开并蒂」
// xQin 11/00

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object ob;
	string msg;
	int skill;
	
	if( !target ) target = offensive_target(me);
	if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("花开并蒂只能带动战斗中的对手。\n");
                
        if( me->query_temp("yield") )
                return notify_fail("你不出掌，怎么能出「花开并蒂」？\n");
        
   /*     if( objectp(ob = me->query_temp("huakai")) )
	{
                if( ob->is_fighting(me) )
                	return notify_fail("你已经在出「花开并蒂」了。\n");
        }
     */   
        if( (int)me->query_skill("mian-zhang", 1) < 99)
        	return notify_fail("你的绵掌不够纯熟，尚未能出此绝招。\n");
        
        if( (int)me->query_skill("taiji-shengong", 1) < 79)
        	return notify_fail("你的太极神功修为不够，不能出「花开并蒂」。\n");
        	
        if( (int)me->query("jiali") > 2 || (int)me->query("jiajin") > 2)
        	return notify_fail("你发现加力后无法把绵掌中若有若无，借力打力的要决发挥出来。\n");
                
        msg = WHT "\n$N深深吸了一口气，一招「花开并蒂」左手挥掌猛击$n的右颊，右手出指疾点$n的“缺盆穴”。\n";
        
        me->add("neili", -30 +random(-20));
        me->add("jingli", -15 +random(-15));
        
	
        if( random(me->query("combat_exp") * me->query_skill("force") /100+ random(10) ) >
        (int)target->query("combat_exp") * target->query_skill("force") /200 ) {
        
		me->start_busy(2);
		call_out("huakai", 1, me, target);
	}
	else
	{
		msg += YEL"可是$p已看破此招，不慌不忙的避开了。\n"NOR;
		me->start_busy(1+random(3));
		}
	
		message_vision(msg, me, target);
	
	return 1;
	

}	
int huakai(object me, object target)
{
	int damage, tjsg, mz, nl;
	
	if( !me->is_fighting(target) || !living(target) ) return 0;
	tjsg = (int)me->query_skill("taiji-shengong");
	mz = (int)me->query_skill("strike");
	nl = (int)me->query("neili");
	
	if( random(me->query_skill("taiji-shengong") * me->query("neili")/100 > 
	(int)target->query_skill("force") * (int)target->query("neili") /200 ) 
	|| (int)me->query_skill("mian-zhang", 1) > 119 )
	{
		me->set_temp("double_huakai");
		damage = mz + tjsg/random(2);
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->add("neili", -(damage/4));

		me->add("neili", -damage/10);
		message_vision(WHT"$P双手递招之后，跟着右掌击$p左颊，左手食指点$p右肩后“缺盆穴”。\n"
		               "这两招「花开并蒂」并成一招，连续四式，便如暴风骤雨般使出，势道之猛，手法之快，当真非同小可！\n"NOR, me, target);
		return 1;               
	}
	else
	{

		damage = mz + tjsg/random(3);
		target->receive_damage("qi", damage, me);
		
		target->receive_wound("qi", damage/4, me);
		target->add("neili", -(damage/5));
		
		me->add("neili", -damage/9);
		message_vision(RED"结果只见$p轻哼一声，后退三步，吐出了一口鲜血。\n"NOR, me, target);
		return 1;
	}
	
	
}
