//Cracked by Roath
// shuishou.c 
inherit NPC;

void create()
{
	set_name("哑巴水手", ({ "shui shou","shou" }) );
	set("gender", "男性");
	set("age", 35);
        set("long",
		"他又聋又哑，但身子骨甚为结实，脸上被海风吹的又红又黑。。\n");
	set("combat_exp", 10000);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("jingli",100);

	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

        setup();
	carry_object("/d/shenlong/obj/cloth")->wear();
	add_money("coin", 50);
}
