//Cracked by Roath

#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY"金元宝"NOR, ({"jin yuanbao", "yuanbao_money", "yuanbao"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "yuanbao");
                set("long", "一锭沉掂掂的金元宝。\n");
                set("unit", "些");
                set("base_value", 100000);
                set("base_unit", "锭");
                set("base_weight", 3000);
        }
        set_amount(1);
}

