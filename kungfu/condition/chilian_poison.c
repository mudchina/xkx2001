//Cracked by Kafei
//May 10th Modified by haowen to enforce poison
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
//	int ml;
//	ml = me->query("max_neili")/1000;
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "忽然一阵晕旋使你急欲作呕，你中的赤炼掌毒发作了！\n" NOR );
      message("vision", me->name() + "头重脚轻，身子突然晃了两晃。\n",
            environment(me), me);
   }
   if(me->query("poisoner")){
      me->receive_damage("qi",random(duration)/2+10,me->query("poisoner"));
      me->receive_wound("jing",random(duration)/2+10,me->query("poisoner"));
	}
	else{
      me->receive_damage("qi", random(duration)/2+10, "赤炼掌毒攻心死了");
      me->receive_wound("jing", random(duration)/2+10,"赤炼掌毒攻心死了");
	}
//   if(!userp(me)) me->receive_curing("jing", 12);

      me->apply_condition("chilian_poison", duration - 1);
//    me->apply_condition("chilian_poison", duration - 1); 
	
   if( duration == 1) me->delete("poisoner");

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
