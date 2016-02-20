//Cracked by Roath
// tiandi.c
// xuy 09/22/96

#include <ansi.h>

int exert(object me, object target)
{
	int level = me->query_skill("linji-zhuang", 1);

	if (level < 30) return notify_fail("你的临济十二庄修为还不够。\n");

	if( (int)me->query("max_neili") < 5*level ) 
		return notify_fail("你的内力还不够强。\n");

	if( (int)me->query("neili") < 4*level ) 
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	
	if ( me->query_temp("linji/tiandi") )
		return notify_fail("你已经运用天地二庄聚精气于身了。\n");

	me->set_temp("linji/tiandi", 1);
	write( HIY "你席地而坐，五心向天，运行天地二庄，益气升阳，益阴潜阳，升降反正，天地二气交泰于身，顿觉自己精气上限增加了。\n" NOR);
	message("vision",
		HIY + "只见" + me->name() + "席地而坐，五心向天，脸上红光时隐时现，不一会儿便神采弈弈地站了起来。\n" NOR,
		environment(me), me);

	me->add("max_qi", level);
	me->add("max_jing", level);
	me->add("max_jingli", level);
	me->receive_curing("qi", level);
	me->receive_curing("jing", level);
	me->receive_heal("jingli", level);
	me->add("neili", -4*level);
	me->set("jiali", 0);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, level :), 1800);

	return 1;
}

void remove_effect(object me, int level)
{
	me->add("max_qi", -level);
	me->add("max_jing", -level);
	me->add("max_jingli", -level);
	if ((int)me->query("eff_qi") > (int)me->query("max_qi") )
		me->set("eff_qi", (int)me->query("max_qi") );
	if ((int)me->query("eff_jing") > (int)me->query("max_jing") )
		me->set("eff_jing", (int)me->query("max_jing") );
	me->delete_temp("linji/tiandi");

	tell_object(me, HIG"你所聚天地之精气已散回天地之间，你又恢复了原有精气。\n"NOR);
}
