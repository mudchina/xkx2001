//Cracked by Roath
#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY"金沙"NOR, ({"jin sha", "jinsha", "gold nugget"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "jinsha");
                set("long", "这是一粒亮闪闪的金沙。\n");
                set("unit", "粒");
                set("base_value", 1500+random(10));
                set("base_unit", "粒");
                set("base_weight", 20);
        }
        set_amount(1);
}

