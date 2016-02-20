//Cracked by Roath
// xuedao_book.c 

inherit ITEM;

void create()
{
	set_name("血刀秘笈", ({ "xuedao book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", 
		"封面上有着几个字不象字，画不象画的图行。内中全是裸体男像，各有异姿，\n"
                "全是曲发钩鼻，深目高颧的西域人氏。\n");
		set("value", 5000);
		set("material", "paper");
		set("no_drop","这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("skill", ([
			"name":	"xue-dao", // name of the skill
			"exp_required":	10000,	  // minimum combat experience required
			"jing_cost":	30+random(30),	  // jing cost every time study this
			"difficulty":	25,	  // the base int to learn this skill
			"max_skill":	99,	  // the maximum level you can learn
		]) );
	}
}
