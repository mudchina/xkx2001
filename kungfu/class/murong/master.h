//Cracked by Roath
// arthurgu 1999.9
//Modify by Sure 2000.5

void attempt_apprentice(object ob)
{
       mapping fam;
       string gsmr;
        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="女性")
                        command ("say 燕子坞不收留出家人，师太请回吧。");
                return;
        }

          if( ob->query("family/family_name") != "姑苏慕容" && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                        +ob->query("family/family_name")+"高手，燕子坞可不敢收留！");
                return;
        }
		  if ((string)ob->query("gender") == "无性" && (int)ob->query_skill("pixie-jian",1) > 50 ) {
                command("say " + RANK_D->query_respect(ob) + "是东厂中人，恕我不能收你。");
                return;
        }
		  if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
                return;
        }
		  if ((string)ob->query("family/family_name") == "全真教" ) {
                command("say 燕子坞不信奉道教，这位道兄还是另请高明吧。");
                return;
        }
		  if ((string)ob->query("family/family_name") == "武当派" ) {
                command("say 道长请回吧，燕子坞不敢让您屈尊。");
                return;
        }
		  if ((string)ob->query("family/family_name") == "星宿派" ) {
                command("say 我家公子最恨丁老贼，你快滚！");
                return;
        }
		  if ((string)ob->query("family/family_name") == "白驼派" ) {
                command("say 我家公子最白驼弟子，你走吧。");
                return;
        }
		  if ((string)ob->query("family/family_name") == "华山派" ) {
                command("say 华山派是名门正派，燕子坞不敢让您屈尊。");
                return;
        }
		  if ((string)ob->query("family/family_name") == "血刀门" ) {
                command("say 燕子坞不手血刀门的淫贼，还不快滚？！");
                return;
        }
		  if ((string)ob->query("family/family_name") == "桃花派" ) {
                command("say 东邪黄药师乃武林奇才，这位" + RANK_D->query_respect(ob) + "为何来投我燕子坞呢？");
                return;
        }
	      if ((string)ob->query("family/family_name") == "大理" ) {
                command("say 大理段氏于西南雄霸一方，这位" + RANK_D->query_respect(ob) + "何苦弃官不做？");
                return;
        }
	{
        	if (ob->query("family/family_name")!="姑苏慕容") {
        	if (ob->query("gender")=="女性") gsmr="使女";
	        else  gsmr = "男丁";
        	command("say 好吧，我就收下你做个" + gsmr + "吧。");
	        command("recruit " + ob->query("id"));
        	ob->set("title","姑苏慕容 燕子坞"+gsmr);
	        ob->set("mr/rank", 1);
        	return;
   
                                                           }
   }
