//Cracked by Roath
// mu jianping ãå½£ÆÁ

inherit NPC;
// inherit F_MASTER;

void create()
{
	set_name("ãå½£ÆÁ", ({ "mu jianping","mu" }));
//      set("nickname", "");
	set("long",
		"Ò»ÕÅ¹Ï×ÓÁ³£¬ÈİÃ²ÉõÃÀ¡£\n");
	set("gender", "Å®ĞÔ");
	set("age", 14);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 20);
	set("int", 25);
	set("con", 22);
	set("dex", 24);
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("jingli", 300);
	set("max_jingli", 300);
	set("jiali", 20);
	set("combat_exp", 20000);
        set("score", 50000);
        set("shen", -3000);

	set_skill("force", 20);
	set_skill("dodge", 30);
	set_skill("strike", 20);
	set_skill("kick", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
        set_skill("jueming-tui", 30);
        set_skill("tiyunzong", 30);
	set_skill("literate", 30);

        map_skill("kick", "jueming-tui");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

	create_family("ÉñÁú½Ì", 3, "³àÁúÃÅµÜ×Ó");

//      set("inquiry", ([
//              "ÃØ¼®" : (: ask_me :),
//      ]));

//      set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();

}
