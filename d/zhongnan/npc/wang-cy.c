//Cracked by Roath
// /kungfu/class/quanzhen/wang-cy.c
// wang-cy.c 王重阳
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("王重阳", ({ "wang chongyang", "wang" }));
	set("nickname", "中神通");
	set("long",
		"他就是全真教的开山鼻祖、曾在第一次华山论剑中力挫群雄，勇夺第一的王重阳真人。\n"
		"他已年过九十，身材高大，眉宇间隐隐一股英侠正气。只见他腰悬长剑，一袭青袍似在\n"
		"风中轻轻飘动，颇具仙风道骨之气，令人为之心折。\n");
	set("gender", "男性");
	set("age", 90);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_jingli", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 300);
	set("combat_exp", 2000000);
	set("score", 60000);

	set_skill("force", 200);
	set_skill("xiantian-gong", 200);
	set_skill("dodge", 200);
	set_skill("jinyangong", 200);
	set_skill("cuff", 200);
	set_skill("chunyang-quan", 200);
	set_skill("strike", 200);
	set_skill("sanhua-juding", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("quanzhen-jian", 200);
	set_skill("literate", 200);
	set_skill("taoism", 200);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 1, "开山祖师");
   

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

	if ((int)ob->query_skill("xiantian-gong", 1) < 180) {
		command("say 我全真教乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在玄门先天功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") < 1000000) {
		command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	name = ob->query("name");
	new_name = name[0..01]+"处" + name[4..5];
	command("say 从今以后你就叫做" + new_name + "。");
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}


#include "auto_perform.h"

