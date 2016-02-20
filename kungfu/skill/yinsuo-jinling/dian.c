// dian.c 银索金铃 点穴
// modified by xuanyuan 29/07/2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	object ob;		
        int ap, dp, pp;
	string result, str, msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("点穴只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("你使用的武器不对。\n");

//	if (!objectp(obj=present("jinling suo", me)))
//		return notify_fail("你手中没有金铃索，不能使用点穴功夫。\n");

	if( (int)me->query_skill("yinsuo-jinling", 1) < 120 )
		return notify_fail("你的银索金铃不够纯熟，还不能认穴\n");

	if( (int)me->query_skill("tianluo-diwang",1)<120)
		return notify_fail("你的天罗地网势火候不足，手法还不够灵活\n");

	if( (int)me->query_skill("yunu-xinjing",1)< 135)
		return notify_fail("你的内功修为太差，劲力无法封闭穴道\n");
	
	if( (int)me->query("max_neili")<1200)
		return notify_fail("你的内力不足以施展点穴功夫.\n");
			
	if ( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够点穴。\n");

	msg = HIY "\n$N手上金铃飞出，使出银索金铃的上乘点穴功夫，直取$n的大椎穴。\n\n"NOR;

	ob = target->query_temp("weapon");
        ap = COMBAT_D->skill_power(me,"whip", SKILL_USAGE_ATTACK)*3;
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        ap = (ap+random(ap*2))/4;

        if( ap > dp )
	{
		me->start_busy(2);
		if (! objectp(ob))
		{
			int damage = 0;

			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += HIR "$n连续变了几种上乘身法，终于没能躲过，"
						"$N的金铃正点在$n的檀中穴上，$n只觉得一口"
						"凉气，自丹田而上，心里有种说不出的难受。\n";
					damage = 3;
					break;
				case 1:
					msg += HIR "$n轻身飘开，身法灵动之极，众人正要喝彩，"
              					"听「噗」的一声，如击败革，$n脸色煞白，摇摇欲坠。\n";
					damage = 5;
					break;
				}
			} else
			if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch(random(2))
				{
				case 0:
					msg += HIR "$n冷哼一声，自持内力高强，反手出招，「啵」"
						"的一声轻响，掌铃相交，$n身行微晃，脸如金纸。\n";
					damage = 3;
					break;
				case 1:
					msg += HIR "$n一声长啸，双手幻化出无数掌影，护住身前。"
						"只听「嗤」的一声，掌影顿消，$n已经变得脸色惨白。\n";
					damage = 4;
					break;
				}
			} else
			{
				switch(random(2))
				{
				case 0:
					msg += HIR "$n看到这招，竟然不知躲避，「嗤」的一声，$N"
						"的金铃正点在$n大椎穴上，$n全身酸软,跌倒在地。\n";
//					target->unconcious();
					damage = 5;
					break;
				case 1:
					msg += HIR "$n一转念，已经想出了九十九种化解的办法，"
						"尚未来得及施展，只听「嗤」的一声，已被$N点中大椎穴，全身酸软，跌倒在地。\n";
//					target->unconcious();
					damage = 5;
					break;
				}
			}
			if (damage > 0)
				target->receive_damage("qi", target->query("max_qi") * damage / 15);
				me->add("neili", - (500 + damage*40) );
				me->start_busy(2 + random(3));
				message_vision(msg + NOR, me, target);
				str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
				message_vision("\n($N"+str+")\n", target);
			return 1;
		}
		if (ob->query("item_make"))
		{
			msg += HIR "$n忙用" + ob->query("name") + "招架，只觉得虎口剧震，所幸兵器完好无损。\n" NOR;
		} else
		{
			msg += HIW "$n连忙招架，只听见「啪」地一声，$n手中的" + ob->name()+ HIW"竟被弹飞！\n";
			ob->move(environment(target));       
		}
		target->start_busy(2);
		me->add("neili", - 200 );
	} else
	{
		int busy = 0;
		if (target->query_skill("dodge") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += "$n一声轻笑，连续变化了几次身法，扰人耳目，一时让$N无法进攻。\n";
				busy = 2;
				break;
			case 1:
				msg += "$n突然向后飘去，疾若闪电，令$N所有的后继变化无从施展。\n";
				busy = 1;
				break;
			}
		} else
		if (target->query_skill("force") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += "$n脸色凝重，加快格架，以巧对巧，让$N无从下手，只能收回金铃。\n";
				busy = 3;
				break;
			case 1:
				msg += "$n满脸不屑，冷笑一声，双掌齐出，其快无比，令$N只能回招自救。\n";
				busy = 1;
				break;
			}
		} else
		{
			switch (random(3))
			{
			case 0:
				msg += "$n左摇右晃，看上去毫无章法，偏偏躲过了$N这一击。\n";
				busy = 2;
				break;
			case 1:
				msg += "$n金铃点出，看上去灵动精妙，$N一呆，攻势顿缓。\n";
				busy = 2;
				break;
			case 2:
				msg += "$n摄住心神，真气贯注" + ob->query("name")
					 + "，堪堪封住了$N的进攻。\n";
				busy = 2;
				break;
			}
		}
		target->start_busy(busy);
		me->start_busy( 2 + random(3) );
	}
	message_vision(msg + NOR, me, target);
	me->add("neili", - 500 );
	me->start_busy( 2 + random(3) );
	return 1;
}
