//Cracked by Roath
// duoming-bi.c	¶áÃüÅÐ¹Ù±Ê

inherit SKILL;

mapping *action = ({
([      "action": "$NÊ¹³ö¶áÃüÅÐ¹Ù±Ê£¬ÊÖÖÐ$w´ó¿ª´óãØÉ¨Ïò$nµÄ$l",
        "force" : 180,
        "dodge":  -5,
        "damage": 30,
        "damage_type": "´ìÉË",
        "lvl" : 0,
        "skill_name" : "¶áÃüÅÐ¹Ù±Ê",
]),
	// add more actions
});

int valid_enable(string usage) { return (usage == "pike") || (usage == "parry")
					|| (usage == "halberd");}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 80)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("duoming-bi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("ÄãÃ»ÓÐÎäÆ÷¡£\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("ÄãµÄ¾«Á¦²»¹»Á·¶áÃüÅÐ¹Ù±Ê¡£\n");
        me->receive_damage("jingli", 25);
        return 1;
}

