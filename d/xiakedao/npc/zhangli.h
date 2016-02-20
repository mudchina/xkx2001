//Cracked by Roath
void init()
{
        object me = this_player();
		::init();
        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	if (query_temp("met") == 0)
	{	if(me->query_temp("greeted") <= 0)
		{	set_temp("met", 1);
			set_temp("xkd/guest", me->query("id"));
			me->set_temp("greeted", 1);
			command("bow " + me->query("id"));
			command("say 侠客岛" + query("nickname")+"，奉岛主之命，恭迎" + me->query("name") + "，请跟我来。\n"+
			"    "+HBRED+HIW"(follow " + query("id") +")"NOR);
			remove_call_out("check_follow");
			call_out("check_follow", 5, me, 0);
		}
	}
	else
	{	if (me->query_temp("greeted") == 0)
		{	me->set_temp("greeted", -1);
			command("sorry " + me->query("id"));
			command("say 现在宾客太多，请等一下。");
		}
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
	return;
}
int check_follow(object me, int count)
{	string curguest;
	curguest = query_temp("xkd/guest");
	command("say " + curguest);
	if (!(present(curguest, environment(this_object()))))
	{	command("say ok");
		move("/d/xiakedao/shatan1");
		set_temp("met", 0);
		return 1;
	}
	if ((me->query_leader() == this_object()) || (count > 0))
	{	command("tell " + me->query("id") + " 请这边来");
		message_vision("$N拉起$n的手，身形一闪就不知去向了。\n", this_object(), me);
		move("/d/xiakedao/register");
		me->move("/d/xiakedao/register");
		message_vision("$N拉着$n的手闪了进来。\n", this_object(), me);
		command("say " + RANK_D->query_respect(me) + "你先要在这登记下。");
		command("bye " + me->query("id"));
		message_vision("$N说玩转身走了出去。\n", this_object());
		me->set_leader("");
		move("/d/xiakedao/shatan1");
		set_temp("met", 0);
	}
	else
	{	command("tell " + me->query("id") + " 请快跟我来。(请键入"+HBRED+HIW"follow " + query("id") + NOR")");
		call_out("check_follow", 10, me, 1);
	}
	return 1;
}