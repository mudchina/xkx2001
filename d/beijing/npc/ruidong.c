//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("瑞栋", ({
		"rui dong",
		"rui",
		"dong",
	}));
	set("title", "侍卫副总管");
	set("long",
		"他就是侍卫副总管。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 30);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 600);
	set("max_jing", 300);
	set("neili", 400);
	set("max_neili", 400);
	set("combat_exp", 200000);
	set("score", 100);
	

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("cuff", 120);
	set_skill("claw",120);
	set_skill("strike",120);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("blade",120);
	set_skill("sword",120);
	set_skill("stick",120);
	set_skill("staff",120);
	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

      carry_object("/d/taihu/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

