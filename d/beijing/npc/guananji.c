//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("关安基", ({
		"guan anji",
		"anqi",
		"guan",
	}));
	set("title", "青木堂会众");
	set("long",
		"一部长须飘在胸前，模样甚是威风。因为他胡子生得神气，又姓关，人家都叫他关夫子。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 35);
	set("shen_type",1);
	set("str", 20);
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

