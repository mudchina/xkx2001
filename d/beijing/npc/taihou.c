//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("皇太后", ({
		"huang taihou",
		"taihou",
	}));
//	set("title", "");
	set("long",
		"她身材不高，脸色苍白，容貌极美，但眉头微蹙，似乎有什么心事。\n"
	);


	set("gender", "女性");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type",-1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 1300);
	set("max_neili", 1300);
	set("combat_exp", 800000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 50);
	set_skill("claw",50);
	set_skill("strike",100);
	set_skill("unarmed",50);
	set_skill("parry", 100);
	set_skill("blade",50);
	set_skill("sword",50);
	set_skill("stick",50);
	set_skill("huagu-mianzhang",100);
	set_skill("dulong-dafa",100);

	map_skill("force", "dulong-dafa");
//	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mainzhang");
//	map_skill("blade", "cibei-dao");

	prepare_skill("huagu-mianzhang");
	setup();

//      carry_object("/d/taihu/obj/cloth")->wear();
//	carry_object("/d/city/obj/gangdao")->wield();
}

