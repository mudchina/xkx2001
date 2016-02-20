//Cracked by Roath
//kurong.c 枯荣心法

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("枯荣心法对他人毫无作用！\n");

	if (me->query_temp("kurong"))
		return notify_fail("你已在运转枯荣心法了。\n");

	if (me->query_skill("kurong-changong",1) < 100
		|| me->query_skill("force",1) < 100
		|| me->query_skill("buddhism",1) < 100 )
		return notify_fail("你的尚未参通枯荣禅，强运枯荣心法毫无益处！\n");

	if (me->query("max_neili")<2000
		|| me->query("neili") < me->query("max_neili")/10)
		return notify_fail("你的内力不够运转枯荣心法！\n");

 	skill=me->query_skill("kurong-changong",1)+me->query_skill("buddhism",1);

	message("vision", HIW "\n"+me->query("name")+"双掌合十，气息流转下，一张脸片刻间变得血肉全无只剩枯骨！再片刻，又回复血肉充盈的模样。\n\n" NOR, environment(me), me);
	tell_object(me, HIW "\n你双掌合十，运转枯荣心法，一股真气自丹田而生，沿心脉流转不息，脸上一枯一荣闪现，片刻即回复正常。\n\n" NOR);

	me->set_temp("kurong", skill*4*me->query("max_neili")/2000);

	remove_call_out("checking");
	call_out("checking", 1, me);
	me->add("neili", - me->query("max_neili")/10);

	return 1;
}

void checking(object me)
{	
	int maxqi, amount;
	
	remove_call_out("checking");
	reset_eval_cost();
	
	if (!me->query_temp("kurong")) {
		tell_object(me, HIW "你感到丹田真气混浊，运转的枯荣心法渐渐散去。\n" NOR);
		return;
	}

	if (!me->is_fighting()) {
		if (me->query_temp("kurong")<=50)
			me->delete_temp("kurong");
		else me->add_temp("kurong",-50);
	}

	maxqi=me->query("eff_qi");

	if (me->is_ghost()) {
		me->delete_temp("kurong");
		return;
	}

	if (living(me) && (maxqi < me->query("max_qi")*95/100 && me->query("neili") > 150)) {
		amount=(me->query_skill("kurong-changong",1)+me->query_skill("buddhism",1))/5+10;
		me->add("neili", -50);
		me->receive_curing("qi", amount);
        message_vision("$N深深吸了几口气，气息流转下伤口的血流自动止住了。\n", me);
	}

	if (living(me) && (me->query("qi") < (maxqi*2/3))) {
		amount = maxqi - me->query("qi");
		if (amount > me->query_temp("kurong")) amount=me->query_temp("kurong");
		me->add_temp("kurong",-amount);
        me->receive_heal("qi", amount);
        message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);
	}

	call_out("checking", 1, me);
	return;
}	
