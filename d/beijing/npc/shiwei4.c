//Cracked by Roath
// Npc: 四等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("四等侍卫", ({
		"sideng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是御前侍卫，看来可能是个满族王公大臣子弟。\n");

	set("age", 29);
	setup();
	set_shiwei_status(80);

}

#include "/d/beijing/autok.h"
