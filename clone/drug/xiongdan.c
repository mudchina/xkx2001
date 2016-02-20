//Cracked by Roath
// xiongdan.c 熊胆
// Modified by xQin 9/00 to fix the unlimited consumption bug

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void init();

void create()
{
	set_name("熊胆", ({ "xiong dan", "dan" }) );
        set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
        	set("long", "这是一颗比拳头还大的熊胆，遍体发出乌黑的亮光。\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
        me->add("food", 50);

        if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->set("jingli", 0);
                me->apply_condition("bonze_drug", 30);
                message_vision(HIR "$N吃下一颗熊胆，只觉得肝肠寸断，五脏欲裂，原来服食太多药物，药效适得其反！\n" NOR, this_player());
		destruct(this_object());
                return 1;
        }

        if( !me->query_temp("cbs/xiongdan") ) {
                me->add_temp("apply/damage", 30);
                me->set_temp("cbs/xiongdan", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query("con"));
        }

        me->add("neili", 200);
        me->apply_condition("bonze_drug", 
        me->query_condition("bonze_drug")+30);
        message_vision(HIY "$N吃下一颗熊胆，只觉得丹田充满真气混身有劲。\n" NOR, me);

        destruct(this_object());
        return 1;
}

void remove_effect(object me)
{
        me->add_temp("apply/damage", -30);
        me->delete_temp("cbs/xiongdan");
        if( wizardp(me) )
                tell_object(me, "过了一会儿，熊胆带来的余热都没了。\n");
}



