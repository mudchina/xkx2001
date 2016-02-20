//Cracked by Roath
//jiutian.c  凤舞九天
//Mantian 漫天 2000/10/02

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object target, int dodge, int speed, int damage, int parry);

int perform(object me, object target)
{
		object weapon, weapon1 ;
		string msg;
		int extra, dodge, speed, parry ,damage;

		if (!target) target = offensive_target(me);

		if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail(HIW"你所用得内功心法不对，无法跃起身形。\n" NOR);

		if (!target
		||      !target->is_character()
		||      !me->is_fighting(target))
			return notify_fail( HIW "「凤舞九天」只能在战斗中使用。\n" NOR);

		if (me->query("gender") !="女性") 
			return notify_fail( HIW "「凤舞九天」只有女性能舞！\n" NOR);

		if (me->query_temp("jiutian"))
			return notify_fail( HIW "你正在舞「凤舞九天」！\n" NOR);

		if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("你使用的武器不对。\n");

		if ((int)me->query_skill("kurong-changong", 1) < 130)
			return notify_fail( HIW "你的枯荣禅功修为未到，无法施展「凤舞九天」。\n" NOR);

		if ((int)me->query_skill("feifeng-bian", 1) < 150) 
			return notify_fail( HIW "你的飞凤鞭法修为还不够，尚未领悟到「凤舞九天」。\n" NOR); 

		if (me->query("max_neili") <= 1000)
			return notify_fail( HIW "你的内力修为不足，劲力不足以施展「凤舞九天」！\n" NOR);
	   
		if ((int)me->query("neili", 1) < 500)
			return notify_fail( HIW "你现在内力不够，劲力不足以施展「凤舞九天」！\n" NOR);

		if (me->query("jingli") <= 300)
			return notify_fail( HIW "你的精力不足，无法施展「凤舞九天」！\n" NOR);

		if (me->query("combat_exp")*3 > target->query("combat_exp")*4) 
			return notify_fail( HIW "想用「凤舞九天」欺负弱小?不太好吧！\n" NOR);

		message_vision(MAG"$N向后纵身一跃，翩翩起舞，手中的"NOR+weapon->name()+NOR MAG"响起阵阵凤鸣，舞姿奇诡莫测，变化无端，宛如凤凰一般刹是好看。\n" NOR, me);

		if (random(me->query("per"))+8 > 20)
        {
		message_vision(HIR"突然$n一个失神，被$N的动作所吸引，顿感心旷神怡，心猿意马，被$N的舞姿迷的神魂颠倒！\n"NOR, me, target);
       	target->start_busy(random(5)+5);
		

		if (target->query_temp("weapon")) {
			weapon1 = target->query_temp("weapon");

			if (me->query("combat_exp") < random(target->query("combat_exp")*8/5)) {
				message_vision(HIW"$n手指一松，"NOR+weapon1->name()+NOR HIW"险些脱手！\n" NOR, me, target);
                }
				else {
			message_vision(HIW"$n手上一松，不由自主的丢下了"NOR+weapon1->name()+NOR HIW"！\n" NOR, me, target);
			weapon1->unequip();
			weapon1->move(environment(target));
			target->reset_action();
			}
		}
        extra = (int)me->query_skill("feifeng-bian",1);
        speed = extra/2 + random(extra/2);
        dodge = extra*3/4 + random(extra/2);
        damage = extra/3 + random(extra/2);
        parry = extra*3/4 + random(extra/5);

        me->add_temp("apply/dodge", dodge);
        me->add_temp("apply/speed", speed);
        me->add_temp("apply/damage", damage);
		target->add_temp("apply/parry", -parry);

		me->set_temp("jiutian", 25+extra/6);
		call_out("checking", 1, me, target, weapon, dodge, speed, damage, parry);

//		call_out("remove_effect", extra/8, me, target, dodge, speed, parry,);

                me->start_busy(1);
                me->add("neili", -250);
                me->add("jing", -50);
        if (me->is_fighting())
		me->start_busy(1)+1;
        }
        else
        {
		message_vision(RED"就看$n收敛心神，心如明镜，全神贯注，并未被$N的舞姿所迷。\n"NOR, me, target);
		me->start_busy(random(5)+2);
        }
        return 1;
}
//void remove_effect(object me, object target, int dodge int speed int parry)
//{
//		if (!me) return;
//		me->add_temp("apply/dodge", -dodge);
//		me->add_temp("apply/speed", -speed);
//		target->add_temp("apply/parry", parry);
//		me->delete_temp("jiutian");
//		message_vision(HIM "$N感觉到气血不顺，速度渐渐慢了下来。\n"NOR,me);
//}
//
void checking(object me, object target, object weapon, int dodge, int speed, int damage, int parry)
{
		if (!living(me) || me->is_ghost())
		{
			remove_effect(me, target, dodge, speed, damage, parry);
			return ;
		}
        if (me->query_temp("jiutian")) {
			if( !me->is_fighting() )
			{
				message_vision(HIY"\n$N向后一跳，收起了步伐。\n"NOR, me);
				remove_effect(me, target, dodge, speed, damage, parry);
				tell_object(me, HIM"\n你身形一止，速度慢了下来。\n\n"NOR);

				return;
			}
			else if (environment(weapon)!= me || weapon!=me->query_temp("weapon"))
			{
				message_vision(HIY"\n$N脚步一顿，停止了舞蹈。\n"NOR, me);
				remove_effect(me, target, dodge, speed, damage, parry);
				tell_object(me, HIM"\n你感觉到气血不顺，速度渐渐慢了下来。\n\n"NOR);

				return;
			}
			else if (weapon->query("weapon_prop") == 0)
			{
				message_vision(HIY"\n$N手中的"NOR+weapon->name()+NOR HIY"已毁，不得不停下脚步。\n"NOR, me);
				remove_effect(me, target, dodge, speed, damage, parry);
				return;
			}
			else if (me->query_skill_mapped("force") != "kurong-changong")
			{
				remove_effect(me, target, dodge, speed, damage, parry);
				tell_object(me, HIY"\n你感到内息不畅，不得不停下脚步。\n\n" NOR);
				return;
			}
		me->add_temp("jiutian", -1);
		call_out("checking", 1, me, target, weapon, dodge, speed, damage, parry);
		}
		else {
		remove_effect(me, target, dodge, speed, damage, parry);
		tell_object(me, HIM"\n你感觉到气血不顺，速度渐渐慢了下来。\n\n"NOR);
		}
}       

//private int remove_effect(object me, object target, int dodge, int speed, int damage, int parry)
void remove_effect(object me, object target, int dodge, int speed, int damage, int parry)
{
		if (!me) return;
		me->delete_temp("jiutian");
		me->add_temp("apply/dodge", -dodge);
		me->add_temp("apply/speed", -speed);
		me->add_temp("apply/damage", -damage);
		if (!target) return;
 		target->add_temp("apply/parry", parry);
}
