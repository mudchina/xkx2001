//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("王武通", ({
		"wang wutong",
		"wutong",
		"wang",
	}));
	set("title", "武胜镖局总镖头");
	set("nickname", "金枪无敌");
	set("long",
		"他是一个神态威猛的汉子，是京城最大镖局武胜镖局的总镖头。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 35);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("combat_exp", 200000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("claw",100);
	set_skill("strike",100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("pike",100);
	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

	carry_object("/clone/armor/huyao")->wear();
	carry_object("/clone/armor/gebu-changpao")->wear();
	carry_object("/clone/weapon/qiang")->wield();
}

