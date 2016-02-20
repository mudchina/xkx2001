//Cracked by Roath
// jingzuo.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int jingzuoing(object me);
int halt_jingzuo(object me);

int main(object me, string arg)
{
	int busy_time, pot_gain;
	int yuga_lvl;
	mapping fam;
	object where;

	seteuid(getuid());
	where = environment(me);

	if( !(fam = me->query("family")) || fam["family_name"] != "峨嵋派" )
		return notify_fail("静坐修练须有峨嵋同门守护，你非峨嵋弟子，不能行功。\n");
	
	if( !where->query("jingzuo_room") )
		return notify_fail("此处不宜静坐修练。\n");

	if( (yuga_lvl = me->query_skill("mahayana", 1)) < 20 ) 
		return notify_fail("你大乘涅磐法修为太低，不能行功修练。\n");

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中静修，找死啊？！\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制心魔静修。\n");

	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你现在体力不够，难以凝聚体能静修。\n");

	pot_gain = yuga_lvl/20 + random(5);
	pot_gain += random(yuga_lvl < 100 ? 6 : 8);
	busy_time = 30/pot_gain;
	pot_gain = 1 + random(pot_gain*2);
	busy_time *= pot_gain;
	if (me->query("food") + me->query("water") < 20) busy_time *= 2;
// printf("yual_lvl=%d, busy_time=%d, pot_gain=%d\n", yuga_lvl, busy_time, pot_gain);
	message_vision("$N盘膝坐下，闭上眼睛开始修练。\n", me);
	me->set_temp("pending/jingzuo", 1);
	me->set_temp("jingzuo/time", busy_time);
	me->set_temp("jingzuo/pot", pot_gain);
	me->start_busy((: jingzuoing :), (:halt_jingzuo:));
	return 1;
}

int jingzuoing(object me)
{
	int time = (int)me->query_temp("jingzuo/time");
	int pot_gain = (int)me->query_temp("jingzuo/pot");
	
	if( time < 1 ) return 0;
	me->set_temp("jingzuo/time", time-=2);

	if( random(12) == 5 )
	{
		me->update_condition();
		if( (int)me->query("water") > 0 ) me->add("water", -1);
		if( (int)me->query("food") > 0 ) me->add("food", -1);
	}

	if( time > 0 ) return 1;
	
	me->set_temp("pending/jingzuo", 0);

	message_vision("$N缓缓睁开眼睛，长舒一口气站了起来。\n", me);

	tell_object(me, HIC "你的潜能增加了" + chinese_number(pot_gain) + "点！\n" NOR);
		me->add("potential", pot_gain);
	if( me->query("potential") > me->query("max_potential") )
		me->set("potential", me->query("max_potential"));

	me->receive_heal("jing", me->query_con());
	me->receive_heal("qi", me->query_con());
	if( (int)me->query("jingli") < (int)me->query("max_jingli") )
		me->add("jingli", me->query_con());
	me->improve_skill("mahayana", 1+random(3*pot_gain));
}

int halt_jingzuo(object me) 
{
	me->set_temp("jingzuo/time", 0);
	me->set_temp("jingzuo/pot", 0);
	me->set_temp("pending/jingzuo", 0);
	return 1;
}
	

int help(object me)
{
        write(@HELP
指令格式 : jingzuo

静坐修练以提高人体的潜能。乃峨嵋派特有练功方式。
HELP
        );
        return 1;
}
