//Cracked by Roath
inherit SKILL;

string *dodge_msg = ({
"$n一式「别巷寂寥人散后」，衣袖轻拂，轻叹一声，飘然退后。\n",
"$n一式「惊残好梦无寻处」，$N只觉眼前一花，一怔之下，$n早已转到他的身后。\n",
"$n似进实退，轻描淡写地避开了这一招，正是「天涯岂是无归意」。\n",
"$n使一招「折得疏梅香满袖」，身形一偏，$N似乎闻到一阵若有若无的香气。\n",
"$n微微一笑，一式「小阁重帘有燕过」，从$N身旁斜掠而过。\n",      
"$n脸现寂寥之色，素手微挥，一式「等闲离别易销魂」退了开去。\n"
"$n脸现寂寥之色，素手微挥，一式「往事成空」，一卷一带，$N的功势都落在了空处。\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage ==
"move"); }

int valid_learn(object me) { return 1; }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练古诗身法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

