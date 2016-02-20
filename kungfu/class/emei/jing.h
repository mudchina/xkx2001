//Cracked by Roath
// /kungfu/class/emei/jing.h for apprentice
// Shan: 96/07/16

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	if (!(ob_fam = ob->query("family"))||ob_fam["family_name"]!= "峨嵋派") {
		command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ((string)ob->query("class")!="bonze" && ob_fam["family_name"]=="峨嵋派")  {
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在庵内学艺。");
		return;
	}

	if ( ob_fam["generation"] == 0 ) {
		command("say 阿弥陀佛！贫尼就收下你做我的弟子了。");
		command("recruit " + ob->query("id"));
		ob->set("emei", 1);
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) ) {
		command("say 你不是跟"+ob_fam["master_name"]+"修行的妈？");
		command("recruit " + ob->query("id"));
		ob->set("emei", 1);
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] ) {
		command("say " + RANK_D->query_respect(ob) + "，贫尼哪里敢当 !");
		return;
	}

	return;
}

