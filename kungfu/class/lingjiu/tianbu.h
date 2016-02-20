//Cracked by Kafei
// tianbu.h for lingjiu master

#include <ansi.h>

void attempt_apprentice(object ob)
{
        mapping fam;

        if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "灵鹫宫") {

		if(ob->query("gender") != "女性") {
                	command("say 灵鹫宫只收女弟子，"+RANK_D->query_respect(ob)+"还是请回吧。");
                return;
                }

        	if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 )  {
               		command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
                	return;
        	}
			
                if (ob->query("family/family_name") != "灵鹫宫" && ob->query("combat_exp") >= 10000 ) {
                        command ("say " + RANK_D->query_respect(this_player())
                                + "是" + fam["family_name"]  + "的武功高手，本派可不敢收留。");
                        return;
                }

                if ((string)ob->query("class") =="bonze") {
			if ((string)ob->query("gender") == "女性")  {
				command("hmm " + ob->query("id"));
				command("say " +RANK_D->query_respect(ob) +"既是出家人，还是去峨嵋山找那的师太们吧。");
                		return;
			}
			else {
                                command("say " +RANK_D->query_respect(ob) +"既是出家人，请去少林寻师吧。");
                        	return;
                	}
		}

		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say 我灵鹫宫虽不是名门正派，但也绝不于奸邪之人为伍。");
                	command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
        		return;
		}

		command("say 好吧，我就收下你了。希望你能行天地正道，将灵鹫宫发扬光大。"); 
        	command("recruit " + ob->query("id"));
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
                		command("say 我看你还是去峨嵋山吧。");
                		return;
			}
		}

		command("say 好吧，我就收下你了。希望你能行天地正道，将灵鹫宫发扬光大。"); 
		command("recruit " + ob->query("id"));
	}
	return;
}
