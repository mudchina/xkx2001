//Cracked by Roath


int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object target=me->select_opponent();
	
	if(target->query("combat_exp") < 500000)
	return 0;

	switch (me->query("real_menpai")) {
	case "huashan" :

	if( me->query("qi",1) < 10 || me->query("jing",1) < 10 || me->query("jingli",1) < 10) return;

	if ( !me->is_fighting() ) {
		if ( me->query("eff_qi") < me->query("max_qi") )
		me->exert_function("heal");
		return 1;
		}

		if ( objectp(weapon) ) {
			if ( weapon->query("skill_type") == "sword" && random(4) == 0 )
			return perform_action("sword.jianzhang"); 
			else if ( weapon->query("skill_type") == "blade" && random(4) == 0)
			return perform_action("blade.sanshen");
		}
	else if ( !me->query_temp("leidong") && random(4) == 0) {
		return perform_action("cuff.leidong");
	}
	else if ( !me->query_temp("wuji") && target->query_condition("hyz_damage") <= 5 && random(4) == 0) {
		return  perform_action("strike.wuji");
	}
	
	if ( !me->is_fighting() ) {
		if ( me->query("eff_qi") < me->query("max_qi") )
			exert_function("heal");
		return 1;
	}

		break;
		
	case "dajin" :
	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;

	if( !objectp(target->query_temp("weapon")) || me->query_temp("chan/"+target->name()))
		command("unwield sword");
	else
		command("wield sword");

	if( !me->query_temp("taiji") && random(3) == 0 && me->query("combat_exp") > 2000000 )
		command("exert taiji");
/*	else if (present("fei biao", me) && random(2) == 0 && !target->query_temp("armor/embed")){
	command("hehe");
	command("throw biao at "+target->query("id"));
	target->remove_killer(me);
	target->fight_ob(me);
	return 1;
	}
*/
	else if( objectp(weapon) && weapon->query("skill_type") == "sword")
	{
		me->map_skill("parry", "taiji-jian");
		me->reset_action();

		if( !target->is_busy() )
			return perform_action("sword.chan");
		else
			return perform_action("sword.shenmen");
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

		break;

	case "shaolin" :

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
			return perform_action("club.zuida");
		else
			return 0;
			
		break;

		case "sword" :
		if (me->query_skill_mapped("sword") == "damo-jian" && random(3) == 0)
		return perform_action("sword.sanjue");
		else 
		return 0;
		break;  
		}       
	}
	else
	{       
		command("exert jingang");

		if (me->query_skill_prepared("strike") == "banruo-zhang" && random(3) == 0)
		{
		me->reset_action();
		return perform_action("strike.san");
		}
		
		if (me->query_skill_prepared("finger") == "nianhua-zhi" && random(2) == 0 )
		{
		me->map_skill("parry", "nianhua-zhi");
		me->reset_action();
		return perform_action("finger.fuxue");
		}	       

		if (me->query_skill_prepared("finger") == "yizhi-chan" && random(2) == 0 )
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
		break;
		
	case "xiyu" :
	if ( !objectp(target)
		|| !random( (int)me->query("combat_exp") * 2
		/ (int)target->query("combat_exp") + 1) ) return 0;

	if( !me->query_temp("reverse") )
		command("exert reverse");
	else if( !me->query_temp("powerup") )
		command("exert powerup");
	else if( !objectp(weapon) && random(2) == 0 )
			return perform_action("strike.puji");
		break;
		
	case "mizong" :
	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;
	if( !me->query_temp("longxiang") && random(2) == 0 )
		command("exert longxiang");
	else if( !me->query_temp("shielded") && random(2) == 0)
		command("exert shield");

	else if( objectp(weapon) && weapon->query("skill_type") == "blade")
	{
		me->reset_action();
		if( !target->is_busy() )
			return perform_action("blade.shendao");
	}

	return perform_action("strike.fen");
		break;

	case "miaojiang" :
	if ( !objectp(target)
	  || !random( (int)me->query("combat_exp") * 2
		   / (int)target->query("combat_exp") + 1) ) return 0;

	command("get corpse");
	if (present("corpse", me) ){
	command("throw corpse at "+target->query("id"));
	target->remove_killer(me);
	target->fight_ob(me);
	return 1;
	}

	if( !target->query_temp("huagong") && random(2) == 0 )
		command("perform sanyin");
	else if( random(2) == 0 )
		command("yun qisuck "+target->query("id"));

	if (present("bilin zhen", me) && random(2) == 1){
	command("throw zhen at "+target->query("id"));
	target->remove_killer(me);
	target->fight_ob(me);
	return 1;
	}
	else if ( present("lianxin dan", me)){
	command("throw dan at "+target->query("id"));
	target->remove_killer(me);
	target->fight_ob(me);
	return 1;
	}
		break;

	default:
		return 0;
	}
}
