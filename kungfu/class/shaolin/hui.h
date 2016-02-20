//Cracked by Roath
// hui.h for fight and get letter from Hui

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin3", ob) ) 
	{
		command("say 怎么样，你拿我的推荐信去拜师了吗 ?");
		return 0;
	}

	if((obj->query("id") == "damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
	        command("say 好，既然已得到方丈许可，我们就来验证一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
	if (obj->query("id") == "tuijian xin2" 
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say 好，" + ob->query("name") + "，你愿意拜我为师吗？");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say 这东西给我可没有什么用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok") ) return 0;

	if ( me->is_fighting() ) 
		return notify_fail(me->name() + "摇头道："
		+ RANK_D->query_respect(ob) + "，请勿倚多为胜！");

	me->set("qi", me->query("max_qi"));	
	me->set("eff_qi", me->query("max_qi"));	
	me->set("jing", me->query("max_jing"));	
	me->set("eff_jing", me->query("max_jing"));	
	me->set("jingli", me->query("max_jingli"));	

	me->set_temp("challenger", ob);

	add_action("do_kill", "kill");
	ob->delete_temp("fight_ok");
	
	return 1;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
	object obj;
	int my_max_qi, his_max_qi;

	if ( !objectp(ob) ) return ::chat();

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
	remove_action("do_kill", "kill");
	if (me->is_fighting()) return ::chat();

	if ( !present(ob, environment()) ) return ::chat(); 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say 青出于蓝胜于蓝，不愧是少林寺的佳弟子 ! 恭喜你了 !\n");
		message_vision("$N交给$n一封推荐信。\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/shaolin/obj/tuijianxin-3");
		obj->move(ob);
		return ::chat();
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + 
			"还得多加练习，方能在少林诸多弟子中出人头地 !\n");
		return ::chat();
	}

	return ::chat();  
}

int do_kill()
{
	object me= this_object();
	say(me->name() + "高高举起达摩令，喝道：见令如见达摩祖师，何人胆敢在此杀人！");
	return 1;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

//	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
//	{
//		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
//		return;
//	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say 是" + ob_fam["master_name"] + "叫你来找我的吧，哈哈哈 !");
			command("say 贫僧又得一可塑之才，真是可喜可贺 !");

			if( me->query("class") == "bonze" )
			{ 
				new_name = "道" + name[2..3];
				ob->set("name", new_name);
				command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派道字辈弟子 !");
			}
			else 	command("say 恭喜你荣升为少林派道字辈俗家弟子！");

			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你没有推荐信，不能越级拜师。");
			return;
		}
	}

	return;
}

