//Cracked by Roath
// jing1.h for the 4 jing shitai who don't recruit

void attempt_apprentice(object ob)
{
        mapping fam;

	if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "峨嵋派")
        {
                if ((string)ob->query("class")!="bonze")
		{
			command ("say 阿弥陀佛！贫尼不收弟子。施主若想学艺可去找我俗家师妹。");
                        return;
                }

	        else if( (string)ob->query("gender") != "女性" )
       		{
              		command ("say 阿弥陀佛！贫尼不收弟子。"+RANK_D->query_respect(ob)+"既是出家人，请去少林寻师吧。");
                	return;
        	}

        	command("say 阿弥陀佛！贫尼不收弟子。"+RANK_D->query_respect(ob)+"去找我师姐吧。");
		return;
	}

        else
	{
               	command ("say 阿弥陀佛！贫尼不收弟子。");
               	command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。");
               	return;
       	}
}
