//Cracked by Roath
// Npc: 二等侍卫
// Ssy, chu

#include <ansi.h>
inherit NPC;

void set_shiwei_status(int);

void create()
{
	set_name("二等侍卫", ({
		"erdeng shiwei",
		"shiwei",
		"wei",
	}));
	set("long",
		"这是一个品级不低的御前侍卫，大多是满族王公大臣子弟。\n"
		"他看起来有点心不在焉。\n"
	);

	set("age", 35);
	setup();
	set_shiwei_status(120);

}

#include "/d/beijing/autok.h"
