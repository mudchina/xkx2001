//Cracked by Roath
// baixian-wan.c 百涎丸
// ywz 08/31/96

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void create()
{
	set_name(HIW "百涎丸" NOR, ({"baixian-wan", "wan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "粒");
		set("long", "这是一粒百涎丸，看上去白熙熙的，还透着亮光，不知道吃了会...\n");
		set("medicine", 1);
		set("value", 10000);
        }

        setup();
}

int cure_ob(object me)
{
	message_vision(HIG "$N吃下一粒百涎丸，只觉得胸内气血翻腾，啊...！吃错药了!!! \n" NOR, me);

//	me->set("eff_jing", (int)me->query("min_jing"));
	me->set("jing", (int)me->query("min_jing"));
//	me->set("eff_qi", (int)me->query("min_qi"));
	me->set("qi", (int)me->query("min_qi"));
//	me->set("neili", (int)me->query("max_neili"));

        destruct(this_object());
        return 1;
}
