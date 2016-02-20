//Cracked by Roath
// shen.c 沈青刚

inherit NPC;

void create()
{
	set_name("沈青刚", ({ "shen qinggang", "shen" }));
	set("nickname", "断魂刀");
	set("long", 
"沈青刚是黄河四鬼的老大，是鬼门龙王沙通天的大弟子，擅使单刀。\n");
	set("title", "黄河四鬼老大");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 10000);

	set_skill("force", 30);
	set_skill("wuhu-duanmen", 45);
	set_skill("wuxingbu", 35);
	set_skill("dodge", 35);
	set_skill("parry", 40);
	set_skill("blade", 45);
	set_skill("unarmed", 35);

	map_skill("blade", "wuhu-duanmen");
	map_skill("parry", "wuhu-duanmen");
	map_skill("dodge", "wuxingbu");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
