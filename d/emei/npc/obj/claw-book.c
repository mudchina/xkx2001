//Cracked by Roath
// claw-book.c 基本爪法
// xbc 1997/02/03

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("羊皮", ({ "skin", "book", "yangpi" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块发黄的羊皮，里面密密麻麻刻了许多小字。\n");
		set("value", 400);
		set("material", "paper");
		set("skill", ([
			"name":	"claw",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	40	// the maximum level you can learn
		]) );
	}
	::create();
}
