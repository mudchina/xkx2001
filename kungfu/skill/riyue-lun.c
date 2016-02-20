//Cracked by Roath
// riyue-lun.c -日月轮法
// Summer, 10/2/96.
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action":"$N左臂微偏，一招 「破竹势」，右手$w直直地递向$n的$l",
	"force" : 180,
        "dodge" : -5,
        "parry" : 5,
	"damage": 10,
	"lvl" : 0,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "破竹势",
	"damage_type":"挫伤"
]),
([	"action":"$N一招「隐山谷势」，忽地$w脱手，急旋着兜了一个大圈，袭向$n的脑後",
	"force" : 220,
        "dodge" : -5,
        "parry" : 10,
	"damage": 20,
	"lvl" : 10,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "隐山谷势",
	"damage_type":"割伤"
]),
([	"action":"$N一招「隐微势」，抛出手中$w，却乘$w还未落地，右脚背在$w上一抄，那$w朝$n激飞过去，铛铛声响",
	"force" : 260,
        "dodge" : -5,
        "parry" : 5,
	"damage": 35,
	"lvl" : 20,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "隐微势",
	"damage_type":"刺伤"
]),
([	"action":"$N晃着手中$w，口中大声酣呼，一招「擒纵势」，向$n迎头击下，一抄一送，呜呜声响，兜向$n的$l",
	"force" : 300,
        "dodge" : -10,
        "parry" : 5,
	"damage": 50,
	"lvl" : 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "擒纵势",
	"damage_type":"挫伤"
]),
([      "action":"$N一招「圆满势」，右手徒松，$w竟向$n头上摔落，$w未到，已是挟着一阵疾风，声势惊人",
        "force" : 340,
        "dodge" : -10,
        "parry" : 5,
        "damage": 60,
        "lvl" : 40,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "圆满势",
        "damage_type":"刺伤"
]),
([	"action":"$N两手在$w上一推，一招「月重辉势」，画个圆弧击向$n双耳，突然手从怀中掏出$w，把$n的身形封在一片$w影中",
	"force" : 360,
        "dodge" : 0,
        "parry" : 15,
	"damage": 75,
	"lvl" : 50,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "月重辉势",
	"damage_type":"挫伤"
]),
([	"action":"$w在$N身前环饶，宛如一个大光环。$N大步踏上，一招「捉月势」，直砸$n的顶门。",
	"force" : 380,
        "dodge" : -5,
        "parry" : 20,
	"damage": 85,
	"lvl" : 60,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "捉月势",
	"damage_type":"割伤"
]),
});

int valid_enable(string usage) { return (usage == "hammer") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 50)
		return notify_fail("你的龙象舨若功修为火候太浅。\n");
	if ( (int)me->query_skill("riyue-lun", 1) >= 30
        && (int)me->query_str() < 25 )
                return notify_fail("你的臂力不够。\n");

	return 1;

}
mapping query_action(object me, object weapon)
{
	int i, level, force, neili;
	object ob;
	ob = me->query_temp("weapon");

        level   = (int) me->query_skill("riyue-lun",1);
        force = me->query_skill("force")/3;
        neili = me->query("neili")/30;

        // if I am performing, don't print out combat msg, and set damage
        if (me->query_temp("xueshan/riyue"))
        {
        return ([
        "action": HIW"$N口中喝道：第"+chinese_number(me->query_temp("xueshan/riyue"))+"招来了"NOR,
        "force" : 450+random(force),
        "dodge" : -10,
        "parry" : 20,
        "damage" : 110+random(force),
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "日月同辉",
        "damage_type":"挫伤"]);
		  }

	if ( me->query_skill_mapped("force") == "longxiang-banruo"
	&& (ob->query("name")=="法轮" || ob->query("name")=="金轮")){
	if (random(me->query_skill("hammer")) > 275 
        && me->query("neili") > 600 && ob->query_amount() >= 5){
        me->add("neili", -50);
        return ([
        "action":HIY "锵锵一阵声响，$N使出「"+chinese_number(ob->query_amount())+"轮大转」，运轮如飞，空中飞起数只$w，双手仍各握一轮，一齐砸向$n"NOR,
        "force" : 600+random(neili*3),
        "dodge" : -10,
        "parry" : 20,
        "damage" : 150+random(force*3),
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "五轮大转",
        "damage_type":"挫伤"]);
        }

        if (random(me->query_skill("hammer")) > 180 
        && me->query("neili") > 300  && ob->query_amount() > 1){
	me->add("neili", -30);
                return ([
                "action":HIW "$N两只手中"+chinese_number(ob->query_amount())+"只$w对击，声若龙吟，悠悠不绝，左手袍袖挥处，右手$w砸了出去"NOR,
                "damage": 120+random(force*2),
		"dodge" : -5,
		"force" : 500+random(neili*2),
		"parry" : 20,
		"lvl" : 80,
		"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "刺伤"]);
        }

	if (random(me->query_skill("hammer")) > 150 && ob->query_amount() >= 3 
        && me->query("neili") > 200){
	return ([      
	"action":HIC "$N掷出手中全部"+chinese_number(ob->query_amount())+"只$w，一式「显吉祥」，或直飞、或斜飞、或回旋、或下坠、或上升，霎时间$n的全部退路已被封死"NOR,
        "force" : 450+random(force),
        "dodge" : -5,
        "parry" : 25,
        "damage": 120+random(neili),
        "lvl" : 70,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "显吉祥",
        "damage_type": "挫伤"]);
	}
   }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "fa lun")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练日月轮法。\n");
	if ( (int)me->query_skill("riyue-lun", 1) >= 30
        && (int)me->query_str() < 25 )
                return notify_fail("你的臂力不够，无法继续提高日月轮法。\n");

	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"riyue-lun/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        string msg;
        int ap, dp, damage;

        ap = me->query("combat_exp")/1000;
        ap += me->query_skill("force");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("force");
        ap = (ap + random(ap*2))/2;

        msg = HIR"$N大呼酣战，口念密宗不动明王真言，运龙象之力朝$n击去！\n"NOR;

        if( me->query_temp("longxiang") && (ap > dp) ) {
                damage *= 2;
                message_vision(msg,me,victim);
        }

	return damage;
}
