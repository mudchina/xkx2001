//Cracked by Roath
// wylieren.c 乌夷猎人

inherit NPC;

void create()
{
	set_name("猎人", ({ "lie ren", "ren", "hunter" }) );
	set("long", "一位中年乌夷族猎手，背了一大卷动物皮毛，看来是上镇子里来出售皮货的。\n");

	set("age", 35);
	set("gender", "男性");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 12000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 10);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/wyhui.c")->wear();
}
