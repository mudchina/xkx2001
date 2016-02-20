//Cracked by Roath
// jingang.c 金刚神通

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
	int original, skill;

	if( objectp(target) && target != me ) 
		return notify_fail("你只能用金刚神通来提升自己的战力。\n");

	if( !me->is_fighting() ) 
		return notify_fail("你必须在战斗中才能使用金刚神通！\n");

	if( me->query_temp("weapon") )
		return notify_fail("你只能在空手时使用金刚神通！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 60 )
		return notify_fail("你的混元一气功火候未到，无法施展金刚神通！\n");

	if( me->query_skill("jingang-quan", 1) < 90 )
		return notify_fail("你的金刚拳火候未到，无法施展金刚神通！\n");

	if( me->query("max_neili") <= 600 )
		return notify_fail("你的内力修为不足，劲力不能运发，无法施展金刚神通！\n");

	if( (int)me->query("neili") < 600  )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("你已经发动了金刚神通！\n");

	skill = me->query_skill("jingang-quan", 1);
	original = me->query_str();

	me->add("neili", -skill*2);
	me->receive_damage("jingli", skill);

	message_vision(
	HIY "\n$N双手合十念佛，刹那间四周地动山摇，发出隆隆巨响！ $N的身形顿然长大了许多倍，如一尊金刚般屹立起来！\n\n" NOR, me);

	me->add_temp("apply/strength", original*3);

	me->set_temp("jingang", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, original :), skill/6);
//	me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/strength", - 3*amount);

	me->delete_temp("jingang");

	tell_object(me, "你缓缓吸了一口气，收回金刚神通，身形又恢复了原状。\n");
}
