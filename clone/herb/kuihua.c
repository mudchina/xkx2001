//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"葵花粉"NOR, ({"kuihua fen","fen"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","这是一钱葵花粉。\n");
                set("value", 100);
                        set("yaocai", 1);
                        set("cure_s",0);
                        set("cure_d",-40);
                        set("cure_n",40);
                
        }
        setup();
}
