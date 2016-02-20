//Cracked by Roath
// gaibang npc code

inherit NPC;

void create()
{
	set_name("裘万家", ({"qiu wanjia", "qiu", "wanjia"}));
	set("title", "丐帮二袋弟子");
	set("gender", "男性");
	set("age", 18);
	set("long", 
		"这是少年乞丐，长得眉青目秀，似乎是家世沦落，被迫浪荡街头。\n");

	set("attitude", "heroism");
	set("str", 17);
	set("int", 26);
	set("con", 20);
	set("dex", 20);

	set("rank", 2);

	set("max_qi", 250);
	set("max_jing", 250);
	set("neili", 100);
	set("max_neili",100);
	set("jiali", 20);
	
	set("combat_exp", 10000);
	
	set_skill("force", 20); 
	set_skill("huntian-qigong", 20); 
	set_skill("strike", 25); 
	set_skill("xianglong-zhang", 20); 
	set_skill("dodge", 20); 
	set_skill("xiaoyaoyou", 18); 
	set_skill("parry", 20); 
	set_skill("stealing", 10); 
	set_skill("checking", 30); 
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("strike", "xianglong-zhang");

	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(1);
	carry_object("/d/gaibang/obj/budai")->wear();
}

#include "/kungfu/class/gaibang/promote.h"
