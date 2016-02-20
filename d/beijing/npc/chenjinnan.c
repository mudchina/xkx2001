//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("陈近南", ({
		"chen jinnan",
		"jinnan",
		"chen",
	}));
	set("title", "天地会总舵主");
	set("long",
		"一个书生打扮的中年汉子，神色和霭可亲，但目光如电，不怒自威。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 35);
	set("shen_type",1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1800);
	set("max_jing", 1800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 1500000);
	set("score", 100);
	

	set_skill("force", 200);
	set_skill("dodge", 180);
	set_skill("cuff", 180);
	set_skill("claw",200);
	set_skill("strike",180);
	set_skill("unarmed",180);
	set_skill("parry", 180);
	set_skill("blade",180);
	set_skill("sword",180);
	set_skill("stick",180);
	set_skill("staff",180);
	
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

