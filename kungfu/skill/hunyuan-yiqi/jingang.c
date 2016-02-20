//Cracked by Roath
// jingang.c 金刚伏魔神通
// Converted to exert from perform by xQin on 6/99
// Modified by Apache 9 / 99

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int original, skill;
        int temp1, temp2;

        if( objectp(target) && target != me ) 
                return notify_fail("你只能用金刚伏魔神通来提升自己的战力。\n");
/*
		  if( !me->is_fighting() )
					 return notify_fail("你必须在战斗中才能使用金刚伏魔神通！\n");
*/
        if( me->query_temp("weapon") )
                return notify_fail("你只能在空手时使用金刚神通！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("你的混元一气功火候未到，无法施展金刚伏魔神通！\n");

        if( me->query_skill("jingang-quan", 1) < 90 )
					 return notify_fail("你的金刚拳火候未到，无法施展金刚伏魔神通！\n");

		  if( me->query("max_neili") <= 600 )
					 return notify_fail("你的内力修为不足，劲力不能运发，无法施展金刚伏魔神通！\n");

		  if( (int)me->query("neili") < 600  )
					 return notify_fail("你的内力不够。\n");

		  if( (int)me->query_temp("jingang") )
					 return notify_fail("你已经发动了金刚伏魔神通！\n");

		  if( me->query_temp("jinzhongzhao") )
					 return notify_fail("你正在运用金刚不坏体神功，功力未够，无法同时运用金刚伏魔的外家神通。\n");

		  skill = me->query_skill("hunyuan-yiqi", 1);

		  me->add("neili", -skill*2);
		  me->receive_damage("jingli", skill);

		  message_vision(HIR
	"\n$N当下屏息凝神，内息暗暗转动，周身骨骼劈劈拍拍，不绝发出轻微的爆响之声。\n"
	"这是佛门正宗的最上武功，自外而内，不带半分邪气，乃是「"HIY"金刚伏魔神通"HIR"」。\n"NOR, me);

		  // The higher the hunyuan-yiqi, the higher the temp strength
		  if (skill < 100) {
		  	temp1 = 1;
		  } else if (skill < 200) {
		  	temp1 = 2;
		  } else {
		  	temp1 = 3;
		  }
		  original = me->query_str();
		  me->add_temp("apply/strength", original*temp1);
		  me->set_temp("jingang", 1);

		  me->start_call_out( (: call_other, __FILE__, "remove_effect", me, original*temp1 :), skill/6);
		  //if( me->is_fighting() )
		  //me->start_busy( 1+random(3) );

		  return 1;
}

void remove_effect(object me, int amount)
{
		  me->add_temp("apply/strength", - amount);
		  me->delete_temp("jingang");
		  // me->receive_damage("qi", 500, "内息错乱，真气失控而死");

		  message_vision(HIR"$N全身骨骼格格乱响，逆运内息，将「"HIY"金刚伏魔神通"HIR"」缓缓散去。\n"NOR, me);
}

