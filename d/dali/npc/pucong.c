//Cracked by Roath
inherit NPC;

void create()
{
	set_name("陪从", ({ "pei cong" }));
	set("gender", "男性");
	set("age", 20 + random(40));

	set("long", "一个部族头领的陪从。\n");

	set("attitude", "friendly");

	set("combat_exp", 4000);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();

	set("chat_chance", 2);
	set("chat_msg", ({
		"陪从：明天咱们出去打猎解闷。\n",
		}) );
}

