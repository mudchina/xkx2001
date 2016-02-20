//Cracked by Roath
// jue.c 「绝剑」
// xQin 10/99
// DEBUG by xQin 04/01
// modified by xiaojian May 22,2001

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me, int damage, int attack, int level,int busytime);
void check2(object me, int o_att, int o_dam, int o_spd);

int perform(object me, object target)
{
	object weapon;
	int busytime,larger;
	int acc_damage = 0;
	int acc_attack = 0;
	int i, level, attack, damage, o_att, o_dam, o_spd;

	weapon = me->query_temp("weapon");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		weapon = me->query_temp("secondary_weapon");	

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( me->query_skill("emei-jian", 1) < 200 )
		return notify_fail("你的峨嵋剑法修为还不够，还未领悟「绝剑」！\n");

	if( me->query_skill("linji-zhuang", 1) < 200 )
		return notify_fail("你的内功修为火候未到，施展「绝剑」只会伤及自身！\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「绝剑」只能对战斗中的对手使用。\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能运用「绝剑」？！\n");

	if( me->query_skill_mapped("force") != "linji-zhuang" )
		return notify_fail("你所用的内功与「绝剑」心法相悖！\n");

	if( (int)me->query_temp("miejue") )
                return notify_fail("你已经施展「灭绝神剑」！\n");

	level = me->query_skill("sword") / 75;
	busytime = 1+level/4+random(level/3);

	if( me->query("max_neili") <= level*500 )
		return notify_fail("你的内力修为不足，劲力不足以施展「绝剑」！\n");

        if( me->query("neili") <= level*80 )
                return notify_fail("你的内力不够，劲力不足以施展「绝剑」！\n");

        if( me->query("jingli") <= level*60 )
                return notify_fail("你的精力有限，不足以施展「绝剑」！\n");

	if( me->query_temp("perform/miejian") )
		return notify_fail("你正在运用「灭剑」心法！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢,没办法施展「绝剑」心法！\n");
	o_att = me->query_temp("apply/attack");
	o_dam = me->query_temp("apply/damage");
	o_spd = me->query_temp("apply/speed");


	damage = ( me->query_skill("force") + me->query("neili")/20 + me->query("max_neili")/5 )/20;
	attack = ( me->query_skill("dodge") + me->query("jingli")/20 + me->query("max_jingli")/5 )/20
		 + me->query_dex()/5 + weapon->query("apply/damage")/2;

	me->add_temp("apply/speed", level*5);
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", attack);
	
	if (busytime <= 4) {
		larger = 4;
		} else {larger = busytime;}
	me->start_call_out((:call_other, __FILE__, "check2", me, o_att, o_dam, o_spd:),larger);
	/*if( wizardp(me) ) tell_object( me,
		sprintf("old damage: %d, old attack: %d, old speed: %d \n",o_att,o_dam,o_spd));*/
	
	me->add_temp("perform/juejian", 1);	

	for( i=0; i < level; i++ )
	{
		if( wizardp(me) ) tell_object( me,
		sprintf("damage: %d, attack: %d, speed: %d\n",
		me->query_temp("apply/damage"), me->query_temp("apply/attack"),
		me->query_temp("apply/speed")));

		COMBAT_D->do_attack(me, target, weapon);

		me->add_temp("apply/damage", -damage/level);
		me->add_temp("apply/attack", -attack/level);
		if ((int)me->query_temp("apply/damage") < 0)
		{
			me->set_temp("apply/damage",0);
		}
		if ((int)me->query_temp("apply/attack") < 0)
		{
			me->set_temp("apply/attack",0);
		}
		acc_damage += damage/level;
		acc_attack += attack/level;
	}

	message_vision(HIY"\n这几下交手，当真是兔起鹬落，迅捷无伦，一刹那间$N连攻了"+
		chinese_number(level) +"下快招，招招是致命的凌厉毒著！！\n"NOR, me);

	me->add("neili", -level*70);
	me->add("jingli", -level*50);
	remove_effect(me,(damage-acc_damage),(attack-acc_attack),level,busytime);

	return 1;
}


void remove_effect(object me, int damage, int attack, int level,int busytime)
{
	if (!me) return;
		me->add_temp("apply/attack",-attack);
        me->add_temp("apply/damage",-damage);
        me->add_temp("apply/speed", -level*5);
	/*if( wizardp(me) ) tell_object( me,
		sprintf("after fight,damage: %d, attack: %d, speed: %d\n",damage,attack,level));*/
       	me->delete_temp("perform/juejian");
       	me->start_busy(busytime);
}


void check2(object me, int o_att, int o_dam, int o_spd)
{
	
	/*if( wizardp(me) ) tell_object( me,
		sprintf("begin to check apply stuff,now.\n"));*/
	if((int)me->query_temp("apply/attack",1) != o_att)
	{
		me->set_temp("apply/attack",o_att);
	}
	if((int)me->query_temp("apply/damage",1) != o_dam)
	{
		me->set_temp("apply/damage",o_dam);
	}
	if((int)me->query_temp("apply/speed", 1) != o_spd)
	{
		me->set_temp("apply/speed", o_spd);
	}


}