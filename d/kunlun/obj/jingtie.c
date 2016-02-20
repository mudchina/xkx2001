//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"精铁"NOR, ({ "jing tie", "tie" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块用乌金矿石打炼出来的精铁，是制造兵器的好材料。\n");
                set("unit", "块");
//		set("no_drop",1);

        }

}
