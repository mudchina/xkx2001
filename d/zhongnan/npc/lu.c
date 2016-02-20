//Cracked by Roath
// /kungfu/class/quanzhen/lu.c
// lu.c  鹿清笃
// sdong 08/01/98

inherit NPC;

void create()
{
	set_name("鹿清笃", ({ "lu qingjia", "lu" }));
	set("long",
		  "他是一位胖大道士，满脸凶气。\n"
		);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 40000);
	set("score", 6000);

	set_skill("force", 40);
	set_skill("xiantian-gong", 40);
	set_skill("dodge", 40);
	set_skill("jinyangong", 40);
	set_skill("cuff", 40);
	set_skill("chunyang-quan", 40);
	set_skill("strike", 40);
	set_skill("sanhua-juding", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("quanzhen-jian", 40);
	set_skill("literate", 40);
	set_skill("taoism", 40);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 4, "弟子");

	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}


