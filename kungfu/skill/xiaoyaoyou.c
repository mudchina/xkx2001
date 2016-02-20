//Cracked by Roath
// xiaoyaoyou.c
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
        "$n一个「蜻蜓点水」，躲过了$N这一招。\n",
        "$n身形向后一纵，使出一招「细胸巧翻云」，避过了$N的攻击。\n",
        "$n使出「虚怀若谷」，恰好躲过了$N的攻势。\n"
//        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
//        "$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
//        "可是$n侧身一让，$N这一招扑了个空。\n",
//        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
//        "$n身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) 
{ 
        return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练逍遥游。\n");
        me->receive_damage("jingli", 30);
        return 1;
}
