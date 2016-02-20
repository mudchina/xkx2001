//Cracked by Roath
// weapon: 「绿波香露刀」 (Xianglu dao)
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("磁石", ({ "cishi", "magnet", "shi" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块不起眼的石头，似乎可以吸起微细的金属物事。\n"NOR);
                set("material", "stone");
        }
        setup();
}

