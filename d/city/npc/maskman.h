//Cracked by Roath
void init()
{
	object *inv, victim, me = this_object();

	if ( !me->query_temp("target") || !objectp(victim = find_player(me->query_temp("target")) ) ) {
		call_out("destruct_me", 1, me);
		return;
	}

	if ( !me->query_temp("said") ) {
	     message_vision("一个蒙面人向$N走了过来，满身的杀气，看来似乎不是易与之辈。\n", victim);

	     switch( random(3) )
	     {
		case 0:
			command( "hehe" );
			command( "say 你"+victim->query("family/family_name")+"名满天下，咱们神教东方教主实在仰慕得紧。");
			break;
		case 1:
			command( "grin" );
			command( "say 咱们神教东方教主有请，你不去也得去，快跟我走一趟吧！" );
			break;
		case 2:
			command( "grin" );
                        command( "say "+victim->name()+"，神教东方教主有请，快随我晋见，可不由得你不去！" );
			break;
	     }
	     me->set_temp("said", 1);
	}

	if ( !me->query_temp("victim") ) {
		me->set_temp("victim", victim->query("id"));
		me->set("pursuer", 1);
        	me->set("vendetta/authority", 1);
        	me->set("bellicosity", 10000);
		me->set_temp("fought", 1);
		message_vision( "$n对着$N大吼：跟我回去参见教主！\n", victim, me );
		me->fight_ob(victim);
		victim->kill_ob(me);

		remove_call_out("checking");
		call_out("checking", 1, me, victim);
	} 
	else if( present(me->query_temp("victim"),environment(me))
	&& !me->is_fighting() && me->query_temp("copied") ) {
		me->kill_ob(victim);
		message_vision( "$n对着$N大吼：还想跑？快跟大爷回去晋见本教主！\n", victim, me );
		
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
	}  
/*     
	if ( userp(victim) && !me->is_fighting() && me->query_temp("fought") ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
	}
*/
	add_action("do_filter", "climb");
	add_action("do_filter", "enter");
	add_action("do_filter", "jump");
	add_action("do_filter", "swim");
	add_action("do_filter", "fly");
	add_action("do_filter_random", "go");
}

int do_filter(string arg)
{
	object player=this_player(), me=this_object();

	if ( objectp(me) && me->query_temp("victim") == player->query("id") ) {
		message_vision("$N加紧攻势，阴笑道：想跑？别做梦了！\n", me);
		return 1;
	}

	return 0;
}

int do_filter_random(string arg)
{
	object player=this_player(), me=this_object();

	if ( objectp(me) && me->query_temp("victim") == player->query("id")
	&& random(10) < 5 ) {
		message_vision("$N加紧攻势，阴笑道：想跑？别做梦了！\n", me);
                return 1;
        }

        return 0;
}

