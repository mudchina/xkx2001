//Cracked by Roath
// haigui
// Ssy


#include <ansi.h>

inherit NPC;

void create()
{
	set_name("海龟", ({ "haigui", "gui"}));
        set("race", "野兽");
        set("age", 100+random(100));
	set("long", "这是只很老的海龟，龟壳又厚又大。\n");
	set("attitude", "peaceful");

	set("str", 15);
	set("int", 10);
	set("con", 19);
	set("dex", 15);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 150);
	set("eff_jing", 150);
	set("jing", 150);

	set("max_jingli", 150);
	set("eff_jingli", 150);
	set("jingli", 150);
	set("combat_exp", 80);
        set_temp("apply/armor",  30);


	setup();
}


