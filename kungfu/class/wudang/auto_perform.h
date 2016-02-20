//Cracked by Roath
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

	if( !objectp(target->query_temp("weapon")) )
		command("unwield sword");
	else
		command("wield sword");

	if( !me->query_temp("taiji") )
		command("exert taiji");

	if( objectp(weapon) && weapon->query("skill_type") == "sword" )
	{
		me->map_skill("parry", "taiji-jian");
		me->reset_action();

		if( !target->is_busy() )
			return perform_action("sword.chan");
	}
	else
	{
		me->map_skill("parry", "taiji-quan");
		me->reset_action();

		switch( random(2) )
		{
			case 0:
				if( target != me->query_temp("nian") )
					return perform_action("cuff.nian");
				else
					return perform_action("cuff.luanhuan");
				break;
   			case 1:
				return perform_action("cuff.luanhuan");
				break;
		}
	}
}
