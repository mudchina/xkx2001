//Cracked by Roath
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
	
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");
	
	
	if ( !me->is_fighting() ) {
		if ( me->query("eff_qi") < me->query("max_qi") )
			exert_function("heal");
		me->set("jiali", 100);
		return 1;
	}

	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;

	if ( objectp(weapon) ) {
		switch (weapon->query("skill_type")) {
	
		case "whip" : 
		return perform_action("whip.chanrao");
		break ;
	
 		case "club" :
		if (me->query_skill_mapped("club") == "zui-gun")
			{
			if (me->query_condition("drunk", 1) < 40)
			{	
			me->apply_condition("drunk", 40);
			return perform_action("club.zuida");
			}
		else 
			return perform_action("club.zuida");
			}
		else
			
			return 0;
			
		break;

		case "sword" :
		if (me->query_skill_mapped("sword") == "damo-jian")
		return perform_action("sword.sanjue");
		else 
		return 0;
		break;	
		}	
	}
	else
	{	
	 	if (me->query_skill_prepared("finger") == "nianhua-zhi")
		{
		me->map_skill("parry", "nianhua-zhi");
		me->reset_action();
		return perform_action("finger.fuxue");
		}		

		if (me->query_skill_prepared("finger") == "yizhi-chan")
		{
		me->map_skill("parry", "yizhi-chan");
		me->reset_action();
		return perform_action("finger.jingmo");
		}
 
		if (me->query_skill_prepared("cuff") == "jingang-quan")
		{
		me->map_skill("parry", "jingang-quan");
		me->reset_action();
		return perform_action("cuff.jingang");
		}
		return 0;
				
}
}
