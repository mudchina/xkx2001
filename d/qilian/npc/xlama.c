//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;

void create()
{
	set_name("小喇嘛", ({ "xiao lama", "xiao", "lama" }));
	set("long", 
"这是一个普普通通的小喇嘛，他身穿黄色袈裟，左手拿着个法轮，右手挟着\n"
"经书，正匆匆忙忙地走着。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("class","bonze");
	set("shen_type", 1);
	set("str", 22);
	set("int", 20);
	set("con", 22);
	set("dex", 21);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("combat_exp", 1000);

	set_skill("force", 20);
	set_skill("dodge", 25);
	set_skill("parry", 20);
	set_skill("strike", 20);


	setup();
	carry_object(__DIR__"obj/lamajiasha")->wear();
}

