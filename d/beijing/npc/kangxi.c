//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("康熙", ({
		"kangxi",
		"emperor",
	}));
	set("title", "大清皇帝");
	set("long",
		"他就是当今皇上。他年龄不大，眉清目秀，神情轩昂，有一股凛然之威。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 16);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 10000);
	set("score", 100);
	

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("cuff", 50);
	set_skill("claw",50);
	set_skill("strike",50);
	set_skill("unarmed",50);
	set_skill("parry", 50);
	set_skill("blade",50);
	set_skill("sword",50);
	set_skill("stick",50);
	set_skill("staff",50);
	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

//      carry_object("/d/taihu/obj/cloth")->wear();
//	carry_object("/d/city/obj/gangdao")->wield();
}

