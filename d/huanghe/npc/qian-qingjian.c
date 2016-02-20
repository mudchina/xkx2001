//Cracked by Roath
// qian.c 钱青健

inherit NPC;

void create()
{
	set_name("钱青健", ({ "qian qingjian", "qian" }));
	set("nickname", "丧门斧");
	set("long", 
"钱青健是黄河四鬼的老四，是鬼门龙王沙通天的四弟子，擅于斧法。\n");
        set("title", "黄河四鬼老四");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 21);
	set("int", 18);
	set("con", 21);
	set("dex", 20);
	
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 9500);

        set_temp("apply/attack",  30);
        set_temp("apply/defense", 30);

	set_skill("force", 30);
	set_skill("dodge", 35);
	set_skill("parry", 40);
	set_skill("axe", 45);
	set_skill("unarmed", 30);

	setup();
	carry_object("/clone/weapon/dafu")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
