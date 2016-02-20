// ping.c 蜂浆瓶

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("蜂浆瓶", ({ "fengjiang ping", "ping" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "个");
        set("value", 0);
        set("material", "玉");
        set("long", "这是一个用上古美玉雕成的小瓶，还未拔开瓶塞，就可以闻到\n"
                    "一股浓郁的香味，可以用来驱蜂。\n") ;
	set("max_liquid", 20);
        }
        setup();
}


