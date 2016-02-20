//Cracked by Roath
// /kungfu/skill/huoyan-dao/fen.c  perform 焚
// Summer, 11/10/96.
#include <ansi.h>
#include <armor.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object armor;
	int damage;
	string *limb, type, result, str;

	type = "内伤";

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("你不在战斗中。\n");

	if ( objectp(me->query_temp("weapon")) )
		return notify_fail("你不是空手。\n");

/*
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
*/
	
	if( (int)me->query_skill("huoyan-dao", 1) < 120 )
		return notify_fail("你的火焰刀修为不够。\n");

	if ( me->query_skill_mapped("force") != "xiaowuxiang"
	&& me->query_skill_mapped("force") != "longxiang-banruo")
                return notify_fail("你所用内功不对！\n");

	if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够！\n");

	if( me->query("jingli") <= 150 )
                return notify_fail("你的精力不够！\n");

	message_vision(HIR "$N长吸一口气，身上衣衫缓缓涨起，两掌变得通红，射出一股灼人热气。$n的身影被笼罩在一团火焰之中。\n\n" NOR, me,target);
	//tell_object(target, BLU "你只觉一股热浪扑面，霍的胸口一阵剧痛。\n"NOR);
	me->add("neili", -100);
	me->add("jingli", -100);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2){ 
		if( target->query_temp("armor/cloth")){
		armor = target->query_temp("armor/cloth");
		if( armor->query("armor_prop/armor") < 150){
		message_vision(HIY"只见$N身上的$n"+HIY+"已被震得粉碎，变成一块块破布掉在地上。\n"NOR, target, armor);
		armor->unequip();
                armor->move(environment(target));
                armor->set("name", "破碎的" + armor->query("name"));	
		armor->set("value", 0);
                armor->set("armor_prop/armor", 0);
                target->reset_action();
		}
	}
		damage = random((int)me->query_skill("strike"))*5;
                target->receive_damage("qi", damage,  me); 
		target->receive_wound("qi", (int)me->query_skill("huoyan-dao", 1), me);
		target->start_busy(1+random(3));
		
	limb = target->query("limbs");
   	result = COMBAT_D->damage_msg(damage, type);
   	result = replace_string( result, "$l", limb[random(sizeof(limb))]);
   	result = replace_string( result, "$p", target->name() );
   	message_vision(result, me, target);

   	str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
   	message_vision("($N"+str+")\n", target);
	}

	else 
	{
	message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, me, target);
	}
	me->start_busy(1+random(3));
	return 1;
}
