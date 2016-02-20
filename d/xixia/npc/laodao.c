//Cracked by Roath

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("老道士", ({ "lao daoshi", "lao", "daoshi" }) );
	set("gender", "男性");
	set("age", 65);
	set("class", "taoist");
	set("long",
		"这是一个精壮老道士。\n");
	set("combat_exp", 5000);
        set("shen_type", 0);
	set("attitude", "peaceful");

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
	set_skill("unarmed", 30);
	set_skill("dodge", 30);

	setup();

        carry_object("/d/wudang/obj/greyrobe")->wear();
}

