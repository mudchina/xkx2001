//Cracked by Roath
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("翔少爷", ({"xiang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒助长内力的灵药，吃了之后有要飞翔的欲望，像个少爷似的。\n");
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        if ( me->query("neili") >= me->query("max_neili")*2 )
        return notify_fail("你现在没必要吃翔少爷。\n");

        me->add("neili", 1);
        message_vision(HIY "$N吃下一粒翔少爷，只觉得身轻如燕要飞翔！\n" NOR, me);

        destruct(this_object());
        return 1;
}

