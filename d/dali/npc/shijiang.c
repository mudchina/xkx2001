//Cracked by Roath
// bossxue.c 薛老板

inherit NPC;

void create()
{
	set_name("石匠", ({ "shi jiang", "shi" }));
	set("long", "　　他是一个打磨大理石的石匠，身上只穿了一件坎肩，全身布满了厚实的肌肉。\n");
	set("gender", "男性");
	set("age", 33+random(10));
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("max_qi", 400);
	set("max_jing", 300);
	set("jiali", 10);
	set("combat_exp", 5000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("hammer", 30);
	set("chat_chance", 8);
	set("chat_msg", ({
		"石匠有一下没一下的凿着手中的一块碑文，嘴里嘟囔着，“苍山之腹盛产奇石，世称大理石，大理也因石而名扬天下。”\n", 
		}) );
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/hammer")->wield();
}
