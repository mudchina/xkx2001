//Cracked by Roath
// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int auto_perform();

string ask_job();

void create()
{
	set_name("玄慈大师", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
		"他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
	);


	set("nickname", "少林寺方丈");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 500000);

	set_skill("force", 140);
	set_skill("hunyuan-yiqi", 140);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 140);
	set_skill("finger", 140);
	set_skill("strike", 140);
	set_skill("hand", 114);
	set_skill("claw", 140);
	set_skill("parry", 140);
	set_skill("nianhua-zhi", 140);
	set_skill("sanhua-zhang", 140);
	set_skill("fengyun-shou", 140);
	set_skill("longzhua-gong", 140);
	set_skill("buddhism", 140);
	set_skill("literate", 140);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("少林派", 36, "弟子");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	(: auto_perform :), }));

        set("inquiry", ([
                "工作" : (: ask_job :),
        ]));
	
	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
#include "/kungfu/class/shaolin/auto_perform.h"
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

	if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄") 
	||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "玄") )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "，你辈份不合，不能越级拜师。");
		return;
	}

	return;
}

string ask_job()
{
        object obj, me = this_player();
        mapping myfam = me->query("family");

        if( !myfam || myfam["family_name"] != "少林派" )
                return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";

        if( myfam["generation"] > 37 )
                return RANK_D->query_respect(me) + "还是在少林寺再练几年吧。";

        if( time() < (int)me->query("fz_ask") + 300 )
                return RANK_D->query_respect(me) + "不是刚问过我吗？";

        if( present("tuijian xin", me) )
                return RANK_D->query_respect(me) + "已经拿到去龙门镖局传授武功的推荐信了。";

        command("nod");
        me->set("fz_ask", time());

        obj = new("/d/shaolin/obj/letter-job");
        obj->set("owner", me->query("id"));
        obj->move(me);
        message_vision("$N交给$n一封推荐信。\n", this_object(), me);
        return RANK_D->query_self(me) + "有一位俗家弟子是龙门镖局的总镖头，" + RANK_D->query_respect(me) + "可去那儿传授镖头武功。";
}

