//Cracked by Roath
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("何不净", ({"he bujing", "he", "bujing"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 30);
	set("long", 
		"这是位衣著邋塌，蓬头垢面的丐帮七袋弟子。\n");
	set("attitude", "heroism");
	set("str", 28);
	set("int", 18);
	set("con", 24);
	set("dex", 20);

	set("rank", 7);

	set("max_qi", 880);
	set("max_jing", 600);
	set("neili", 980);
	set("max_neili", 980);
	set("jiali", 90);
	
	set("combat_exp", 240000);
	
	set_skill("force", 90); 
	set_skill("huntian-qigong", 85); 
	set_skill("strike", 85); 
	set_skill("xianglong-zhang", 85); 
	set_skill("dodge", 95); 
	set_skill("xiaoyaoyou", 90); 
	set_skill("parry", 83); 
	set_skill("begging", 60); 
	set_skill("stealing", 80); 
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("strike", "xianglong-zhang");

	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(6);
	carry_object("/d/gaibang/obj/budai")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("combat_exp") < 30000 ) return;

        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="女性")
                        command ("say 师太是是出家人，怎么能在本帮做叫化子呢？");
                return;
        }

	if( ob->query("family/family_name") != "丐帮" ) 
	{
	        if( ob->query("rank") > 1 ) {
       	         	command("say 本帮以忠义为先，可容不下你这种无信无义的家伙！\n");
                	return;
        	}

		command("say 你很爱打架吧？ 哈哈哈，好吧，我就收下你了！");
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
