// wuqing.c 美女拳-古墓幽居
// by liu 24/07/2001
// Xuanyuan 5/9/2001修改

/*
杨过悄退数步，坐到小龙女身畔，右手支颐，左手轻轻挥出，长叹一声，脸现寂
寥之意。这是“美女拳法”最后一招的收式，叫作“古墓幽居”，却是杨过所自
创，林朝英固然不知，小龙女也是不会。杨过掌年学全了美女拳法之后，心想祖
师婆婆姿容德行，不输于古代美女，武功之高更不必说，这路拳法中若无祖师婆
婆在，算不得有美皆备，于是自行拟了这一招，虽说为抒写林朝英而作，举止神
态却是模拟了师父小龙女。当日小龙女见到，只是微微一哂，自也不会跟着他去
胡闹。
*/

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object ob;
	string msg;
	int damage,jiali,jiajin;

	jiali = (int)me->query("jiali");
	jiajin= (int)me->query("jiajin");

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("玉女无情只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须先放下手中的兵器！\n");
/*
	if( me->query_temp("yield") )
		return notify_fail("你不出手，如何使得出古墓幽居？\n");

	if( !target->query_temp("luowang") )
		return notify_fail("对手的原神还在，不能施展古墓幽居！\n");
*/
        if( (int)me->query_skill("cuff", 1) < 120 )
                return notify_fail("你的美女拳修为不够，不会使用古墓幽居。\n");

        if( (int)me->query_skill("force", 1) < 120 )
                return notify_fail("你的内功还未娴熟，不能用古墓幽居。\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return notify_fail("你所用的并非玉女心经，使不出古墓幽居！\n");

        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("你现在内力太弱，不能使用古墓幽居。\n");

        if( (int)me->query("jingli", 1) < 500 )
                return notify_fail("你现在精力太弱，不能使用古墓幽居 n。\n");

	if( jiali > 50 )
	return notify_fail("古墓幽居乃是上乘内家功夫，掌上加带内力太多无法使出。\n");

	msg = HIB "\n$N悄退数步似要坐倒，右手支颐，左袖轻轻向$n挥出，长叹一声，脸现寂寥之意。\n\n"NOR;

	msg += HIY"这是“美女拳法”最后一招的收式，叫作“古墓幽居”，却是杨过所自创，林朝英固然\n";
	msg += HIY"不知，即便是小龙女也是不会。当年杨过掌年学全了美女拳法之后，心想祖师婆婆姿容\n";
	msg += HIY"德行不输于古代美女，武功之高更不必说，这路拳法中若无祖师婆婆在，算不得有美皆\n";
	msg += HIY"备，于是自行拟了这一招，虽说为抒写林朝英而作，举止神态却是模拟了师父小龙女。\n\n";

  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/2 ) || !living(target) )
  {
	damage = random(  me->query_skill("force") + me->query_skill("cuff") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
	if(damage > 2000) damage = 2000;
	if(damage < 600) damage = 600;
	me->add("neili", -damage/2 );
	me->add("jingli", -me->query("jiajin")/2);

	target->receive_damage("qi", damage,  me);
	target->receive_wound("qi", random(damage), me);
	target->start_busy(0);

	if ( damage < 800) {
		msg += HIR"只听噗的一声，$n被一拳击中小腹，内血翻涌喷口而出。\n"NOR;
	}else if ( damage < 1400) {
		msg += HIR"只听砰、砰两声，$n左眼发青、右眼发紫，狼狈不堪。\n"NOR;
	}else if ( damage < 2000) {
		msg += HIR"结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
	}else {
		msg += RED"只听砰、砰、砰、砰几声巨响，$n被打得骨骼碎裂飞了出去。\n"NOR;
	}
	msg += NOR;
	me->start_busy(2+random(2));
	}
	else {
	msg += HIG"$n灵光一现，纵身跃起，本能的反应辟开了$N的衣袖。\n\n"NOR;
	me->add("neili", -jiali*2 );
	me->add("jingli", -me->query("jiajin") );
	me->start_busy(2 + random(3));
	message_vision(msg+"\n", me, target);
	return 1;
  }

	message_vision(msg+"\n", me, target);
	COMBAT_D->report_status(target);
	return 1;
}
