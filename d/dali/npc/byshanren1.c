//Cracked by Roath
// byshanren1.c 摆夷山人

inherit NPC;

void create()
{
	set_name("砍竹人", ({ "kanzhu ren", "ren", "man" }) );
	set("long", "一个壮年村民，住在山下的村落里，是上山来砍伐竹子的。\n");

	set("age", 25);
	set("gender", "男性");
	set("dalivictim",1);

	set("str", 25);
	set("cor", 25);

    set("combat_exp", 5000);
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
	carry_object("/d/dali/npc/obj/kandao.c")->wield();
	carry_object("/d/dali/npc/obj/maozhan.c")->wear();
}
