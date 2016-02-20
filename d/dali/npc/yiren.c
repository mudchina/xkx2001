//Cracked by Roath
// yiren.c 江湖艺人

inherit NPC;

void create()
{
	set_name("江湖艺人", ({ "jianghu yiren", "yiren" }));
	set("long", "　　他是一个外地来的江湖艺人，手里牵着一只金丝猴儿，满脸风尘之色。\n");
	set("gender", "男性");
	set("age", 40+random(20));
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 2);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("max_qi", 300);
	set("max_jing", 300);
	set("combat_exp", 3500+random(1500));
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30+random(15));
	set_skill("parry", 50+random(5));
	set_skill("blade", 30+random(10));
	set("chat_chance", 8);
	set("chat_msg", ({
		"江湖艺人敲着手里的铜钹吆喝道：大家有钱的捧个钱场，没钱的捧个人场。\n",
		}) );
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/tongbo")->wield();
}
