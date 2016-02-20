//Cracked by Roath
// Npc: /kungfu/class/shaolin/hui-ru.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慧如尊者", ({
		"huiru zunzhe",
		"huiru",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
        set_skill("cuff", 70);
        set_skill("luohan-quan", 70);
        set_skill("blade", 70);
	set_skill("cibei-dao", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 38, "弟子");

	setup();

        carry_object("/clone/weapon/jiedao")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}



