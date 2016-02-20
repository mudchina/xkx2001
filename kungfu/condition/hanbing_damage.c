//Cracked by Roath

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int ml;
	ml = me->query("max_neili")/1000;
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
	if(me->query("eff_jing") > me->query("max_jing")/4)
	tell_object(me, HIB"你觉得一股冷气从直透心口，全身立时寒战，牙齿互击，格格作响。\n"NOR );
	else tell_object(me, HIB"你觉得胸口烦恶欲呕，数番潜运内力欲图稳住身子，总是天旋地转，几欲摔例。\n" NOR );
      
      message("vision", me->name() + "突然打了个寒战，脸色青白，便如僵尸。\n",
            environment(me), me);
   }
      me->receive_damage("qi", (duration/2)+20, "因寒冰绵掌阴毒侵入内脏而死");
      me->receive_wound("jing", (duration/2)+20, "因寒冰绵掌阴毒侵入内脏而死");

      me->apply_condition("hanbing_damage", duration - 1);
                me->apply_condition("hanbing_damage", duration - 1); 

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
