//Cracked by Roath
// danggui.c 当归

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void init();

void create()
{
	set_name( GRN "当归" NOR , ({"dang gui", "danggui"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵百年的老当归，虽然已经干瘪，但其养精镇神的药效甚佳。\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
		me->set("jingli", 0);
		me->apply_condition("bonze_drug", 30);
        message_vision(HIR "$N吃下一颗当归，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
		destruct(this_object());
        }
	me->add("max_jingli", 1);
	me->add("eff_jingli", 1);
	me->set("jingli", (int)me->query("max_jingli"));
	me->apply_condition("bonze_drug", me->query_condition("bonze_drug")+25);
	message_vision(HIY "$N吃下一棵老当归，一道热线直上重楼，全身的精力都恢复了。\n" NOR, me);

	destruct(this_object());
	return 1;
}
