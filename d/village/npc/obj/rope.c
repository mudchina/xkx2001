//Cracked by Roath
// paper.c
inherit ITEM;

void create()
{
        set_name("绳子", ({"sheng zi", "sheng", "rope" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "捆");
                set("long", "一捆有几十丈长的绳索。\n");
                set("material", "cloth");
		set("value", 200);
        }
}

