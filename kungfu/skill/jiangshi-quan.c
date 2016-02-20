//Cracked by Roath
// jiangshi-quan.c 僵ㄕ拳
// qfy September 28, 1996.

inherit SKILL;

mapping *action = ({
([      "action" : "$N双臂直挺，向前一跃，插向$n的$l",
        "force" : 300,
        "dodge" : 5,
	"parry" : 10,
        "lvl" : 0,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N举起漆白的手爪，抓向$n的$l",
	"force" : 350,
        "dodge" : -5,
	"parry" : 15,
	"lvl" : 10,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一声尖叫，挺起双臂，掐向$n的颈项",
	"force" : 400,
        "dodge" : 10,
	"parry" : 10,
	"lvl" : 20,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N僵直的跳起，伸长手爪，带着凌厉的声势扑向$n",
	"force" : 450,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 30,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N吱吱的尖叫起来，突然扑向$n，手爪向$l猛然插下",
	"force" : 500,
        "dodge" : 10,
	"parry" : 15,
	"lvl" : 38,
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	return notify_fail("想学僵ㄕ拳？嘿嘿，死了这条心别作梦啦！。\n");
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("jiangshi-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"jiangshi-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("jiangshi-quan", 1)) > 30 ) {
                victim->apply_condition("xx_poison", 
                random(me->query_skill("xingxiu-duzhang", 1)/2) + victim->query_condition("xx_poison"));
        }
}
