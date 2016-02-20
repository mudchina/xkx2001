//Cracked by Roath
// literate.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	if (!me->query_temp("mark/朱")
		&& (me->query("class") != "bonze"
			 || (me->query("family/family_name") != "峨嵋派" &&
			me->query("family/family_name") != "少林派"
			 && !me->query_temp("mark/谷虚"  ))
			 || me->query_skill("literate", 1) > 100) &&
			 (me->query("class") != "taoist" || me->query("family/family_name") != "全真教"
			 || me->query_skill("literate", 1) > 100) )
		return notify_fail("你现在不能学习读书写字。\n");
	return 1;
}
