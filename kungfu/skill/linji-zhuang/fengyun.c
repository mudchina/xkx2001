//Cracked by Roath
// fengyun.c
// xuy 4/22/97

#include <ansi.h>

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);

	if (level < 120) return notify_fail("你的临济十二庄修为还不够。\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("你的内力还不够强。\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	
	if ( me->query_temp("linji/fengyun") )
		return notify_fail("你此时四肢百骸真气鼓荡，不必再次运功。\n");

	me->set_temp("linji/fengyun", 1);
	write( HIY "你暗运风云两庄，心思浮云飘空之悠闲缓慢，默想狂风荡地之迅速紧急，\n一股丹田热气分注四肢百骸，但觉身手敏捷了许多。\n" NOR);
	message("vision",
		HIY + "只见" + me->name() + "微闭双眼，身旁凝起一圈白雾，瞬息间一股旋风卷过，"+me->name()+"身形又复清晰。\n" NOR,
		environment(me), me);

	me->add("neili", -level);
	level /= 10;
	me->add_temp("apply/dexerity", level);
	me->add_temp("apply/attack", -level);
	me->set("jiali", 0);

	me->start_call_out( (: call_other, __FILE__, "recover", me, level :), 500);

	return 1;
}

void recover(object me, int level)
{
	me->add_temp("apply/dexerity", -level);
	me->add_temp("apply/attack", level);
	me->delete_temp("linji/fengyun");

	tell_object(me, HIG"你风云行功已久，略觉步履沉重了一些。\n"NOR);
}
