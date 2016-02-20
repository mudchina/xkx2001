//Cracked by Roath
// monk.c 僧人

inherit NPC;

void create()
{
	set_name("僧人", ({ "seng ren", "seng" }));
	set("long",
		"这是一位僧人。\n"
	);


	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("chat_msg",({
		"僧人稽首说道：这位施主有请了！\n",
	}));

	set("age", 35);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 150);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 5000);
	set("score", 100);
	set("chat_chance", 5);

	set_skill("force", 25);
	set_skill("dodge", 25);
	set_skill("unarmed", 25);
	set_skill("parry", 25);

	setup();
}
