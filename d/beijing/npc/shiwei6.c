//Cracked by Roath
// Npc: 六等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("六等侍卫", ({
		"liudeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long", "这是一个刚从官兵里提拔出来的侍卫。\n");

	set("age", 25);
	setup();
	set_shiwei_status(30);

}

#include "/d/beijing/autok.h"
