//Cracked by Roath
// tongshou.c 天地同寿
// Sdong fixed #50 perform tongshou bug. fixed perform tongshou;fu jin; then won't die bug, 7/16/1999

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	mapping skill_status;
	string msg, *sname;
	object weapon;
	int exp, shen, mine, count;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天地同寿只能对战斗中的对手使用。\n");

	if( me->is_ghost() || me->query("eff_qi") <0 )
		return notify_fail("你已经死了。\n");


	if( me->is_busy() )
		return notify_fail("你现在忙着呢，使不出这一招。\n");


	if( !me->query("yinliting_teach") )
		 return notify_fail("你未得殷梨亭传授，不会使用天地同寿。\n");

	weapon = me->query_temp("weapon");
		  if( weapon->query("skill_type") != "sword" )
					 return notify_fail("你手中无剑，如何使得天地同寿？\n");

	if( (int)me->query_skill("sword") < 150 )
		return notify_fail("你的太极剑法极不够娴熟，不会使用天地同寿。\n");
/*
	if( me->query("neili") >= 100 || me->query("qi") >= 200)
					 return notify_fail("你未到山穷水尽之地，不需用此狠招！\n");
*/
	if( (int)me->query_skill("taiji-shengong", 1) < 120 )
		return notify_fail("你的太极神功修为不够，不会使用天地同寿。\n");

	if( me->query_skill_mapped("force") != "taiji-shengong")
					 return notify_fail("你所用的内功与太极剑意气路相悖！\n");

		  if( me->query("combat_exp") < 300000)
					 return notify_fail("你实战经验不足，不会使用天地同寿。\n");

	if (target->query("shen") < -10000)
		shen = (int)me->query("shen")/50;
	else shen = -(int)me->query("shen")/50;

	exp = (int)me->query("combat_exp")/100;
//	if (exp > 6000) exp = 5000 + random(1000);

	msg = HIW"$N一声悲啸，背心空门大开，飞撞向$n"+HIW"怀中，倒转剑柄向自己小腹直插而下！！！\n"NOR;

	mine = random(me->query("combat_exp") + me->query("shen"));
	if( mine > (int)target->query("combat_exp")/3*2 ) {
		msg += HIR"$n"+HIR"猝不及防之下，被$N撞入怀中，只觉小腹一凉，"NOR+weapon->name()+HIR"已自$N后背透体而入！！！\n" NOR;
		message_vision(msg, me, target);
			me->add("max_neili", -(30+random(30)) );
			me->add("combat_exp", -exp);
		me->add("shen", shen);

/*
		if ( mapp(skill_status = me->query_skills()) ) {
						skill_status = me->query_skills();
						 sname = keys(skill_status);
						count = sizeof(skill_status);
						for(i=0; i<sizeof(skill_status); i++) {
								point = (skill_status[sname[i]]+1)*(skill_status[sname[i]]+1)/2+1;
								while ( (point /= 2) > 0 )
										  me->improve_skill(sname[i], -point+1);
						}
			}
*/

		me->receive_wound("qi", me->query("max_qi")+200,
		"使用天地同寿与"+target->name()+"同归于尽了！");
		target->receive_wound("qi", target->query("max_qi")+200,
					 "与"+me->name()+"同归于尽了！");

		me->start_busy(3 + random(3));
		target->start_busy(3 + random(3));

		me->die();
		target->die();

	} else {
		msg += HIC"$n不料$N用此招数，手忙脚乱，狼狈万状的躲闪开去，但已吓得手足冰凉，好一阵动弹不得。\n" NOR;
		message_vision(msg, me, target);
		me->receive_wound("qi", me->query("max_qi")+200, "使用天地同寿壮烈成仁！");
		me->start_busy(3);
		me->die();
		target->start_busy(3 + random(3));
	}

	return 1;
}
