//Cracked by Roath
// liu yan 柳燕

inherit NPC;

void create()
{
	set_name("柳燕", ({ "liu yan","liu" }));
//      set("nickname", "");
	set("long",
		"张淡月的弟子，体态极肥，脸如满月，眼小嘴大。\n");
	set("gender", "女性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 25);
	set("con", 26);
	set("dex", 26);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jingli", 500);
	set("max_jingli", 500);
	set("jiali", 20);
	set("combat_exp", 30000);
	set("score", 50000);
	set("shen", -6000);

	set_skill("force", 40);
	set_skill("dulong-dafa", 30);
	set_skill("dodge", 50);
	set_skill("lingshe-shenfa", 50);
	set_skill("strike", 30);
	set_skill("huagu-mianzhang", 20);
	set_skill("parry", 40);
	set_skill("kick", 50);
	set_skill("jueming-tui", 40);
	set_skill("hook", 20);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("kick", "jueming-tui");

	prepare_skill("kick", "jueming-tui");

	create_family("神龙教", 3, "黑龙门弟子");

	setup();
	carry_object("/clone/armor/flower_shoe")->wear();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/hook")->wield();

}
