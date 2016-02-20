//Cracked by Roath
// qianzhu-wandu.c 千蛛万毒手

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : MAG "$N左掌虚晃, 右手捏了个五彩诀, 食指指向$n的下三路要害" NOR,
	"force" : 100,
	"dodge" : 5,
	"lvl" : 0,
	"damage" : 10,
	"weapon": "指力",
	"skill_name" : "彩蛛盘网",
	"damage_type" : "刺伤"
]),
([      "action" : BLU "$N右手食指从第二指节至指尖忽然变得漆黑，径往$n$l拂去" NOR,
	"force" : 200,
	"dodge" : -5,
	"lvl" : 60,
	"damage" : 20,
	"weapon": "指力",
	"skill_name" : "乌虫乘风",
	"damage_type" : "刺伤"
]),
([      "action" : YEL "$N倏地踏前，运指成风，连点$n胸腹之间五处大穴" NOR,
	"force" : 300,
	"dodge" : 10,
	"lvl" : 100,
	"damage" : 40,
	"weapon": "指力",
	"skill_name" : "连珠毒箭",
	"damage_type" : "刺伤"
]),
([      "action" : CYN "$N脸上黑气大盛，指风掌影猛然暴张，快逾电光石火，戳向$n的$l" NOR,
	"force" : 400,
	"dodge" : 25,
	"lvl" : 150,
	"damage" : 80,
	"weapon": "指力",
	"skill_name" : "万蛛毒",
	"damage_type" : "刺伤"
])
});

string *dodge_msg = ({
        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
        "$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
});

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string type() { return "knowledge";}

int valid_enable(string usage) { 
	return  usage=="hand" ||
		usage=="finger" || 
		usage=="parry"  ||
		usage=="dodge"  ||
		usage=="force";
}

int valid_combine(string combo) { return combo=="qianzhu-wandu"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("qianzhu-wandu", 1) > 10)
		return notify_fail("千蛛万毒手只能自己修练。\n");
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
    int level = me->query_skill("qianzhu-wandu", 1);
    int i, j, n;

    for (n=0; n<sizeof(action); n++) {
	if (level < action[n]["lvl"]) {
	    break;
	}
    }
    i = random(n);
    j = random(n);

    if (wizardp(me))  
	tell_object(me, sprintf("lvl=%d, n=%d, i=%d, j=%d\n", level, n, i, j));
    if (i>j) return action[i];
    return action[j];
}

int practice_skill(object me)
{
	return notify_fail("千蛛万毒手不是这么练的。\n");
}

string perform_action_file(string action)
{
        return __DIR__"qianzhu-wandu/" + action;
}

string exert_action_file(string action)
{
	notify_fail("getting qzwd.heal ");
        return __DIR__"qianzhu-wandu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if( random(me->query_skill("qianzhu-wandu", 1)) > 10 ) {
	victim->apply_condition("qianzhu-poison", 
	    me->query_skill("qianzhu-wandu", 1)/10 + 
		victim->query_condition("qianzhu-poison"));
        if(victim->query("poisoner") != me)	victim->set("poisoner", me);
    }
}

void skill_improved(object me)
{
  int level = me->query_skill("qianzhu-wandu",1);
  int o_lvl = me->query("qianzhu-wandu/old_lvl");
 
  if ( o_lvl < level && level > 100) {
      if ( level%10 == 1) {
	if (me->query("per") > 0) {
	    tell_object(me, 
	        "你觉得体内的千蛛毒气翻腾不止，你脸上浮肿又加重了。\n");
	    me->add("per", -1);
	}
        me->set("qianzhu-wandu/old_lvl", level);
      }
  }
}
