//Cracked by Roath
// liangyi.c 「两仪剑法」
// xQin 5/99

#include <ansi.h>
inherit F_SSERVER;

int remove_effect(object yin, object yang, int amount);

int perform(object me, object target)
{
	object yin, yang, victim, sword1, sword2;
	int skill1, skill2, amount;
	string ji;

	if( me->query("wudang/liangyi") == "yin" )
		yin = me;
	else if( me->query("wudang/liangyi") == "yang" )
		yang = me;
	else return notify_fail("你尚未学会「两仪剑法」。\n");

	sword1 = me->query_temp("weapon");
	if( !objectp(sword1) || (string)sword1->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能进行两仪合璧？\n");

	if( me->query_skill_mapped("sword") != "wudang-jian" )
		return notify_fail("你所使并非武当剑法，无法进行两仪合璧！\n");

	if( me->query_temp("wudang/raozhi") )
		return notify_fail("你正在施展「绕指柔剑」，无法同时使出「两仪剑法」！\n");

	if( me->query_temp("yield") )
		return notify_fail("你不出剑，如何进行两仪合璧？\n");

	if( !target )
		return notify_fail("你必须找一个人来两仪合璧。\n");

	if( target == me )
		return notify_fail("与自己两仪合璧？可惜你不会左右互搏。\n");

	if( !target->query("wudang/liangyi") )
		return notify_fail(target->name() +"尚未学会「两仪剑法」。\n");

	ji = me->query("wudang/liangyi")=="yin"?"阳":"阴";
	if( objectp(yin) && target->query("wudang/liangyi") == "yang" )
		yang = target;
	else if( objectp(yang) && target->query("wudang/liangyi") == "yin" )
		yin = target;
	else return notify_fail(target->name() +"不会施展「两仪剑法」中的"
		+ ji +"极，无法与你两仪合璧。\n");

	sword2 = target->query_temp("weapon");
	if( !objectp(sword2) || (string)sword2->query("skill_type") != "sword" )
		return notify_fail(target->name() +"手中无剑，无法与你两仪合璧！\n");

	if( target->query_skill_mapped("sword") != "wudang-jian" )
		return notify_fail(target->name() +"所使并非武当剑法，无法与你两仪合璧！\n");

	if( target->query_temp("wudang/raozhi") )
		return notify_fail(target->name() +
		"正在施展「绕指柔剑」，无法同时使出「两仪剑法」！\n");

	if( target->query_temp("yield") )
		return notify_fail(target->name() +"不想与你两仪合璧。\n");

	if( me->is_fighting(target) )
		return notify_fail("你正与"+ target->name() +"相互切磋中，无法进行两仪合璧。\n");

	skill1 = yin->query_skill("sword");
	skill2 = yang->query_skill("sword");
	amount = ( skill1 + skill2 ) / 8;

	if( skill1*4/5 > skill2 || skill2*4/5 > skill1 )
		return notify_fail("你与"+ target->name() +"的剑法相差太远，无法进行两仪合璧。\n");

	if( me->is_fighting() )
	{
		victim = offensive_target(me);
		if( !target->is_fighting(victim) )
			return notify_fail(target->name() +"并未和你一齐与"
			+ victim->name() +"搏斗。\n");
	}
	else if( target->is_fighting() )
	{
		victim = offensive_target(target);
		if( target->is_killing(victim->query("id")) )
			me->kill_ob(victim);
		else
			me->fight_ob(victim);
	}
	else return notify_fail("「两仪剑法」只能在战斗中进行合璧。\n");

	if( (string)me->query_temp("wudang/ly_partner") == (string)target->query("name") &&
		(string)target->query_temp("wudang/ly_partner") == (string)me->query("name") &&
			me->query_temp("wudang/ly_count") == 1 && skill1 >= 250 &&
		 		target->query_temp("wudang/ly_count") == 1 && skill2 >= 250 )
	{
		message_vision(HIY"\n忽听得$N与$n齐声呼啸，剑法大变，$N"
		+ yang->query_temp("weapon")->name() +HIY
		"大开大阖，势道雄浑，$n疾趋疾退，剑尖上幻出点点寒星。\n"NOR, yang, yin);

		yin->delete_temp("wudang/ly_yin");
		yin->set_temp("wudang/ly_count", 2);
		yin->add_temp("apply/attack", amount);
		yin->add_temp("apply/defense", amount);

		yang->delete_temp("wudang/ly_yang");
		yang->set_temp("wudang/ly_count", 2);
		yang->add_temp("apply/defense", amount);
		yang->add_temp("apply/attack", amount);

		remove_call_out("checking");
		call_out("checking", 1, yin, yang, amount);
		return 1;
	}

	if( me->query_temp("wudang/ly_partner") )
		return notify_fail("你正在与"+ (string)me->query_temp("wudang/ly_partner") +
		"两仪合璧。\n");

	if( target->query_temp("wudang/ly_partner") )
	{
		if( (string)target->query_temp("wudang/ly_partner") == (string)me->query("name") )
			return notify_fail(target->name() +"正在与你两仪合璧。\n");
		else
			return notify_fail(target->name() +"正在与"
			+ (string)target->query_temp("wudang/ly_partner") +"两仪合璧。\n");
	}

	message_vision(HIW"\n$N东刺一剑、西劈一剑的练了起来，使得三四下，忽然忘记了，搔头凝思，又使了几招。\n"
	BLK"$n"+ yin->query_temp("weapon")->name() +HIW+BLK+
	"在手，便即乱劈乱刺，出手极快，犹如发疯一般。\n"NOR, yang, yin);

	yin->set_temp("wudang/ly_partner", yang->name());
	yang->set_temp("wudang/ly_partner", yin->name());

	yin->set_temp("wudang/ly_yin", 1);
	yang->set_temp("wudang/ly_yang", 1);

	yin->add_temp("apply/parry", amount/3);
	yin->add_temp("apply/dodge", amount/3);
	yin->add_temp("apply/speed", amount);
	yin->add_temp("apply/damage", -amount*3/4);
	yang->add_temp("apply/parry", amount/3);
	yang->add_temp("apply/dodge", amount/3);
	yang->add_temp("apply/damage", amount);
	yang->add_temp("apply/speed", -amount*3/4);

	yang->add_temp("wudang/yang_att", 1);
	COMBAT_D->do_attack(yang, victim, yang->query_temp("weapon"));
	yang->delete_temp("wudang/yang_att");

	call_out("checking", 1, yin, yang, amount);
	return 1;
}

int checking(object yin, object yang, int amount)
{
	int i, num = 0;
	object victim = offensive_target(yin);

	if( !yin->is_fighting() && !yang->is_fighting() ) 
	{
		remove_effect(yin, yang, amount);
		message_vision(HIG"\n$N与$n同时向后纵出，便如两头大鸟一般，稳稳的飞出数丈之外。\n"NOR, yang, yin);
		return 0;
	}
	if( yin->query_temp("wudang/ly_yin") &&
		(yin->query_temp("wudang/ly_yin") == 2 || random(5) == 1) )
	{
		num = 2+random(2);
		for( i=1; i <= num; i++ )
                	COMBAT_D->do_attack(yin, victim, yin->query_temp("weapon"));
		message_vision(HIW+BLK"\n$N提起剑来一阵乱刺乱削，刹那间接连劈了"+chinese_number(num)+"剑。\n"NOR, yin);
        }
	if( yin->query_temp("wudang/ly_yin") == 3 )
	{
		yin->set_temp("wudang/ly_count", 1);
		yang->set_temp("wudang/ly_count", 1);
		message_vision(YEL"\n$N与$n的剑招一个迟缓，一个迅捷，可是剑法中破绽之少，实所罕见。\n"
		"二人的姿式固是难看之极，但剑招古朴浑厚，剑上的威力似乎只发挥得一二成，其余的却是蓄势以待，深藏不露。\n"NOR, yang, yin);
	}
	if( yin->query_temp("wudang/ly_yin") == 5 )
		message_vision(WHT"\n$N与$n出招攻击之时虽仍一个呆滞，一个癫狂，但当闪避招架之际，身手却轻灵沉稳，兼而有之。\n"NOR, yang, yin);

	if( yin->query_temp("wudang/ly_yin") )
		yin->add_temp("wudang/ly_yin", 1);
	if( yang->query_temp("wudang/ly_yang") )
		yang->add_temp("wudang/ly_yang", 1);

	call_out("checking", 1, yin, yang, amount);
	return 1;
}

int remove_effect(object yin, object yang, int amount)
{
	if( yin->query_temp("wudang/ly_count") == 2 )
	{
		yin->add_temp("apply/attack", -amount);
		yin->add_temp("apply/defense", -amount);
	}
	if( yang->query_temp("wudang/ly_count") == 2 )
	{
		yang->add_temp("apply/defense", -amount);
		yang->add_temp("apply/attack", -amount);
	}

	if( yin->query_temp("wudang/ly_yin") )
		yin->delete_temp("wudang/ly_yin");
	if( yang->query_temp("wudang/ly_yang") )
		yang->delete_temp("wudang/ly_yang");

	yin->add_temp("apply/parry", -amount/3);
	yin->add_temp("apply/dodge", -amount/3);
	yin->add_temp("apply/speed", -amount);
	yin->add_temp("apply/damage", amount*3/4);
	yang->add_temp("apply/parry", -amount/3);
	yang->add_temp("apply/dodge", -amount/3);
	yang->add_temp("apply/damage", -amount);
	yang->add_temp("apply/speed", amount*3/4);

	yin->delete_temp("wudang/ly_count");
	yin->delete_temp("wudang/ly_partner");
	yang->delete_temp("wudang/ly_count");
	yang->delete_temp("wudang/ly_partner");
}