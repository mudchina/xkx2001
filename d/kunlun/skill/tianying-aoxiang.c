//Cracked by Roath
// tianying-aoxiang.c 天鹰翱翔

inherit SKILL;

string *dodge_msg = ({
        "只见$n使出天鹰翱翔，躲过了$N这一招。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge"); 
}

int valid_learn(object me) 
{ 
	return 1; 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练天鹰翱翔。\n");
        me->receive_damage("jingli", 30);
        return 1;
}
