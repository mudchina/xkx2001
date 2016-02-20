//Cracked by Roath
// sheli-zii.c 舍利子

#include <ansi.h>

inherit ITEM;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name("舍利子", ({"sheli zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗活佛坐化的舍利子，小指尖大小，色泛灰白，隐隐有宝光流动。\n");
//		set("no_drop","这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
		set("value", 300000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	int add_skill, improve, add;

	add = 10+random(20);
	
	if ( (int)me->query_condition("bonze_drug" ) > 0 ){
		me->add("max_jingli", -add);
		me->add("eff_jingli", -add);
		me->apply_condition("bonze_drug", 80);
	message_vision(HIR "$N吃下一颗舍利子，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
	me->unconcious();
	destruct(this_object());
	}
	else {
		message_vision(HIY "$N吃下一颗舍利子，油然间只觉脑袋里注进了一缕清新之气...\n" NOR, this_player());
                me->add("max_jingli", add);
		me->add("eff_jingli", add);
		me->apply_condition("bonze_drug", 80);
	}
	me->unconcious();
	destruct(this_object());
	return 1;
}

