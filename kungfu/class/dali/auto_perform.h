//Cracked by Roath
int auto_perform()
{
	int tempjiali;
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if (!me->is_fighting()) {
		if ( me->query("eff_qi") < me->query("max_qi") ) {
			tempjiali=me->query("jiali");
			exert_function("heal");
			me->set("jiali", tempjiali);
		}
		return 1;
	}

	if (!objectp(target)
		|| !random( (int)me->query("combat_exp") * 2 / (int)target->query("combat_exp") + 1) )
		return 0;

	if (objectp(weapon)) {
		if (weapon->query("skill_type") == "sword")
			return perform_action("sword.ailao");
	}

	if (!objectp(weapon)) {
		if ( me->query_skill("yiyang-zhi", 1) > 80)
			return perform_action("finger.qiankun");
	}
	else

	return 1;
}

