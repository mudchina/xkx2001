//Cracked by Roath
// bywoman.c 摆夷妇女

inherit NPC;

void create()
{
	set_name("村妇", ({ "cun fu", "fu", "woman" }) );
	set("long", "一个年轻的摆夷村妇。\n");

	set("age", 20);
	set("gender", "女性");
	set("dalivictim",1);

	set("str", 15);
	set("cor", 15);

	set("combat_exp", 1500);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 3);
	set_temp("apply/armor", 3);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/byskirt.c")->wear();
}
