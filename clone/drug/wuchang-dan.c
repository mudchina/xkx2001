//Cracked by Roath
// wuchang-dan.c 无常丹

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
        set_name(HIR "无常丹" NOR, ({"wuchang dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是桃花岛疗伤圣药无常丹。\n");
                set("value", 5000);
		set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
        {
                this_player()->add("neili", -100);
                message_vision(HIR "$N吃下一棵无常丹，只觉得头重脚轻，火气翻腾，
原来服食太多，药效适得其反！\n" NOR, this_player());
                this_player()->apply_condition("bonze_drug",
                this_player()->query_condition("bonze_drug")+10);
		destruct(this_object());
        }
	me->set("eff_qi", (int)me->query("max_qi"));

	message_vision(HIG 
"$N吃下一粒无常丹，顿时神完气足，精神焕发\n" NOR, me);
	this_player()->apply_condition("bonze_drug",
                this_player()->query_condition("bonze_drug")+10);

	destruct(this_object());
	return 1;
}

