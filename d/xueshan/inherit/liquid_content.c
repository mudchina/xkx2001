//Cracked by Roath
// liquid_content.c

#include <ansi.h>
#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

// some variable need to be set
// liquid/status set to 1 if it's a liquid type
// must inherit this

static int amount;
static string chinese_amount;

void setup()
{
    seteuid(getuid());
}

int query_amount() { return amount; }

private void destruct_me() { destruct(this_object()); }

void set_amount(int v)
{
	if( v < 0 ) error("combine:set_amount less than 1.\n");
	if( v==0 ) { ::move(VOID_OB); call_out("destruct_me", 1); }
	else {
		amount = v;
		this_object()->set_weight(v * (int)query("base_weight"));
	}
}

void add_amount(int v)  { set_amount(amount+v); }

// this is the conversion function 
// to convert the amount into chinese number and 
// scalers
string query_chinese_amount()
{

   //   合、升、斗、斛。is the base,
   // 10 合 = 1 升, 10 升 = 1 斗 
   // 10 斗 = 1 斛
   int base1, base2, base3, base4;
   string str1, str2, str3, str4;
   base1 = (int)(query_amount()/1000);
   base2 = (int)((query_amount() - base1*1000)/100);
   base3 = (int)((query_amount() - base1*1000 - base2*100)/10);
   base4 = (int)(query_amount() - base1*1000 - base2*100 - base3*10);


   str1 = base1 ? chinese_number(base1) + "斛" : "";
   str2 = base2 ? chinese_number(base2) + "斗" : "";
   str3 = base3 ? chinese_number(base3) + "升" : "";
   str4 = base4 ? chinese_number(base4) + "合" : "";

   return str1 + str2 + str3 + str4;


}

// we should not display the actual amout of liquid
// since you can not tell how much liquid exactly in a bottle
// by just looking at it.
// so query_chinese_amount() should be used in other forms.
string short()
{
	return query_chinese_amount() + ::short();
}

// this is the function that actually moves liquid
// don't know if we should use the F_MOVE feature to move
// becuase then you have to take weight into account
int move_it (object dest)
{
	if (!objectp(dest))
	   return 0;
	move_object(dest);
}

// this move_liquid function moves liuquid from
// one container to another
// call use: liquid_object->move_liquid(desination_container)
int move_liquid (object target)
{
	 object obj = this_object();
	 object *inv, liquid, obj2;
	 int liquid_found, remain, i, j, k;

     inv = all_inventory(target);
	 liquid_found = 0;

	 // check if this bottle can only take one kind of liquid
 	 if (target->query("liquid/unique"))
	    if ( obj->query("id") != target->query("liquid/uniqueid") )
			// you can't pour some liquid into this bottle
    		return notify_fail("你可不能把这东西倒入那儿。\n");

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
	 // if there are liquid inside, then check if it's the same liquid
	 if (liquid_found) {
		// if the same kind, move some amount into it
		if ( obj->query("id") == liquid->query("id") ) 
		{
			// how much can if be filled
			remain = target->query_max_liquid() - liquid->query_amount();
			if (remain < 1)
        		return notify_fail("已经满了，没法往里倒了。\n");
			// if more than it can be filled
			if( obj->query_amount() > remain) {
		  		obj->add_amount(-remain);
				liquid->set_amount(target->query_max_liquid());
				target->set_current_liquid(target->query_max_liquid());
				return 1;
			}
			else {
				liquid->add_amount(obj->query_amount());
				target->set_current_liquid(liquid->query_amount());
				destruct(obj);
				return 1;
 			}
		}
		// maybe later on we can mix two kinds of liquid here
		else
		    return notify_fail("这两样东西不能混。\n");
	 }
	 // no liquid found
	 {
			if (obj->query_amount() > target->query_max_liquid() )
			{
                  obj->add_amount( -(target->query_max_liquid()) );
                  obj2 = new(base_name(obj));
                  obj2->set_amount(target->query_max_liquid());
				  obj2->move_it(target);
				  target->set_current_liquid(target->query_max_liquid());
				  return 1;
			}
			else
			{
				  obj->move_it(target);
    			  target->set_current_liquid(obj->query_amount());
				  return 1;
			}
	 }
	 return 1;
}