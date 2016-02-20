//Cracked by Roath
// shentong.c 先天功 纯阳神通功
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
		  int skill, value;

	//me = this_object();

	if( target == me)target=offensive_target(me);

	if( !target )target = offensive_target(me);
	if( !target )target = me->select_opponent();

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「纯阳神通功」只能对战斗中的对手使用。\n");


	if( (int)me->query("neili") < 1000  )
	{
		 return notify_fail("你的内力不够。\n");
	}

	if( (int)me->query_temp("shentong") )
					 return notify_fail("你已经在运功\中了。\n");
/*
	if( !target	||	!me->is_fighting() )
		return notify_fail("纯阳神通功只有在战斗中才能使用。\n");
*/

	if( me->query("shentong") < 60 )
		return notify_fail("你还未领悟和练成纯阳神通功！\n");

	if( me->query_skill("force") < 300 )
		return notify_fail("你的玄门先天功火候未到，无法施展纯阳神通功！\n");

	if( me->query_skill("taoism") < 90 )
		return notify_fail("你的道学心法火候未到，无法施展纯阳神通功！\n");



		  message_vision(
		  HIW "$N运起纯阳神通功，片刻之间，白气笼罩全身，双眼精光四射，身手分外矫健，进退神速，与平时判若两人。\n" NOR, me);
		  message_vision(
		  HIG "\n你不禁诧异，难道这就是王重阳独步武林，打遍天下无敌手的不传绝技：纯阳神通功。据说当年连全真七子和周伯通也没练成。\n" NOR, me);

		  skill = me->query_skill("force");
		  me->add("neili", -skill*3);

   	 	  me->set("jiali",0);
		  value = skill * random(me->query("shentong")*5);
		  if( value > 90000 ) value = 90000;
		  if( value < 30000 ) value = 30000;
//	disabled adding jingli since player exploiting this to add max jingli
		  me->add( "jingli",value  );
		  me->add_temp( "apply/attack",value/500  );
		  me->set_temp("shentong", 1);


		  if( me->is_fighting() ){
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->start_busy(1+random(3));
		  }

		  me->add( "jingli", -value );
		  me->add_temp( "apply/attack",-value/500  );
		  me->delete_temp("shentong", 1);

		  return 1;
}
