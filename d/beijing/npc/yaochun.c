//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("姚春", ({
		"yao chun",
		"chun",
		"yao",
	}));
	set("title", "回春堂大夫");
	set("long",
		"他是京城有名的跌打大夫，擒拿短打也是一绝，不过看起来倒满和蔼。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 50);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 900);
	set("max_neili", 900);
	set("combat_exp", 200000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("claw",100);
	set_skill("strike",100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

	carry_object("/clone/armor/gebu-changpao")->wear();
}

