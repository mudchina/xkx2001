//Cracked by Roath
// combined_item.c
 //Last modified by wzfeng, 07/2000

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

static int amount;

void setup()
{
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

string short()
{
        return chinese_number(query_amount()) + query("base_unit")
                + ::short();
}

varargs int move(mixed dest, int silent)
{
        object env, *inv;
        int i, total;
        string file;

// we want combined item can always be transfered without checking
// overweight. The correct weight will be reset by set_amount later;
  
		//wzfeng have remove it.becasue if set it =0 ,u can arbitrari put anything in a bag. 
		//this_object()->set_weight(0);
        if( ::move(dest, silent) ) {
			//I douno why add living .if add it, when u put something in bag, will jump over
			//so I'm remove it				wzfeng 2000 7/////////////////////////////////
/*                if( living(env = environment()) 
                   && !this_object()->query("embedded")) 
				   */
                if( (env = environment()) 
                   && !this_object()->query("embedded")) 
				{
                        file = base_name(this_object());
                        inv = all_inventory(env);
                        total = (int)query_amount();
                        for(i=0; i<sizeof(inv); i++) {
                                if( inv[i]==this_object() ) continue;
                                if( base_name(inv[i])==file && !inv[i]->query("embedded")) {
                                        total += (int)inv[i]->query_amount();
                                        destruct(inv[i]);
                                }
                        }
                        set_amount(total);
                }
                return 1;
        }
}
