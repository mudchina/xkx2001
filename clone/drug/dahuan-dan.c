//Cracked by Roath
// dahuan-dan.c 大还丹

#include <ansi.h>

inherit ITEM;

void setup()
{}
int cure_ob(string);
void init()
{
	add_action("do_put", "put");
}

void create()
{
	set_name("大还丹", ({"dahuan dan", "dahuan", "dan"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗紫红晶亮的大还丹。此丹乃少林珍药，提高功力，灵效无比。\n");
		set("value", 10000);
		set("medicine", 1);
		set("no_drop", "这样东西不能离开你。\n");
	}

	set("shaolin",1);
	setup();
}

int cure_ob(object me)
{

	if ( me->query_skill_mapped("force") != "hunyuan-yiqi" )
	{
		me->add("max_neili", -10);
		message_vision(HIR "$N吃下一颗大还丹，只觉得肝肠寸断，原来所练内功不符，反而大损真元！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗大还丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N吃下一颗大还丹，只觉得体内真力源源滋生，过紫宫，入泥丸
透十二重楼，遍布奇筋八脉，全身功力顿然提高 !\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 60);
	
	destruct(this_object());
	return 1;
}

int do_put(string arg1, string arg2, string arg3)
{
	if( present(arg1, this_player()) == this_object() ) return 1;

	return 0;
}

