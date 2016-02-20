//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("小太监", ({
		"xiao taijian",
		"taijian",
	}));
//	set("title", "普通太监");
	set("long",
		"这是一个小太监，面皮白净，没有一点儿胡须。\n"
	);


	set("gender", "无性");
	set("attitude", "heroism");

	set("age", 13);
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
	

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("cuff", 20);
	set_skill("claw",20);
	set_skill("strike",20);
	set_skill("unarmed",20);
	set_skill("parry", 20);
	
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

