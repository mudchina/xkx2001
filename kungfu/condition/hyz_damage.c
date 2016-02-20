//Cracked by Roath
// hyz_damage.c 混元无极劲伤
// qfy Nov 11, 96.

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   int amt1, amt2;

   amt1 = me->query("huashan/enemy");
   amt2 = amt1/2;
        
   if( !living(me) ) {
      message("vision", me->name() + "脸上红班点点，脸色苍白得骇人。\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "忽然你一阵头晕目眩，你所中的混元无极劲内伤发作了！\n" NOR );
      message("vision", me->name() + "的脸色突然大为苍白，摇摇欲坠，似乎是内伤发作了！\n",
            environment(me), me);
   }

   me->receive_damage("qi", amt1, "内伤发作死了");
   me->receive_wound("qi", amt2, "内伤发作死了");       
   me->apply_condition("hyz_damage", duration - 1);

   if ( !me->query_temp("huashan/hyz_damage") ) {
	me->add_temp("apply/attack", -amt1*2/3);
	me->add_temp("apply/dodge", -amt1*2/3);
	me->set_temp("huashan/hyz_damage", 1);
   }

   if( duration < 1 ) {
	me->delete("huashan/enemy");

	if ( me->query_temp("huashan/hyz_damage") ) {
		me->add_temp("apply/attack", amt1*2/3);
		me->add_temp("apply/dodge", amt1*2/3);
		me->delete_temp("huashan/hyz_damage");
	}

	return 0;
   }

   return CND_CONTINUE;
}