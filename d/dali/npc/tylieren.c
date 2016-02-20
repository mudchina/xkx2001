//Cracked by Roath
// tylieren.c 台夷猎人

inherit NPC;

void create()
{
	set_name("台夷猎人", ({ "lie ren", "man", "hunter" }) );
	set("long", "一位台夷族的猎手，擅用短弩，射飞鸟。\n");

	set("age", 25);
	set("gender", "男性");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 1500);
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
	carry_object("/d/dali/obj/shortbow.c")->wield();
	carry_object("/clone/weapon/arrow.c");
	carry_object("/d/dali/npc/obj/tyxiaoao.c")->wear();
	carry_object("/d/dali/npc/obj/tytoujin.c")->wear();
}
