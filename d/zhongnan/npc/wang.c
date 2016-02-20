//Cracked by Roath
// /kungfu/class/quanzhen/wang.c
// wang.c 玉阳子王处一
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("王处一", ({ "wang chuyi", "wang" }));
	set("nickname", "玉阳子");
	set("long",
		"他就是全真七子中的王处一，道号玉阳子，在王重阳的弟子中武功仅次于丘处机。\n"
		"他某次与人赌胜，曾独足而立，凭临万丈深谷之上，大袖飘飘，前摇后摆，只吓得\n"
		"山东河北数十位英雄好汉目迷神眩，桥舌不下，因而得了个“铁脚仙”的名号。\n"
      );
	set("gender", "男性");
	set("age", 67);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 3000);
	set("max_jing", 2000);
	set("max_jingli", 2500);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 50);
	set("combat_exp", 900000);
	set("score", 110000);

	set_skill("force", 165);
	set_skill("xiantian-gong", 165);
	set_skill("dodge", 165);
	set_skill("jinyangong", 165);
	set_skill("cuff", 165);
	set_skill("chunyang-quan", 165);
	set_skill("strike", 150);
	set_skill("sanhua-juding", 150);
	set_skill("parry", 150);
	set_skill("sword", 165);
	set_skill("quanzhen-jian", 165);
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

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );


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

	if ((int)ob->query_skill("xiantian-gong", 1) < 70) {
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

