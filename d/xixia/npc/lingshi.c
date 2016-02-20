//Cracked by Roath

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("石人武士", ({ "wu shi", "shi", "guard" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是西夏黄帝的守陵卫士，看起好象来身手不凡。\n");
	set("combat_exp", 500000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 1200);
	set("eff_qi", 1200);
	set("qi", 1200);
	set("max_jing", 800);
	set("jing", 800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 60);

	set_temp("apply/attack",  100);
	set_temp("apply/defense", 100);

	set_skill("pike", 150);
	set_skill("unarmed", 130);
	set_skill("force", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);

	set("no_get", "石人武士对你而言太重了。");
	setup();

        carry_object("/clone/weapon/qiang")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

