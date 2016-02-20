//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("康亲王", ({
		"kang qinwang",
		"qinwang",
		"kang",
	}));
	set("title", "正红旗主");
	set("long",
		"当年从关外打到关内的一名悍将，大贝勒代善之后，现为八旗中正红旗主。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 45);
	set("shen_type",1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 800);
	set("max_neili", 800);
	set("combat_exp", 100000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 60);
	set_skill("cuff", 90);
	set_skill("claw",70);
	set_skill("strike",80);
	set_skill("unarmed",90);
	set_skill("parry", 90);
	set_skill("blade",90);
	set_skill("sword",90);
	set_skill("stick",70);
	set_skill("staff",70);
	
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

