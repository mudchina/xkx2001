//Cracked by Roath
// tianxiang.c 天香断续膏

#include <ansi.h>

inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
{

	set_name(MAG"天香断续膏"NOR, ({"tian xiang", "gao"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "盒");
		set("long", "这是一盒极为有效的峨嵋独门伤药，专治内外伤等。\n");
		set("value", 5000);
		set("medicine", 1);
		set("no_drop", "如此宝贵的灵药丢弃了不怕回去被师父责罚吗？");
	}

	set("used", 3);
	set("emei",1);
	setup();
}

int cure_ob(object me)
{
	if (me->query("eff_qi") == me->query("max_qi"))
		return notify_fail("你现在不用敷天香断续膏。\n");
	
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		this_player()->receive_wound("qi", 50, "用药不当伤势恶化死了");
		message_vision(HIR "$N敷上一些天香断续膏，只觉伤口反而恶化，原来敷药过急过多，药效适得其反！\n" NOR, me);
	}
	else if ( me->query_skill_mapped("force") != "linji-zhuang" ) 
		message_vision(HIC "$N敷上一些天香断续膏，只觉作用不大，原来内功不符，药力行不开。\n" NOR, me);
	else
	{
		this_player()->receive_curing("qi", 500);
		message_vision(HIC "$N敷上一些天香断续膏，只觉伤势大为好转，气色好多了。\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 15);

	if ( add("used", -1) < 1 ) {
		tell_object(me, "这盒天香断续膏用完了。\n");
		destruct(this_object());
	}
	return 1;

}

