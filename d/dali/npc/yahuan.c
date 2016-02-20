//Cracked by Roath
// yahuan.c

inherit NPC;

void create()
{
	set_name("小丫鬟", ({ "ya huan","yahuan","ya" }) );
	set("gender", "女性");
	set("age", 16);
	set("long",
		"她是钟万仇家的丫鬟，大约十多岁年纪，在万劫谷里负责伺候夫人和小姐。\n");
	set("combat_exp", 2000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("apply/attack", 10);
	set("apply/defense", 10);

	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();

	carry_object("/clone/misc/cloth")->wear();
}
