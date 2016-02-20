//Cracked by Roath
// duo.c 獒口夺杖

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int exp1,exp2,comb1,comb2;
	int force1,force2,neili1,neili2,str1,str2;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target))
		return notify_fail("獒口夺杖只能对战斗中的对手使用。\n");

    if( !objectp(weapon = me->query_temp("weapon") ) )
		return notify_fail("你所用的并非打狗棒法，不能施展獒口夺杖！\n");

	if (weapon->query("skill_type") != "stick")
		return notify_fail("你所用的并非打狗棒法，不能施展獒口夺杖！\n");

	if( me->query_skill_mapped("stick") != "dagou-bang" )
		return notify_fail("你所用的并非打狗棒法，不能施展獒口夺杖！\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )	
		return notify_fail("你所用的并非混天气功，施展不出獒口夺杖！\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("你的混天气功功力尚浅，无法施展獒口夺杖！\n");

	if( me->query_skill("stick") < 100 )
		return notify_fail("獒口夺杖需要精湛的打狗棒法方能有效施展！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用獒口夺杖！\n");

    if( !objectp(weapon = target->query_temp("weapon") ) )
		return notify_fail("对手并未使用兵刃！\n");

	message_vision(HIG "\n忽然$N欺近$n身前，伸出两指，向$n双眼插去！\n\n" NOR, me, target);

	exp1 = me->query("combat_exp");
	exp2 = target->query("combat_exp");
	force1 = me->query_skill("force");
	force2 = target->query_skill("force");
	neili1 = me->query("neili");
	neili2 = target->query("neili");
	str1 = me->query_str();
	str2 = target->query_str();
	
	if (exp1 < exp2/3)
	{
		message_vision("谁知$n不避不闪，待到$N两指已到眼前一尺，猛的使一个「铁板桥」，$N的攻击立时落空，$n同时施以反击。\n",me,target);
		me->start_busy(1+random(3));
		me->add("neili",-50);
		COMBAT_D->do_attack(target,me,me->query_temp("weapon"));
		return 1;
	}

//if exp1 = exp2, 
//因为是萃不及防，所以使用者略占优势。 5:4

	if (exp1 > random(exp2*8/5))
	{
		
message_vision(HIR"$n心头一惊，急忙伸手欲格开$N的双指。\n\n"NOR,me,target);
		comb1 = str1*neili1*force1;
		comb2 = str2*neili2*force2;
		if (comb1 < comb2/3)
		{
			
message_vision(HIG"$N蓦地收回双指，手掌下沉，已抓住了$n手中的"+weapon->query("name")+HIG"，运劲回夺！\n\n"NOR,me,target);
			
message_vision(HIR"$N只觉$n手中的"+weapon->query("name")+HIG"如同铸在铁中一般，只好放手，飘身退开。\n"NOR,me,target);
			me->start_busy(1+random(2));
			me->add("neili",-150);
			return 1;
		}
	
		if (comb1 > comb2)
		{
			
message_vision(HIG"不料$N蓦地收回双指，手掌下沉，已抓住了$n手中的"+weapon->query("name")+HIG"，轻轻巧巧地夺了过去！\n"NOR,me,target);
			weapon->move(me);
			me->add("neili",-50);
			return 1;
		}

message_vision(HIG"不料$N蓦地收回双指，手掌下沉，已抓住了$n手中的"+weapon->query("name")+HIG"，运劲回夺！\n\n"NOR,me,target);
			message_vision(HIR"$n见势头不对，急忙低身弓步，与$N对持。\n………\n……………\n一时双方僵持不下。\n\n",me,target);

			switch(random(3))
			{
				case 0:
				{
					
message_vision(HIG"突然$N大喝一声，手上加力，把"+weapon->query("name")+HIG"硬夺过来！\n",me,target);
					weapon->move(me);
					me->add("neili",-150);					
				}	
				break;
				case 1:
				{
					
message_vision(HIR"突然$N与$n同时发一声喊，各自退开几步，"+weapon->query("name")+HIG"已在$N手中！\n",me,target);
					weapon->move(me);
					me->add("neili",-200);					
					target->add("neili",-150);					
				}
				break;
				case 2:
				{
					
message_vision(HIR"突然$N与$n同时发一声喊，各自退开几步，"+weapon->query("name")+HIG"仍在$n手中！\n",me,target);
					me->add("neili",-200);					
					target->add("neili",-150);
					me->start_busy(1+random(2));
				}
				break;
			}
			return 1;
	}
	message_vision("$n疑心有诈，不敢硬接，飘身躲开$N的攻击。\n",me,target);
	me->add("neili",-50);
	me->start_busy(1+random(2));
	return 1;
}
