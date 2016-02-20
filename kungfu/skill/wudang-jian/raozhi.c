//Cracked by Roath
// raozhi.c 「绕指柔剑」
// xQin 10/98

/*
这路「绕指柔剑」全仗以浑厚内力逼弯剑刃，使剑招闪烁无常，敌人难以挡架。
殷天正从未见过这等剑法，急忙沉肩相避，不料铮的一声轻响，那剑反弹过来，
直刺入他左手上臂。
*/

#include <ansi.h>
void remove_effect(object me, object weapon, int sword, int force);

int perform(object me)
{
	int force, sword;
	object weapon = me->query_temp("weapon");
	string shape = weapon->query("id");

	if( !me->is_fighting() )
		return notify_fail("「绕指柔剑」只能在战斗中使用。\n");

	if( !me->query("wudang/raozhi") )
		return notify_fail("你未得高人指点，不知该如何施展「绕指柔剑」。\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能使出「绕指柔剑」？！\n");

	if( me->query_temp("yield") )
		return notify_fail("你不出剑，如何使出「绕指柔剑」？\n");

	if( me->query_temp("wudang/raozhi") )
		return notify_fail("你已经将内力贯注入剑中了！！\n");

	if( me->query_skill_mapped("force") != "wudang-jiuyang" )
		return notify_fail("你所用的内功与「绕指柔剑」心法相悖！\n");

	if( me->query_skill("sword") < 200 )
		return notify_fail("你的剑法修为还不够，难以施展「绕指柔剑」！\n");

	if( me->query_skill("force") < 200 )
		return notify_fail("你的内功修为火候未足，无法以内力逼弯剑刃！\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("你的内力不够浑厚，劲力不足以逼弯剑刃！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的内力不够，劲力不足以逼弯剑刃！\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("你的体力有限，难以施展「绕指柔剑」！\n");

	if( shape == "xuantie jian" )
		return notify_fail("你所持之剑质地过於坚硬，难以用内力将其逼弯！\n");

	if( shape == "tie di" || shape == "tie xiao" || shape == "zhu xiao"
	 || shape == "yu xiao")
		return notify_fail("箫笛形状不适合施展「绕指柔剑」！\n");

	if( shape == "xiuhua zhen" || shape == "qijue zhen" || shape == "emei ci"
	 || shape == "duanjian" || shape == "bishou" )
		return notify_fail("你所持之剑太短，不适合施展「绕指柔剑」！\n");

	me->add("neili", -100);
	me->add("jingli", -150);

	if( (string)weapon->query("material") != "steel" )
	{
		message_vision(HIW "\n猛地里$N一声清啸，剑法忽变。可是手中"+ weapon->name() 
			+HIW"却已经不住内力冲击，裂成碎片！！\n"NOR, me);
		destruct(weapon);
		me->set_temp("apply/damage", 0);
		me->reset_action();
		me->start_busy(1);

		return 1;
	}

	force = me->query_skill("force")/2;
	sword = me->query_skill("sword")/3;

	weapon->add("rigidity", force);
	me->add_temp("apply/attack", sword);
	me->set_temp("wudang/raozhi", sword);

	message_vision(HIG "\n猛地里$N一声清啸，剑法忽变，那柄"+ weapon->name()
		+HIG"竟似成了一条软带，轻柔曲折，飘忽不定。\n正是武当派绝技"+
		HIW +"「绕指柔剑」"+ HIG +"！\n"NOR, me);

	call_out("checking", 1, me, weapon, sword, force);
	return 1;
}

void checking(object me, object weapon, int sword, int force)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, weapon, sword, force);
		return;
	}
	else if( !me->is_fighting() && !me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(HIG "\n$N伸指在剑脊上轻轻一弹，只听得"
			+ weapon->name() + HIG"振起嗡嗡之响，剑身不停抖动。\n"+NOR
			CYN+"$N顺势挽起一个剑花，将剑势收回。\n"NOR, me);
		me->start_busy(1);
		return;
	}
	else if( environment(weapon) != me || weapon != me->query_temp("weapon") )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(HIR "\n$N放弃手中"+ weapon->name() +HIR"，将剑势收回！\n"NOR, me);
		return;
        }
	else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
		(int)me->query("jingli") < (int)me->query("max_jingli") / 4 )
	{
	        remove_effect(me, weapon, sword, force);
        	tell_object(me, HIR "\n你微觉内息不畅，不得不将内力收回！\n" NOR);
		message("vision", CYN+"\n"+ me->name() + weapon->name() +CYN
			"圈转，收回剑势。招数已不如之前闪烁无常，变幻不定！\n"NOR, environment(me), me);
		me->start_busy(2);
		return;
	}
	else if( me->query_skill_mapped("sword") != "wudang-jian" && !me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(CYN "\n$N圈转" + weapon->name()+ CYN
			"，突然变招，使出与"+ HIW +"「绕指柔剑」"+ NOR + CYN"不同的剑法！\n"NOR, me);
		return; 
	}
	else if( me->query_temp("wudang/raozhi") <= 50 )
	{
		remove_effect(me, weapon, sword, force);
		message_vision(HIC "\n$N" + weapon->name()+ HIC
			"圈转，已堪堪将一路"+ HIW +"「绕指柔剑」"+ HIC +"尽数使出！\n"NOR, me);
		return; 
	}

	call_out("checking", 1, me, weapon, sword, force);
} 

void remove_effect(object me, object weapon, int sword, int force)
{
	me->delete_temp("wudang/raozhi");
	me->add_temp("apply/attack", -sword);
	weapon->add("rigidity", -force);
}
