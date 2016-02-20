//Cracked by Roath
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("左全", ({"zuo quan", "zuo", "quan"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("rank", 7);

	set("max_qi", 860);
	set("max_jing", 500);
	set("neili", 810);
	set("max_neili", 810);
	set("jiali", 80);
	
	set("combat_exp", 250000);
	
	set_skill("force", 83); 
	set_skill("huntian-qigong", 80); 
	set_skill("hand", 80); 
	set_skill("shexing-diaoshou", 90); 
	set_skill("dodge", 80); 
	set_skill("xiaoyaoyou", 81); 
	set_skill("parry", 80); 
	set_skill("begging", 50); 
	set_skill("checking", 50); 
	set_skill("digging", 60); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("hand", "shexing-diaoshou");
	
	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(6);
	carry_object("/d/gaibang/obj/budai")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "男性") {
		command("say 我只收男弟子。你去找找本帮其他弟子吧。");
		return;
	}

	if( ob->query("family/family_name") != "丐帮" )
	{
	        if( ob->query("rank") > 1 ) {
                	command("say 本帮以忠义为先，可容不下你这种无信无义的家伙！\n");
                	return;
        	}

		ob->set("rank", 1); 
		command("recruit " + ob->query("id"));
                ob->set("title", "丐帮一袋弟子");
		command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
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
