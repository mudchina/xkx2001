//Cracked by Roath

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int exp1, exp2, gain, gain1, gain2, bonus;
	int int1, int2, age1, age2;
	float gain3;
	mapping fam1, fam2;
//	object where;
	
//	where = environment(me);
	fam1 = (mapping)me->query("family");
	fam2 = (mapping)victim->query("family");	

/*	if (strsrch(file_name(where), "/d/taohua/") < 0)
		return; 
*/
	if (!fam1 || fam1["family_name"] != "ÌÒ»¨µº")
		return 0;
	if (!fam2 || fam2["family_name"] != "ÌÒ»¨µº")
		return 0;

/*	if (!userp(victim)) 
		return;
*/
/*	if ((string)query("owner") != (string)me->query("id"))
		return;
*/
	exp1 = me->query("combat_exp");
	exp2 = victim->query("combat_exp");
	int1 = me->query_int();
	int2 = victim->query_int();
	age1 = me->query("age");
	age2 = victim->query("age");
	
	if (exp1 > exp2) gain1 = (int)(exp1/exp2);
		else gain1 = (int)(exp2/exp1);
	if (gain1 > 2) gain1 = 0;
	if (int1 > int2) gain2 = int1-int2;
		else gain2 = int2-int1;
	if (gain2 > 4) gain2 = 0;
	if (age1 > age2) gain3 = age1/age2;
		else gain3 = age2/age1;
	if (gain3 > 1.2) gain3 = 0.2;
	
	gain = (int)((gain1+gain2)*gain3);
	if (gain > 3) gain = 3;
	bonus = damage_bonus%(int)(gain*(int2+int1)/40+1);
	me->add("combat_exp",bonus);
	if (victim->query("potential")<victim->query("max_potential"))
	victim->add("potential", bonus);
	victim->reset_action();
	set_heart_beat(1);
	return;
}
