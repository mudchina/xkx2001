//Cracked by Roath

inherit ITEM;

void init();
void do_eat(string);

void create()
{
	set_name("馕",({"nang"}));
	set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只脸盆般大小的馕，是长途旅行必备的干粮。\n");
		set("unit", "只");
		set("value", 80);
        set("remaining", 9);
	set("food_supply", 20);
    }
	
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{

    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("你已经吃得太饱了。\n");

	set("value", 0);
    this_player()->add("food", (int)query("food_supply"));

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N拿起馕吃了几口。\n", this_player());
	} else 
	{ 
   		 message_vision("$N把剩下的馕吃得干干净净。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
