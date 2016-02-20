//Cracked by Roath
// jueming-tui.c

inherit SKILL;

mapping *action = ({
([      "action": "$nÓÃÓÒ½Å¹³Ìß$N×ó½ÅÏÂÅÌ£¬$NÌá½Å±Ü¿ª$n·æÃ¢£¬Ò»ÕÐ¡¸ºÚ»¢µÅÉ½¡¹£¬\n"
                  "Ñ¸ËÙÃÍÁ¦µØÁ¬Ðøõß»÷$nµÄ$l¡£",
        "dodge": 10,
        "force": 200,
        "damage_type": "ðöÉË"
]),
([      "action": "$nÓÒÈ­»÷$NÍ·²¿£¬$NÉÏÌåºóÉÁ£¬Í¬Ê±ÆðÓÒ½ÅÃÍµÅ$n¸¹²¿£¬¡¸°×Ô³µÇÖ¦¡¹£¬\n"
                  "Í»È»±ä²àõßÍÈÃÍÁ¦õß»÷$n$l¡£",
        "dodge": 25,
        "force": 180,
        "damage_type": "ðöÉË"
]),
([      "action": "$N×óÈ­ÁÃ²¦$nÈ­Í·£¬ÓÒ½ÅÄÚ²à²È»÷$nµÄëÖ¹Ç£¬Ò»ÕÐ¡¸»¢Î²½ÁÁÖ¡¹\n"
                  "²àõßÍÈ¹¥»÷$n$l",
        "dodge": -40,
        "force": 120,
        "damage_type": "ðöÉË"
]),
([      "action": "$NÓÃÓÒ½Å¹³Ìß$n×óÍÈÏÂÅÌ£¬Í¬Ê±ÓÒ¹³ÌßÍ»È»ºáÉ¨$nÑü²¿£¬Ò»ÕÐ¡¸·ç¾í²ÐÒ¶¡¹",
        "dodge": -50,
        "force": 160,
        "damage_type": "ðöÉË"
]),
([      "action": "$nÓÃÓÒÈ­ÃÍ»÷$NÃæ²¿£¬$NËÙÓÃÓÒÀïºÏÍÈ¹ÒÀ¹$nÍó²¿£¬Ò»ÕÐ¡¸¼²ÀË·­»¨¡¹£¬\n"
                  "±äÎª²àõßÍÈõß$nµÄ$l",
        "dodge": 60,
        "force": 200,
        "damage_type": "ðöÉË"
]),
([      "action": "$NÍ»·¢ÓÒÍÈµ¯Ìß$nñÉ²¿£¬¡¸ÀË×ÓÌßÇò¡¹£¬ÓÒÍÈËÙ±äµã½ÅÃÍÁ¦Ìß»÷$nÖ®$l",
        "dodge": 70,
        "force": 250,
        "damage_type": "ðöÉË"
]),
([      "action": "$NÓÃÓÒ½Å¹³Ìß$n×ã¸ù£¬Ê¹³ö¡¸Ë³·ç³¶Æì¡¹£¬Ë³ÊÆ±äÎªºáÍÈ£¬²àµ¹¼²É¨$n$l",
        "dodge": 80,
        "force": 100,
        "damage_type": "ðöÉË"
]),
([      "action": "$NÆðÓÒ½Åµ¯Ìß$nµµ²¿£¬Ò»ÕÐ¡¸Ò°Âí±¼Ìã¡¹£¬µ¯ÌßÖ®ÍÈ¼²±äÎª²àõßÍÈ£¬ÃÍÁ¦¹¥»÷$n$l",
        "dodge": 90,
        "force": 300,
        "damage_type": "ðöÉË"
]),
});

int valid_enable(string usage) { return  usage=="kick"; }
int valid_combine(string combo) { return combo=="huagu-mianzhang"; }

int valid_learn(object me)
{
//        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//                return notify_fail("Á·¾öÃüÍÈ±ØÐë¿ÕÊÖ¡£\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("ÄãµÄ¶¾Áú´ó·¨»ðºî²»¹»£¬ÎÞ·¨Ñ§¾öÃüÍÈ¡£\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·¾öÃüÍÈ¡£\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 40)
                return notify_fail("ÄãµÄ¾«Á¦Ì«µÍÁË¡£\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·¾öÃüÍÈ¡£\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jueming-tui/" + action;
}
