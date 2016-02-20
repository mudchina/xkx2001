//Cracked by Roath
// liqueur.c

inherit ITEM;

void init();

void create()
{
	set_name("酒",({"liqueur", "jiu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯琥珀色的陈酒，艳若胭脂，芳香袭人。\n");
		set("unit", "杯");
		set("value", 300);
	set("remaining", 2);
	set("drink_supply", 50);
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

	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0);
	this_player()->add("water", (int)query("drink_supply"));
	this_player()->apply_condition("drunk", 5 + (int)this_player()->query_condition("drunk") );

	if( this_player()->is_fighting() )
		this_player()->start_busy(2);

	add("remaining", -1);
	if ( query("remaining") )
	{
		 message_vision("$N举起酒杯饮了口酒，祗觉酒香扑鼻，甚是醇美。\n", this_player());
	} else 
	{ 
		 message_vision("$N举起酒杯，把剩下的酒一饮而尽。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
