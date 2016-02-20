//Cracked by Roath
// leidong.c 雷动九天

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int lvl, str, dex, skill;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("雷动九天只能对战斗中的对手使用。\n");

	if( me->query_temp("leidong") )
		return notify_fail("你已在使用雷动九天了！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("雷动九天需空手才能施展！\n");

	if( me->query_skill_mapped("cuff") != "pishi-poyu" )
		return notify_fail("你所用的并非劈石破玉拳，不能施展雷动九天！\n");

	if( me->query_skill_prepared("cuff") != "pishi-poyu" )
                return notify_fail("你所备的并非劈石破玉拳，不能施展雷动九天！\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("你所用的并非紫霞功，施展不出雷动九天！\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("你的紫霞功火候未到，无法施展雷动九天！\n");

	if( (lvl=me->query_skill("cuff")) < 135 )
		return notify_fail("雷动九天需要精湛的劈石破玉拳方能有效施展！\n");

	if( me->query("neili") <= lvl*2 )
		return notify_fail("你的内力不够使用雷动九天！\n");
/*
	if( me->query_skill_prepared("strike") == "hunyuan-zhang" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("strike");
        }
*/
	message_vision(MAG "\n只听得$N一声大喝，拳风突然变得猛劲之极，身法却更加飘忽难测！\n\n" NOR, me, target);

//	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	str = me->query_str();
	dex = me->query_dex();
	me->add_temp("apply/strength", str*2);
	me->add_temp("apply/dexerity", dex*2);
	me->set_temp("leidong", 1);
	skill=(me->query_skill("pishi-poyu",1)+me->query_skill("huashan-shenfa",1)) / 2;

	me->start_call_out( (: call_other, __FILE__, "end_perform", me, str, dex:), skill/8);

	me->add("neili", -lvl);
	me->add("jingli", -lvl);

//	if( me->query_temp("restore") ) me->prepare_skill("strike", "hunyuan-zhang");

	return 1;
}

void end_perform( object me, int str, int dex)
{
	me->add_temp("apply/strength", -str*2);
	me->add_temp("apply/dexerity", -dex*2);
	me->delete_temp("leidong");

	tell_object(me, "你缓缓吸了一口气，将内劲收回丹田。\n");
}	
