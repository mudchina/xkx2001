//Cracked by Roath
inherit ITEM;
#include <ansi.h>
inherit F_EQUIP;
void create()
{
        set_name("铁链", ({ "tie lian"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一条明晃晃，沉甸甸的铁链。\n");
        	set("unit", "袋");
		set("base_unit", "支");
        	set("value", 150);
		set("armor_type", "shoulder");
                set("armor_prop/armor",1);
		set("armor_prop/attack", -400);
                set("armor_prop/defense", -400);
                set("armor_prop/unarmed", -400);
		set("no_sell", 1);
        }
        setup();
}
int wear() { return 0; }
int unequip() { return 0; }

int do_embed()
{
	::wear();
	set("no_drop", 1);
	set("no_get", 1);
	set("long", "一条沉甸甸的铁链，穿在"+environment()->query("name")+"两肩的琵琶骨上。\n");
	return 1;
}

string query_autoload()
{
        if( query("equipped") ) return query("name");
}
void autoload(string arg)
{
        set("name", arg);
	set("embedded", 1);
        set("no_drop", 1);
        set("no_get", 1);
        ::wear();
}
