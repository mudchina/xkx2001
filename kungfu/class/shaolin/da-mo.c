//Cracked by Roath
// Npc: /kungfu/class/shaolin/xuan-bei.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("达摩", ({
		"damo",
		"damo zushi",
		"zushi",
	}));

	set("long",
		"这是一位白须白眉的老僧。他身材高大，却骨瘦如柴，\n"
		"只见他脸露微笑，全身笼罩在一片淡淡的祥光之中。\n"
	);

	set("title", "少林祖师");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 300);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_living_name("damo");

	set_skill("force", 200);
	set_skill("hunyuan-yiqi", 200);
	set_skill("dodge", 200);
	set_skill("shaolin-shenfa", 200);
	set_skill("parry", 200);

	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("finger", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("club", 200);
	set_skill("staff", 200);

	set_skill("jingang-quan", 200);
	set_skill("luohan-quan", 200);
	set_skill("banruo-zhang", 200);
	set_skill("sanhua-zhang", 200);
	set_skill("qianye-shou", 200);
	set_skill("fengyun-shou", 200);
	set_skill("longzhua-gong", 200);
	set_skill("yingzhua-gong", 200);
	set_skill("yizhi-chan", 200);
	set_skill("nianhua-zhi", 200);
	set_skill("cibei-dao", 200);
	set_skill("xiuluo-dao", 200);
	set_skill("fumo-jian", 200);
	set_skill("damo-jian", 200);
	set_skill("zui-gun", 200);
	set_skill("weituo-gun", 200);
	set_skill("pudu-zhang", 200);
	set_skill("wuchang-zhang", 200);
	set_skill("riyue-bian", 200);

	set_skill("buddhism", 200);
	set_skill("literate", 200);
	set_skill("yiwei-dujiang", 200);
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("finger", "yizhi-chan");
	map_skill("blade", "cibei-dao");
	map_skill("sword", "damo-jian");
	map_skill("club", "weituo-gun");
	map_skill("staff", "pudu-chang");
	map_skill("parry", "cibei-dao");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");

	create_family("少林派", 34, "弟子");

	setup();

	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
	carry_object("/d/shaolin/obj/chanzhang")->wield();
}

void init()
{
	::init();
	if( interactive(this_player()) ) 
	{
		if( this_player()->query("family/family_name") != "少林派"
		||  this_player()->query("family/generation") > 36
		||  this_player()->query_temp("win_times") < 3 )
		destruct(this_object());
	}
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) && name[0..1] == "玄" )
	{
		if ( ob->query_temp("win_times") >= 3 )
		{	
			command("say 老衲手创少林，今于百岁之龄，得此衣钵传人，可谓武林之福也！");

			name = ob->query("name");
			new_name = "渡" + name[2..3];
			ob->set("name", new_name);
	
			command("say 今后你的法名叫做" + new_name + "，恭喜你成为少林派渡字辈长老！");
			command("say 现在老衲就传你一苇渡江之法，从此任你飞渡天堑，遨游四海，渡化众生！");
			message_vision(HIY "\n\n" + me->name() + 
				"将手掌平放于$N顶心，只见一片祥云降下，内里白光旋转，把$N笼罩其中。" + 
				"过了半饷，才渐渐消散。\n\n" NOR, ob);
			
			ob->set_skill("yiwei-dujiang", 100);
			ob->delete_temp("win_times");

			command("recruit " + ob->query("id"));

			command("say 你去罢！我救济世人，行踪无定，你我若有缘，可在此相会。");
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + 
				"，老衲收徒甚严，你还没有资格做我的徒弟。");
			return;
		}
	}

	return;
}
