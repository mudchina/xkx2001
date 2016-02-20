//Cracked by Roath
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黎生", ({"li sheng", "li", "sheng"}));
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 38);
	set("long", 
		"这是位生性刚直，嫉恶如仇的丐帮八袋弟子。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);

	set("rank", 8);

	set("max_qi", 1000);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	
	set("combat_exp", 350000);
	
	set_skill("force", 91); 
	set_skill("huntian-qigong", 102); 
	set_skill("strike", 25); 
	set_skill("xianglong-zhang", 35); 
	set_skill("hand", 105); 
	set_skill("shexing-diaoshou", 75); 
	set_skill("dodge", 100); 
	set_skill("xiaoyaoyou", 102); 
	set_skill("parry", 102); 
	set_skill("blade", 100); 
	set_skill("liuhe-dao", 100); 
	set_skill("begging", 70); 
	set_skill("digging", 80); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("strike","xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(7);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("shen") < 0 ) {
		command ("say 你看起来有些行为不正，我不能收你。");
		return;
	}

/*
        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="女性")
                        command ("say 师太是是出家人，怎么能在本帮做叫化子呢？");
                return;
        }
*/

	if( ob->query("family/family_name") != "丐帮" )
	{
	        if( ob->query("rank") > 1 ) {
                	command("say 本帮以忠义为先，可容不下你这种无信无义的家伙！\n");
                	return;
        	}

		command("say 好，有你这样一等一的人才做我徒弟，我欢喜还来不及呢！");
		ob->set("rank", 1); 
		command("recruit " + ob->query("id"));
                ob->set("title", "丐帮一袋弟子");
	} 
	else
	{
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
	}
}

#include "/kungfu/class/gaibang/promote.h"
