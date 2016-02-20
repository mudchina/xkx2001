//Cracked by Roath
//taixuan-gong.c
//dong, 8/29/97

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("taixuan-gong", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10
          ||(int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("你的基本内功火候不足，不能学太玄功。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("太玄功无发用练来加深。\n");
}

string exert_function_file(string func)
{
        return __DIR__"taixuan-gong/" + func;
}

