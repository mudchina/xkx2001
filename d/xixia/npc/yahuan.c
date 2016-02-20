//Cracked by Roath

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小丫环", ({ "xiao yahuan", "xiao", "yahuan" }) );
	set("gender", "女性");
	set("age", 15);
	set("long",
		"这是将军府的小丫环。\n");
	set("combat_exp", 100);
        set("shen_type", 0);
	set("attitude", "peaceful");

	set("str", 16);
	set("con", 22);
	set("int", 20);
	set("dex", 19);

	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 100);
	set("jing", 100);

	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);

	setup();

        carry_object("/d/city/obj/pink_cloth")->wear();
}

