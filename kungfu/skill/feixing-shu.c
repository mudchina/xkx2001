//Cracked by Roath
// feixing-shu

#include <ansi.h>
inherit SKILL;


string *parry_msg = ({
	  "$n左袖一扬，一股无形的劲力送出，将$N击向$n的$l的一招直荡了开去。\n",
          "但见$n阴阴地一笑，从袖中射出一道暗劲，将$N这招在中途架了开去。\n",
          "$n身行纹丝不动，脸上红光大现，$N微觉诧异，不由得将招数收了回去。\n",
          "$n一声尖叫，向后一跳，将来招躲开。\n",
          "$n动也不动，待$N这招使到，双袖扬起，$N在微光下见到一层粉沫向自己飘来，只好向后躲开。\n",
});


int valid_enable(string usage)
{
        return (usage == "parry");
}


string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}


int practice_skill(object me)
{
        return notify_fail("飞星术不可以练习，只能通过自己领悟和学习提高。\n");

}
string perform_action_file(string action)
{
        return __DIR__"qiankun-danuoyi/" + action;
}

