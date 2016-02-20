//Cracked by Roath
// apple.c 苹果
// by aln 4 / 98

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("苹果", ({"ping guo", "apple", "guo"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "一个又大又红的苹果\n");
		set("unit", "个");
                set("value", 80);
		set("food_remaining", 5);
		set("food_supply", 5);
        }
}

void init()
{
        add_action("do_yao", "yao");
        add_action("do_yao", "eat");
        add_action("do_yao", "chi");
}

int do_yao(string arg)
{
        if( !this_object()->id(arg) ) 
                return 0;

        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");

        if( !living(this_player()) ) 
                return 0;

        if( !query("food_remaining") )
                return notify_fail( name() + "已经没什么好吃的了。\n");

        if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
                return notify_fail("你已经吃得太多了。\n");

        this_player()->add("food", (int)query("food_supply"));
        this_player()->receive_curing("jing", this_player()->query("con"));

        if( this_player()->query_condition("sl_poison") )
        this_player()->apply_condition("sl_poison",
                this_player()->query_condition("sl_poison") - 1);

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        set("value", 0);
        add("food_remaining", -1);
        if( !query("food_remaining") ) {
                message_vision("$N将剩下的" + name() + "吃得干乾净净。\n", this_player());
                if( !this_object()->finish_eat() )
                        destruct(this_object());
        } else 
                message_vision("$N拿起" + name() + "咬了几口。\n", this_player());

        this_player()->start_busy(1);
        return 1;
}

