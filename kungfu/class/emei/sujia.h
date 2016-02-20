//Cracked by Roath
// sujia.h for sujia master

#include <ansi.h>

void attempt_apprentice(object ob)
{
        mapping fam;

        if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "峨嵋派") {

        	if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 )  {
               		command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
                	return;
        	}
			
                if (ob->query("combat_exp") >= 10000 && ob->query("family") ) {
                        command ("say " + RANK_D->query_respect(this_player())
                                + "是" + fam["family_name"]  + "的武功高手，本派可不敢收留。");
                        return;
                }

                if ((string)ob->query("class") =="bonze") {
			if ((string)ob->query("gender") == "女性")  {
				command("hmm " + ob->query("id"));
				command("say " +RANK_D->query_respect(ob) +"既是出家人，还是去本山的庵堂里找我静字辈师姐吧。");
                		return;
			}
			else {
                                command("say " +RANK_D->query_respect(ob) +"既是出家人，请去少林寻师吧。");
                        	return;
                	}
		}

		if ((int)ob->query("shen") < -10)  {
                        command("hmm " + ob->query("id"));
                        command("say 我峨嵋派乃是堂堂名门正派，对弟子要求极严。");
                	command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
        		return;
		}

		if ((string)ob->query("gender") != "女性")  { 
                        command("hmm " + ob->query("id"));
                        command("say 我们峨嵋派的功夫比较适合女弟子修习。"); 
                        command("say 既然" +RANK_D->query_respect(this_player()) +  "要学些强身健体的本领，就留在我这里吧。");
                	command("recruit " + ob->query("id"));
        		ob->set("emei", 1);
			if (!ob->query("MKS_emei")) 
			    ob->set("MKS_emei", ob->query("MKS"));
//			ob->set("emei_shen", ob->query("shen"));
                	return;
        	}

		command("say 好吧，我就收下你了。希望你能行天地正道，将峨嵋精神发扬光大。"); 
        	command("recruit " + ob->query("id"));
		if (!ob->query("MKS_emei")) 
		    ob->set("MKS_emei", ob->query("MKS"));
        	ob->set("emei", 1);
//		ob->set("emei_shen", ob->query("shen"));
	}

	else {
        	if ((string)ob->query("class") == "bonze")  {
			if ((string)ob->query("gender") != "女性" ) {
				message_vision( "$n看着$N说道：你既然出了家，在我这里怎样修行？\n", ob, this_object() );
                		command("say 我看你不如去少林寺寻师吧。\n");
                		return;
        		}
			else {
                                message_vision( "$n看着$N说道：你出了家，在我这里怎样修行？\n", ob, this_object() );
                		command("say 我看你还是回庵去吧。");
                		return;
			}
		}

/*
		if ((int)ob->query("shen") < (int)ob->query("emei_shen"))  {
        		command("hmm " + ob->query("id"));
        		command("say 我峨嵋派乃是堂堂名门正派，对弟子要求极严。");
        		message_vision( "$n看着$N说道：你在外边做的事你师父知道吗？我不能收你，你去吧。\n", ob, this_object() );
        		return;
		}
*/
		if ((string)ob->query("gender") != "女性" ) { 
                	command("hmm " + ob->query("id"));
                	command("say 我们峨嵋派的功夫比较适合女弟子修习。"); 
                	command("say 既然" +RANK_D->query_respect(this_player()) +  "要学些强身健体的本领，就留在我这里吧。");
                	command("recruit " + ob->query("id"));
			ob->set("emei", 1);
//			ob->set("emei_shen", ob->query("shen"));
                	return;
        	}

		command("say 好吧，我就收下你了。希望你能行天地正道，将峨嵋精神发扬光大。"); 
		command("recruit " + ob->query("id"));
		ob->set("emei", 1);
//		ob->set("emei_shen", ob->query("shen"));
	}
	return;
}
