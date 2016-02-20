//Cracked by Roath
// taiji-shengong.c 太极神功

#include <combat.h>
#include <ansi.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("taiji-shengong", 1);
                mapping skl; 
        string *sname;
        int i, k=0;
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t *= 2;
                skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("this_skill") > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail
("你体内不同内力互相冲撞，难以领会更高深的武功。\n");
        }



//      if ( me->query("gender") == "无性" )
//              return notify_fail("太极神功练的是天地正气，讲的是阴阳调合，以公公无根无性之身，如何修得！\n");

        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

        if ((int)me->query_skill("force", 1) < 10 
          || (int)me->query_skill("force", 1)/2 < lvl/3 )
                return notify_fail("你的基本内功火候还不够。\n");

        if (lvl > 10 && (int)me->query("shen") < t * 100
             && me->query_skill("taoism", 1) < 100) 
                return notify_fail("你的侠义正气太低了。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"taiji-shengong/" + func;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");
        int ap, dp, s_damage;
	mapping prepare;
        string attack_skill, result;

        if( (int)victim->query_skill("taiji-shengong", 1) < 50 ) return damage;

        dp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);
        if( objectp(weapon2) && (string)weapon2->query("skill_type") == "sword" )
	{
		if( victim->query_skill_mapped("parry") != "taiji-jian" ) return damage;
		dp /= 3;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        }
	else if( !objectp(weapon2) && victim->query_skill_mapped("parry") == "taiji-quan" )
	{
		if( victim->query_skill_prepared("cuff") != "taiji-quan" ) return damage;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        }
	else return damage;

        ap = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);

        prepare = me->query_skill_prepare();
        if( !prepare ) prepare = ([]);

        if( objectp(weapon1) ) attack_skill = weapon1->query("skill_type");
	else switch( sizeof(prepare) )
	{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
	}

	ap += COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        ap /= 100;
        dp /= 100;

	if( wizardp(victim) ) tell_object(victim, sprintf("ap: %d, dp: %d\n", ap, dp));
        if( random(ap+dp) > ap )
	{
		if( objectp(weapon2) )
			result = "只见$n使出四两拨千斤之巧劲，剑锋斜引，$N的力道尽数击在空处。\n";
		else
		{
			result = "只见$n使出四两拨千斤之巧劲，轻轻一转，一推，$N的力道尽数击向$P自己。\n";
			s_damage = damage + damage_bonus;
			if( victim->query_temp("taiji") )
				s_damage += me->query_temp("apply/damage");
                        if( s_damage > 0 )
			{
				me->receive_damage("qi", s_damage, victim);
				me->receive_wound("qi", random(s_damage/2), victim);
				result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
			}
                }
                damage_bonus = -10000; // just a number negative enough
                return ([ "result" : result, "damage" : damage_bonus ]);
        }
	else if( random(ap+dp+dp) > ap )
	{
                if( objectp(weapon2) )
		{
                        result = "$n使出四两拨千斤之巧劲，将$N的力道卸去大半。\n";
                        damage_bonus = 0;
                }
		else
		{
                        result = "$n使出四两拨千斤之巧劲，将$N的力道尽数卸去。\n";
                        damage_bonus = -10000; // just a number negative enough
                }
                return ([ "result" : result, "damage" : damage_bonus ]);
        }
	else
	if( random(ap+dp+dp+dp) > ap )
	{
                if( !objectp(weapon2) )
		{
                        result = "$n使出四两拨千斤之巧劲，将$N的力道卸去大半。\n";
                        damage_bonus = 0;
                }
                return ([ "result" : result, "damage" : damage_bonus ]);
        }
	else return damage;
}

mapping curing_msg(object me)
{
	return ([
		"apply_short"	: me->name() +"坐在一旁垂帘入定，头顶笼罩"HIW"氤氲白气"NOR"，汗气上蒸。",
		"start_self"	: HIW"你潜运内力，在周身穴道流转疗伤，调匀气息。\n"NOR,
		"start_other"	: HIW"只见"+ me->name() +"闭目坐下，片刻之时，头顶冒出丝丝白气。\n"NOR,
		"finish_self"	: HIY"你只觉内息运转顺畅，将真气还合丹田，站起身来。\n"NOR,
		"finish_other"	: me->name() +"惨白的脸色渐渐红润，缓缓睁开眼，站起身来。\n",
		"unfinish_self" : "你渐感真气不纯，后劲不继，不得不将在体内搬运的内息收回。\n",
		"unfinish_other": me->query("eff_qi") < me->query("max_qi")*3/4 ?
				  "猛地里"+ me->name() +"口一张，喷出几口鲜血。\n" :
				  "猛地里"+ me->name() +"口一张，吐出口紫黑瘀血。\n",
	]);
}

		