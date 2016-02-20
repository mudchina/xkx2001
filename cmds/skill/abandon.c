//Cracked by Roath
// abandon.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping skills, skillmap;
	string *skill;
	int i;
	
	if( !arg || arg=="" ) 
		return notify_fail("你要放弃哪一项技能？\n");

	if( !me->delete_skill(arg) )
		return notify_fail("你并没有学过这项技能。\n");

	write("你决定放弃继续学习" + to_chinese(arg) + "。\n");

	if( arg =="all" ) {
		skills = me->query_skills();
		if( !mapp(skills) || sizeof(skills)==0 ) return 1;

		skill = keys(skills);
		for (i=0; i<sizeof(skill); i++) {
			me->delete_skill(skill[i]);
		}
	} else {		 
		skillmap = me->query_skill_map();
		if( !mapp(skillmap) || sizeof(skillmap)==0 ) return 1;

		skill = keys(skillmap);
		for (i=0; i<sizeof(skill); i++) {
			if( skillmap[skill[i]] == arg ) me->map_skill(skill[i]);
		}
	}
	
	return 1;
}

int help()
{
	write(@TEXT
指令格式：abandon|fangqi <技能名称>

放弃一项你所学过的技能，注意这里所说的「放弃」是指将这项技能从你人物
的资料中删除，如果你以后还要练，必须从０开始重练，请务必考虑清楚。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由于每个
人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头来只会样
样不精。
TEXT
	);
	return 1;
}
