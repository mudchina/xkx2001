//Cracked by Roath
// hunyuan-yiqi.c 少林 混元一气功
// dts@xkx, cleansword@xkx
// modified by aln

inherit FORCE;
string check() { return "force"; }
#include <ansi.h>
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
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("hunyuan-yiqi", 1);
	ns = (int)me->query("guilty");
	
	skl=me->query_skills();
    sname=sort_array( keys(skl), (: strcmp :) );

    if(me->query_skill("hunyuan-yiqi", 1) > 99){

	   for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;  
	    }

	    if ( k >=2 )
		return notify_fail ("你体内不同内力互相冲撞，难以领会更高深的武功。\n");
        }

	if ( me->query("gender") != "男性" )
		return notify_fail("你非童男之体，不能练习混元一气功。\n");

	if ( me->query("class") != "bonze" && nh > 39)
		return notify_fail("你未入佛门，尘缘难断，无法继续修练与禅宗丝缕相连的混元一气功。\n");

	if ( nb < 120 && nb <= nh )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的混元一气功。\n");

	if ( nf < 10 || nf/2 < nh/3 )
		return notify_fail("你的基本内功火候还不够，无法领会混元一气功。\n");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的混元一气功。\n");


	return 1;
}


int practice_skill(object me) {
	if ( me->query_skill("hunyuan-yiqi", 1) < 150 )
		return notify_fail("你的混元一功修为不够，只能用学(learn)的来增加熟练度。\n");
	if ( (int)me->query("qi") < 150 )
        return notify_fail("你的体力不够练习混元一气功。\n");
	if ( (int)me->query("jingli") < 150 )
        return notify_fail("你的精力不够练习混元一气功。\n");
	if ( (int)me->query("neili") < 150 )
        return notify_fail("你的内力不够练习混元一气功。\n");

	if ( me->query_skill("hunyuan-yiqi", 1) < 250 ) {
        	me->add("neili", -80);
        	me->receive_damage("jingli", 80, "精力透支过度死了");
        	me->receive_damage("qi", 80, "体力透支过度死了");
	}
	else {
		me->add("neili", -100);
                me->receive_damage("jingli", 100, "精力透支过度死了");
                me->receive_damage("qi", 100, "体力透支过度死了");
	}

	return 1;
	// return notify_fail("混元一气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"hunyuan-yiqi/" + func;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor) {
        object weapon = me->query_temp("weapon");
        string result;
        int ap, dp, wp, aextra, dextra, ex_damage, s1, s2;

        if( !victim->query_temp("jinzhongzhao") ) return damage;

 //       if( damage < 0 ) return damage;

        // let neili be the main determine factor, give defender
        // a bit more benefit.
        aextra = (int)me->query("neili")/50;
        dextra = (int)victim->query("neili")/40;
     
        s1 = me->query_skill("force");
        s2 = victim->query_skill("force");

        ap = aextra * (int)(s1 / 100) + random(s1);
        dp = dextra * (int)(s2 / 100) + random(s2);

        victim->add("neili", -dextra/5);

        if( objectp(weapon) ) {
                if( random(dp + ap) > ap && dp > ap / 2 ) {
                        switch(weapon->query("skill_type")) {
                        case "whip"   : wp = 10; break;
			case "sword"  : wp = 8; break;
                        case "fork"   : wp = 7; break;
                        case "hook"   : wp = 6; break;
			case "blade"  : wp = 5; break;
                        case "halberd": wp = 4; break;
			case "club"   : wp = 3; break;
                        case "stick"  : wp = 2; break;
			case "staff"  : wp = 1; break;
                        case "axe"    : wp = 1; break;
                        case "hammer" : wp = 1; break;
                        default       : wp = 3; break;
                        }

                        wp *= weapon->query("weapon_prop/damage");
                        if( random(dp/5 + wp) > wp ) {
                        result = HIR"\n$N只觉虎口一热，"NOR + weapon->name() + HIR"顿时脱手而出，飞出丈外。\n\n"NOR;
                        weapon->unequip();
                        weapon->move(environment(me));
                        me->reset_action();

                        ex_damage = damage + (int)victim->query_skill("force");
                        if( ex_damage > 0 ) {
                        ex_damage += random(ex_damage);
                        me->receive_damage("qi", ex_damage/3, victim);
                        me->receive_wound("qi", ex_damage/6, victim);
                        }

                        me->start_busy(1);
                        result += "( $N" + COMBAT_D->eff_status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                        damage_bonus = -5000;
                        return ([ "result" : result, "damage" : damage_bonus ]);
                        }

                        result = "";
                        damage_bonus -= dp;
                        return ([ "result" : result, "damage" : damage_bonus ]);
                } else  return damage;
	}

        if( random(dp + ap) > ap && dp > ap / 2 ) {
                if( random(victim->query("combat_exp")) > me->query("combat_exp")/2 ) {
                result = HIR"$n抢先反震，使$N内息翻腾，脸如白纸，全无血色。\n"NOR;

                ex_damage = random(damage) + (int)victim->query_skill("force");
                if( ex_damage > 0 ) {
                ex_damage += random(ex_damage);
                me->receive_damage("qi", ex_damage, victim);
		me->receive_wound("qi", ex_damage/2, victim);
                }

                result += "( $N" + COMBAT_D->eff_status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                damage_bonus = -5000;
	} else {
                result = HIR"$N只觉$n身上生出一股反震之力，只震得胸内腹中，五脏有如一齐翻转。\n"NOR;
                me->add("neili", -aextra);
                damage_bonus -= dp;
        }
                return ([ "result" : result, "damage" : damage_bonus ]);
        }

        if( random(ap + dp) > dp && ap > dp ) {
                result = HIR"$n登时内脏震裂，护体神功随即瓦解。\n"NOR;
                me->add("neili", -aextra);
                damage_bonus += random(ap);
                return ([ "result" : result, "damage" : damage_bonus ]);
        }

        return damage;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"	: HIY"你暗运内功心法，凝神致志，导引体内真气盘旋。\n"NOR,
		"start_other"	: HIY+ me->name() +"盘膝坐下，目观鼻，鼻观心，左手抚胸，右手按腹。\n"NOR,
		"finish_self"	: HIY"你依法盘旋得数下，真气便如是细流归支流、支流汇大川，内息畅通无碍。\n"NOR,
	]);
}
