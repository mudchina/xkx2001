//Cracked by Roath
// yufu.c 渔夫

inherit NPC;

void create()
{
	set_name("渔夫", ({ "yu fu","fu" }) );
	set("gender", "男性");
	set("age", 35);
        set("long",
		"一个寻常的以打鱼为生的渔夫。\n");
	set("combat_exp", 8800);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  50);
	set("apply/defense", 50);
	set("jingli",300);
	set("max_jingli",300);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);


        setup();
	carry_object("/d/shenlong/obj/cloth")->wear();
	add_money("coin", 50);
}

