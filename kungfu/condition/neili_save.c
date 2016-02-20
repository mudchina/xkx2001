//Cracked by Roath

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{	
   int cost, gene;

   if (!me->is_fighting()) {
	tell_object(me, GRN "你将掌中汇集的真气收回丹田。\n" NOR );
	me->apply_condition("neili_save", 0);
	return 0;
   }
   if( !living(me) ) {
      message(HIR"vision", me->name() + "口中鲜血狂喷。\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIG "你感到真气渐渐向掌中汇集！\n" NOR );
      message_vision(HIG"$N掌上青芒越来越盛，掌缘青光一片，如同剑锋一般！\n"NOR,me);
   }
   
   cost = (int)me->query_condition("neili_save");
   if ( me->query("neili") > 0 && me->query("qi") > cost*3/2 ) {
	gene = (int)me->query("th_jianyi");
	me->apply_condition("neili_save", cost+100*gene);
	me->add("neili", -100*gene);
   } else {
      	message(HIR"vision", me->name() + "口中鲜血狂喷。\n"NOR,environment(me), me);	
	me->receive_damage("qi", cost/2,"真气失控，走火如魔而亡");
   }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
