//Cracked by Roath

inherit NPC;

void create()
{
	set_name("老和尚", ({"seng ren","heshang"}));
	set("long",
		"他是一位老和尚，骨瘦如柴，身上的袈裟打满了补丁。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 65);
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 25);
	set("dex", 23);
	set("max_qi", 580);
	set("max_jing", 500);
	set("neili", 480);
	set("max_neili", 480);
	set("jiali", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);

	setup();
	carry_object("/d/shaolin/obj/cloth")->wear();

	setup();
}

int accept_object(object me, object obj)
{
	if( obj->query("name") == "金刚经" )
	{
		command("smile");
		command("say 阿弭陀佛，多谢这位" + RANK_D->query_respect(me) + "了 ！");
	}

	return 1;
}

