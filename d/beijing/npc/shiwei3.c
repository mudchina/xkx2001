//Cracked by Roath
// Npc: 三等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("三等侍卫", ({
		"sandeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是一个御前侍卫，看来可能是个满族王公大臣子弟。\n");

	set("age", 32);
	setup();
	set_shiwei_status(100);

}

#include "/d/beijing/autok.h"
