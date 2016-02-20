//Cracked by Roath
// yuxiao-jian.c
//kane 22/5/97  
//maco 12/30/99

#include <ansi.h>

inherit SKILL;
nomask int parry_available() { return 1; }
string *parry_msg = ({
	"却见$n身子微转，轻描淡写的以$W轻轻挡开$w，口唇未离箫边，乐声竟未有片刻停滞。\n",
});
string query_parry_msg(object weapon, object victim)
{
	object ob;

	if (!objectp(ob = victim->query_temp("weapon"))
	|| !victim->query_temp("exercise/playing"))
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action = ({
([      "action" : "$N身形一闪，手中$w一振，使出一招「山外清音」，圈转手中$w，拦腰横削，陡然呼地一声，$w反撩，风驰电挚般疾刺$n的$l",
	"force" : 100,
	"dodge" : 10,
	"parry" : -15,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "山外清音",
	"damage_type" : "刺伤"
]),
([      "action" : "$N$w一横，使出一式「金声玉振」，身随剑走，寓守于攻，对$n的招式竟是不闪不避，径直削向$n的$l",
	"force" : 120,
	"dodge" : -10,
	"parry" : 15,
	"damage": 30,
	"lvl" : 5,
	"skill_name" : "金声玉振",
	"damage_type" : "劈伤"
]),
([      "action" : "$N手中$w盘旋飞舞，使出一招「响隔楼台」，反手一剑刺出，半途中已连变好几个方位，刺向$n的$l",
	"force" : 140,
	"dodge" : 10,
	"parry" : -5,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "响隔楼台",
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w蓦然一立，使出一招「月射寒江」，$w如新月般成弧圈转，倏地一展，电光石火般刺向$n的$l",
	"force" : 170,
	"dodge" : 5,
	"parry" : -10,
	"damage": 35,
	"lvl" : 10,
	"skill_name" : "月射寒江",
	"damage_type" : "刺伤"
]),
([      "action" : "$N挺手中$w，向$n上盘刺到，正是一招「凤曲长鸣」，剑光闪烁，剑尖微颤，手中$w发出嗡嗡之声，点向$n上盘诸处大穴",
	"force" : 190,
	"dodge" : -10,
	"parry" : -5,
	"damage": 40,
	"lvl" : 15,
	"skill_name" : "凤曲长鸣",
	"damage_type" : "刺伤"
]),
([      "action" : "$N袍袖一拂，顺势使出一招「潇湘水云」，剑势连绵，泠若御风，身形一沾即走，宛如翩翩起舞，飘然刺向$n的$l",
	"force" : 210,
	"dodge" : 20,
	"parry" : -5,
	"damage": 45,
	"lvl" : 20,
	"skill_name" : "潇湘水云",
	"damage_type" : "刺伤"
]),
([      "action" : "$N伸指在$w上一弹，铮的一声清响，一招「棹歌中流」，$w中宫直进，更无丝毫花巧，凌厉无前的刺向$n的$l",
	"force" : 230,
	"dodge" : 0,
	"parry" : 45,
	"damage": 55,
	"lvl" : 20,
	"skill_name" : "棹歌中流",
	"damage_type" : "刺伤"
]),
([      "action" : "$N身形展动，使出一式「萧史乘龙」，手中$w矫夭飞舞，如神龙破空一般，刺向$n的$l，姿态飘逸，大有仙气",
	"force" : 250,
	"dodge" : 10,
	"parry" : 0,
	"damage": 45,
	"lvl" : 25,
	"skill_name" : "萧史乘龙",
	"damage_type" : "刺伤"
]),
([      "action" : "$N剑法一变，身形急趋急退，一式「飞花点翠」，剑气森森，剑势如满天花雨一般，向四面八方铺洒开来，实在令人避无可避",
	"force" : 280,
	"dodge" : 0,
	"parry" : 10,
	"damage": 50,
	"lvl" : 30,
	"skill_name" : "飞花点翠",
	"damage_type" : "刺伤"
]),
([      "action" : "$N逆踏先天八卦方位，剑交左手，徐徐使出一招「猗兰履霜」，手中$w斜指，刺向$n，剑势虚虚实实，应左则右，与通常剑理大相径庭",
	"force" : 300,
	"dodge" : -5,
	"parry" : 5,
	"damage": 50,
	"lvl" : 35,
	"skill_name" : "猗兰履霜",
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w成弧，一招「玉漏催银箭」，刺向$n，去势虽不甚急，但却占尽先机，将$n身周三尺方圆之地尽数封住",
	"force" : 320,
	"dodge" : 0,
	"parry" : 5,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "玉漏催银箭",
	"damage_type" : "刺伤"
]),
([      "action" : "$N脚步踉踉跄跄，看似已摇摇欲坠，实则足踩九宫，一招「酒阑闻塞笛」，剑势平平淡淡，若有若无地刺向$n的$l",
	"force" : 350,
	"dodge" : 0,
	"parry" : 5,
	"damage": 65,
	"lvl" : 45,
	"skill_name" : "酒阑闻塞笛",
	"damage_type" : "刺伤"
]),
([      "action" : "$N移步换形，一招「歧山别鹤」，$w脱手飞出，疾射$n的$l，接着使出分身捉影，后发先至，紧贴$w飞撩过来，骈指为剑，刺向$n",
	"force" : 380,
	"dodge" : 10,
	"parry" : -10,
	"damage": 75,
	"lvl" : 50,
	"skill_name" : "歧山别鹤",
	"damage_type" : "刺伤"
]),
([      "action" : "$N一声长啸，内力源源不绝注入剑身，剑上青芒大盛，一式「广陵止息」，剑发龙吟，一道匹练也似的剑光挟着森森剑气破空而起，宛如天河倒泻，沛然莫御",
	"force" : 400,
	"dodge" : -10,
	"parry" : -20,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "广陵止息",
	"damage_type" : "刺伤"
]),
([      "action" : "$N脚踩伏羲六十四卦方位，剑势加快，使出一招「星河千帆舞」，只见一片茫茫剑气中，无数青色光圈潮涌而至，倾刻之间$n已没入剑光之中",
	"force" : 420,
	"dodge" : 10,
	"parry" : 10,
	"damage": 95,
	"lvl" : 70,
	"skill_name" : "星河千帆舞",
	"damage_type" : "劈伤"
]),
([      "action" : "$N跨上一步，$w向前递出，其势增之一分嫌太急，减之一分嫌太缓，正是一式「天际识归舟」，剑势尤如青天白云，无暇无垢",
	"force" : 450,
	"dodge" : 0,
	"parry" : 20,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "天际识归舟",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("bitao-xuangong",1) < 50)
		return notify_fail("你的碧涛玄功火候太浅。\n");
	if ((int)me->query("shijian") > 20000+random(20000)) {
		tell_object(me, CYN"你心中一凝，似乎对桃花岛剑法精义若有所悟！\n"NOR);
		me->add("th_jianyi",1);
		me->delete("shijian");
	}
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
	int i, level, jm;
	object target;

	level   = (int) me->query_skill("yuxiao-jian",1);
	target = me->select_opponent();
	weapon = me->query_temp("weapon");
	jm = me->query_temp("th_jianmang");
	
	if (me->query_temp("final_jianmang")) {
	if( wizardp(me) )
		tell_object(me,"jm:"+jm+"\n");

	return ([
	"action":HIC"$w"NOR+HIC"上的剑芒，犹似长蛇般伸缩不定......\n\n"NOR+HIG"$N丹田中猛提一口真气，身子滴溜溜的打了半个圈子，手中$w"NOR+HIG"一挺，蓦地剑芒突盛，青芒疾刺$n$l！"NOR,
	"force" : 480+jm*20,
	"dodge" : 0,
	"parry" : 0,
	"damage": 140+jm*10,
	"weapon": HIG"剑芒"NOR,
//	"post_action": (: next_sword :),	
	"damage_type":  "刺伤"
]);
	}
	if( me->query_temp("th_jianzhi") ) 
	{
		if( wizardp(me) )
			tell_object(me,"剑指次数还有"+(me->query_temp("th_jianzhi") - 20));

	me->add_temp("th_jianzhi", -1); 
	weapon->unequip();
	
	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();

	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}
	
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练玉箫剑法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yuxiao-jian/" + action;
}
