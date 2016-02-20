//Cracked by Roath
#include <ansi.h>;
inherit PILL;

void setup()
{}

int cure_ob(string);

void create()
{
	set_name(HIR"金刚大力丸"NOR, ({"dali wan", "wan"}));
	set_weight(100);
	if (clonep())
	set_default_object(__FILE__);
	else 
	{
		set("unit", "颗");
		set("long","这是江湖上常见的药丸，红色，龙眼大小，服后会力气大增。\n");
		set("value", 5000);
	}
	setup();
}

int cure_ob(object me)
{
	int app_str;
	if (me->query_temp("daliwan"))
		return notify_fail("你已服过大力丸了。\n");
	app_str = random(5)+1;
	message_vision(HIR"$N服下一颗金刚大力丸，抡了抡胳膊，直想找人打一架。\n"NOR,me);
	me->add_temp("apply/strength",app_str);
	me->set_temp("daliwan",1);
    destruct(this_object());
    return 1;
}

//void remove_eff(int app_str, object me)
//{
//	message_vision(HIM"$N胳膊一阵发软，看来金刚大力丸药性已去。\n"NOR,me);
//	me->add_temp("apply/strength",-app_str);
//	me->delete_temp("daliwan");
//}
