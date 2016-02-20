//Cracked by Roath
// /kungfu/class/quanzhen/ji.c
// ji.c  姬清虚
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_for_join();
int do_kneel();

int auto_perform();

void create()
{
	set_name("姬清虚", ({ "ji qingxu", "ji" }));
	set("long",
		  "他是一位体格强健的青年道士，似乎身怀武艺。\n"
		);
	set("gender", "男性");
	set("age", 25);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 40000);
	set("score", 6000);

	set_skill("force", 40);
	set_skill("xiantian-gong", 40);
	set_skill("dodge", 40);
	set_skill("jinyangong", 40);
	set_skill("cuff", 40);
	set_skill("chunyang-quan", 40);
	set_skill("strike", 40);
	set_skill("sanhua-juding", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("quanzhen-jian", 40);
	set_skill("literate", 40);
	set_skill("taoism", 40);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 4, "弟子");

	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;


	if ((int)ob->query("shen") < 0) {
		command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

		  if( ob->query("family/family_name") == "全真教"
		  && ob->query("generation") <= this_object()->query("generation") )
		  {
					 command("say " + RANK_D->query_respect(ob) + "，贫道哪里敢当 !");
					 return;
		  }

		  if( ob->query("family/family_name") != "全真教"
		  &&  (ob->query("combat_exp",1) >= 10000 )        )
		  {
					 command ("say 无量寿佛！施主是别派的武功高手，本宫可不敢收留！");
					 return;
		  }


		  if( (string)ob->query("class")!="taoist" )
		  {
					 command ("say 无量寿佛！贫道就收下你做『俗家弟子』了。");
		  }
		  else    command ("say 无量寿佛！");


	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}


