//Cracked by Roath
// longxiang-banruo.c 雪山 龙象般若功
// Summer, 9/29/96. 
// kane, 25/01/99

#include <ansi.h>
inherit FORCE;
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
        mapping skl; 
        string *sname;
        int v, k=0;

	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("lamaism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("longxiang-banruo", 1);
	        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("longxiang-banruo", 1) > 99){

       for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
        }


	if ( me->query("class") != "lama" && nh > 39)
		return notify_fail("你未入佛门，尘缘难断，无法继续修练与密宗丝缕相连的龙象般若功。\n");

	if ( nb < 120 && nb <= nh )
		return notify_fail("你的密宗心法修为不够，无法领会更高深的龙象般若功。\n");

	if ( nf < 10 || nf/2 < nh/3 )
		return notify_fail("你的基本内功火候还不够，无法领会龙象般若功。\n");



	return 1;
}


int practice_skill(object me)
{
	return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"longxiang-banruo/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
	int ap, dp;
        int damage, myneili, yourneili, my_max, your_max;
        string force_skill;
        mixed foo;
        string result;

	ap = me->query("combat_exp")/1000;
        ap += me->query_skill("force");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("force");
        ap = (ap + random(ap*2))/2;

        msg = HIR"$N大呼酣战，口念密宗不动明王真言，运龙象之力朝$n击去！\n"NOR;

        myneili = (int)me->query("neili");
        yourneili = (int)victim->query("neili");
        my_max = (int)me->query("max_neili")*2;
        your_max = (int)victim->query("max_neili")*2;
        myneili = my_max > myneili ? myneili : my_max;
        yourneili = your_max > yourneili ? yourneili : your_max;
        me->add("neili", - factor );
        damage = myneili/20 + factor - yourneili/25;

        if( me->query_temp("longxiang") && (ap > dp) ) {
                damage *= 2;
                message_vision(msg,me,victim);
        }

        if (force_skill = victim->query_skill_mapped("force") ) {
                foo = SKILL_D(force_skill)->hit_by(me, victim, damage, damage_bonus, factor);

                if (stringp(foo)) return (string)foo;
                else if (intp(foo)) damage = (int)foo;
                else if (mapp(foo)) return foo;
        }

        if ( damage > 0 )
                damage = damage * factor / (int)me->query_skill("force") * 2;

        if( damage < 0 ) {
                if( !me->query_temp("weapon")
                && random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
                        damage = - damage;
                        me->receive_damage( "qi", damage * 2, victim);
                        me->receive_wound( "qi", damage, victim );
                        if( damage < 10 ) result = "$N受到$n的内力反震，闷哼一声。\n";
                        else if( damage < 20 ) result = "$N被$n以内力反震，「嘿」地一声退了两步。\n";
                        else if( damage < 40 ) result = "$N被$n以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
                        else result = "$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n";
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                        damage_bonus = -5000; // just a number negative enough
                        return ([ "result" : result, "damage" : damage_bonus ]);
                }
                if( damage_bonus + damage < 0 ) return - damage_bonus;
                return damage;
        }

        damage -= victim->query_temp("apply/armor_vs_force");
        if( damage_bonus + damage < 0 ) return - damage_bonus;
        if( random(me->query_skill("force")) < damage )
                return damage;
}
