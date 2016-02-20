//Cracked by Roath
// gaibang npc code

inherit NPC;

void create()
{
	set_name("李斧头", ({"li futou", "futou", "li"}));
	set("title", "丐帮六袋弟子");
	set("gender", "男性");
	set("age", 32);
	set("long", 
		"李斧头生性豪爽，擅使大板斧，当着无敌，是丐帮有名的豪杰之士。\n");

	set("attitude", "heroism");
	set("str", 30);
	set("int", 18);
	set("con", 28);
	set("dex", 20);

	set("rank", 6);

	set("max_qi", 650);
	set("max_jing", 400);
	set("neili",600);
	set("max_neili", 600);
	set("jiali", 50);
	
	set("combat_exp", 166000);
	
	set_skill("force", 60); 
	set_skill("huntian-qigong", 60); 
	set_skill("strike", 55); 
	set_skill("xianglong-zhang", 65); 
	set_skill("axe", 80); 
	set_skill("dodge", 60); 
	set_skill("xiaoyaoyou", 50); 
	set_skill("parry", 60); 
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(5);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/banfu")->wield();
}

#include "/kungfu/class/gaibang/promote.h"
