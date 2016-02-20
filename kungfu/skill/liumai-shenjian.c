//Cracked by Roath
#include <ansi.h>
#include <mudlib.h>


inherit SKILL;
inherit F_DAMAGE;

string *skill_name = ({
        "少商",
        "商阳",
        "中冲",
        "关冲",
        "少冲",
        "少泽",
});

mapping *action = ({
	([
		"action":"$N右手小指一伸，一条气流从少冲穴中激射而出，射向$n的$l",
		"force" : 500,
		"dodge" : 500,
//		"damage" : 100,
		"weapon": "无形剑气",
		"lvl" : 0,
		"damage_type" : "刺伤"
		]),
		([
		"action":"$N「少泽剑」忽来忽去，变化精微。$n神色错愕间忽觉$l一痛",
		"force" : 530,
		"dodge" : 500,          
		"weapon": "无形剑气",
		"lvl" : 10,
		"damage_type" : "刺伤"
		]),
		([
		"action":"$N中指一竖，「中冲剑」剑式向前急掣而出",
		"force" : 550,
		"dodge" : 500,
		"weapon": "无形剑气",
        "lvl" : 30,
        "damage_type" : "刺伤"
		]),
		([      
		"action":"$N中指划动，「中冲剑」大开大阖，气势雄迈。$n顿时上蹿下跳神色狼狈",
		"force" : 580,
		"dodge" : 600,
		"weapon": "无形剑气",
		"lvl" : 45,
		"damage_type" : "刺伤"
		]),
		([
		"action":"$N左手小指一点一捺，「少泽剑」意味古拙，剑气纵横，$n莫辨其方向，难以招架",
		"force" : 600,
		"dodge" : 600, 
		"weapon": "无形剑气",
		"lvl" : 60,
		"damage_type" : "刺伤"
		]),
		([
		"action":"$N右手食指向$n急指，内力自然而然从食指中涌出，正是“六脉神剑”中“商阳剑”的一招",
		"force" : 600,
		"dodge" : 600,
		"weapon": "无形剑气",
		"parry" : 120,
		"lvl" : 75,
		"damage_type" : "刺伤"
		]),
		([      
		"action":"$N六脉剑法纵横飞舞，大开大阖，气派宏伟，每一剑刺出，都有石破天惊、风雨大至之势",
		"force" : 600, 
		"dodge" : 600,
		"weapon": "无形剑气",
		"lvl" : 150,
		"damage_type" : "刺伤"
		]),
});  

int valid_enable(string usage)
{
        return usage == "finger" || usage == "parry";
}

int valid_learn(object me)
{
        int fi,ff,fl,fy;
        fy = (int)me->query_skill("yiyang-zhi", 1);
        fl = (int)me->query_skill("liumai-shenjian", 1);
        ff = (int)me->query_skill("force", 1);
        fi = (int)me->query_skill("finger", 1);

        if ( fl  >= 20 && fy < 140 && fy <= fl )
                return 
notify_fail("你的一阳指火候还不够，无法修练更高深的六脉神剑。\n");

        if  ( fl >= 160 || fi < 140 )
                return 
notify_fail("你的基本指法不够火候，无法修练更高深的六脉神剑。\n");

        if ( ff < 140 || ff/2 < fl/3 )
                return 
notify_fail("你的基本内功火候还不够，无法修练更高深的六脉神剑。\n");

        return 1;
}


int practice_skill(object me)
{
                if ((int)me->query("jingli") < 60)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练六脉神剑。\n");
        me->receive_damage("jingli", 10);
        me->add("neili", -10);
        return 1;

}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("liumai-shenjian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_skill_name(int level)
{
        return skill_name[level/30];
}

string perform_action_file(string action)
{
    return __DIR__"liumai-shenjian/" + action;
}

void skill_improved(object me)
{
        int level = me->query_skill("liumai-shenjian",1);
        int lm_lvl = me->query("liumai_lvl");
        int i;

        if ( level/15*15 == level ) {
                tell_object(me, HIG "你对「" + skill_name[level/30-1] + "」已豁然贯通。\n"NOR);
                if (lm_lvl < level) {
                        tell_object(me, HIG"顿时你对一阳指的领悟也大大提高。\n"NOR);
                        for (i=0; i< level; i++)                
                                me->improve_skill("yiyang-zhi", level);
                }
        }

        if ( level/30*30 == level ) 
                if (lm_lvl < level) {
                        tell_object(me, HIY"此时你" + skill_name[level/60-1] +"剑融会贯通，对以指力驱使无形剑气又深了一层了解，指法修为更精深了一层。\n"NOR);
                        me->improve_skill("finger", level*70);
                }

        if ( lm_lvl < level ) me->set("liumai_lvl", level);
                
}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
int damage_bouns;

if (victim->query("combat_exp") > 50) 
{
return "aaaaaaaaaaaa";
}
}
*/
