//Cracked by Kafei
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.san");
					 if ( weapon->query("skill_type") == "blade" )
								return perform_action("blade.lianhuan");
		  }

		else if( me->query("id") == "tong lao" )
		{  command("perform zhongfu "+opp->query("id"));
		}
		if( !me->query_temp("lingjiu/baihong") )
			return perform_action("strike.baihong");
		else return perform_action("hand.zhemei");
}