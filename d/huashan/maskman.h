//Cracked by Roath
void init()
{
	object victim = this_player();
	object *inv, me = this_object();
	mapping skill_status;
	string *sname;
	int i, max = 0, j;

	if ( !interactive(victim) && me ) {
		destruct(me);
		return;
	}

	if ( !me->query_temp("said") ) {
	     switch( random(2) )
	     {
		case 0:
			command( "grin" );
			command( "say 你撞破了我的行藏，只好送你去见阎罗王了！" );
			me->set_temp("kill_rob", 1);
			break;
		case 1:
			command( "hehe" );
			command( "say 大爷我正愁无法立功，现在你自个儿送上门来，算你倒霉吧！" );
			me->set_temp("kill_rob", 0);
			break;
	     }
	     me->set_temp("said", 1);
	}

	if ( !me->query_temp("copied") ) {
	   if ( mapp(skill_status = victim->query_skills()) ) {
		skill_status = victim->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
		}

		me->set_skill("dodge", max*3/4);
		me->set_skill("parry", max*3/4 );
		me->set_skill("force", max*3/4);
		switch( random(4) )
	     	{
			case 0:
				me->set_skill("cuff", max*3/4);
				me->set_skill("yujiamu-quan", max*3/4);
				me->map_skill("cuff", "yujiamu-quan");
				me->prepare_skill("cuff", "yujiamu-quan");
				me->set_skill("hand", max*3/4);
				me->set_skill("dashou-yin", max*3/4);
				me->map_skill("hand", "dashou-yin");
				me->prepare_skill("hand", "dashouyin");
				me->set_skill("longxiang-banruo", max*3/4);
				me->map_skill("force", "longxiang-banruo");
				me->set_skill("shenkongxing", max*3/4);
				me->map_skill("dodge", "shenkongxing");
				switch( random(2) ) {
				   case 0:
					me->set_skill("staff", max);
					me->set_skill("jingang-chu", max);
					me->map_skill("staff", "jingang-chu");
					me->map_skill("parry", "jingang-chu");
					me->carry_object("/clone/weapon/gangzhang")->wield();
					break;
				   case 1:
					me->set_skill("sword", max);
					me->set_skill("mingwang-jian", max);
					me->map_skill("sword", "mingwang-jian");
					me->map_skill("parry", "mingwang-jian");
					me->carry_object("/clone/weapon/changjiang")->wield();
					break;
				}
				break;
			case 1:
				me->set_skill("strike", max*3/4);
				me->set_skill("chousui-zhang", max*3/4);
				me->map_skill("strike", "xingxiu-duzhang");
				me->prepare_skill("strike", "xingxiu-duzhang");
				me->set_skill("claw", max*3/4);
				me->set_skill("sanyin-zhua", max*3/4);
				me->map_skill("claw", "sanyin-zhua");
				me->prepare_skill("claw", "sanyin-zhua");
				me->set_skill("huagong-dafa", max*3/4);
				me->map_skill("force", "huagong-dafa");
				me->set_skill("staff", max);
				me->set_skill("tianshan-zhang", max);
				me->map_skill("staff", "tianshan-zhang");
				me->set_skill("zhaixinggong", max*3/4);
				me->map_skill("dodge", "zhaixinggong");
				me->map_skill("parry", "tianshan-zhang");
				me->carry_object("/clone/weapon/gangzhang")->wield();
				break;
			case 2:
				me->set_skill("strike", max*3/4);
				me->set_skill("lingshe-shenfa", max*3/4);
				me->map_skill("dodge", "lingshe-shenfa");
//				me->set_skill("chousui-zhang", max*3/4);
//				me->map_skill("strike", "xingxiu-duzhang");
//				me->prepare_skill("strike", "xingxiu-duzhang");
//				me->set_skill("claw", max*3/4);
//				me->set_skill("sanyin-zhua", max*3/4);
//				me->map_skill("claw", "sanyin-zhua");
//				me->prepare_skill("claw", "sanyin-zhua");
//				me->set_skill("dulong-dafa", max*3/4);
				me->map_skill("force", "dulong-dafa");
//				me->set_skill("tianshan-zhang", max);
//				me->map_skill("staff", "tianshan-zhang");
				me->set_skill("blade", max);
				me->carry_object("/clone/weapon/gangdao")->wield();
				break;
			case 3:	
				me->set_skill("strike", max*3/4);
				me->set_skill("hamagong", max*3/4);
				me->set_skill("hand", max*3/4);
				me->set_skill("shexing-diaoshou", max*3/4);
				me->map_skill("hand", "shexing-diaoshou");
				if ( max > 100 ) {
					me->map_skill("strike", "hamagong");
					me->prepare_skill("strike", "hamagong");
				}
				else {
					me->prepare_skill("hand", "shexing-diaoshou");
				}
				me->map_skill("force", "hamagong");
				me->set_skill("staff", max);
				me->set_skill("lingshe-zhang", max);
				me->map_skill("staff", "lingshe-zhang");
				me->map_skill("parry", "lingshe-zhang");
				me->set_skill("chanchubu", max*3/4);
				me->map_skill("dodge", "chanchubu");
				me->carry_object("/clone/weapon/gangzhang")->wield();
				break;
		}

		me->set("combat_exp", victim->query("combat_exp"));
		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali"));
		me->set("max_neili", victim->query("max_neili"));
		me->set("max_jingli", victim->query("max_jingli"));
		me->set("neili", victim->query("neili"));
		me->set("jingli", victim->query("jingli"));

		me->set("no_sing", 1);
		me->set_temp("copied", 1);
	}

	if ( !me->query_temp("victim") ) {
		remove_call_out("rob_kill");
		call_out("rob_kill", 1, me, victim);
		me->set_temp("victim", victim->query("id"));
	} 
	else if( (string)victim->query("id") == (string)me->query_temp("victim") ) {
		remove_call_out("rob_kill");
		call_out("rob_kill", 1, me, victim);
		}
	}  
     
	if ( userp(this_player()) && !me->is_fighting() && me->query_temp("fought") ) 
		call_out("destruct_me", 1, me);

