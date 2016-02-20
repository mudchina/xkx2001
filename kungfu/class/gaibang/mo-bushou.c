//Cracked by Roath
// gaibang npc code

inherit NPC;

void create()
{
	set_name("莫不收", ({"mo bushou", "mo", "bushou"}));
	set("title", "丐帮三袋弟子");
	set("gender", "男性");
	set("age", 21);
	set("long", 
		"这是个蓬头垢面的青年乞丐，整天端着个破碗哼哼：“你不收，他不收，谁也不愿收 ...”\n");

	set("attitude", "peaceful");
	set("str", 25);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("rank", 3);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 150);
	set("max_neili", 150);
	set("jiali", 25);
	
	set("combat_exp", 29000);
	
	set_skill("unarmed", 30);
	set_skill("force", 30); 
	set_skill("huntian-qigong", 30); 
	set_skill("stick", 30); 
	set_skill("dagou-bang", 35); 
	set_skill("dodge", 30); 
	set_skill("xiaoyaoyou", 30); 
	set_skill("parry", 32); 
	set_skill("begging", 30); 
	set_skill("checking", 20); 
	
	map_skill("force", "huntian-qigong");
	map_skill("stick", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(4);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/d/village/npc/obj/stick")->wield();
}

#include "/kungfu/class/gaibang/promote.h"
