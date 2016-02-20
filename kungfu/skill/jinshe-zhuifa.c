//Cracked by Roath
// jinshe-zhuifa 金蛇锥法
// qfy September 18, 1996

#include <ansi.h>
inherit SKILL;

string* xuedao = ({
        "四白穴",
        "地仓穴",
        "大迎穴",
        "峡车穴",
        "头维穴",
        "下关穴",
        "隐白穴",
        "太白穴",
        "商丘穴",
        "地机穴",
	"少冲穴",
        "少海穴",
        "通理穴",
        "神门穴",
        "印堂穴",
        "金律穴",
        "玉液穴",
        "鱼腰穴",
        "百劳穴",
        "百会穴",
        "灵台穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "气海穴"
});

mapping *action1 = ({
([	"action":"$N拿起一枚$w，对准$n一扬手，将$w笔直射向$n的"+xuedao[random(sizeof(xuedao))],
	"force" : 120,
        "dodge" : 20,
	"damage": 20,
	"number": -1,
	"lvl" : 0,
]),
([	"action":"$N双手连挥，两枚$w带着呼啸风声，划成二弧射向$n的"+xuedao[random(sizeof(xuedao))]+"和"+xuedao[random(sizeof(xuedao))],
	"force" : 180,
        "dodge" : 30,
	"damage": 40,
	"number": -2,
	"lvl" : 5,
]),
([	"action":"$N飞身跃起，居高临下向$n猛射三枚$w，直取$n的双目和"+xuedao[random(sizeof(xuedao))],
	"force" : 220,
        "dodge" : 30,
	"damage": 60,
	"number": -3,
	"lvl" : 15,
]),
([	"action":"突然$N低头恭身，只听得「嗖」的一声，一枚$w由后领飞出，往$n的"+xuedao[random(sizeof(xuedao))]+"电射而去",
	"force" : 260,
        "dodge" : 15,
	"damage": 40,
	"number": -1,
	"lvl" : 25,
]),
([	"action":"但见$N将双手拢入袖中，无声无息地发出一枚$w，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比",
	"force" : 300,
        "dodge" : 25,
	"damage": 50,
	"number": -1,
	"lvl" : 35,
]),
([      "action":"$N一笑而退，伸手却在腰间一拍，两枚$w由胸前猛然射出，飞取$n的咽喉及"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 70,
        "number": -2,
        "lvl" : 45,

]),
([      "action":"$N双手同挥发出两枚$w攻向$n双目，张口一吐又是一枚$w，后来居上地超越前两枚$w，急劲地射至$n的"+xuedao[random(sizeof(xuedao))],
	"force" : 380,
        "dodge" : 30,
        "damage": 85,
        "number": -3,
        "lvl" : 45,
]),
});

mapping *action2 = ({
([      "action":"$N拿起一枚$w，对准$n一扬手，将$w笔直射向$n的"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 20,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"$N双手连挥，两枚$w带着呼啸风声，划成二弧射向$n的"+xuedao[random(sizeof(xuedao))]+"和"+xuedao[random(sizeof(xuedao))],
        "force" : 180,
        "dodge" : 30,
        "damage": 40,
        "number": -2,
        "lvl" : 5,
]),
([      "action":"突然$N低头恭身，只听得「嗖」的一声，一枚$w由后领飞出，往$n的"+xuedao[random(sizeof(xuedao))]+"电射而去",
        "force" : 260,
        "dodge" : 15,
        "damage": 40,
        "number": -1,
]),
([      "action":"但见$N将双手拢入袖中，无声无息地发出一枚$w，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比",
        "force" : 300,
        "dodge" : 25,
        "damage": 50,
        "number": -1,
        "lvl" : 35,
]),
([      "action":"$N一笑而退，伸手却在腰间一拍，两枚$w由胸前猛然射出，飞取$n的咽喉及"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 70,
        "number": -2,
        "lvl" : 45,
]),
});

mapping *action3= ({
([      "action":"$N拿起一枚$w，对准$n一扬手，将$w笔直射向$n的"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 20,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"突然$N低头恭身，只听得「嗖」的一声，一枚$w由后领飞出，往$n的"+xuedao[random(sizeof(xuedao))]+"电射而去",
        "force" : 260,
        "dodge" : 15,
        "damage": 40,
        "number": -1,
]),
([      "action":"但见$N将双手拢入袖中，无声无息地发出一枚$w，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比",
        "force" : 300,
        "dodge" : 25,
        "damage": 50,
        "number": -1,
        "lvl" : 35,
]),
});

int valid_enable(string usage) { return usage == "throwing" ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("你的内功火候太浅。\n");

	if ((int)me->query_int() < 30)
		return notify_fail("你的悟性不够，无法领悟金蛇锥法。\n");

        if ((int)me->query_con() < 20)
                return notify_fail("你的根骨不够，无法练金蛇锥法。\n");

	if (!present("jinshe miji", me)) 
                return notify_fail("练习金蛇锥法必须一面研读《金蛇密籍》。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	mapping act;

	level   = (int) me->query_skill("jinshe-zhuifa",1);

	if ( weapon->query_amount() >= 3 ) {
           for(i = sizeof(action1); i > 0; i--) {
                if(level > action1[i-1]["lvl"]) {
			act = action1[NewRandom(i, 20, level/5)];
			if (weapon->query_amount()==3 && (int)act["number"]==-3) {
				weapon->unequip();
				tell_object(me, HIR "你的"+weapon->name()+"用光了！\n" NOR);
			}
			weapon->add_amount(act["number"]);
                        return act;
		}
	    }
	}

	if ( weapon->query_amount() >= 2 ) {
	   for(i = sizeof(action2); i > 0; i--) {
		if(level > action2[i-1]["lvl"]) {
			act = action2[NewRandom(i, 20, level/5)];
			if (weapon->query_amount()==2 && (int)act["number"]==-2) {
				weapon->unequip(); 
				tell_object(me, HIR "你的"+weapon->name()+"用光了！\n" NOR);
			}
                        weapon->add_amount(act["number"]);
                        return act;
                }
	    }
	}

	for(i = sizeof(action3); i > 0; i--) {
           if (level > action3[i-1]["lvl"]) {
			weapon->unequip();
                        weapon->add_amount(-1);
			tell_object(me, HIR "你的"+weapon->name()+"用光了！\n" NOR);
			return action3[NewRandom(i, 20, level/5)];
	   }
	}
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练金蛇锥法。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhuifa/" + action;
}
