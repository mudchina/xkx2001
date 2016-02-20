//Cracked by Roath
// haigui_s
// Ssy


#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小海龟", ({ "small haigui", "haigui", "gui"}));
        set("race", "野兽");
        set("age", 20);
	set("long", "这是只小海龟，挺可爱的样子。\n");
	set("attitude", "peaceful");

	set("str", 13);
	set("int", 10);
	set("con", 19);
	set("dex", 15);

	set("max_qi", 100);
	set("eff_qi", 100);
	set("qi", 100);
	set("max_jing", 100);
	set("eff_jing", 100);
	set("jing", 100);

	set("max_jingli", 100);
	set("eff_jingli", 100);
	set("jingli", 100);
	set("combat_exp", 50);

	setup();
}


