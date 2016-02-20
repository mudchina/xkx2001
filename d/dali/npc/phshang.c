//Cracked by Roath
// phshang.c 皮货商

inherit NPC;

void create()
{
	set_name("皮货商", ({ "pihuo shang", "shang" }) );
	set("long", "一位来远道而来的汉族商人，来此采购皮货。\n");

	set("age", 35);
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
	carry_object("/clone/misc/cloth")->wear();
}
