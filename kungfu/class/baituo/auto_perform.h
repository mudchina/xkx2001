//Cracked by Roath
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if( !me->query_temp("powerup") && random(3) ==1)
		command("exert powerup");
	else if( !me->query_temp("reverse") && random(3) ==1)
		command("exert reverse");

	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;

	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "staff" && (int)me->query_skill("poison", 1) > 200 && random(2) == 1)
			return perform_action("staff.bite");
		else return perform_action("staff.shoot");

	}
	else return perform_action("strike.puji");
}
