//Cracked by Roath
// byjisi.c 摆夷祭司

inherit NPC;

void create()
{
	set_name("老祭司", ({ "lao jisi", "jisi", "ji" }) );
	set("long", "一个颇老朽的摆夷老人，穿戴齐整，是本村的祭司，权力颇大，相当于族长。\n");

	set("age", 60);
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
	carry_object("/d/dali/npc/obj/byskirt.c")->wear();
}
