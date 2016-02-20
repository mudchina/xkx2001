//Cracked by Roath
// dulong-dafa.c 蛇岛  毒龙大法
// ywz Nov 11 1996 .

inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
	mapping skills;
	string *sname;

	int lvl = (int)me->query_skill("dulong-dafa", 1);
	int t = 1, i, j;
	int other_force = 0;

	for (j = 1; j < lvl / 10; j++) t *= 2;

	if (!me->query("yijin_wan"))
		return notify_fail("你未曾服食教主的豹胎易经丸，没有根基，无法学习毒龙大法。\n");

	if (me->query("yijin_wan") < me->query("age") - 13 )
		return notify_fail("你未曾每年按期服食教主的豹胎易经丸，无法继续学习毒龙大法。\n");

	if ( (int)me->query_skill("force", 1)  <  10 
	   ||(int)me->query_skill("force", 1)/2 < lvl/3 )
		return notify_fail("你的基本内功火候还不够，无法领会毒龙大法。\n");

	skills = me->query_skills();
	sname = keys(skills);
	for(i=0; i<sizeof(skills); i++) {
		if( sname[i] != "dulong-dafa" && SKILL_D(sname[i])->valid_enable("force") ) {
			other_force = 1;
			break;
		}
	}

	if ( (int)me->query_skill("dulong-dafa", 1) >= 45
	&& other_force
	&& (int)me->query_int() < 40 )
		return notify_fail("你身上具有别派内功，与毒龙大法相悖，再难更上一层楼。\n");

	if ( (int)me->query_skill("dulong-dafa", 1) >= 90
	&& other_force
	&& (int)me->query_int() < 50 )
		return notify_fail("你身负别派内功，与毒龙大法水火难容，毒龙大法很难更上一层楼。\n");

	if (lvl > 10 && (int)me->query("shen") > t * 100
	&& ( me->query_skill("taoism", 1) || me->query_skill("buddhism", 1)) )
		return notify_fail("你尚不适宜学习毒龙大法。\n");

	return 1;
}

int practice_skill(object me)
{
        return notify_fail("毒龙大法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"dulong-dafa/" + func;
}
