//Cracked by Roath
// xiaojian May 25, 2000
//getting tools for shaolin tiaoshui job
// mantian add name control on piao May/17/2001
string ask_piao()
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	obj = present("shui piao", me);
	if(obj && obj->query("onwer") == me->query("id"))
		return "你身上不是有水瓢吗, 要那么多干吗? ";
	if (!me->query("shaolin/job_asked") && !me->query_condition("tiaoshui"))
		return "你要瓢来干什么? ";
	if (me->query_temp("piao_asked"))
		return "你不是刚刚要过瓢吗，怎么又来要了? ";

	command("say 又丢了水瓢? 下次小心点! ");
	obj = new("/d/shaolin/obj/piao");
	obj->set("owner/id",me->query("id"));
	obj->set("owner/name",me->query("name"));
	obj->move(me);
	message_vision("$n给$N一个水瓢。\n",me, ob);
	me->set_temp("piao_asked",1);
	return "记得用完后还回来啊。";
	
	
}

string ask_tong()
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	obj = present("shui tong", me);
	if (obj) 
		return "你身上不是有水桶吗? ";
	obj = present("shui tong", environment(me));
	if (obj && obj->query("onwer") == me->query("id"))
		return "地上不是有你的水桶吗，怎么还不干活去? ";
	if (me->query("shaolin/tool_assigned"))
		return "你不是已经领到工具了吗，怎么又来要了? ";
	if (!me->query("shaolin/job_asked"))
		return "你现在没有领任务，要什么工具? ";
	command("nod");
	command("say 难得你愿意为本寺解决困难，这太好了! ");
	command("say 这是挑水用的水桶，你拿去用吧。");
	obj = new("/d/shaolin/obj/tong");
	obj->set("owner", me->query("id"));
	obj->move(me);
	message_vision("$N交给$n一个水桶。\n", ob, me);
	me->set("shaolin/tool_assigned", 1);
	return "早去早回，我还等着水用呢。";
}

int accept_object(object ob, object obj)
{
	object me;
	me = this_player();
	if(obj->query("id") == "shui piao"){
	        call_out("destroy_dest", 0, me, obj);
		return 1;
	}
	if(obj->query("id") =="shui tong"){
		if(obj->query("full")){
			if(me->query("shaolin/job_asked")&& me->query_condition("tiaoshui")){
				if (obj->query("owner") != me->query("id"))
					return notify_fail("这不是你的水桶呀。\n");
				else {
				call_out("reward_dest",1,me,obj);
				return 1;
				}
			}
			else{
			command("faint "+me->query("id"));
			command("say 你怎么现在才回来? 已经有别人抢先挑好了水。\n");
			me->delete("shaolin/job_asked");
			me->delete("shaolin/tool_assigned");
			if (me->query_condition("tiaoshui"))
				me->clear_one_condition("tiaoshui");
			me->apply_condition("ts_pending",20+ random(5));
			call_out("dest_tool",1,me,obj);
			return 1;
		}
		}
		else{
				command("hmm "+me->query("id"));
				command("say 桶还没满呢，怎么就拿来给我？\n");
				return 0;
				}
		}

        command( "hmm" );
        command( "say 你给我这东西做什麽？\n" );
        return 0;
}
void destroy_dest(object me, object obj)
{
	command("nod");
	command("say 辛苦了! \n");
	me->delete_temp("piao_asked");
	destruct(obj);
	return;
}
void dest_tool(object me, object obj)
{
	destruct(obj);
	return;
}
void reward_dest(object me, object obj)
{
	command("thank "+me->query("id"));
	command("say 辛苦你了，下去休息一下吧。\n");
	destruct(obj);
	me->delete("shaolin/job_asked");
	me->delete("shaolin/tool_assigned");
	if (me->query_condition("tiaoshui"))
		me->clear_one_condition("tiaoshui");
	me->apply_condition("ts_pending",10+random(6));
	//me->add("combat_exp", 200+ random(50));
	me->add("potential", 80+ random(20));
	if(me->query("potential") > me->query("max_potential"))
		me->set("potential", me->query("max_potential"));
	if(me->query("combat_exp") < 100000)
		me->add("combat_exp", 310 + random(50));
	else if (me->query("combat_exp") < 300000)
		me->add("combat_exp", 250 + random(60));
		else me->add("combat_exp", 180 + random(50));
	return;
}
