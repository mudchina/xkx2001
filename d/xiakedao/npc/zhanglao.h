//Cracked by Roath

int do_checking1();
int perform_sanshen();
void greeting(object me);

void init()
{
      object me = this_player();
	if( interactive(me) )
      {	remove_call_out("greeting");
            call_out("greeting", 1, me);
      }
}

void greeting(object me)
{     object obj = this_object();
	object sl1, sl2, sl3;
	object bro;
	string broname;
	int maxqi = obj->query("max_qi");
	int maxjingli = obj->query("max_jingli");
	if (obj->query("id") == "gao lao")
	{	broname = "ai lao";}
	else
	{	broname = "gao lao";}
	bro = present(broname, environment(obj));
	sl1 = present("du e", environment(obj));
	sl2 = present("du jie", environment(obj));
	sl3 = present("du nan", environment(obj));
      if (!obj->is_fighting())
      {	if (bro && sl1 && sl2 && sl3)
		{	if (random(10) == 1 )
                	{	obj->set("jingli", maxjingli);
				obj->set("eff_qi", maxqi);
				obj->set("qi", maxqi);
				command("say 让我们兄弟俩领较少林三僧的金刚服魔圈吧。");
				obj->fight_ob(sl1);
				obj->fight_ob(sl2);
				obj->fight_ob(sl3);
				sl1->fight_ob(obj);
				sl2->fight_ob(obj);
				sl3->fight_ob(obj);
				if (!bro->is_fighting())
				{	bro->fight_ob(sl1);
					bro->fight_ob(sl2);
					bro->fight_ob(sl3);
					sl1->fight_ob(bro);
					sl2->fight_ob(bro);
					sl3->fight_ob(bro);
				}
                	}
		}	    	
	}
	remove_call_out("do_checking1");
	call_out("do_checking1", 2);
}
int do_checking1()
{	object obj = this_object();
	int maxqi = obj->query("max_qi");
	int maxjingli = obj->query("max_jingli");
	int maxneili = obj->query("max_neili");
	if ( obj->is_fighting() ) 
	{
           	if ( !obj->query_temp("hebi") ) 
		{	if ( obj->query("id") == "gao lao" ) command("perform hebi ai");
                	if ( obj->query("id") == "ai lao" ) command("perform hebi gao");
           	} 

           	if ( !obj->query_temp("perform_pending") ) 
		{	if (random(2) == 1)
                	{	obj->set_temp("perform_pending", 1);
				call_out("perform_sanshen", 5, obj);
			}
		}

		call_out("do_checking1", 1);
		return 1;
	}

	obj->set("jingli", maxjingli);
	obj->set("eff_qi", maxqi);
	obj->set("qi", maxqi);		
	obj->set("neili", maxneili);
	if ( obj->query("perform_pending")==1 ) 
	{
		obj->delete_temp("perform_pending");
		remove_call_out("perform_sanshen");
		return 1;
	}

	return 1;
}

int perform_sanshen()
{	object obj= this_object();
	obj->delete_temp("perform_pending");
	command("perform sanshen");
	return 1;
}
void attempt_apprentice(object me)
{	command("say 别来烦我啦");
}
int accept_fight()
{	command("say OK");
	return 1;
}