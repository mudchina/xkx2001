//Cracked by Roath
// linpingzhi.c 林平之

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("林平之", ({ "lin pingzhi", "lin", "pingzhi" }));
	set("gender", "男性");
	set("age", 20);
	set("long", "他就是「福威镖局」的少当家－－林平之。\n");

	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("sword", 40);
	set_skill("unarmed", 30);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("san-sword", 35);

	map_skill("sword", "san-sword");
	map_skill("parry", "san-sword");


	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 10);

	setup();
	carry_object(__DIR__"obj/changjian")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}
	
