//Cracked by Roath
// hammer.c

#include <weapon.h>

inherit HAMMER;

static int amount;

void set_amount(int v)
{
        if( v < 0 ) error("combine:set_amount less than 1.\n");
        if( v==0 ) call_out("destruct_me", 1);
        else {
                amount = v;
                this_object()->set_weight(v * (int)query("base_weight"));
                this_object()->set("weapon_prop/damage", v * (int)query("base_weapon"));
		this_object()->set("weapon_prop/dodge", v * (int)query("base_dodge"));
		this_object()->set("weapon_prop/speed", v * (int)query("base_speed"));
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
                                if( base_name(inv[i])==file ) {
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
        set_name("法轮", ({ "fa lun", "fa", "lun" }) );
//	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("base_unit", "只");
                set("base_weight", 6000);
		set("base_speed", -2);
		set("base_dodge", -2);
		set("long", "这是直径尺半的一个铁环，上面刻满了密宗伏魔真言，环内中空。\n");
		set("value", 1000);
		set("material", "iron");
		set("no_sell",1);
		set("rigidity", 100);
		set("base_weapon", 25);
		set("wield_msg", "$N拿出一副$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

        init_hammer(25);
	set_amount(1);
	setup();
}
