//Cracked by Roath
// yujia-muquan ½ð¸Õè¤çìÄ¸È­
// qfy, chage, paoshou Sept 26, 1996
// Ryu, 11/14/96.

inherit SKILL;

mapping *action = ({
([      "action" : "$Nµ¥È­¡¸¹à¶¥¡¹££¬åÉÖ±Ïò$nµÄÌìÁé¸ÇÅüÏÂ",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "¹à¶¥",
        "damage_type" : "ðöÉË"
]),
([	"action" : "$NË«ÊÖ°Ú¡¸½â¿à¡¹Ê½£¬ÎÕÈ­²àÖÃÓÚÉí£¬ÑÛÍûÓÒÉÏ·½£¬ºöµÄÔ¾Æð¿ÚÖÐ±©ºÈ£¬Ò»È­µ·Ïò$nµÄ$l",
	"force" : 170,
        "dodge" : 5,
	"lvl" : 8,
	"skill_name" : "½â¿à",
	"damage_type" : "ðöÉË"
]),
([	"action" : "$NÊÕÁ³¡¸ò­Ã¼¡¹£¬×óÊÖÐéÑÚ£¬ÓÒÈ­´©³ö£¬È­ÊÆÈçÑæßÁÅ¾±¬ÏìµØ»÷Íù$n$l",
	"force" : 200,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 16,
	"skill_name" : "ò­Ã¼",
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÒ÷ÎÞÖ÷Öä£¬Ò»Ê½¡¸àÁí£¡¹£¬ÊÕÈ­³ö¹Õ£¬¿ÄÏò$nµÄ$l",
        "force" : 240,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 24,
        "skill_name" : "àÁí£",
        "damage_type" : "ÄÚÉË"
]),
([	"action" : "$N×÷¡¸¾²¼Å¡¹Ê½£¬µÍ·üÔÚµØ£¬ÃÍÈ»·­ÉíÌøÆð£¬Ë«ÊÖË«½ÅÆë³ö£¬½«$nÁýÕÖÔÚÈ­·çÏÂ",
	"force" : 280,
        "dodge" : 15,
	"damage": 10,
	"lvl" : 32,
	"skill_name" : "¾²¼Å",
        "damage_type" : "ÄÚÉË"
]),
([      "action" : "$N×ó±ÛÎ¢Ì§£¬ÐÄÄî¡¸ÃîÒô¡¹£¬ÎÕÈ­Èç¹³£¬»÷Ïò$nµÄ$l",
        "force" : 320,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "ÃîÒô",
        "damage_type" : "ðöÉË"
]),
([      "action" : "$N½ÅÌ¤¿ÕÐÐ²½£¬Ê¹³öÒ»ÕÐ¡¸Ã÷ÐÄ¡¹£¬ÈÆµ½$nÉí²à£¬Ë«È­ÕÅ¿ª£¬²åÏò$nµÄ$l",
        "force" : 320,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 48,
        "skill_name" : "Ã÷ÐÄ",
        "damage_type" : "ÄÚÉË"
]),
([	"action" : "$NË«È­ÖÃÓÚÉíºó£¬Î¢Ð¦ÖÐºóÍËÁ½²½£¬³Ã$n³ÙÒÉ¼ä»íÈ»³åÉÏ£¬Ò»ÕÐ¡¸ÖÆÊ¤¡¹Ë«È­¹áÏò$nÁ½¶ú",
	"force" : 360,
        "dodge" : 5,
	"damage": 20,
	"lvl" : 56,
	"skill_name" : "ÖÆÊ¤",
        "damage_type" : "ðöÉË"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="dashou-yin"; } 

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("Á·½ð¸Õè¤çìÄ¸È­·¨±ØÐë¿ÕÊÖ¡£\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 10
	&& (int)me->query_skill("xiaowuxiang", 1) < 10){
		return notify_fail("ÄãµÄÄÚ¹¦ÐÞÎª»ðºò²»¹»£¬ÎÞ·¨Ñ§½ð¸Õè¤çìÄ¸È­·¨¡£\n");
	}
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·½ð¸Õè¤çìÄ¸È­·¨¡£\n");
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
	level   = (int) me->query_skill("yujiamu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("ÄãµÄ¾«Á¦Ì«µÍÁË¡£\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·½ð¸Õè¤çìÄ¸È­·¨¡£\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yujia-muquan/" + action;
}
