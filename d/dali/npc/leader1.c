//Cracked by Roath
// leader1.c 傣族首领

inherit NPC;

void create()
{
	set_name("傣族首领", ({ "daizu shouling", "leader" }));
	set("title", "洪源洞洞主");
	set("gender", "男性");
	set("long", "这是一个身裹虎皮的高大男性。\n");
	set("age", 45);

	set("str", 20);
	set("int", 30);
	set("dex", 20);
	set("con", 20);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 50000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_skill("blade", 80);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);

	setup();
	carry_object("d/dali/obj/mandao")->wield();
	carry_object("d/dali/obj/hupi")->wear();
	add_money("gold", 1);
}
