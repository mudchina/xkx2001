//Cracked by Roath
// bai.c 白龙门弟子
inherit NPC;

void create()
{
	set_name("白龙门弟子", ({ "bailong dizi","dizi" }) );
	set("gender", "男性");
	set("age", 15+random(10));
	set("long",
		"这是白龙门弟子，年纪都很小，似乎不谙世事。\n");
	set("combat_exp", 2000+random(20000));
	set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  15);
	set("apply/defense", 15);

	set("jingli",100);

	set("chat_chance", 5);
	set("chat_msg", ({
		"弟子说道：洪教主身通护佑，众弟子勇气百倍，以一当百，以百当万。\n",
		"弟子说道：洪教主神目如电，烛照四方。\n",
		"弟子说道：我弟子杀敌护教，洪教主亲加提拔，升任圣职。\n",
		"弟子说道：我教弟子护教而死，同升天堂。\n",
	}) );

	set_skill("sword", 15+random(50));
	set_skill("unarmed", 15+random(50));
	set_skill("parry", 15+random(50));
	set_skill("dodge", 15+random(50));
	set_skill("strike", 15+random(50));

	create_family("神龙教", 4, "弟子");

	setup();
	switch( random(3) )
	{
		case 0:
			carry_object("/clone/weapon/gangjian")->wield();
			break;
		case 1:
			carry_object("/clone/weapon/changjian")->wield();
			break;
		case 2:
			carry_object("/clone/weapon/duanjian")->wield();
			break;
	}

	carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 20);
}
