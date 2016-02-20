//Cracked by Roath
// hsf_poison.c
// 化尸粉  a very powerful one, and do nto write medicine for it please.

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 10;
   if( !living(me) ) {
      message("vision", me->name() + "浑身溃烂，发出熏天的臭气，引来不少苍蝇。\n", environment(me), ({me}));
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")*2/3) {
      tell_object(me, HIR "你的伤口火辣辣地发痛，开始溃疡，你伤口被人涂了化尸粉了！\n" NOR );
      message("vision", me->name() + "四肢扭曲，伤口流出黄色的脓液。\n",
            environment(me), ({me}));
      }
      else if(me->query("eff_jing") > me->query("max_jing")/3) {
      tell_object(me, HIR "你全身疼痛，大片的皮肉开始脱落，你中了化尸粉毒了！\n" NOR );
      message("vision", me->name() + "全身抽搐，黄色的脓液流了一身，发出隐隐的臭气。\n",
            environment(me), ({me}));
      }
      else {
      tell_object(me, HIR "你开始感到全身的肌肉已经不在骨架上，已经动弹不了了！\n" NOR );
      message("vision", me->name() + "突然摔倒在地，浑身溃烂，发出阵阵臭气。\n",
            environment(me), ({me}));
      }
   }
	if (duration > 0) damage = duration;
	else damage = 10;

      me->receive_wound("qi", damage*2, "被化尸粉化掉了");
      me->receive_wound("jing", damage, "被化尸粉化掉了");
      me->receive_damage("jingli", damage, "被化尸粉化掉了");
	if (me->query_condition("hsf_poison")>(5+me->query_skill("poison",1)/10))
		me->apply_condition("hsf_poison", 
		duration - 5 - me->query_skill("poison",1)/10);
	else return 0;
   //return CND_CONTINUE;
   return 1;
}
