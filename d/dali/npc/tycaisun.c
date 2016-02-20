//Cracked by Roath
// tycaisun.c 台夷采笋人

inherit NPC;

void create()
{
	set_name("采笋人", ({ "caisun ren", "ren", "woman" }) );
	set("long", "一个卢鹿部的青年台夷妇女，背后背了个竹筐，手拿一把砍柴刀，来采竹笋。\n");

	set("age", 25);
	set("gender", "女性");
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
	carry_object("/d/dali/npc/obj/tytongqun.c")->wear();
	carry_object("/d/dali/npc/obj/zhutong.c");
}
