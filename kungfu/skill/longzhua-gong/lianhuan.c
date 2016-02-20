//Cracked by Roath
// lianhuan.c 龙爪功连环八式
/// maco
/*
    空性突然间大喝一声，纵身而上，双手犹如狂风骤雨，「捕风式」、「捉影式」、「抚琴式」、「鼓瑟式」、「批亢式」、「捣虚式」、「抱残式」、「守缺式」，八式连环，疾攻而至。张无忌神定气闲，依式而为，捕风捉影、抚琴鼓瑟、批亢捣虚、抱残守缺，接连八招，招招后发而先至。
    空性神僧这八式连环的龙爪手绵绵不绝，便如是一招中的八个变化一般，快捷无比，
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int claw, lv, i, hit;
	string weapon, lzg_msg;

	if( !target ) target = offensive_target(me);
	
        if (!wizardp(me))
            return notify_fail("这功能还不开放。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("龙爪功连环攻击只能对战斗中的对手使用。\n");

        if( me->query_temp("lzg_effect") )
                return notify_fail("你刚才已经使出了龙爪功连环攻击，一时难以再行抢攻！\n");

	if ( me->query_temp("weapon") )
                return notify_fail("龙爪功连环攻击必须空手方可施展。\n");
	if( me->query_skill_prepared("hand") == "qianye-shou" )
                return notify_fail("你无法在使用如来千叶手时同时施展龙爪功连环攻击！\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi")
                return notify_fail("你所运使的内功不是混元一气功，无法施展龙爪功连环攻击！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 100 )
		return notify_fail("你的混元一气功火候未到，无法施展龙爪功连环攻击！\n");

	if( me->query_skill("claw",1) < 140 )
		return notify_fail("你的爪法修为有限，无法施展龙爪功连环攻击！\n");

	if( me->query_skill("longzhua-gong",1) < 140 )
		return notify_fail("你的龙爪功造诣未到，无法施展龙爪功连环攻击！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不足以使出龙爪功连环攻击！\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用龙爪功连环攻击！\n");

	claw = me->query_skill("claw");
	lv = (int)me->query_skill("longzhua-gong",1);
	hit = (lv/100)*2;
	if(hit > 8) hit = 8;
	if(hit <4) hit = 4;
	
	me->add_temp("apply/speed", lv/10);

	lzg_msg = HIY"\n$N突然间大喝一声，纵身而上，双手犹如狂风骤雨，";
	
	if(hit >= 4)lzg_msg += "「捕风式」、「捉影式」、「抚琴式」、「鼓瑟式」";
	if(hit >= 6)lzg_msg += "、「批亢式」、「捣虚式」";
	if(hit >= 8)lzg_msg += "、「抱残式」、「守缺式」";
	
	lzg_msg += "，"+chinese_number(hit)+"式连环，疾攻而至！\n"NOR;

	message_vision(lzg_msg, me, target);
	me->set_temp("lzg_times",hit);
	me->set_temp("lzg_effect",1);
	me->add_temp("lzg_lianhuan", 3);
        for( i=0; i < hit; i++ )
        {
		me->add_temp("lzg_lianhuan", 1);
                COMBAT_D->do_attack(me, target, weapon);
        }


        message_vision(HIY"\n这"+chinese_number(hit)+"式连环的龙爪手绵绵不绝，便如是一招中的"+chinese_number(hit)+"个变化一般，快捷无比！\n"NOR, me);

	me->add("neili", -hit*20+20);
	me->add("jingli", -hit*5);
	me->start_busy(1+random(2));
	me->delete_temp("lzg_lianhuan");
	me->delete_temp("lzg_times");
	me->add_temp("apply/speed", -lv/10);
        call_out("remove_effect", hit*2, me);
	return 1;
}


void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("lzg_effect");
        tell_object(me, YEL"\n你微一调息，平复了施展龙爪功後鼓荡奔腾的真气。\n"NOR); 
}
