//Cracked by Kafei
// ziyin_book2.c

inherit ITEM;

void create()
{
	set_name("玉女二十四诀下卷", ({ "yunu book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","玉女二十四诀是古墓派修身练精的心法要诀。十二多反诀：\n"
			   "多思则神怠，多念则精散，多欲则智损，多事则形疲，多语则气促，\n"
			   "多笑则肝伤，多愁则心慑，多乐则意溢，多喜则忘错昏乱，多怒则百\n"
			   "脉不定，多好则专迷不治，多恶则焦煎无宁。此十二多不除，丧生之本也。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"yunu-jue",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	40,			// jing cost every time study this
			"difficulty":	20,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	100			// the maximum level you can learn
								// from this object.
		]) );
	}
}
