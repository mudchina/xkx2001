//Cracked by Roath
// Jay 5/10/97

inherit NPC;

void create()
{
	set_name("陆高止", ({ "lu gaozhi", "lu" }));
	set("title","师爷");
	set("nickname", "绵里针");
	set("long", 
		"陆高止真名陆菲青，乃武当派大侠，壮年时在大江南北行侠仗义，\n"
		"端的名震江湖，原是屠龙帮中一位响当当的人物。\n");
	set("gender", "男性");
	set("age", 54);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("max_qi", 1200);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 50000);
        set("inquiry", ([
                "李沅芷" : "她是我徒弟，很任性。\n",
		"张召重" : "他是我师弟，已经成了朝廷鹰犬，可叹。\n",
        ]));


	set_skill("force", 120);
	set_skill("taiji-shengong", 120);
	set_skill("dodge", 130);
	set_skill("tiyunzong", 130);
	set_skill("cuff", 110);
	set_skill("taiji-quan", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("taiji-jian", 150);
	set_skill("taoism", 80);
	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	prepare_skill("cuff", "taiji-quan");

 	create_family("武当派", 14, "弟子");

	setup();
        if (clonep())
        carry_object("/clone/weapon/bailong-jian",
                "/clone/weapon/changjian")->wield();
        carry_object("/d/xixia/obj/robe")->wear();
}

void attempt_apprentice(object me)
{
        command("say 常言道：“大隐隐于朝，中隐隐于市，小隐隐于野”，老夫隐名于此，不便收徒。");
}

