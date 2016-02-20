//Cracked by Roath
// bynong.c 摆夷农夫

inherit NPC;

void create()
{
	set_name("农夫", ({ "nong fu", "nong", "farmer" }) );
	set("long", "一个身强力壮的摆夷农夫。\n");

	set("age", 25);
	set("gender", "男性");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 3000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/maozhan.c")->wear();
}
