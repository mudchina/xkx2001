// yinsuo-jinling.c ÒøË÷½ğÁ

#include <ansi.h>
inherit SKILL;

string  *msg = ({
"$N×óÊÖÇáÑï£¬ÊÖÖĞ$wºöµØË¦ÁË³öÀ´£¬Ö±ÆË$nµÄ$l¡£ÕâÒ»ÏÂÀ´µÃÎŞÉùÎŞÏ¢£¬ÊÂÏÈ¾¹Ã»°ëµãëŞÕ×",
"$NÊÖ³Ö$w½ÃÊ¸ËÆÁéÉß»÷Ïò$n£¬ÔÙ¼ÓÁ½Ã¶½ğÇò²»¶Ï·¢³öçàçàÖ®Éù£¬¸üÊÇÈÅÈËĞÄÆÇ",
"ÓÖÌıµÃ½ğÇòÖĞ·¢³öçàçàÉùÏì£¬ÉùËä²»´ó£¬È´ÊÇÊ®·Ö¹ÖÒì£¬Èë¶úµ´ĞÄÒ¡ÆÇ¡£$n´ó¾ªÖ®ÏÂ£¬Éí×ÓááÑö£¬$wÀëÁ³Êı´ç¼±ÂÓ¶ø¹ı",
"$NÊÖÍóÎ¢¶¶£¬$w·­½«¹ıÈ¥£¬×ÔÏÂ¶øÉÏ£¬´òÏò$nÉíÉÏ$l´¦µÄ¡¸ºÏ¹ÈÑ¨¡¹",
"$NË«ÊÖÆë»Ó£¬$wÓÌÈçË®Éß°ãòêÑÑ¶ø³ö£¬çàçàÁ½Ïì£¬½ÓÖøÓÖÊÇçàçàÁ½Ïì£¬$nÊÖÍóÉÏµÄ¡¸ÁéµÀÑ¨¡¹¶¼±»ÁıÕÖÔÚ$wÖ®ÏÂ",
"$NÎ¢Î¢Ò»Ğ¦¿çÇ°Ò»²½£¬ÓÒÊÖ$wÒ»¶¶£¬$w½ÃØ²·ÉÎè£¬ºÃ±È²Ê·ï³¯ÑôÒ»°ã³éÏò$n",
});

int valid_enable(string usage){ return (usage == "whip") || (usage == "parry"); }

mapping query_action(object me, object weapon)
{    
	return ([           
	"action":msg[random(sizeof(msg))],           
	"damage":(random(2)+1)*40,           
	"damage_type":random(2)?"±ŞÉË":"±ŞÉË",           
	"dodge":random(45)-random(15),           
	"force":random(300)+50           
	]);
}

int valid_learn(object me)
{       
	object weapon;       
	if( (int)me->query("max_neili") < 100 )               
		return notify_fail("ÄãµÄÄÚÁ¦²»×ã£¬Ã»ÓĞ°ì·¨Á·ÒøË÷½ğÁå¡£\n");       
	if ((int)me->query_skill("yunu-xinjing", 1) < 100)               
		return notify_fail("ÄãµÄÓñÅ®ĞÄ¾­ÄÚ¹¦»ğºòÌ«Ç³¡£\n");       
	if ( !objectp(weapon = me->query_temp("weapon")) || ( string)weapon->query("skill_type") != "whip" )               
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");       
	return 1;
} 

int practice_skill(object me)
{       
	object weapon;       
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")               
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");       
	if ((int)me->query_skill("yunu-xinjing", 1) < 25)               
		return notify_fail("ÄãµÄÓñÅ®ĞÄ¾­ÄÚ¹¦»ğºòÌ«Ç³¡£\n");         
	if ((int)me->query("jingli") < 50)               
		return notify_fail("ÄãµÄ¾«Á¦²»¹»Á·ÒøË÷½ğÁå¡£\n");       
	if ((int)me->query("neili") < 30)               
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·ÒøË÷½ğÁå¡£\n");        
	me->receive_damage("jingli", 30, "¾«Á¦Í¸Ö§¹ı¶ÈËÀÁË¡£");
	me->add("neili", -15);       
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{      
	object weap,weap1;      
	weap = victim->query_temp("weapon");      
	weap1 = me->query_temp("weapon");     

	if( (me->query_skill("yinsuo-jinling") > 150) 
		&& (me->query("neili") > 700) 
		&& (victim->query_temp("weapon")) 
		&& random(10) > 7)
		{       
		message_vision(HIW "Ö»¼û$N»ÓÎè" + weap1->name() + "£¬×ª³öÎŞÊı¸ö´óĞ¡È¦×Ó£¬ÒÔÒõÈáÖ®¾¢²ø×¡ÁË$nµÄ" + weap->name() +"£¡\n" NOR, me, victim  );            
		victim->start_busy(1);       

		if (random(me->query_str() + me->query_dex()) > victim->query_str() + me->query_dex()){
		message_vision(HIY "\n$NÆøÔËÊÖ±ÛÓÃÁ¦Ò»×§£¬" + weap->name()  + "È´ÎŞ·¨´Ó"+weap1->name()+"µÄ²øÈÆÖĞÍÑ¿ª£¬Çé¼±Ö®ÏÂÖ»ºÃ·ÅÆúÁËÊÖÖĞµÄ" + weap->name()  + "¡£\n" NOR, victim );       
		weap->move(environment(me));       
		victim->reset_action();       
		} 

		else {      
		message_vision(HIY "\n$N°µÔËÇÉ¾¢£¬" + weap->name()   + "Ë³×Å·½Ïò¿ìËÙĞı×ªÊıÏÂ£¬½â¿ªÁË"+weap1->name()+"µÄ²øÈÆ¡£\n" NOR, victim );      
		victim->add("neili", -50);      
		}      

	me->add("neili", - (20+random(30)));      
	}      
	return 1;
}

string perform_action_file(string action)
{      
return __DIR__"yinsuo-jinling/" + action;
}