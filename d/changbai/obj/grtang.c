//Cracked by Roath
// grtang

inherit ITEM;

void init();

void create()
{
	set_name("狗肉汤",({"gourou tang", "tang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的狗肉汤，上面还漂着几片葱花。\n");
		set("unit", "碗");
		set("value", 150);
                set("remaining", 5);
                set("drink_supply", 30);
                set("food_supply", 10);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{	
	
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
    if((int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	
        add("remaining", -1);
        this_player()->add("water", (int)query("drink_supply"));
/*
        this_player()->receive_heal("jing", 30);
        this_player()->receive_curing("jing", 15);
        this_player()->receive_heal("jingli", 30);
*/

	if ( query("remaining") ) {
   		 message_vision("$N端起大碗，咕咚咕咚的喝了几口汤。\n", this_player());
	} else { 
   		 message_vision("$N端起大碗，把剩下的汤喝得干干净净。\n", this_player());
		
		 destruct(this_object());
	}

	return 1;
}


