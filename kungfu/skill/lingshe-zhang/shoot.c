//Cracked by Roath
// shoot 发射暗器
// maco

#include <ansi.h>

inherit F_SSERVER;
inherit F_DBASE;

void remove_shoot(object);

int perform(object me, object target)
{
	int t = (int)me->query_temp("baituo/shoot");
	string type, limbs, str, dodge_skill, limb, result;
	object weapon;
	int poi_amount, level, exp1, exp2;

	if( environment(me)->query("no_fight"))
		return notify_fail("这里不能发射暗器。\n");

	if( !target && me->is_fighting()) target = offensive_target(me);

	if( !target )
		return notify_fail("你要对谁发射暗器？\n");
		
	if( target == me )
		return notify_fail("对自己发射暗器？\n");

	if( t && (time()-t) < 10 )
                return notify_fail("你刚刚才发射了暗器，短时间内不宜故技重施！\n");

	if (!objectp(weapon = me->query_temp("weapon")))
		 return notify_fail("你必需手持能发射暗器的蛇杖。\n");

	type = weapon->query("snake_type");

	if ( !type && weapon->query("id") != "shezhang")
		return notify_fail("你的"+weapon->name()+"上并没有暗器机关。\n");

	level = (int)me->query_skill("lingshe-zhang", 1);
	if (level < 40 )
		return notify_fail("你的灵蛇杖法不够娴熟，无法操纵发射暗器的机关。\n");

	if ((int)me->query_skill("poison", 1) < 40 )
		return notify_fail("你的基本毒技造诣太浅，无法操纵发射暗器的机关。\n");

	if( me->query_skill_mapped("force") != "hamagong")
		return notify_fail("你所用的内功与「灵蛇杖法」气路相悖！\n");

	limbs = target->query("limbs");
	//level = level/2;
	poi_amount = level + me->query_skill("poison", 1);

	if( me->query("neili") < poi_amount )
		return notify_fail("你的内力不够。\n");
        if( me->query("jingli") < 50 )
                return notify_fail("你的精力不够。\n");

	exp1 = me->query("combat_exp");
	exp2 = target->query("combat_exp");

	if(exp1*3 < exp2 && exp2 > 1000000)
		return notify_fail("你料知"+target->name()+"这等身手，杖头暗器也奈何他不得，不如不发，免惹耻笑。\n");

	message_vision(HIB"$N将"+weapon->name()+HIB"在地下一顿，呜的一声怪响，杖头中飞出一件奇形暗器，笔直往$n射去。\n"NOR, me, target);

	me->add("neili", -poi_amount/2);
	me->add("jingli", -50);

	if( me->query("neili") > random(target->query("neili")) && exp1 > random(exp2) ) {

		message_vision(HIR"那暗器去得好快，祗听$n一声惨嚎，尚未看清暗器来路，已被射中"+limbs[random(sizeof(limbs))]  +"！\n"NOR, me, target);

		if( type == "怪蛇" || type == "灵蛇" )
			target->apply_condition("bt_poison",
			poi_amount*3 + target->query_condition("bt_poison"));
		else
			target->apply_condition("snake_poison",
			poi_amount*3 + target->query_condition("snake_poison"));
			target->set("poisoner", me);
		
		target->receive_wound("qi", random(level) + level/2 , me);
		target->start_busy(random(2));
		result = COMBAT_D->eff_status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
	        message_vision("( $N"+result+" )\n", target);
	        
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
		message_vision(str, me, target);
	}

	target->kill_ob(me);
	me->set_temp("baituo/shoot",time());
	remove_call_out("remove_shoot");
	call_out("remove_shoot", 10,me);
	me->start_busy(random(2));

	return 1;
}

void remove_shoot(object me)
{
	me->delete_temp("baituo/shoot");

        tell_object(me, "你的蛇杖里的暗器准备好了。\n");
}
