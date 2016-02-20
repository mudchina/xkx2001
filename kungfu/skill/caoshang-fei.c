//Cracked by Roath
// caoshang-fei.c 草上飞 (韦一笑's dodge)
// by maco 

#include <combat.h>
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "但是$n奔得快极，这一招差了尺许，没能击中。$p似乎有意炫耀功夫，竟不远走，便绕着$N急兜圈子。\n",
        "dodge"  : 90,
]),
([      "action" : "$N招数甫出，$n却已在数丈之外，正自飞步疾奔，身法之快，直是匪夷所思，眼见万万追赶不上。\n",
        "dodge"  : 90,
]),
([      "action" : "$n不待此招打老，身影一晃一闪，早已避开，当真趋退若神，天下罕有。\n",
        "dodge"  : 90,
]),
([      "action" : "$n身子倏然倒弹而出，犹如一溜轻烟，转瞬间已与$N相隔十余丈。\n",
        "dodge"  : 90,
]),
([      "action" : "$n斜身一让，有若一股旋风般地滑了开去，这一手“草上飞”的轻功虽非特异，但练到这般犹如凌虚飘行，实是神乎其技！\n",
        "dodge"  : 90,
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("caoshang-fei");

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
       return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        return 0;
}

