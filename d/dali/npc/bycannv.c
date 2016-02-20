//Cracked by Roath
// bycannv.c 摆夷养蚕女

inherit NPC;

void create()
{
	set_name("养蚕女", ({ "yangcan nu", "nu", "woman" }) );
	set("long", "一个年轻的摆夷村妇，养蚕纺丝为生。\n");

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
