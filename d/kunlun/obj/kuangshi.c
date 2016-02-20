//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"乌金矿石"NOR, ({ "wujin kuangshi", "kuangshi" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块黑黝黝的乌金矿石，是炼制兵器的好材料。\n");
                set("unit", "块");
//				set("no_drop",1);

        }

}
