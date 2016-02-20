//Cracked by Roath
// wygirl.c 乌夷少女

inherit NPC;

void create()
{
	set_name("少女", ({ "shao nu", "girl" }) );
	set("long", "一位乌夷族的少女，以酥泽发，盘成两环，上披蓝纱头巾，饰以花边。\n");

	set("age", 15);
	set("gender", "女性");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 1000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/wyskirt.c")->wear();
}
