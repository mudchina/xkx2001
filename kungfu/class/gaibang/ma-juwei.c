//Cracked by Roath
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("马俱为", ({"ma juwei", "ma", "juwei"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位武艺精强，却沉默寡言的丐帮八袋弟子。\n");
	set("attitude", "peaceful");
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("rank", 8);

	set("max_qi", 800);
	set("max_jing", 500);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 60);
	
	set("combat_exp", 200000);
	
	set_skill("force", 85); 
	set_skill("huntian-qigong", 82); 
	set_skill("hand", 85); 
	set_skill("shexing-diaoshou", 85); 
	set_skill("dodge", 78); 
	set_skill("xiaoyaoyou", 80); 
	set_skill("parry", 80); 
	set_skill("blade", 85); 
	set_skill("liuhe-dao", 85); 
	set_skill("begging", 80); 
	set_skill("digging", 80); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(6);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="女性")
                        command ("say 师太是是出家人，怎么能在本帮做叫化子呢？");
                return;
        }

	if( ob->query("con") < 20 ) return;

	if( ob->query("family/family_name") != "丐帮" )
	{
	        if( ob->query("rank") > 1 ) {
                	command("say 本帮以忠义为先，可容不下你这种无信无义的家伙！\n");
                	return;
        	}

		command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
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
