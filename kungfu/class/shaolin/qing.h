//Cracked by Roath
// qing.h for fight and get letter from Qing

int accept_object(object ob, object obj)
{
	mapping skl, my_fam, ob_fam; 
	string *sname;
	object me;
	int i;
	
	me = this_object();
	my_fam  = me->query("family");
	ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin1", ob) ) 
	{
		command("say 怎么样，你拿我的推荐信去拜师了吗 ?");
		return 0;
	}

	if((obj->query("id") == "damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		skl = ob->query_skills();
		sname  = keys(skl);

		for(i=0; i<sizeof(skl); i++) {
			if (skl[sname[i]] < 30) 
			ob->set_temp("not_ready", 1);
		}

		if( ob->query_temp("not_ready") ) {
			command("say " + RANK_D->query_respect(ob) + 
			"你的功力不够，不能跟我验证武功。");
			ob->delete_temp("not_ready");
		}

		ob->set_temp("fight_ok",1);
		command("say 好，既然已得到方丈许可，我们就来验证一下武功。");
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
		obj=new("/d/shaolin/obj/tuijianxin-1");
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

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	return;
}

