//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("苏冈", ({
		"su gang",
		"gang",
		"su",
	}));
	set("title", "圣手居士");
	set("long",
		"一个神情威武的中年人，为人沉着老练。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("combat_exp", 200000);
	set("score", 10);
	

	set_skill("force", 100);
	set_skill("dodge", 80);
	set_skill("cuff", 80);
	set_skill("claw",40);
	set_skill("strike",70);
	set_skill("unarmed",80);
	set_skill("parry", 90);
	set_skill("blade",90);
	set_skill("sword",90);
	set_skill("stick",70);
	set_skill("staff",80);
	
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

