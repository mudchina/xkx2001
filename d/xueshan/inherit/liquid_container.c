//Cracked by Roath
// liquid_container.c

#include <ansi.h>
#include <dbase.h>
#include <name.h>

// variables need to set:
// liquid/container : set 1 if it's a liquid container
// liquid/unique : set to 1 if there is only one kind of liquid can be inside
// liquid/uniqueid : set to the id of that kind	liquid

static int max_liquid;
static int current_liquid;
static string liquid_name;

// couple of statics
// max_liquid is the max amout of liquid this container can hold
// current liquid is the current level of liquid inside
// liquid_name is the current liquid inside of the container

void init()
{
	add_action("do_pour", "pour");
	add_action("do_fill", "fill");
	add_action("do_empty", "empty");
}

int query_max_liquid() { return max_liquid; }
int query_current_liquid() { return current_liquid; }
string query_liquid_name() { return liquid_name; }

varargs object carry_liquid(string file, int amount, string alternative)
{
        object ob;

        ob = new(file);
        if( !objectp(ob) && stringp(alternative) ) ob = new(alternative);
        if( !objectp(ob) ) return 0;
		ob->set_amount(amount);
        ob->move_liquid(this_object());
	 //	current_liquid=amount;
        return ob;
}

void set_liquid_name(string arg) 
{
    if(strlen(arg) < 1)
        liquid_name = arg;
}

void set_max_liquid (int v)
{
	if( v < 0 ) error("Can't have nagative amout of liquid.\n");
	else {
		max_liquid = v;
	}
}

void set_current_liquid(int v)
{
	if( v < 0 ) error("Can't have nagative amout of liquid.\n");
	if( v > max_liquid ) {
	    current_liquid = max_liquid;
	}
	else {
		current_liquid = v;
	}
}

void add_current_liquid(int v)  { set_current_liquid(current_liquid+v); }

string extra_long()
{
	int amount, max;
	string str;

	if( (amount = query_current_liquid()) >= 0 ) {
		max = query_max_liquid();
		if( amount == max )
			str = "看上去装得满满的。  \n";
		else if( amount > max/3*2 )
			str = "七八分满的样子。  \n";
		else if( amount > max/3 )
			str = "五六分满的样子。  \n";
		else if( amount > 0  )
			str = "几乎已经空了。  \n";
		else if( amount == 0 )
		    str = "看上去空空如也。  \n";
		return str;
	}
	else return 0;
}

int do_pour(string arg)
{
	// bottle1 is this current container, 
	// bottle2 is the destination container.
	string arg1, arg2, liquid_name;
	object me = this_player();
	object obj = this_object();
	object bottle1, bottle2, *inv, liquid;
	int i, liquid_found;

	if( !living(this_player()) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");

	if( !(arg))
	     return  notify_fail("命令格式：pour <容器> into <容器>\n");

	// syntex is pour bottle1 into bottle2
    if( sscanf(arg, "%s into %s", arg1, arg2)!= 2 ) 
	     return  notify_fail("命令格式：pour <容器> into <容器>\n");

	// player has to have the bottle in his inventory to pour.
	// so they can't pour something that's on the ground
	if( !(bottle1 = present(arg1, me)) )
	     return  notify_fail("你身上没有这样东西。\n");

	// check if the destination container is in player's inventory or on the ground
	if( !(bottle2 = present(arg2, me)) ){
	  if(  !(bottle2 = present(arg2, environment(me))) ) 
	     return  notify_fail("找不到那样东西。 \n");
    }
	// check I am pouring the same bottle as the action, 
	// don't know if the check is needed, leave it out for now
//	if (bottle1 != obj)
//	     return  notify_fail("can find that bottle \n");

	// if it's a liquid container
	// only when it's a liquid container you are allow to pour
	if( query("liquid/container") ){

    	inv = all_inventory(bottle1);
		liquid_found = 0;

		// you should only find at most 1 liquid inside the bottle
		// and nothing else
		// but if you do find any other kind, should destory it
     	for( i=0; i<sizeof(inv); i++ )
     	{
			// double check if it's liquid inside 
			// also check if this is the first kinda of liquid found
			if (inv[i]->query("liquid/status") && liquid_found == 0 ) {
				liquid_found = 1;
				liquid = inv[i];
			}
			else 
			   destruct(inv[i]);
		}
		// if no liquid
		if (!(liquid_found))
        	return  notify_fail("那里是空的，倒什么？\n");

		// now check the destination bottle
		if ( bottle2->query("liquid/container") ) {

			 if (bottle1 == bottle2)
				 return  notify_fail("倒回原处，莫非你有病？\n");

			 liquid_name = liquid->name();
			 // move liquid to the destination bottle
			 if (liquid->move_liquid(bottle2)) {
				 // if move liquid sucess, need to update bottle1's status
				 if(!liquid)
					 bottle1->set_current_liquid(0);
                 else {
				     if (present(liquid, bottle1)) 
				         bottle1->set_current_liquid(liquid->query_amount());
				     else
				         bottle1->set_current_liquid(0);
				 }
                 message_vision("$N将"+liquid_name+"小心翼翼的倒入"+bottle2->name()+"内。\n"NOR, me );
			 } 
		}
    	else 
	         return  notify_fail("你不能往那里倒。\n");
		
	}
	else 
	   return  notify_fail("这样东西不能倒。\n");


	return 1;
}

int do_fill(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !environment(this_player())->query("resource/water") )
		return notify_fail("这里没有地方可以装水。\n");
	return 1;
}

int do_empty(string arg)
{
	object *inv, bottle;
	object me = this_player();
	int i;

	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");

	if( !(bottle = present(arg, me)) )
	     return  notify_fail("你身上没有这样东西。\n");

   	inv = all_inventory(bottle);
    for( i=0; i<sizeof(inv); i++ )
    {
			   destruct(inv[i]);
	}
	bottle->set_current_liquid(0);
    message_vision("$N将$n倒的一干二净。\n"NOR, this_player(), this_object());
	return 1;
}
