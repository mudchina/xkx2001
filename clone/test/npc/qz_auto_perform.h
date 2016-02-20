//Cracked by Roath
// /kungfu/class/quanzhen/autoperform.h
// for quanzhen npc's autoperform
// by sdong 08/01/98
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");


	//if ( !objectp(target) ) return 0;



	if( !is_busy() && !is_fighting() && !objectp(target) )
	{
		if( me->query("eff_qi",1) < me->query("max_qi") && me->query("eff_qi",1) > me->query("max_qi")/2 )
		{
			command("yun heal");
			command("yun heal");
			command("yun recover");
			return 1;
		}

		command("dazuo 500");
		return 1;
	}




	if ( objectp(weapon) && weapon->query("skill_type") == "sword")
	{

		  if( me->query("eff_qi",1) > me->query("max_qi")/2 &&
			me->query("eff_qi",1) < me->query("max_qi",1)*2/3)
		  {
			command("halt");
			command("yun heal");
			command("yun heal");
			command("yun heal");
			command("yun recover");
		  }
		  else if( me->query("neili") < 150 && me->query("eff_qi",1) < me->query("max_qi")/2 )
			perform_action("sword.tonggui");
		  else
		  {
			if(!me->query_temp("sanqing"))
				return perform_action("sword.sanqing");
			else if( me->query("shentong") > 60 )
			{
				command("yun shentong "+target->query("id"));
			}
			else return perform_action("sword.sanqing");
		  }


	}
	else if ( objectp(weapon) && weapon->query("skill_type") == "whip")
	{
		return perform_action("whip.riyue");
	}
	else
	{
		if( !me->query_temp("sanhua",1) )
			return perform_action("strike.sanhua");
		else if( me->query("shentong") > 60 )
		{  
			command("yun shentong "+target->query("id"));
		}
		else return perform_action("cuff.lianhuan");
	}
}


