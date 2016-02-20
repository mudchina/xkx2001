//Cracked by Roath
// tufei2.c

inherit NPC;

void create()
{
	int i = random(5)+2;
	set_name("蒙面大汉", ({ "bandit" }) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"这家伙脸上蒙了块布一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 20000*i);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("max_qi", 200*i);
	set("max_jing", 600);
	set("max_jingli", 800);
	set("max_neili", 800);
	set("jiali", 12*i);


	set_skill("unarmed", 20*i);
	set_skill("parry", 20*i);
	set_skill("dodge", 20*i);
	set_skill("blade", 20*i);
	set_skill("luan-blade", 10*i);
	set_skill("force", 20*i);
	set_skill("ding-force", 20*i);
	set_skill("ding-dodge", 20*i);

	map_skill("blade", "luan-blade");
	map_skill("parry", "luan-blade");
	map_skill("force", "ding-force");
	map_skill("dodge", "ding-dodge");

	setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("clone/weapon/gangdao")->wield();
}
