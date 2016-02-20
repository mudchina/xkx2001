//Cracked by Roath
// Npc: 一等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("一等侍卫", ({
		"yideng shiwei",
		"shiwei",
		"wei",
	}));
	set("long",
		"这是一个品级不低的御前侍卫，大多是满族王公大臣子弟。\n"
		"他看起来有点心不在焉。\n"
	);

	set("age", 39);
	setup();
	set_shiwei_status(150);

}

#include "/d/beijing/autok.h"
