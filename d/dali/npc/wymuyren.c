//Cracked by Roath
// wymuyren.c 乌夷牧羊人

inherit NPC;

void create()
{
	set_name("牧羊人", ({ "muyang ren", "ren", "man" }) );
	set("long", "一位乌夷族的牧羊人。\n");

	set("age", 25);
	set("gender", "男性");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

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
	carry_object("/d/dali/npc/obj/wyskirt.c")->wear();
	carry_object("/d/xingxiu/npc/obj/bian")->wield();
}
