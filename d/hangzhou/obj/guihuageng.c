//Cracked by Roath

inherit ITEM;
#include <ansi.h>
void init();
void do_eat();

void create()
{
	set_name(HIM"桂花鲜栗羹"NOR,({"guihua geng", "soup", "geng"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗稠稠的桂花羹，悠悠地冒着香气～～～\n");
		set("unit", "碗");
		set("value", 120);
        set("remaining", 3);
        set("drink_supply", 50);
	set("food_supply", 30);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{

	int heal, recover, jing, e_jing, m_jing;
	
	recover = 5;
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("你已经吃得太多了，再吃就要把肚子撑破了。\n");

    set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    this_player()->add("food", (int)query("food_supply"));
    jing = (int)this_player()->query("jing");
    e_jing = (int)this_player()->query("eff_jing");
    m_jing = (int)this_player()->query("max_jing");

// No heal effect for 香茶
/***

    if ( e_jing < m_jing )
	{ 	
		if ( (e_jing + heal) >= m_jing )
		{
			this_player()->set("eff_jing", m_jing);
		} else
		{	
			this_player()->set("eff_jing", e_jing+heal);
		}	
	} 
***/

	if (jing < e_jing )
	{
        if ( (jing + recover) >= e_jing )
        {
            this_player()->set("jing", e_jing);
        } else
        {   
            this_player()->set("jing", jing+recover);
        }   
	}

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N端起碗桂花鲜栗羹，有滋有味地品了几口。\n"+
      		"一股桂花香直入心脾，$N觉得精神好多了。\n", this_player());
	} else 
	{ 
   		 message_vision("$N端起碗，把剩下的桂花鲜栗羹一饮而尽。\n"+
      		"一股桂花香直入心脾，$N觉得精神好多了。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
