//Cracked by Roath
// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name(HIG"Ò°²ËÌÀÍë"NOR, ({"soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÍëĞÂÏÊÒ°²Ë×öµÄÌÀ¡£\n");
                set("unit", "Íë");
                set("value", 0);
        set("max_liquid", 4);
    }


    set("liquid", ([
        "type": "water",
        "name": "Ò°²ËÌÀ",
        "remaining": 6,
        "drunk_supply": 15,
    ]));
}
