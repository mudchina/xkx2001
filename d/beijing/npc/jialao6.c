//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("贾老六", ({
		"jia laoliu",
		"laoliu",
		"jia",
	}));
	set("title", "青木堂会众");
	set("long",
		"他头顶头秃秃地，一根小辫子上没剩下几根头发，脸上有个大刀疤。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 30000);
	set("score", 10);
	

	set_skill("force", 30);
	set_skill("dodge", 40);
	set_skill("cuff", 50);
	set_skill("claw",40);
	set_skill("strike",30);
	set_skill("unarmed",50);
	set_skill("parry", 40);
	set_skill("blade",40);
	set_skill("sword",40);
	set_skill("stick",40);
	set_skill("staff",40);
	
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

