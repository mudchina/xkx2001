//Cracked by Kafei
// hebi.c 玉女剑与全真剑和璧左右互搏
//by sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

private int remove_effect(object me, int amount,object weapon);

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object victim;
	object weapon,weapon2;
    object *inv;
    int i, count;
	string bei_skill;

	if( !victim ) victim = offensive_target(me);

    if(me->query("double_attack",1) <1)
		return notify_fail("你不会左右互搏，不能双剑和璧左右互搏！\n");

//	if(me->query_skill("zuoyou-hubo",1) <60)
//		return notify_fail("你的左右互搏不够熟练，不能双剑和璧左右互搏！\n");

	if( !victim || !victim->is_character() || !me->is_fighting(victim) )
		return notify_fail("双剑和璧左右互搏只能对战斗中的对手使用。\n");


	
	if( (int)me->query_temp("hubo") ) 
	{
		return notify_fail("你正进行双剑和璧左右互搏。\n");
	}

	if( (int)me->query_temp("hebi") ) 
	{
		return notify_fail("你正与人合壁，不能再进行双剑和璧左右互搏。\n");
	}


	if( me->query_skill_mapped("sword") != "yunu-jianfa" &&
		me->query_skill_mapped("sword") != "quanzhen-jian"||
		me->query_skill("yunu-jianfa",1) < 1 ||
		me->query_skill("quanzhen-jian",1) < 1 
		)
		return notify_fail("必须通晓并备有玉女剑法与全真剑法才能双剑和璧左右互搏！\n");

	if(me->query_skill("quanzhen-jian",1) <150)
		return notify_fail("你的全真剑法不够熟练，不能双剑和璧左右互搏！\n");

	if(me->query_skill("yunu-jianfa",1) <150)
		return notify_fail("你的玉女剑法不够熟练，不能双剑和璧左右互搏！\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" &&
		me->query_skill_mapped("force") != "xiantian-gong"
		)
		return notify_fail("你所用的并非玉女心经或先天功，无法施展双剑和璧左右互搏！\n");

	if( me->query_skill("yunu-xinjing", 1) < 120 &&
		me->query_skill("xiantian-gong", 1) < 120
		)
		return notify_fail("你的玉女心经或先天功火候未到，无法施展双剑和璧左右互搏！\n");
	

	if( !objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("必须持有双剑才能和璧左右互搏！\n");

     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
           if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   break;
		   }
     }

	if( !objectp(weapon2) )
		return notify_fail("必须持有双剑才能和璧左右互搏！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不够使用双剑和璧左右互搏！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用双剑和璧左右互搏！\n");
	if( me->query("jing") <= 120 )
		return notify_fail("你的精不够使用双剑和璧左右互搏！\n");

	skill =  ( me->query_skill("sword",1) + me->query_skill("yunu-jianfa",1)
		+ me->query_skill("quanzhen-jian",1) +me->query_skill("yunu-xinjing",1) 
		+ me->query_skill("force")) / 16; 

	message_vision(
	HIR "$N突然间左手抽出另一把剑，双手使出截然不同的剑法，正是左右互搏绝技。\n"+HIC"只见$N双剑一交，左右手玉女剑法与全真剑法配合得天衣无缝，攻守之势猛然大增！\n\n" NOR, me);

	me->add_temp("apply/attack", skill/6);
	me->add_temp("apply/damage", skill/4);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->set_temp("hubo", 1);

    me->add_temp("apply/damage", 180);

	bei_skill = me->query_skill_mapped("sword");

    me->map_skill("sword", "yunu-jianfa");
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	weapon->unequip();
	weapon2->wield();
    me->map_skill("sword", "quanzhen-jian");
	me->setup();
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	weapon2->unequip();
	weapon->wield();
    me->map_skill("sword", "yunu-jianfa");
	me->setup();
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	weapon->unequip();
	weapon2->wield();
    me->map_skill("sword", "quanzhen-jian");
	me->setup();
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	weapon2->unequip();
	weapon->wield();
    me->map_skill("sword", "yunu-jianfa");
	me->setup();
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	weapon->unequip();
	weapon2->wield();
    me->map_skill("sword", "quanzhen-jian");
	me->setup();
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));

    me->map_skill("sword", bei_skill);
	me->setup();
	weapon2->unequip();
	weapon->wield();
    me->add_temp("apply/damage", -180);
	me->add("jingli", -100);
	me->add("jing", -100);
	me->add("neili", -300);
	me->start_busy(1+random(2));


	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2,weapon2 :), 6);

	return 1;
}

private int remove_effect(object me, int amount,object weapon)
{
	me->add_temp("apply/attack", -amount/3);
	me->add_temp("apply/damage", -amount/2);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/dodge", -amount);
	me->delete_temp("hubo");
	message_vision(
	HIY "\n$N吸了一口气，左手潇洒地将"+"$n" + HIY "插回剑鞘，收回左右互搏绝技！\n\n" NOR, me,weapon);

	return 0;
}
