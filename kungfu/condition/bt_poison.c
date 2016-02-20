//Cracked by Roath
// bt_poison.c
// 西域灵蛇毒，化尸粉的母毒

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 1;
   if( !living(me) ) {
      message("vision", me->name() + "浑身溃烂，发出熏天的臭气，引来不少苍蝇。\n", environment(me), ({me}));
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")*2/3) {
      tell_object(me, HIR "你的伤口发麻，全身僵直，不听使唤，这不是普通的蛇毒！\n" NOR );
      message("vision", me->name() + "四肢扭曲，脚步踉跄。\n",
            environment(me), ({me}));
      }
      else if(me->query("eff_jing") > me->query("max_jing")/3) {
      tell_object(me, HIR "你全身麻木，但神志却异常清醒，你中了西域灵蛇毒了！\n" NOR );
      message("vision", me->name() + "只膝弯曲，身子慢慢垂下，口中发出似人似兽的荷荷之声。\n",
            environment(me), ({me}));
      }
      else {
      tell_object(me, HIR "你开始感到全身上下麻痒难当，偏偏又动弹不得！\n" NOR );
      message("vision", me->name() + "忽然满面堆欢裂嘴嘻笑，显得诡异无伦。\n",
            environment(me), ({me}));
      }
   }
	if (duration > 0) damage = duration;
	else damage = 10;

      me->receive_wound("jing", damage/2, "身中西域灵蛇毒死掉了");
      me->receive_damage("jingli", damage/2, "身中西域灵蛇毒死掉了");

	if (me->query_condition("bt_poison")>(5+me->query_skill("poison",1)/10))
		me->apply_condition("bt_poison", 
		duration - 5 - me->query_skill("poison",1)/10);
	else return 0;
   //return CND_CONTINUE;
   return 1;
}
