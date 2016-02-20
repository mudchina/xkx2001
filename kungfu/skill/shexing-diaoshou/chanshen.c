//Cracked by Roath
// chanshen.c 缠身
//wzfeng 2000 6

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      
      
      lvl = ((int)me->query_skill("xiaoyaoyou", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
	  if( !target ) target = offensive_target(me);
	   if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「缠身决」之技只能在战斗中对敌人使用。\n");

        if( (int)target->query_temp("gb_chanshen") )
                return notify_fail("对方已经被你使缠身决缠住了！\n");
      if( (int)me->query_skill("xiaoyaoyou",1) < 150 )
      return notify_fail("你的逍遥游不够娴熟，不能使出缠身决！\n");
      if( (int)me->query_skill("shexing-diaoshou",1) < 150 )
      return notify_fail("你的逍遥游不够娴熟，不能使出缠身决！\n");
      if( (int)me->query_skill("huntian-qigong", 1) < 150 )
      return notify_fail("你的混天气功等级不够，不能使出缠身决！\n");
      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("你的内力太弱，不能使出缠身决！\n");
      if( (int)me->query("neili") < 200 )
      return notify_fail("你的内力太少了，不能使出缠身决！\n");   
	        if( (int)me->query("neili") < 300 )
      return notify_fail("你的精力太少了，不能使出缠身决！\n");   

			if(!me->query_temp("gb_huixuan"))
				return notify_fail("你没有使出逍遥回旋步，无法使出缠身决！\n");   


      message_vision(HIB"\n突然间$N口中发出“嘶嘶”的声音，双手半曲，三指上竖成蛇状，陪合着潇遥步法，突然欺近$n的身边，令$n大吃一惊。\n"NOR, me,target);
      me->add("neili", -100+random(50)); 
      me->add("jingli", -50+random(50));      
	  	target->add_temp("apply/parry",  -lvl/3);
		target->add_temp("apply/dodge",  -lvl/3);
		target->add_temp("apply/aromr",  -lvl/3);
		if(target->query("combat_exp")<random(me->query("combat_exp"))*2
			)
		{
			message_vision(HIB"但见$N的身形有如蛇蝎缠身一般，环在$n的身边，令$n不知所措，只觉的仿拂有无形的绳索慢慢的束缚了$n。\n"NOR, me,target);
			
			target->start_busy(3+random(lvl/40));
		}

		target->set_temp("gb_chanshen",1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", target, lvl/3 :), lvl/25);
		
		me->start_busy(1+random(1));
      return 1;
}

void remove_effect(object target,int lvl)
{
		        if( !target ) return;
			target->add_temp("apply/parry",  lvl);
			target->add_temp("apply/dodge",  lvl);
			target->add_temp("apply/aromr",  lvl);
			target->delete_temp("gb_chanshen");
	        if(target->is_fighting() )
			{
			target->start_busy(1 + random(1));
			message_vision(HIG"$N使出浑身解数，算是挣脱了蛇形刁手的诡异怪招。\n"NOR, target);
			}
}

