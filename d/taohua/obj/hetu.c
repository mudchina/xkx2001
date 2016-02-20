//Cracked by Roath
// hetu.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name( GRN"河图"NOR, ({ "tu", "he tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "卷");
		set("long", "这是一卷陈旧的竹卷轴，上刻有两个金文“河图”。\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 30+random(20), 	// jing cost every time study this
			"difficulty":	35,	// the base int to learn this skill
			"max_skill":	360,	// the maximum level you can learn
		]) );
	}
	::create();
}
