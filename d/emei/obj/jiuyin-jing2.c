//Cracked by Roath
// jiuyin-jing2.c 九阴真经下卷

inherit ITEM;

void create()
{
	set_name("九阴真经", ({ "jing", "jiuyin-zhenjing" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本手抄小书，封面上写着「九阴真经——下册」几个字，里面密密麻麻写了许多小字。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"claw",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	50,	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	60	// the maximum level you can learn
		]) );
	}
}
