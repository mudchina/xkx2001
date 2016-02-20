//Cracked by Roath
// yijing.c

inherit ITEM;

void create()
{
	set_name( "易经《序卦篇》", ({ "jing", "yi jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册易经。上面写着：\n
　　有天地，然后有万物； 有万物，然后有男女； 有男女，然后有夫妇；
有夫妇，然后有父子；有父子然后有君臣；有君臣，然后有上下；有上下，
然后礼仪有所错。 夫妇之道，不可以不久也，故受之以恒；物不可穷也，
故受之以未济终焉。
\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 10, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30,	// the maximum level you can learn
		]) );
	}
}
