//Cracked by Roath
// youke1.c 游客

inherit NPC;

void create()
{
	set_name("游客", ({ "you ke", "ke" }) );
	set("long", "一个远道来的汉族游客，风尘仆仆，但显然为眼前美景所动，兴高彩烈。\n");

	set("age", 30);
	set("gender", "男性");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 8000);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth.c")->wear();
}
