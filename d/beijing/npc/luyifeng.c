//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("卢一峰", ({
		"lu yifeng",
		"yifeng",
		"lu",
	}));
	set("title", "云南候补官员");
	set("long",
		"他看起来白白胖胖，肥头大耳，一口云南腔。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 43);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 5000);
	set("score", 10);
	

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("cuff", 30);
	set_skill("claw",30);
	set_skill("strike",30);
	set_skill("unarmed",30);
	set_skill("parry", 30);
	set_skill("blade",30);
	set_skill("sword",30);
	set_skill("stick",30);

	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

      carry_object("/d/taihu/obj/cloth")->wear();
//	carry_object("/d/city/obj/gangdao")->wield();
}

