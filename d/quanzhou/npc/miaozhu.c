//Cracked by Roath
// miaozhu.c 庙祝

inherit NPC;

void create()
{
	set_name("庙祝", ({ "miao zhu", "zhu" }));
	set("long",
		"这是一位年老的庙祝，在此已几十年了，对此地一切都十分熟悉。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("chat_msg",({
		"庙祝说道：这位施主请来上柱香，求菩萨和土地爷保佑。\n",
		"庙祝说道：善有善报，菩萨和土地爷一定会保佑善心人的。\n",
	}));

	set("age", 65);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 150);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 3000);
	set("score", 100);
	set("chat_chance", 5);

	set_skill("force", 25);
	set_skill("dodge", 25);
	set_skill("unarmed", 25);
	set_skill("parry", 25);

	setup();
}
