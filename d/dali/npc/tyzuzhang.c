//Cracked by Roath
// tyzuzhang.c 台夷族长

inherit NPC;

void create()
{
	set_name("族长", ({ "zu zhang", "zhang", "woman" }) );
	set("long", "一位满脸皱纹的老年妇女，正是本村的族长。台夷时处母系氏族，族中权贵皆为妇女。\n");

	set("age", 65);
	set("gender", "女性");
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
	carry_object("/d/dali/npc/obj/tytongqun.c")->wear();
}
