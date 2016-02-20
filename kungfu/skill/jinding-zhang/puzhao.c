//Cracked by Roath
// 佛光普照
// sdong 11/11/98

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
  object ob;
  string msg;
  int damage;
  int finger, skill, jiali, my_rate, your_rate;

  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() ||  !me->is_fighting(target) )
	 return notify_fail("佛光普照只能在战斗中用。\n");

  if( target->query("eff_qi") < target->query("max_qi")/4 )
	 return notify_fail("你的对手已是伤痕累累，使用佛光普照有违佛家慈悲为怀的本意。\n");

  if( target->query("qi") < target->query("max_qi")/6 )
	 return notify_fail("你的对手已是伤痕累累，使用佛光普照有违佛家慈悲为怀的本意。\n");

  if( me->query_temp("yield") )
	 return notify_fail("你不出手，如何使得出佛光普照？\n");


  if( (skill = (int)me->query_skill("jinding-zhang", 1)) < 150 )
	 return notify_fail("你的金顶绵掌不够娴熟，不会使佛光普照。\n");

  if( (int)me->query_skill("linji-zhuang", 1) < 120 )
	 return notify_fail("你的临济桩功修为不够，不会使用佛光普照。\n");

  if( me->query_skill_mapped("force") != "linji-zhuang" )
	 return notify_fail("你所用的并非临济桩，使不出佛光普照！\n");

  jiali=(int)me->query("jiali");
  if( jiali < 50 )
	 return notify_fail("佛光普照乃是内家功夫，掌上不带内力使不出来。\n");

  if( me->query("neili") < 300 ) return notify_fail("佛光普照乃是内家功夫，你现在内力不足，使不出这一招。\n");

  msg = HIY "\n$N突然间全身骨骼中发出劈劈拍拍的轻微爆裂之声，炒豆般的响声未绝，右掌已向$n胸口击去。\n\n"NOR;
  msg += HIG"这一掌是峨嵋派的绝学，叫做“佛光普照”。这“佛光普照”的掌法便只一招，而且这\n";
  msg += HIG"一招也无其他变化，招式平平淡淡，一成不变，可是其威力之生，就在于以峨嵋派绝顶\n";
  msg += HIG"内功作为根基。一掌既出，内力如排山倒海一般袭来，敌人挡无可挡，避无可避。\n\n";


  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			if(damage > 3000) damage = 3000;
			if(damage < 500) damage = 500;
			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

		msg += HIR"猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;
		if ( damage < 400) {
			msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
		}else if ( damage < 600) {
			msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
		}else if ( damage < 1000) {
			msg += YEL"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。\n"NOR;
		}else if ( damage < 2000) {
			msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;
		}else if ( damage < 3000) {
			msg += RED"只听一声巨响，$n口中鲜血狂喷，全身骨骼碎裂。\n"NOR;
		}else {
			msg += RED"只听一声巨响，$n全身骨骼碎裂，竟被这排山倒海般的一击将身子打成了两截。\n"NOR;
		}
		msg += NOR;
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 2;
			if(damage > 2000) damage = 2000;
			if(damage < 350) damage = 350;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIY"$p眼看这一招来势汹汹，知道难于对付，连忙发力抵抗，猛听得砰然一声大响，$N已打中在$p胸口.\n"NOR;
		if ( damage < 400) {
			msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
		}else if ( damage < 600) {
			msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
		}else if ( damage < 1000) {
			msg += RED"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。\n"NOR;
		}
		else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
	  random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 3;
			if(damage > 1000) damage = 1000;
			if(damage < 250) damage = 250;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIM"$p眼看这一招来势汹汹，慌忙使出本门身法，向侧跃出数丈，可是这佛光普照蕴藏峨眉内家上乘内功，\n";
			msg += "方圆数丈都被神功所震撼，$p只觉得后心一震，已被劈空掌力所伤.\n"NOR;
		if ( damage < 400) {
			msg += HIC"$n身子一晃，立足不定，差点儿就要摔倒。\n"NOR;
		}else if ( damage < 600) {
			msg += HIR"$n向后接连摔了两个筋斗，哇的一声，喷出一口鲜血。\n"NOR;
		}else if ( damage < 1000) {
			msg += RED"$n哇的一声，喷出一口鲜血，委顿在地，便似一堆软泥。，\n"NOR;
		}
		else msg += RED"$n身子便如一捆稻草般，在空中平平的飞了出去，重重摔在地下，口中鲜血狂喷．\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else {
	 msg += HIC"$n眼看这一招来势汹汹，使出本门身法，向後跃出数丈，\n\n"NOR;
	 msg += HIW"$N这一招乃是使上了全力，丝毫不留余地。没想到全无用处，不觉脸如死灰，手掌微微发抖。\n" NOR;
	 me->add("neili", -jiali*2 );
	 me->add("jingli", -me->query("jiajin") );
	 me->start_busy(2 + random(2));
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}


