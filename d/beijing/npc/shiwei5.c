//Cracked by Roath
// Npc: 五等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("五等侍卫", ({
		"wudeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是一个低级御前侍卫。\n");

	set("age", 29);
	setup();
	set_shiwei_status(50);

}

#include "/d/beijing/autok.h"
