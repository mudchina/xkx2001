//Cracked by Roath
// reverse.c 
// cyz 2000.02.16
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me,object target)
{
	if (target != me)
		return notify_fail("枯荣心法对他人毫无作用！\n");

	if (!(me->query_temp("kurong")))
		return notify_fail("你并未运转枯荣心法。\n");

	if (me->query_skill("kurong-changong",1) < 100
		|| me->query_skill("force",1) < 100
		|| me->query_skill("buddhism",1) < 100 )
		return notify_fail("你的尚未参通枯荣禅，强行逆运枯荣心法毫无益处！\n");

	if (me->query("max_neili")<2000
		|| me->query("neili") < me->query("max_neili")/10)
		return notify_fail("你的内力不够逆运枯荣心法！\n");

 	
	message("vision", HIW "\n"+me->query("name")+"双掌合十，气息流转下，一张脸片刻间变得红通通的！再片刻，又回复正常的模样。\n\n" NOR, environment(me), me);
	tell_object(me, HIW "\n你双掌合十，逆运枯荣心法，脸上一荣一枯闪现，片刻即回复正常。\n\n" NOR);

	me->delete_temp("kurong");

	me->add("neili", -100);

	return 1;
}
