//Cracked by Roath
// huaying.c 雁行刀之无形幻影

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, fakeme, fakeweapon;
	object *enemy;
	string master;
	int i, serial;

	weapon = me->query_temp("weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !objectp(weapon) || weapon->query("skill_type") != "blade") 
		return notify_fail("你手中无刀，岂能运用「无形幻影」？！\n");

	if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("「无形幻影」只能对战斗中的对手使用。\n");

	if( me->query_temp("yanxing/huanying") )
		return notify_fail("敌手正被你的「无形幻影」迷惑！\n");

	if( me->query_skill("yanxing-dao",1) < 60 )
		return notify_fail("你雁行刀法修为还不够，还未领悟「无形幻影」！\n");

	if( me->query_skill("linji-zhuang", 1) < 60 )
		return notify_fail("你的内功修为火候未到，不足以施展「无形幻影」！\n");

	if( me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("你所用的内功与「雁行刀」气路相悖！\n");

	if( me->query_skill("dodge") < 60 )
		return notify_fail("你的轻功火候不够，不足以施展「无形幻影」！\n");

	if( me->query("max_neili") <= 400 )
		return notify_fail("你的内力修为不足，劲力不足以施展「无形幻影」！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够，劲力不足以施展「无形幻影」！\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力有限，不足以施展「无形幻影」！\n");

	if ( userp(me) ) {
		me->add("neili", -100);
		me->add("jingli", -50);
	}

	seteuid(getuid());
	if ( userp(me) ) {
	    fakeme = new(__DIR__"copy/user.c");
	    fakeme->set("id", me->query("id")+" shadow");
	    fakeme->set("master_id", me->query("id"));
	    me->save();
	    if (!fakeme->restore())
		return notify_fail("如果你看到这个信息，说明系统有问题，请向巫师报告。\n");

	    fakeme->setup();
	    fakeweapon = weapon->clone();
	    fakeweapon->move(fakeme);
	    fakeweapon->wield();
	} else {	// npc
	    fakeme = new(base_name(me));
	    if ((me->query("family/family_name") == "御林军") &&
		(master=me->query("master")) &&
		(serial=me->query("serial"))) {	// this is a 随从 npc
		
		me->save();
		fakeme->set("master", master);
		fakeme->set("serial", serial);
		if (!fakeme->restore())
		    return notify_fail("请报告巫师：随从系统有问题。\n");
		fakeme->drop_all_weapon();
		fakeweapon = weapon->clone();
		fakeweapon->move(fakeme);
		fakeweapon->wield();
	    }
	}
	fakeme->set_name(me->name()+"幻影", ({fakeme->query("id"), me->query("id")}));
	fakeme->move(environment(me));
	fakeme->add_temp("apply/dexerity", me->query_temp("apply/dexerity"));
	fakeme->add_temp("apply/strength", me->query_temp("apply/strength"));
	fakeme->set_temp("apply/speed", 0);
	fakeme->set("env/wimpy", 0);
	fakeme->set("env/invisibility", 10);

	message_vision(HIY "\n\n$N前后游走，身形闪动，手中"+weapon->name()+"越使越快，幻起无数刀光化出数个身形。\n"
			+"$n被此雁行刀法之「无形幻影」所迷惑，手足无措，不知哪个$N是真，哪个是假。\n" NOR, me, target);

	enemy = me->query_enemy();
	for (i=0; i<sizeof(enemy); i++)
		if(environment(enemy[i]) == environment(me))
		{
			if (me->is_killing(enemy[i]->query("id")))
				fakeme->kill_ob(enemy[i]);
			else
				fakeme->fight_ob(enemy[i]);

			if (enemy[i]->is_killing(me))
				enemy[i]->kill_ob(fakeme);
			else
				enemy[i]->fight_ob(fakeme);
		}

	fakeme->set_temp("yanxing/huanying", me);
	me->set_temp("yanxing/huanying", fakeme);

        call_out("checking", 1, me, target, fakeme, random(10)+me->query_skill("blade")/15);
        return 1;
}

private void stop_huanying(object me, object victim, object fakeme)
{
	me->delete_temp("yanxing/huanying");
	destruct(fakeme);
	if (victim && victim->is_fighting(me)) {
	    message_vision(HIY "\n\n$N终于识破了$n的「无形幻影」，不为$n所迷惑。\n" NOR, 
		victim, me);
	}
}

int checking(object me, object target, object fakeme, int delay)
{
	if ( !objectp(fakeme) ) return 1;
	if ( !objectp(me) ) {destruct(fakeme); return 1;}
        if ( !objectp(target) ) {destruct(fakeme); return 1;}
	if (!me->is_fighting(target) || !living(fakeme) || delay < 1) {
		stop_huanying(me, target, fakeme);
		return 1;
	} 
	if (me->is_fighting(target) && !fakeme->is_fighting(target) )
		fakeme->fight_ob(target);
	call_out("checking", 1, me, target, fakeme, delay-1);
	return 1;
}
