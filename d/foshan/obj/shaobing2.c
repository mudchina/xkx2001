//Cracked by Roath
// Jay 5/3/97

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("烧饼", ({"shaobing", "cake"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一张香喷喷的大烧饼，里面有葱花，外面有芝麻。\n");
                set("unit", "张");
                set("value", 70);
                set("food_remaining", 3);
                set("food_supply", 30);
		set("no_steal", 1);
		set("no_steall", 1);
        }
}

void init()
{
        add_action("do_eat", "chi");
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object ling;
	object me = this_player();

	if (!id(arg))
                return notify_fail("你要吃什么？\n");

	if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( !living(me) ) return 0;

        if( !query("food_remaining") )
                return notify_fail( name() + "已经没什么好吃的了。\n");
        if( (int)me->query("food") >= (int)me->max_food_capacity() )
                return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

        me->add("food", query("food_supply"));
        me->add("jingli", query("food_supply")/5);
        if( me->query("jingli") > me->query("max_jingli")) 
        me->set("jingli", me->query("max_jingli"));

        if( me->is_fighting() ) me->start_busy(2);

        // This allows customization of drinking effect.
        if( query("eat_func") ) return 1;

        set("value", 0);
        add("food_remaining", -1);
        if( !query("food_remaining") ) {
                tell_object(me,"突然嘎嘣一声，你差点咯掉一颗牙。原来烧饼里有一块铁片。\n");
                ling = new(__DIR__"xtling");
                ling->move(me);
                message_vision("$N将剩下的" + name() + "吃得干乾净净。\n", me);

                if( !this_object()->finish_eat() ) {
                        destruct(this_object());
                }


        } else 
                message_vision("$N拿起" + name() + "咬了几口。\n", me);

        me->start_busy(1);
        return 1;
}


