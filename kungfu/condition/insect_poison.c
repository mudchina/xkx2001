//Cracked by Roath
// insect_poison.c

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")/2) {
      tell_object(me, HIB "你开始感到身体变得冰凉。\n" NOR );
      message("vision", me->name() + "突然面部抽搐，手脚发起抖来。\n",
            environment(me), me);
      }
      else if(me->query("eff_jing") > me->query("max_jing")/4) {
      tell_object(me, HIB "你感到呼吸困难，四肢渐渐肿了起来。\n" NOR );
      message("vision", me->name() + "突然两眼发直，全身抽搐起来。\n",
            environment(me), me);
      }
      else {
      tell_object(me, HIB "你开始感到天旋地转，四周景物都在慢慢离你远去。\n" NOR );
      message("vision", me->name() + "突然摔倒在地，张大嘴巴，手脚无力地抽动着。\n",
            environment(me), me);
      }
   }
      me->receive_damage("qi", 30, "毒发身死了");
	me->apply_condition("insect_poison", duration - 1);
	if(me->query("poisoner"))
	me->receive_wound("jing", 5, me->query("poisoner"));
	else	
	me->receive_wound("jing", 5, "毒发身死了");

     if( duration == 1) me->delete("poisoner");
     if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
