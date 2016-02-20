//Cracked by Roath
// zixia_book.c 紫霞秘笈

inherit ITEM;
void create()
{
	set_name("紫霞秘笈", ({ "zixia book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", 
		"这是华山气宗的镇山之宝《紫霞秘籍》。紫霞神功是武林中一等\n"
		"一的内家功夫，能为别人疗伤及自疗。\n");
		set("value", 7000);
		set("material", "paper");
		set("skill", ([
			"name":	"zixia-gong", // name of the skill
			"exp_required":	3000,	  // minimum combat experience required
			"jing_cost":	30,	  // jing cost every time study this
			"difficulty":	10,	  // the base int to learn this skill
			"max_skill":	50,	  // the maximum level you can learn
		]) );
	}
}
