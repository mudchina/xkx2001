//Cracked by Roath
//lianhuan.c  疯魔杖法之疯魔飞杖

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object weapon);
private int remove_attack(object me, object weapon);

int perform(object me, object target)
{
	object weapon;
	int skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("疯魔飞杖只能对战斗中的对手使用。\n");

	if( me->query_temp("fengmo") )
                return notify_fail("你已在使用疯魔飞杖了！\n");

	weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("你手中无杖，如何能够施展疯魔飞杖？\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的并非混天气功，无法配合杖法施展疯魔飞杖！\n");

        if( me->query_skill("force") < 100 )
                return notify_fail("你的混天气功火候未到，无法配合杖法施展疯魔飞杖！\n");

	if( me->query_skill("fengmo-zhang", 1) < 100 )
		return notify_fail("你疯魔杖法修为不足，还不会使用疯魔飞杖！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够施展疯魔飞杖！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够施展疯魔飞杖！\n");

 	skill = me->query_skill("staff");
	
	message_vision(HIR "\n$N大喝一声将手中急转着的"+weapon->name()+"脱手掷出，在空中高低左右回旋！\n\n" NOR, me, target);

	me->set_temp("fengmo", 1);
	me->set_temp("location", file_name(environment(me)));
//	me->set_temp("my_weapon", base_name(weapon));
//	me->set_temp("weapon_name", weapon->name());
	me->add("neili", -200);
	me->add("jingli", -100);
	weapon->unequip();
//	destruct(weapon);
	weapon->move("/u/ryu/workroom");
	me->reset_action();
//	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, weapon :), 1);
	call_out("check_fight", 1, me, target, weapon);

	return 1;
}

void check_fight(object me, object target, object weapon)
{
	string *limbs, limb, result, str, type;
	int damage;

	me->reset_action();

	if ( me->query_temp("fengmo") >= (int)me->query_skill("fengmo-zhang", 1)/5 ) {
	   call_out("remove_attack", 1, me, weapon);
	}
	else if ( me->is_fighting() && me->query_temp("fengmo") ) {
	limbs = target->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	type = "挫伤";

	   message_vision(HIR "\n突然间$n自行向$N的"+limb+"猛然飞撞过去！\n" NOR, target, weapon);

	   if ( random(me->query("combat_exp")) > target->query("combat_exp") ) {

//RYU: the following code is to make it look nice.
	   damage = 5+random(me->query_skill("fengmo-zhang", 1));
	   target->receive_damage("qi", damage, me);

           result = COMBAT_D->damage_msg(damage, type);
	   result = replace_string( result, "$l", limb);
	   str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));

	   message_vision(result, me, target);
	   message_vision("($N"+str+")\n", target);

	   }
	   else {
		message_vision(YEL "$N看得分明，身形一让，避过了$n！\n" NOR, target, weapon);
	   }
	
	   message_vision(HIR "\n$N猛吸一口气，飘身赶上$n伸掌在杖尾一推，将其又推在半空飞旋。\n\n" NOR, me, weapon);

	   me->add_temp("fengmo", 1);
	   call_out("check_fight", 1, me, target, weapon);
	}
	else {
	   call_out("remove_attack", 1, me, weapon);
	  
	}
}		

int remove_attack(object me, object weapon)
{
	remove_call_out("check_fight");
	me->delete_temp("fengmo");
	
	if ( file_name(environment(me)) == me->query_temp("location") && living(me) ) {
		weapon->move(me);
		weapon->wield();
		message_vision(YEL "\n$N纵身上前，将飞旋的$n收回。\n\n" NOR, me, weapon);
	}
	else {
		weapon->move(me->query_temp("location"));
		message("vision", "只听得锵的一声，"+weapon->name()+"力尽由半空跌落。\n", environment(weapon), ({weapon}) );
	}

//	me->delete_temp("my_weapon");
//	me->delete_temp("weapon_name");
	me->delete_temp("location");

	return 1;
}
