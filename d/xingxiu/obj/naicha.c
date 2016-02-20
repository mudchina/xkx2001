//Cracked by Roath
// 奶茶

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("奶茶",({"tea", "cha", "nai cha"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗香香浓浓的奶茶，上面漂着黄灿灿的酥油花。\n");
		set("unit", "碗");
		set("value", 300);
	set("remaining", 3);
	set("drink_supply", 60);
	set("food_supply", 20);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
	int heal, jing, e_jing, m_jing;
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
	return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    this_player()->add("food", (int)query("food_supply"));

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
		 message_vision("$N端起大碗，咕噜咕噜地喝了几口奶茶。\n", this_player());
	} else 
	{ 
		 message_vision("$N端起大碗，把剩下的奶茶一饮而尽，双手捂了一下碗口。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
