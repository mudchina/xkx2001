//Cracked by Roath

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("樵夫", ({ "qiao fu", "qiao", "fu" }) );
	set("gender", "男性");
	set("age", 55);
	set("long",
		"这是一个精壮老汉。\n");
	set("combat_exp", 5000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 400);
	set("eff_qi", 400);
	set("qi", 400);
	set("max_jing", 500);
	set("jing", 500);

	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);

	set_skill("axe", 30);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);

	setup();

        carry_object("/clone/weapon/dafu")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

