//Cracked by Roath

//tanzhi-shentong.c
//kane 4/9/97 
#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

string* xuedao = ({
	"巨骨穴",
	"地仓穴",
	"肩井穴",
	"颊车穴",
	"承泣穴",
	"风池穴",
	"章门穴",
	"风府穴",
	"精促穴",
	"陶道穴",
	"强间穴",
	"少海穴",
	"犊鼻穴",
	"神门穴",
	"华盖穴",
	"大椎穴",
	"凤尾穴",
	"至阳穴",
	"劳宫穴",
	"百会穴",
	"灵台穴",
	"太阳穴",
	"膻中穴",
	"命门穴",
	"鸠尾穴",
	"三阴交",
	"天柱穴"
});

mapping *action = ({
([      "action" : "$N曲起食指，嗤的一声轻响，一股细细气劲射向$n"+xuedao[random(sizeof(xuedao))],
	"force" : 250,
	"dodge" : 0,
	"parry" : 0,
	"damage": 25,
	"lvl" : 0,
	"weapon": "指力", 
	"damage_type" : "刺伤"
]),
([      "action" : "$N扣住中指，哧哧哧连弹三下，三缕指风锋锐若剑，风驰电挚般射向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))],
	"force" : 300,
	"dodge" : 20,
	"parry" : 15,
	"damage": 40,
	"lvl" : 20,
	"weapon": "指风",
	"damage_type" : "刺伤"
]),
([      "action" : "$N扣起中指、无名指，一齐弹出，中指指劲激射$n"+xuedao[random(sizeof(xuedao))]+"，无名指上暗劲则已悄无声息的掩至"+xuedao[random(sizeof(xuedao))],
	"force" : 350,
	"dodge" : 25,
	"parry" : 20,
	"damage": 50,
	"lvl" : 40,
	"damage_type" : "内伤"
]),
([      "action" : "$N双足不丁不八，踏着东方乙木之位，食中二指反扣住拇指，一声长啸，反手弹出，但见一股凌厉无极的指劲激射向$n的"+xuedao[random(sizeof(xuedao))],
	"force" : 400,
	"dodge" : 30,
	"parry" : 15,
	"damage": 60,
	"lvl" : 60,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N冷哼一声，双手笼入袖中，脸上青气一闪即逝，几缕指风已无声无息的袭向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"数处要穴",
	"force" : 450,
	"dodge" : 40,
	"parry" : 10,
	"damage": 80,
	"lvl" : 80,
	"weapon": "指风",
	"damage_type" : "刺伤"
]),
([      "action" : "$N面色凝重，真气流转，只见$N右手中指渐变为淡青色，缓缓弹向$n，$n只觉胸口一窒，被一股森寒之极的指风压得几乎连气也喘不过来",
	"force" : 500,
	"dodge" : 50,
	"parry" : 10,
	"damage": 100,
	"lvl" : 100,
	"damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

//int valid_combine(string combo) { return combo=="lanhua-fuxue"; }

int valid_learn(object me)
{
	if (me->query("family/master_name") != "黄药师")
		return notify_fail("弹指神通乃桃花岛绝技，必需向黄药师请教。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练弹指神通必须空手。\n");
	if ((int)me->query_skill("bitao-xuangong", 1) <60)
		return notify_fail("你的碧涛玄功火候不够，无法学弹指神通。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练弹指神通。\n");
	if ((int)me->query_skill("finger", 1) <60)
	   return notify_fail("你的基本指法火候不够，无法学弹指神通。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;        
	object victim, w;

	if( !victim && me->is_fighting() ) victim = offensive_target(me);
	w = victim->query_temp("weapon");
        level   = (int) me->query_skill("tanzhi-shentong",1);
/*
	if ((w) && random(level)>random(400) && me->query("neili")>600) {
        	me->add("neili", -100);	
        	message_vision(HIG"$N冷笑一声，伸出食中二指向$n手中的"+w->name()+HIG"弹去！\n"NOR,me,victim);
        	remove_call_out("bash_weapon");
		call_out("bash_weapon",0, me, victim);
        }
*/	
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 80)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练弹指神通。\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
       return __DIR__"tanzhi-shentong/" + action;
}

int bash_weapon(object me, object victim)
{
        object ob;
        int wap, wdp;
//      string attack_skill;
//      attack_skill = weapon->query("skill_type");

        if( (me->query("neili") > 100)
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)me->query("neili") / 20
                        + (int)me->query("max_neili")/2
                        + (int)me->query_str()
                        + (int)me->query_skill("tanzhi-shentong",1)/2;
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query("neili")/15;
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$N只觉得手中" + ob->name() + "把持不定，脱手飞出！\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision(HIW "只听见「啪」地一声，$N手中的" + ob->name() + "已经断为两截！\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
//                      ob->set("value", (int)ob->query("value") / 10);
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > wdp / 2 ) {
                        message_vision("$N只觉得手中" + ob->name() + "一震，险些脱手！\n",
                                victim);
                } 
/*		else {
                        message_vision("$N射出的小石子和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                }*/
        }
}
