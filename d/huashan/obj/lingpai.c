//Cracked by Roath
// lingpai.c 邪派弟子令牌
inherit ITEM;
static int amount;

void set_amount(int v)
{
        if( v < 0 ) error("combine:set_amount less than 1.\n");
        if( v==0 ) call_out("destruct_me", 1);
        else {
                amount = v;
                this_object()->set_weight(v * (int)query("base_weight"));
//              this_object()->set_max_encumbrance(v * 1000);
//              this_object()->set("armor_prop/armor", v * (int)query("base_armor"));
        }
}

int query_amount() { return amount; }

private void destruct_me() { destruct(this_object()); }

void add_amount(int v) { set_amount(amount+v); }

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

        if( ::move(dest, silent) ) {
                if( living(env = environment()) ) {
                        file = base_name(this_object());
                        inv = all_inventory(env);
                        total = (int)query_amount();
                        for(i=0; i<sizeof(inv); i++) {
                                if( inv[i]==this_object() ) continue;
                                if( base_name(inv[i])==file &&
				inv[i]->query_temp("owner")==this_object()->query_temp("owner")) {
                                        total += (int)inv[i]->query_amount();
                                        destruct(inv[i]);
                                }
                        }
                        set_amount(total);
                }
                return 1;
        }
}

void create()
{
        set_name("青铜令牌", ({"ling pai", "ling", "pai"}));
	set_amount(1);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("base_unit", "面");
                set("base_weight", 50);
                set("long",
"青铜铸的令牌一边刻着虎头，另一边刻着狼头，生动栩栩，狰狞可怕。\n");
                set("material", "iron");
        }
}
/*
void init()
{
	object ling=this_object(), me=this_player();

	if ( !ling->query_temp("owner") && environment(ling)->query("id")!="mengmian ren") {
		ling->set_temp("owner", me->query("id"));
	}
}
*/
