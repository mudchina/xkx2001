//Cracked by Roath
// bycaisang.c 摆夷妇女

inherit NPC;

void create()
{
	set_name("采桑女", ({ "caisang nu", "nu", "girl" }) );
	set("long", "一个年轻的摆夷采桑姑娘。\n");

	set("age", 18);
	set("gender", "女性");
	set("dalivictim",1);

	set("str", 15);
	set("cor", 15);

    set("combat_exp", 1500);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 3);
	set_temp("apply/armor", 3);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/byskirt.c")->wear();
}
