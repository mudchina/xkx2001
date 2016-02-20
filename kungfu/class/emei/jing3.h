//Cracked by Roath
// jing3.h for higher 4 jing shitai

void attempt_apprentice(object ob)
{
        mapping fam;

	if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "峨嵋派")
        {
        	if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 ) 
		{
                	command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
                	return;
        	}

		if (ob->query("combat_exp") >= 10000 && ob->query("family") )
		{
			command ("say " + RANK_D->query_respect(this_player())
				+ "是" + fam["family_name"] 
				+ "的武功高手，本派可不敢收留。");
			return;
		}

                else if ((string)ob->query("class")!="bonze")
		{
			command ("say 阿弥陀佛！贫尼不收俗家弟子。施主若想学艺可去找我俗家师妹。");
                        return;
                }

	        else if( (string)ob->query("gender") != "女性" )
       		{
              		command ("say 阿弥陀佛！大师呀，贫尼可不敢开这等玩笑啊。");
			command ("say "+RANK_D->query_respect(ob)+"既是出家人，请去少林寻师吧。");
                	return;
        	}

                else if ((int)ob->query("shen") < 0) 
		{
                	command("hmm " + ob->query("id"));
                	command("say 我峨嵋派乃是堂堂名门正派，对弟子要求极严。");
                	command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
                	return;
        	}

		command("say 阿弥陀佛，善哉！善哉！在本庵修行，我要先考考你的佛法。");
        	ob->set_temp("pending/kao", 1);
		command("say 你要准备好了，就告诉(nod)我吧。\n");
        	return; 
	}

        else
	{
        	if ( (string)ob->query("class") != "bonze" ) 
        	{
                	command ("say 阿弥陀佛！贫尼不收俗家弟子。");
                	command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。");
                	return;
        	}

                else if( (string)ob->query("gender") != "女性" )
                {
                        command ("say 阿弥陀佛！大师呀，贫尼可不敢开这等玩笑啊。");
                	command ("say " +RANK_D->query_respect(ob)+"既然出了家，不如去少林寻师。");
			return;
		}
		else if ((int)ob->query("shen") < 0) 
                {
                        command("hmm " + ob->query("id"));
                        command("say 我峨嵋派乃是堂堂名门正派，对弟子要求极严。");
                	message_vision(
                		"$n看着$N说道：你在外边做的事你师父知道吗？我不能留你，你去吧。\n",
                		ob, this_object() );
                        return;
                }

                command("say 阿弥陀佛，善哉！善哉！在本庵修行，我要先考考你的佛法。");
                ob->set_temp("pending/kao", 1);
                command("say 你要准备好了，就告诉(nod)我吧。\n");
                return;

	}
}
