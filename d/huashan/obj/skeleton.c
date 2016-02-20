//Cracked by Roath
// skeleton.c 骷髅骨

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("骷髅骨", ({"skeleton", "kulou", "gu"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("long",
			"骷髅骨身上衣服已烂了七八成，宛然尚可见到是个人形。\n");
                set("material", "steel");
		set("value", 100);
        }
}
