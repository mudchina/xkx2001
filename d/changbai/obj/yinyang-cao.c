//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIG"“ı—Ù≤›"NOR, ({"yinyang cao","cao"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "ø√");
                set("long","’‚ «“ªø√“ı—Ù≤›°£\n");
                set("value", 0);
                        set("yaocai", 1);
                        set("cure_s",0);
                        set("cure_d",-40);
                        set("cure_n",40);
                
        }
        setup();
}
