//Cracked by Roath
/// kungfu/skill/xiantian-gong.c 先天功
// sdong, 7/25/98

#include <combat.h>
#include <ansi.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int lvl = (int)me->query_skill("xiantian-gong", 1);
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

        if ( k >=2 && me->query_skill("taiji-shengong") < 80 )
		  return notify_fail("你体内不同内力互相冲撞，难以领会更高深的武功。\n");
		  }


	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的先天气功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("先天气功讲究阴阳调合，有违佛家六根清净之意，"
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
        if ( me->query_skill("xiantian-gong", 1) < 150 )
                return notify_fail("你的先天功修为不够，只能用学(learn)的来增加熟练度。\n");
        if ( me->query_temp("weapon") )
                return notify_fail("练习先天功必须空手，静坐诚心方可。\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("你的体力不够练习先天功。\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("你的精力不够练习先天功。\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够练习先天功。\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "精力透支过度死了");
		  me->receive_damage("qi", 60, "体力透支过度死了");
		  return 1;
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-gong/" + func;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
	object weapon1 = me->query_temp("weapon");
	object weapon2 = victim->query_temp("weapon");
	int ap, dp;
	string result;

	if ( (int)victim->query_skill("xiantian-gong", 1) < 50 ) return damage;

	dp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);
	if (objectp(weapon2) && (string)weapon2->query("skill_type") == "sword" ) {
		if ( victim->query_skill_mapped("parry") != "quanzhen-jian" )
			return damage;
		dp /= 3;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/2;
	} else if (!objectp(weapon2) ) {
		if ( victim->query_skill_prepared("strike") != "sanhua-juding" )
			return damage;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
	} else return damage;

	ap = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);
	if (objectp(weapon1))
		ap += COMBAT_D->skill_power(me, weapon1->query("skill_type"), SKILL_USAGE_ATTACK);
	else
		ap *= 2;

	ap /= 100;
	dp /= 100;

	if ( random(ap+dp) > ap ) {
		if ( weapon2 && objectp(weapon2) ) {
			if (damage + damage_bonus > 0)
			{
				me->receive_damage("qi", (damage + damage_bonus)/2, victim);
				result = HIG"只见$n手中剑巧妙地一粘一拉，$N的力道通通击在空处，$P用力过猛，失去平衡，跌了个跤。\n"NOR;
				result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
				me->start_busy( 2+random(2) );
			}
			else
				result = "只见$n手中剑巧妙地一粘一引，$N的力道被化解为无形。\n";
		}
		else if( victim->query_temp("sanhua") || victim->is_busy() )
		{
			if( !weapon1 )
			{
				result = HIM"只见$n先天护体神功自然而然发动，将$N的力道尽数反震向$P自己。\n"NOR;
				if (damage + damage_bonus > 0)
					me->receive_damage("qi", (damage + damage_bonus)/2, victim);
				result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
			}
			else
			{
				result = HIM"只见$n先天护体神功自然而然发动，将$N的力道引到一边。\n"NOR;
			}
		}
		else return damage;

		damage_bonus = -5000; // just a number negative enough
		return ([ "result" : result, "damage" : damage_bonus ]);

	} else if( random(ap+dp+dp+dp) > ap ) {

		if (objectp(weapon2)) {
			result = "$n手中剑轻轻斜引，$N的力道被化解了大半。\n";
			damage_bonus = 0;
		}
		else if( victim->query_temp("sanhua") || victim->is_busy())
		{
			result = MAG"只见$n先天护体神功自然而然发动，将$N的攻击化为无形。\n"NOR;
			damage_bonus = -5000;
		}
		else return damage;

		return ([ "result" : result, "damage" : damage_bonus ]);
	} else if( random(ap+dp+dp+dp+dp) > ap ) {

		 if( victim->query_temp("sanhua") || victim->is_busy() )
		{
			result = MAG"只见$n先天护体神功自然而然发动，抵抗$N的攻击。\n"NOR;
			damage_bonus = 0;
		}
		else return damage;

		return ([ "result" : result, "damage" : damage_bonus ]);
	} else
		return damage;
}

mapping curing_msg(object me)
{
	return ([
		"apply_short"	: me->name() +"坐在地下，头上一缕缕热气袅袅而上，犹如蒸笼一般。",
		"start_self"	: YEL"你盘膝坐下，调气护伤，运气在周身大穴运转。\n"NOR,
		"unfinish_other": "过了一会，"+ me->name() +"吐出一口瘀血。\n",
	]);
}
