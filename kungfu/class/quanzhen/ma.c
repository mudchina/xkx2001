//Cracked by Roath
// /kungfu/class/quanzhen/ma.c
// ma.c 马钰
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("马钰", ({ "ma yu", "ma" }));
	set("nickname", "丹阳子");
	set("long",
		"他就是全真七子中的首徒马钰，道号丹阳子，前任全真教掌教真人。\n"
		"他是一个苍须道士，脸色红润，手里拿着一柄拂麈。\n"
		"装束十分古怪，头顶梳了三个髻子，高高耸立，一件道袍一尘不染。\n"
      );
	set("gender", "男性");
	set("age", 75);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 3000);
	set("max_jing", 2500);
	set("max_jingli", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 120);
	set("combat_exp", 800000);
	set("score", 60000);

	set_skill("beidou-zhenfa", 160);
	set_skill("force", 380);
	set_skill("xiantian-gong", 170);
	set_skill("dodge", 150);
	set_skill("jinyangong", 150);
	set_skill("cuff", 150);
	set_skill("chunyang-quan", 150);
	set_skill("strike", 150);
	set_skill("sanhua-juding", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("whip", 150);
	set_skill("duanyun-bian", 150);
	set_skill("quanzhen-jian", 160);
	set_skill("literate", 150);
	set_skill("taoism", 380);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");
	map_skill("whip", "duanyun-bian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 2, "弟子");


	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("inquiry", ([
		"秘籍" : (: ask_me :),
		"miji" : (: ask_me :),
	]));


	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/fuchen")->wield();
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

string ask_me()
{
	mapping fam;
	object ob, *obs,ob2 ;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
		return RANK_D->query_respect(this_player()) +
		"与本派素无来往，不知此话从何谈起？";

	if (query("book_count") < 1)
		return "你来晚了，本派的鞭法秘籍不在此处。";

	obs = filter_array(children("/d/zhongnan/obj/whip_book"), (: clonep :));
		  if (sizeof(obs) > 5)
		return "你来晚了，本派的鞭法秘籍不在此处。";

	ob=new("/d/zhongnan/obj/whip_book");
	ob->move(this_player());
	add("book_count", -1);
	command ("rumor "+this_player()->query("name")+"弄到了一册丹阳鞭法谱。");
	return "好吧，这本「丹阳鞭法谱」你拿回去好好钻研。";
}

#include "auto_perform.h"

