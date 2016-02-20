//Cracked by Kafei
// qufu.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int sp, dp, i;

	if( !target ) target = offensive_target(me);

       	if(me->query("lingjiu/shengsi")!=1)
			    return notify_fail("你虽听过生死符的名字，但是不懂得如何催动内力解符。\n");

	if( !objectp(target) || target == me 
	|| target->query("id") == "mu ren" 
	|| target->query("id") == "shangshan" 
	|| target->query("id") == "mengzhu" 
	|| target->query("id") == "fae" )
                return notify_fail("你要驱谁身上的生死符？\n");

//	if( !userp(target) )
//		return notify_fail("你只能驱谁玩家身上的生死符。\n");

	if ((int)me->query_skill("xiaowu-xiang", 1)<150
		&& (int)me->query_skill("bahuang-gong", 1)<150
		&& (int)me->query_skill("beiming-shengong", 1)<150)
		return notify_fail("你的逍遥派内功功力不够，不能驱生死符！\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n");	

        if( (int)me->query_skill("liuyang-zhang",1) < 150 )
                return notify_fail("你的天山六阳掌功力不够，不能种生死符！n");
                
        if ( me->query_skill_mapped("strike") != "liuyang-zhang")
                return notify_fail("你没有备天山六阳掌！\n"); 

	if( me->is_fighting() || target->is_fighting() )

		return notify_fail("战斗中不能驱生死符！\n");

	if( !target->query("zf")) 
		return notify_fail("此人没有被种下生死符！\n");

	if( (int)me->query("neili",1) < 1000 )
		return notify_fail("你的内力不够，不能驱生死符。\n");

	if( target->query("zf_lv") > me->query_skill("bahuang-gong",1) )
		return notify_fail("你的八荒六合唯我独尊神功低于种符之人，驱不了生死符！\n");

	message_vision(
		HIR "$N双掌紧贴$n的后背，渐渐运功，不一会儿两人头顶各冒出一股白气．\n\n" NOR,
		me, target );
                tell_object(target, HIR "你只觉胸口舒畅许多，一阵热气直入肺腑，脑中也清纯了很多！\n" NOR);
		tell_object(me, HIG "你觉得掌间的热力流入" + target->name() + "的后心，连续发力冲遍全身，慢慢的把生死符驱除了。\n" NOR);
	
		target->delete("zf");
                target->apply_condition("zf_poison",0);
		target->delete("zf_lv");
		
		me->add("max_neili",-30);

		me->start_busy(random(10));
//		target->add("jingli", -random(50));
		target->start_busy(random(3));
		me->add("neili", -200);
		me->add("jingli", -50);

		return 1;
}


