//Cracked by Roath
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"大木杆"NOR,({ "bole" }));
        set_weight(70000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一根大木干，木上装有铁钩。\n");
                set("unit", "根");
                set("value", 100);
                set("material", "wood");
                set("self_destruct", 1);
        }
        
        setup();
}

int value()
{
        return 1;
}
