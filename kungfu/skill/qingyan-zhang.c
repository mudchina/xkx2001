//Cracked by Roath
// qingyan-zhang.c ÎåÂÞÇáÑÌÕÆ
//cyz
inherit SKILL;

mapping *action = ({
([	"action" : 
"$NË«ÕÆ±ä»ÃÍÌÍÂ£¬Ò»Ê½¡¸ÇáÑÌôÁôÁ¡¹ÅÄÏò$nµÄ$l",
	"force" : 90,
        "dodge" : 5,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "ÇáÑÌôÁôÁ",
        "damage_type" : "ðöÉË"
]),
([	"action" : 
"$NÉíÐÎÎ¢²à£¬ÓÒÕÆÒ»Ê½¡¸ÑÌÎíçÔÈÆ¡¹ÐÐÔÆÁ÷Ë®°ãÏòºóÐ±Ð±ÅÄ³ö",
	"force" : 140,
        "dodge" : 10,
        "parry" : 15,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "ÑÌÎíçÔÈÆ",
        "damage_type" : "ðöÉË"
]),
([	"action" : 
"$NË«ÕÆÀ´»ØÅÌÐý£¬½«$nµÄ$lÁýÕÖÔÚÕÆ·çÖ®ÏÂ£¬Ò»Ê½¡¸ÑÌº£ÔÆÌÎ¡¹Ïò$n»÷È¥",
	"force" : 180,
        "dodge" : 15,
        "parry" : 20,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "ÑÌº£ÔÆÌÎ",
        "damage_type" : "ðöÉË"
]),
([      "action" :   
"$NÒ»Ê½¡¸ÔÆÑÌÃìÃì¡¹£¬Á³É«Ò»Æ¬²Ô°×£¬Ë«ÕÆ»Ã³ÉÂþÌì·ÉÑ©£¬Óêµã°ãÏò$nÅÄÏÂ",
        "force" : 210,
        "dodge" : 15,
        "parry" : 25,
        "damage": 35,
        "lvl" : 30,
        "skill_name" : "ÔÆÑÌÃìÃì",
        "damage_type" : "ðöÉË"
]),
([      "action" :   
"$NÉíÐÎ»Î¶¯£¬»Ã³ÉÊýÌõ»ÃÓ°Î§ÈÆ×Å$nÓÎ×ß£¬ºöµÄÅÄ³öÒ»ÕÆÐý¼´ÉÁ¿ª£¬ºÃÒ»Ê½¡¸ÑÌÎíÃÖÂþ¡¹",
        "force" : 260,
        "dodge" : 15,
        "parry" : 25,
        "damage": 50,
        "lvl" : 40,
        "skill_name" : "ÑÌÎíÃÖÂþ",
        "damage_type" : "ðöÉË"
]),
([      "action" :
"$NË«ÕÆÒ»²¢£¬Ò»Ê½¡¸ÑÌÏûÔÆÉ¢¡¹ºÏÉí³å½ø$nµÄ»³Àï£¬ÒâÍ¾Æ´¸öÄãËÀÎÒ»î",
       
	"force" : 420,
        "dodge" : 40,
        "parry" : 30,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "ÑÌÏûÔÆÉ¢",
        "damage_type" : "ðöÉË"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("Á·ÎåÂÞÇáÑÌÕÆ±ØÐè¿ÕÊÖ¡£\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20
		&& (int)me->query_skill("beiming-shengong", 1) < 20)
	return notify_fail("ÄãµÄ¿ÝÈÙìø¹¦»ðºò²»¹»£¬ÎÞ·¨Ñ§ÎåÂÞÇáÑÌÕÆ¡£\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·ÎåÂÞÇáÑÌÕÆ¡£\n");
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
	level   = (int) me->query_skill("qingyan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("ÄãµÄ¾«Á¦Ì«µÍÁË¡£\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·ÎåÂÞÇáÑÌÕÆ¡£\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

