//Cracked by Roath
// gaibang npc code

inherit NPC;

void create()
{
	set_name("快活三", ({"kuaihuo san", "kuaihuo", "san"}));
	set("title", "丐帮四袋弟子");
	set("gender", "男性");
	set("age", 25);
	set("long", 
		"他是个长得十分结实的青年乞丐，正笑咪咪的盯着你瞧，不知他为啥这么高兴。\n");

	set("attitude", "heroism");
	set("str", 28);
	set("int", 18);
	set("con", 22);
	set("dex", 20);

	set("rank", 4);

	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 30);
	
	set("combat_exp", 58000);
	
	set_skill("force", 40); 
	set_skill("huntian-qigong", 40); 
	set_skill("blade", 45); 
	set_skill("liuhe-dao", 45); 
	set_skill("dodge", 40); 
	set_skill("xiaoyaoyou", 35); 
	set_skill("parry", 30); 
	set_skill("begging", 50); 
	set_skill("stealing", 60); 
	
	map_skill("force", "huntian-qigong");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(3);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

#include "/kungfu/class/gaibang/promote.h"
