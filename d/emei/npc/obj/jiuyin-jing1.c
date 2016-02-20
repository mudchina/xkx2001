//Cracked by Roath
// jiuyin-jing1.c 九阴真经上卷
inherit F_UNIQUE;
inherit ITEM;

void create()
{
	set_name("羊皮", ({ "skin", "yangpi" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块发黄的羊皮，里面密密麻麻写了许多小字。\n");
		set("value", 10);
		set("material", "paper");
		set("skill", ([
			"name":	"jiuyin-zhao",	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	40	// the maximum level you can learn
		]) );
	}
	::create();
}
