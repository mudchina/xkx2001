//Cracked by Roath
// wynong.c 乌夷农夫

inherit NPC;

void create()
{
	set_name("农夫", ({ "nong fu", "nong", "farmar" }) );
	set("long", "一位乌夷族的农夫，束发总于脑后，用布纱包着，上半身裸露，下著兽皮。\n");

	set("age", 25);
	set("gender", "男性");
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
	carry_object("/d/dali/npc/obj/wyhui.c")->wear();
}
