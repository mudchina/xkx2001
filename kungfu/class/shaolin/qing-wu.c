//Cracked by Roath
// Npc: /kungfu/class/shaolin/qing-wu.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("清无比丘", ({
		"qingwu biqiu",
		"qingwu",
		"biqiu",
	}));
	set("long",
		"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 17);
	set("con", 20);
	set("dex", 24);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 20000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("cuff", 30);
	set_skill("luohan-quan", 30);
	set_skill("blade", 30);
	set_skill("cibei-dao", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "cibei-dao");

        prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 40, "弟子");

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "少林派" 
	&&  ob->query("combat_exp") >= 10000 )
	{
		command ("say 阿弥陀佛！ 施主是" + fam["family_name"] + "的武功高手，本寺可不敢收留！");
		return;
	}

	if( (string)ob->query("gender") == "女性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	}
	else    command ("say 阿弥陀佛，善哉！善哉！");

	command("recruit " + ob->query("id"));
}
