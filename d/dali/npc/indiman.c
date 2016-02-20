//Cracked by Roath
// indiman.c 印度商人

inherit NPC;

void create()
{
	set_name("盛皮罗客商", ({ "ke shang", "shang" }) );
	set("long", "这是一位从印度来的客商，皮肤黝黑，白布包头，大理把印度人叫作盛皮罗。\n");

	set("age", 30);
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