//      remove_call_out("checking");
//      call_out("checking", 45, me, victim);
}

void rob_kill(object me, object victim)
{
	if( !objectp(victim) ) 
		victim = present((string)me->query_temp("victim"), environment(me) );
	
	if( !objectp(me) || !objectp(victim) ) return;
	
	me->set_temp("fought", 1);
	message_vision( "$n对着$N大吼：纳命来吧！\n", victim, me );
	
	if ( me->query_temp("kill_rob") == 1 ) {
		me->kill_ob(victim);
	}
	else {
		me->kill_ob(victim);
		victim->fight_ob(me);
	}

	remove_call_out("checking");
	call_out("checking", 1, me, victim);
}

void destroy_me(object me)
{
	if(me) destruct(me);
}

int checking(object me, object victim)
{
	if ( !me ) return 1;
	
	if ( victim->is_ghost() ) {
		destruct(me); 
		return 1;
	}
	else if ( !living(victim) && me->query_temp("kill_rob") == 0 ) {
		command("get all from "+me->query_temp("victim"));
		destruct(me); 
		return 1;
	}
		
	if ( !me->is_fighting() ) {destruct(me); return 1;}

	if ( !objectp(victim) ) 
		victim = present((string)me->query_temp("victim"), environment(me));
	if ( victim && present(victim, environment(me)) ) call_out("checking", 1, me, victim) ;

	return 1;
}


int accept_fight(object victim)
{
	object me = this_object();

	command( "say 你吃了狼心豹子胆啦，竟敢反抗！" );
	me->set_temp("fought", 1);
	me->kill_ob(victim);
	remove_call_out("checking");
	call_out("checking", 1, me, victim);
	return 1;
}

int accept_kill(object victim)
{
	object me = this_object();

	command( "say 不知死活的东西，让大爷我超渡你吧！" );
	me->kill_ob(victim);
	remove_call_out("checking");
	call_out("checking", 1, me, victim);
	return 1;
}

void unconcious()
{
	message_vision("\n$N突然卖一破绽，跳出战圈，逃了！\n", this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n$N死了！\n", this_object());
	destruct(this_object());
}
