//ruyi.c 如意连环刀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill, amount;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「如意连环刀」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
                return notify_fail("「如意连环刀」必须用刀才能施展。\n");

        if( (int)me->query_skill("ruyi-dao", 1) < 150 )
                return notify_fail("你的「如意刀法」不够娴熟，不会使用「如意连环刀」。\n");

        if ( me->query_skill_mapped("blade") != "ruyi-dao")
                return notify_fail("你没有激发如意刀到刀法上！\n"); 

	if ((int)me->query_skill("xiaowu-xiang", 1)<150
		&& (int)me->query_skill("bahuang-gong", 1)<150
		&& (int)me->query_skill("beiming-shengong", 1)<150)
		return notify_fail("你的逍遥派内功火候不够。\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n");	

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("ruyi-dao");
	amount = ( skill * 2 ) / 15;

	if ( amount < 40 ) amount = 40;
	if ( amount > 80 ) amount = 80;

	me->add_temp("apply/damage", amount);
	me->add_temp("apply/attack", amount*2);
	me->add_temp("apply/dodge", amount*2);

	if( wizardp(me) ) tell_object( me,
		sprintf("damage: %d, attack: %d, dodge: %d",
		me->query_temp("apply/damage"), me->query_temp("apply/attack"),
		me->query_temp("apply/dodge")) );

	message_vision(HIY "\n$N一声长笑，只觉世事如意，豪气满胸，哪管什么是非荣辱，反手一刀砍出！\n"NOR, me,target);   
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -50);       
        message_vision(HIY "\n$N身随刀转，顺手又是一刀！\n"NOR, me,target); 
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -50);        
	message_vision(HIY "\n$N刀风过处，意犹未尽，反手又是一刀！\n"NOR, me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -50);        
        message_vision(HIY "\n$N身形再转，如意一刀又回转回来！\n"NOR, me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -50);      

	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/attack", -amount*2);
	me->add_temp("apply/dodge", -amount*2);
	me->start_busy(2+random(3));

        return 1;
}
