//Cracked by Roath
//yun xixia
//by xiaojian on Oct8,2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount,int amount1);

int exert(object me, object target)
{
	int skill,str;
	if (!wizardp(me))
        return notify_fail("这功能目前还不对玩家开放。\n");
    if( objectp(target) && target != me ) 
        return notify_fail("你只能用紫霞神功来提升自己的战力。\n");
	if(me->query_skill("zixia-gong",1) <300)
		return notify_fail("你的紫霞功修为不够。\n");
	if(me->query_skill("zhengqi-jue",1)<210)
		return notify_fail("你的正气决火候不到，无法施展紫霞神功。\n");
	if(me->query_skill("ziyin-yin",1)<210)
		return notify_fail("你的紫氤吟火候不到，无法施展紫霞神功。\n");
	if( me->query_skill_mapped("force") != "zixia-gong" )
        return notify_fail("你所用的并非紫霞功，施展不出紫霞神功！\n");
	if( (int)me->query("max_neili") <1000)
		return notify_fail("你的内力修为不足，无法施展紫霞神功！\n");
	if( (int)me->query("neili") < 800  )
        return notify_fail("你的内力不够。\n");
	if( me->query("family/master_id") == "feng qingyang" )
		return notify_fail("你是剑宗高手，施展不出气宗的高深工夫。\n");
    if( me->query_temp("leidong") )
        return notify_fail("你已经在使用雷动九天了，无法同时运用紫霞神功！\n");
	if( me->query_temp("zixia"))
		return notify_fail("你已经施展出紫霞神功了。\n");
	skill = (int)me->query_skill("zixia-gong",1);
	str = me->query_str();
    
    message_vision(
MAG"$N微一凝神，运起紫霞神功，脸上突然紫气大盛！只是那紫气一现即隐，$N脸上又回复如常。\n" NOR, me);

	me->add("neili", -skill);
    me->receive_damage("jingli",skill/2,"精力透支过度死了");
	me->set_temp("zixia",1);	
    me->add_temp("apply/attack", 2*skill);
    me->add_temp("apply/strength",str);
        
    me->start_call_out((:call_other,__FILE__,"remove_effect",me,2*skill,str:),skill/3);
    if( me->is_fighting() )
		me->start_busy(1+ random(1));
    return 1;
}

void remove_effect(object me, int amount, int amount1)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/strength", -amount1);
        me->delete_temp("zixia");
        tell_object(me, "你的紫霞神功运行完毕，将内力收回丹田。\n");
}






