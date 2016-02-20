//Cracked by Roath
// lingpai
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("令牌", ({ "ling pai", "ling", "pai" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块明门正派声讨邪教的令牌。\n"NOR);
                set("material", "stone");
        }
        setup();
}

