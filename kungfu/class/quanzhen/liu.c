//Cracked by Roath
// /kungfu/class/quanzhen/liu.c
// liu.c 刘处玄
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("刘处玄", ({ "liu chuxuan", "liu" }));
	set("nickname", "长生子");
	set("long",
		"他就是全真七子中的刘处玄，道号长生子，在王重阳的弟子中排行第三。\n"
		);
	set("gender", "男性");
	set("age", 70);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("max_jingli", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set("combat_exp", 700000);
	set("score", 60000);

	set_skill("beidou-zhenfa", 150);
	set_skill("force", 150);
	set_skill("xiantian-gong", 150);
	set_skill("dodge", 150);
	set_skill("jinyangong", 150);
	set_skill("cuff", 150);
	set_skill("chunyang-quan", 150);
	set_skill("strike", 150);
	set_skill("sanhua-juding", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("quanzhen-jian", 150);
	set_skill("literate", 120);
	set_skill("taoism", 150);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 2, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;
   string name,new_name;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "全真教" )
	{
		command ("say " + RANK_D->query_respect(this_player())
			+ "并非我门中人，习武还是先从各位道长起吧！");
		return;
	}

	if ((int)ob->query_skill("xiantian-gong", 1) < 60) {
		command("say 我全真教乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在玄门先天功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") < 35000) {
		command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	name = ob->query("name");
	new_name = name[0..01]+"志" + name[4..5];
	command("say 从今以后你就叫做" + new_name + "。");
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}


#include "auto_perform.h"
