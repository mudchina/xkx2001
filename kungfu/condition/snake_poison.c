//Cracked by Roath
// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")/2) {
      tell_object(me, HIB "随着一阵钻心的疼痛，你开始感到四肢发麻，蛇毒发作了！\n" NOR );
      message("vision", me->name() + "突然面部抽搐，四肢瑟瑟地抖了起来。\n",
            environment(me), me);
      }
      else if(me->query("eff_jing") > me->query("max_jing")/4) {
      tell_object(me, HIB "你感到呼吸困难，麻木的感觉顺着四肢逐渐上行，蛇毒发作了！\n" NOR );
      message("vision", me->name() + "突然两眼发直，全身抽搐起来。\n",
            environment(me), me);
      }
      else {
      tell_object(me, HIB "你开始感到天旋地转，四周景物都在慢慢离你远去，蛇毒发作了！\n" NOR );
      message("vision", me->name() + "突然摔倒在地，张大嘴巴，手脚无力地抽动着。\n",
            environment(me), me);
      }
   }
      if(me->query("poisoner")){
      me->receive_damage("qi", duration/2, me->query("poisoner"));
      me->receive_wound("jing", duration/3, me->query("poisoner"));
      }
      else {	
      me->receive_damage("qi", duration/2, "蛇毒攻心死了");
      me->receive_wound("jing", duration/3, "蛇毒攻心死了");
      }
	if (me->query_condition("snake_poison")>(5+me->query_skill("poison",1)/10))
		me->apply_condition("snake_poison", 
		duration - 5 - me->query_skill("poison",1)/10);
	else return 0;
   //return CND_CONTINUE;
   return 1;
}
