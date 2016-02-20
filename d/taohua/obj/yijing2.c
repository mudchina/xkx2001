//Cracked by Roath
// yijing.c

inherit ITEM;

void create()
{
	set_name( "易经《说卦篇》", ({ "jing", "yi jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册易经。上面写着：\n
　　昔者，圣人之作易也，幽赞神明而生蓍。
　　观变於阴阳，而立卦；发挥於刚柔，而生爻；和顺於道德，而理於
义；穷理尽性，以至於命。
\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 15, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	60,	// the maximum level you can learn
		]) );
	}
}
