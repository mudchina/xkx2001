//Cracked by Roath
//Cracked by Kafei
// attack.c 
// arthurgu 1999/10

#include <ansi.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int exert(object me, object target)
{
	object weapon, ob;
    string msg, string1;
    int count;
 
    if( !me->is_fighting() )
	    return notify_fail("你不在战斗中。\n");

	if((int)me->query_int() < 27)
		return notify_fail("你的悟性不够, 目前还不能使用这项绝技! \n");

	if((int)me->query_skill("douzhuan-xingyi",1) < 100)
		return notify_fail("你的内功的修为不够, 不能使用这一绝技 !\n");

	if((int)me->query_skill("literate",1) < 80)
		return notify_fail("你的学问太低, 无法正确使用此功！\n");
 
    if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

     if( me->query("family/family_name") != "姑苏慕容" )
                return notify_fail("你不是慕容弟子，无法使用此功！\n");

     message("vision", HIW "\n"+me->query("name")+"长吸一口气，运转斗转星移神功，将对手的攻击尽数引向其身，俨然是姑苏慕容的“以彼之道，还施其身”！\n" NOR, environment(me), me);
        tell_object(me, HIR "你运转斗转星移神功，将对手的攻击引向他自身！\n" NOR);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(ob, ob, ob->query_temp("weapon"), 0);
	COMBAT_D->do_attack(ob, ob, ob->query_temp("weapon"), 0);
	

	me->add("neili", -200);
	me->start_busy(random(3));

    return 1;
}