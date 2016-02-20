//Cracked by Roath
//jinglei 弹指惊雷
// kane 12/9/1997

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int level;
	string msg;
	object w;

        level   = (int) me->query_skill("tanzhi-shentong",1);

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("弹指惊雷只能对战斗中的对手使用。\n");
	        
	w = target->query_temp("weapon");
	if (!w) return notify_fail("对方没有武器，需要用弹指惊雷吗？！\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("你所用的内功与「弹指惊雷」心法相悖！\n");

        if( me->query_skill("bitao-xuangong", 1) < 120 )
                return notify_fail("你的内功修为火候未到，还未领悟「弹指惊雷」！\n");

	if( me->query_skill("finger",1) < 120 )
		return notify_fail("你基本指法修为还不够，还未领悟「弹指惊雷」！\n");

	if( me->query_skill("tanzhi-shentong",1) < 120 )
                return notify_fail("你弹指神通修为还不够，还未领悟「弹指惊雷」！\n");
        
	if( me->query("neili") <= 600 )
                return notify_fail("你的内力不够，劲力不足以施展弹指惊雷！\n");
	
	message_vision(HIG"$N真气运转七周天，脸色由红转白，再由白转青，指间似乎有劲气流窜！\n"NOR,me,target);        
        if (me->query("combat_exp")>random(target->query("combat_exp")*3/2) ) {
		me->add("neili", -100);
		me->add("jingli", -30);
/*		if (!w) {
                remove_call_out("hit_target");
                call_out("hit_target", random((int)(600/level)), me, target);
		}
		else {*/
                remove_call_out("bash_weapon");
                call_out("bash_weapon", random((int)(600/level)), me, target);
//               	}
        } else {
		message_vision(HIW"$N大惊之下，抢上一轮急攻，$n不得不散去真气，全力招架！\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
	}

	return 1;
}

int bash_weapon(object me, object victim)
{
        object ob;
        int wap, wdp, busy;

        ob = victim->query_temp("weapon");
	busy = me->query("max_neili") + me->query("max_jingli");
	
	if(busy > 3000) busy = 3000;

	me->start_busy(1);
        me->reset_action();

	message_vision(HIY"$N一声长笑，伸出食中二指向$n手中的"+ob->name()+HIY"弹去，指劲划空而过，竟发出微微“噼噼啪啪”爆裂之声！！\n"NOR,me,victim);
        
	if( me->is_fighting(victim) && me->query("neili") > 100 ) {
                wap = (int)me->query("max_neili") / 10
                        + (int)me->query("neili")
                        + (int)me->query_str()
                        + (int)me->query_skill("finger")
			+ (int)me->query("combat_exp")/1000;
                wdp = (int)ob->weight() / 800
                        + (int)victim->query("neili")
                        + (int)victim->query_str()
                        + (int)victim->query_skill("parry")
			+ (int)victim->query("combat_exp")/1000;
                wap = (wap+random(wap))*3/4;
                if( wap > 2 * wdp && ob->query("weapon_prop/damage") < 80 ) {
			message_vision(HIW "只听见「啪」地一声，$N手中的"+ob->name()+HIW"已经断为两截！\n"NOR, victim );                        
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
			victim->start_busy(3+busy/300);
                } else if( wap > wdp ) {
			message_vision(HIW "$N只觉得手中"+ob->name()+HIW"把持不定，脱手飞出！\n"NOR,victim);                        
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
			victim->start_busy(3+random(busy/300));
                } else if( wap > wdp / 2 ) {
                        message_vision("$N只觉得手中"+ob->name()+"一震，险些脱手！\n",victim);
                	victim->start_busy(random(3)+2);
		}
                else {
                        message_vision("$N的指劲弹在$n的"+ob->name()+"上，冒出点点的火星。\n", me, victim);
                	me->start_busy(random(2));
		}
        }
}

/*
int hit_target(object me, object victim)
{
        int busy;

	busy = me->query("max_neili") + me->query("max_jingli");
	me->start_busy(1);
        me->reset_action();

	message_vision(HIY"$N一声长笑，伸出食中二指向$n弹去，指劲划空而过，竟发出微微“噼噼啪啪”爆裂之声！！\n"NOR,me,victim);


}
*/