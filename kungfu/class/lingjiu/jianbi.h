//Cracked by Kafei
// tianbu.h for lingjiu master

#include <ansi.h>

void attempt_apprentice(object ob)
{
        	mapping fam = ob->query("family");

		if (ob->query("gender") != "女性") {
			command("say 我只收女弟子，"+RANK_D->query_respect(ob)+"请回吧。");
			return; 
		}
		if (!fam || fam["family_name"] != "灵鹫宫"){
                	command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                	return;
                }
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
		if((int)ob->query_skill("force", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                	return;
                }  
		if((int)ob->query_skill("bahuang-gong", 1) < 80) {
			command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
                	return;
                }  
		if((int)ob->query_skill("dodge", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("yueying-wubu", 1) < 80 && (int)ob->query_skill("lingbo-weibu", 1) < 80 ) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("sword", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("tianyu-qijian", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                	return;
                }
		if (ob->query_con() < 20) {
			command("say 本门功法极为难练,你的根骨似乎不够.");
			return;
		}
		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say 我灵鹫宫虽不是名门正派，但也绝不于奸邪之人为伍。");
                	command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
        		return;
		}
		command("say 好吧，我就收下你了。希望你能行天地正道，将灵鹫宫发扬光大。"); 
        	command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
}
