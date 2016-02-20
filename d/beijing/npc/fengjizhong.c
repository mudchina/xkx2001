//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("风际中", ({
		"feng jizhong",
		"jizhong",
		"feng",
	}));
	set("title", "青木堂会众");
	set("long",
		"他相貌平平，武功高强，举止却和一个呆头木乡下佬一般。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("combat_exp", 500000);
	set("score", 100);
	

	set_skill("force", 130);
	set_skill("dodge", 120);
	set_skill("cuff", 150);
	set_skill("claw",140);
	set_skill("strike",130);
	set_skill("unarmed",150);
	set_skill("parry", 140);
	set_skill("blade",120);
	set_skill("sword",120);
	set_skill("stick",120);
	set_skill("staff",120);
        set_skill("wuxing-quan",100);
        set_skill("wuxingbu",100);	
/*
	map_skill("force", "hunyuan-yiqi");
*/
	map_skill("dodge", "wuxingbu");
	map_skill("cuff", "wuxing-quan");
/*
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	prepare_skill("cuff", "wuxing-quan");
	setup();

      carry_object("/d/taihu/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

