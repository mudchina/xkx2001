//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("一等侍卫", ({
		"yideng shiwei",
		"shiwei",
		"wei",
	}));
//	set("title", "一等侍卫");
	set("long",
		"这是一个品级不低的御前侍卫，大多是满族王公大臣子弟，他看起来有点心不在焉。\n"
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
	set("combat_exp", 100000+random(200000));
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("claw",100);
	set_skill("strike",100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("blade",100);
	set_skill("sword",100);
	set_skill("stick",100);
	set_skill("staff",100);
	
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

