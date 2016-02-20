//Cracked by Roath
// sanhua-zhang.c -É¢»¨ÕÆ

inherit SKILL;

mapping *action = ({
([	"action" : "$NºÏÕÆ±§Çò£¬Ò»Ê½¡¸´ºÉî·¼²Ý¾¡¡¹£¬Ë«ÕÆ±ä»ÃÍÌÍÂ£¬»º»ºÍÆÏò$nµÄ$l",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "´ºÉî·¼²Ý¾¡",
        "damage_type" : "ðöÉË"
]),
([	"action" : "$NÎåÖ¸ÕÀ¿ª£¬Ò»Ê½¡¸ÏÄÏÐ¶ÀÀ¼Ü°¡¹£¬×óÓÒÕÆ´©²å·­·É£¬¼²Ïò$nµÄ$lÅÄÈ¥",
	"force" : 260,
        "dodge" : 10,
        "parry" : 15,
	"damage": 20,
	"lvl" : 20,
	"skill_name" : "ÏÄÏÐ¶ÀÀ¼Ü°",
        "damage_type" : "ðöÉË"
]),
([	"action" : "$NÊ¹Ò»Ê½¡¸Çïº¨¾ÕËªÇå¡¹£¬×óÕÆÐéÍÐ£¬ÓÒÕÆÕ§ÉìÕ§ºÏ£¬ÃÍµØ²åÍù$nµÄ$l",
	"force" : 340,
        "dodge" : 15,
        "parry" : 20,
	"damage": 30,
	"lvl" : 40,
	"skill_name" : "Çïº¨¾ÕËªÇå",
        "damage_type" : "ðöÉË"
]),
([	"action" : "$NË«ÕÆÑªºì£¬Ò»Ê½¡¸¶¬ÎÔÌýÃ·Ò÷¡¹£¬»Ã³ÉÂþÌìÃ·»¨¶ä¶ä£¬Óêµã°ãÏò$n»÷È¥",
	"force" : 420,
        "dodge" : 20,
        "parry" : 30,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "¶¬ÎÔÌýÃ·Ò÷",
        "damage_type" : "ðöÉË"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="nianhua-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("Á·É¢»¨ÕÆ±ØÐë¿ÕÊÖ¡£\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("ÄãµÄ»ìÔªÒ»Æø¹¦»ðºò²»¹»£¬ÎÞ·¨Ñ§É¢»¨ÕÆ¡£\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·É¢»¨ÕÆ¡£\n");
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
	level   = (int) me->query_skill("sanhua-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("ÄãµÄ¾«Á¦Ì«µÍÁË¡£\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·É¢»¨ÕÆ¡£\n");

        if( (int)me->query_skill("weituo-gun", 1) < 60
        &&  (int)me->query_skill("cibei-dao", 1) < 60
        &&  (int)me->query_skill("pudu-zhang", 1) < 60
        &&  (int)me->query_skill("fengyun-shou", 1) < 60 )
                return notify_fail("Äã±ØÐëÔÚÎ¤ÍÓ¹÷£¬´È±¯µ¶£¬ÆÕ¶ÉÕÈ£¬ºÍ·çÔÆÊÖÖÐÈÎÑ¡Ò»ÃÅÁ·µ½Ò»¶¨¾³½ç²ÅÄÜÁ·É¢»¨ÕÆ¡£\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

