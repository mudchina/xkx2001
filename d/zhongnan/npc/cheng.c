//Cracked by Roath
	// /kungfu/class/quanzhen/cheng.c
// cheng.c  程瑶迦
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("程瑶迦", ({ "cheng yaojia", "cheng" }));
	set("long",
		"她是清净散人孙不二的弟子。\n"
		"她长的眉清目秀。\n"
		);
	set("gender", "女性");
	set("age", 46);
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
	set("combat_exp", 80000);
	set("score", 6000);

	set_skill("force", 70);
	set_skill("xiantian-gong", 70);
	set_skill("dodge", 70);
	set_skill("jinyangong", 70);
	set_skill("cuff", 70);
	set_skill("chunyang-quan", 70);
	set_skill("strike", 70);
	set_skill("sanhua-juding", 70);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("quanzhen-jian", 80);
	set_skill("literate", 80);
	set_skill("taoism", 90);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 3, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;
   string name,new_name;

	if(ob->query("gender",1)!="女性"){
		command ("say 对不起，我只收女弟子！");
		return;
	}


	if( mapp(fam = ob->query("family")) && fam["family_name"] != "全真教" )
	{
		command ("say " + RANK_D->query_respect(this_player())
			+ "并非我门中人，习武还是先从各位道长起吧！");
		return;
	}

	if ((int)ob->query_skill("xiantian-gong", 1) < 20) {
		command("say 我全真教乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在玄门先天功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") < 5000) {
		command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	name = ob->query("name");
	new_name = name[0..01]+"清" + name[4..5];
	command("say 从今以后你就叫做" + new_name + "。");
	ob->set(name,new_name);
	command("recruit " + ob->query("id"));
}


