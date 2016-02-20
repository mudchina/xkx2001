//Cracked by Roath
// du.h for fight and apprentice Du

int do_checking1();
int perform_chanrao();
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
	object sl1, sl2;
	object hs1, hs2;
	string name1, name2;
	int maxqi = obj->query("max_qi");
	int maxjingli = obj->query("max_jingli");
		
	if (obj->query("id") == "du e")
	{	name1 = "du jie";
		name2 = "du nan";
	}
	if (obj->query("id") == "du jie")
	{	name1 = "du e";
		name2 = "du nan";
	}
	if (obj->query("id") == "du nan")
	{	name1 = "du e";
		name2 = "du jie";
	}
	hs1 = present("gao lao", environment(obj));
	hs2 = present("ai lao", environment(obj));

	sl1 = present(name1, environment(obj));
	sl2 = present(name2, environment(obj));
      if (!obj->is_fighting())
      {	if (sl1 && sl2 && hs1 && hs2)
		{	if (random(10) == 1 )
                	{	obj->set("jingli", maxjingli);
				obj->set("eff_qi", maxqi);
				obj->set("qi", maxqi);
				command("say 让我们三僧领较一下华山的两仪刀法吧。");
				obj->fight_ob(hs1);
				obj->fight_ob(hs2);
				if (!sl1->is_fighting())
				{	sl1->fight_ob(hs1);
					sl1->fight_ob(hs2);
					hs1->fight_ob(sl1);
					hs2->fight_ob(sl1);

				}
				if (!sl2->is_fighting())
				{	sl2->fight_ob(hs1);
					sl2->fight_ob(hs2);
					hs1->fight_ob(sl2);
					hs2->fight_ob(sl2);
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
           	if ( !obj->query_temp("perform_chanrao") ) 
		{	if (random(40) == 2)
                	{	obj->set_temp("perform_pending", 1);
				call_out("perform_chanrao", 5, obj);
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
		remove_call_out("perform_chanrao");
		return 1;
	}

	return 1;
}

int perform_chanrao()
{	object obj= this_object();
	obj->delete_temp("perform_pending");
	command("perform sanshen");
	return 1;
}
void attempt_apprentice(object me)
{	command("say 别来烦我啦");
}
