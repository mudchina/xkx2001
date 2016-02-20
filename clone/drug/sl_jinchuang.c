//Cracked by Roath
// jinchuang-yao.c 金创药

#include <ansi.h>

inherit ITEM;

void setup()
{}
int cure_ob(string);
void create()
{

	set_name("金创药", ({"jin chuangyao", "jin"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包别具灵效的少林金创药，专治内外伤等。\n");
		set("value", 2000);
		set("no_drop", "这样东西不能离开你。\n");
	}

	set("shaolin",1);
	setup();
}

int cure_ob(object me)
{

	if (me->query("eff_qi") == me->query("max_qi"))
		return notify_fail("你现在不需要用金创药。\n");
	
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		this_player()->add("eff_qi", -50);
		message_vision(HIR "$N敷上一些金创药，只觉胸口烦恶欲呕，四肢乏力，原来用得太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		this_player()->receive_curing("qi", 50);
		message_vision(HIC "$N小心翼翼地把一包金创药敷在伤口上，只觉伤势大为好转，气色看起来好多了。\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 15);

	destruct(this_object());
	return 1;

}

