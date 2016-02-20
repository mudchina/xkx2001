//Cracked by Roath
void attempt_apprentice(object ob)
{
	mapping fam;
    string dldj;

	if (ob->query("family/family_name")!="大理段家") {
		command("shake "+ob->query("id"));
		command("say 我早已投身大理为臣，不再涉足江湖俗务，不能收徒了。");
        return;
	}

    command ("look "+ob->query("id"));

	if (ob->query("shen")<0) {
		command("say 大理境内容不得你这等阴险小人！");
		return;
	}

	command("hehehe "+getuid(ob));
	command("say 你我本是同府共事，想找我学些功夫当然没问题。");
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
	return;
}