void destruct_me(object me)
{
	if(me) {
		if ( (me->query("eff_qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("qi") * 100 / me->query("max_qi")) < 20
		|| (me->query("eff_jing") * 100 / me->query("max_jing")) < 20
		|| (me->query("jing") * 100 / me->query("max_jing")) < 20 ) {
			message_vision("$N悻然说道：算你够狠！老子先不奉陪了！咱们走着瞧！\n", me);
		}
		else if ( me->query_temp("runaway") ) {
			message_vision("$N突然卖一破绽，跳出战圈，逃了！\n", me);
		}
		else {
			command("get all");
			message_vision("$N悻悻说道：算你有种跑得快，老子真是倒霉！该如何向教主交代呢？\n", me);
		}
		message_vision("接着$N纵身几个起落，便消失不见了。\n\n", me);
		destruct(me);
	}
}

void simple_destruct(object me)
{
	if(me) {
		message_vision("$N飞快地在牢内望了几眼，然后便出牢将门锁上离开了。\n", me);
		destruct(me);
	}
}

int checking(object me, object victim)
{
	if ( !me ) return 1;

	if ( !victim=find_player(me->query_temp("victim")) ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
		return 1;
	}
	
	if ( victim->is_ghost() ) {
		command("grin");
		command("say 不识抬举！大爷请你你不来，居然要到阎王殿去做客，那只好成全你啦！");
		command("haha");

		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
		return 1; 
	}

	if ( me->is_fighting() ) {
	   if ( victim->query_skill_mapped("force") == "taiji-shengong"
	 	|| victim->query_skill_mapped("force") == "xiantian-gong" ) {
			me->set("jiali", 0);
	   }
	   else if ( victim->query_skill_mapped("force") == "linji-zhuang"
		&& !me->query_temp("weapon") ) {
			me->set("jiali", 0);
           }
           else if ( victim->query_skill_mapped("force") == "hunyuan-yiqi"
		&& victim->query_temp("jinzhongzhao") ) {
			me->set("jiali", 0);
           }
	   else {
	   	me->set("jiali", victim->query("jiali"));
	   	if ( me->query("jiali") < 100 ) me->set("jiali", 100);
	   }

	   me->set("jiajin", victim->query("jiajin"));
	   if ( me->query("jiajin") < 20 ) me->set("jiajin", 20);
	
	   if ( (victim->query("eff_qi") * 100 / victim->query("max_qi")) < 5
                || (victim->query("qi") * 100 / victim->query("max_qi")) < 5
                || (victim->query("eff_jing") * 100 / victim->query("max_jing")) < 5
                || (victim->query("jing") * 100 / victim->query("max_jing")) < 5 ) {
		victim->unconcious();
		command("halt");
                me->remove_all_enemy();

		command("grin");
		command("say 总算大功告成，对教主可有个交代了。哈哈！");
 		command("get all from "+victim->query("id"));
		message_vision("$n由怀里抽出绳子，将$N五花大绑扛在肩上，纵身几个起落便消失不见了。\n", victim, me );

		victim->set_temp("rysj_prisoner", 1);
		victim->set("startroom", "/d/qilian/dilao");
		victim->move("/d/qilian/dilao");
		message("vision", "地牢牢门「呀」的一声开了，一个昏沉沉的人被一个蒙面人提了进来扔在地上。\n", environment(victim), ({victim}) );
		me->move("/d/qilian/dilao");
		remove_call_out("checking");
		remove_call_out("simple_destruct");
		call_out("simple_destruct", 5, me);

		if ( victim->query("family") ) 
		   command("chat 哼！堂堂"+victim->query("family/family_name")+"好大的名气，但也不过如此，都是欺世盗名之辈。");
		command("chat "+victim->name()+"在江湖上也算得上是一号人物，不也栽在本教神威之下？嘿嘿！");
		
                return 1;
	   }	
           else if ( (me->query("qi")*100 / me->query("max_qi")) <= 10 
	   || (me->query("jing")*100 / me->query("max_jing")) <= 10 ) {
		command("halt");
		me->remove_all_enemy();
		//random_move();
		
		remove_call_out("checking");
		remove_call_out("destruct_me");
                call_out("destruct_me", 1, me);
                //call_out("checking", 3, me, victim);
		return 1;
           }
	}

	if ( !me->is_fighting() ) {
		if ( present(victim, environment(me)) ) {
	        	victim->kill_ob(me);
			me->kill_ob(victim);
			if ( !environment(me)->query("no_fight") )
				message_vision( "$n对着$N大吼：还想跑？快跟大爷回去晋见本神教教主！\n", victim, me );
		
			remove_call_out("checking");
			call_out("checking", 1, me, victim);
			return 1;
		}
		else if ( (me->query("qi")*100 / me->query("max_qi")) > 10 && objectp(victim) ) {
			me->move(environment(victim));
			message_vision("$n突然飞身过来，对着$N大吼：还想跑？乖乖地跟大爷回去晋见教主！\n", victim, me );
			
			remove_call_out("checking");
                        call_out("checking", 1, me, victim);
                        return 1;
                }
		else {	
			command("get all");
			remove_call_out("destruct_me");
			call_out("destruct_me", 1, me);
			return 1;
		}
	}

	remove_call_out("checking");
	call_out("checking", 1, me, victim);
	return 1;
}

int accept_fight(object victim)
{
	object me = this_object();

	if ( me->query_temp("victim") && victim->query("combat_exp") > me->query("combat_exp") ) {
		 command( "say 滚开！大爷没功夫和你瞎闹！" );
		 return 0;
	}
	else {
		command( "say 不识抬举的东西，看大爷我将你拿下！" );
		me->set_temp("fought", 1);
		me->kill_ob(victim);
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return 1;
	}
}

int accept_kill(object victim)
{
	object me = this_object();

	if ( me->query_temp("victim") && victim->query("combat_exp") > me->query("combat_exp") ) {
		 command( "say 好汉不吃眼前亏，即然你有帮手，大爷我便让你多活几天。" );
		 //message_vision("\n$N突然卖一破绽，跳出战圈，逃了！\n", me);
		 remove_call_out("checking");
		 me->remove_all_enemy();
		 me->set_temp("runaway", 1);
		 call_out("destruct_me", 1, me);
		 return 0;
	}
	else {
		command( "say 不知死活的东西，让大爷我超渡你吧！" );
		remove_call_out("checking");
		call_out("checking", 1, me, victim);
		return 1;
	}
}

void unconcious()
{
	object winner;

	message_vision("\n$N突然卖一破绽，跳出战圈，逃了！\n", this_object());

	if ( objectp( winner = find_player(this_object()->query_temp("victim")) ) ) {
		tell_object(winner,"你临敌的经验增加了！\n");
		winner->add("combat_exp", 40+random(30));
	}

        destruct(this_object());
}

void die()
{
	object winner;

	message_vision("\n$N倒在地上，手脚几下抽动便死了！\n", this_object());

	if ( objectp( winner = find_player(this_object()->query_temp("victim")) ) ) {
                tell_object(winner,"你临敌的经验增加了！\n");
                winner->add("combat_exp", 70+random(30));
        }

        destruct(this_object());
}
