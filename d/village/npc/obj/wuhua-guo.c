//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name("无花果", ({"wuhua guo","guo"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "个");
                set("long","这是一个无花果。\n");
                set("value", 100);
                        set("yaocai", 1);
                        set("cure_s",0);
                        set("cure_d",-40);
                        set("cure_n",40);
                
        }
        setup();
}
