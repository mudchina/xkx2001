//Cracked by Kafei
// sikong.c 司空玄

inherit NPC;

void create()
{
	set_name("司空玄", ({ "sikong xuan", "siknong", "xuan" }));
	set("nickname", "神农帮帮主");
	set("long", 
		"他就是神农帮帮主司空玄，他长着一把山羊胡子，神态甚是倨傲。\n");
	set("gender", "男性");
	set("age", 50);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("score", 20000);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 100000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
  	set_skill("blade", 80);

	setup();
	carry_object("/d/dali/obj/duandao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

