//Cracked by Roath
// daxiao.c
// xuy 4/22/97

#include <ansi.h>

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);
	int amount;

	if (level < 150) return notify_fail("你的临济十二庄修为还不够。\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("你的内力还不够强。\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	
	if ( me->query_temp("linji/daxiao") )
		return notify_fail("你已经运功调节精气大小了。\n");

	me->set_temp("linji/daxiao", 1);
	write( HIY "你屏息静气，交错运行大小二庄，只觉一股暖流出天门，穿地户，沿着全身经脉运行一周，汇入丹田气海。\n" NOR);
	message("vision",
		HIY + "只见" + me->name() + "屏息静气，头顶飘起一缕缕白气，神态略现疲乏。\n" NOR,
		environment(me), me);

	amount = me->query("max_jing") - me->query("max_qi");
	if (amount < 0) amount = 0;

	amount = amount*level/400;

	me->add("max_qi", amount);
	me->add("max_jing", -amount);
	me->receive_curing("qi", amount);
	if ( (int)me->query("eff_jing") > (int)me->query("max_jing") ) 
		me->set("eff_jing", (int)me->query("max_jing") );
	me->add("neili", -4*level);
	me->set("jiali", 0);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, amount :), 1800);

	return 1;
}

void remove_effect(object me, int level)
{
	me->add("max_qi", -level);
	me->add("max_jing", level);
	if ((int)me->query("eff_qi") > (int)me->query("max_qi") )
		me->set("eff_qi", (int)me->query("max_qi") );
	me->receive_curing("jing", level);
	me->delete_temp("linji/daxiao");

	tell_object(me, HIG"你行大小二庄已久，又恢复了原有精气。\n"NOR);
}
