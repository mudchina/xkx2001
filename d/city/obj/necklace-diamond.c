//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name(HIW"钻石项链"NOR, ({ "diamond necklace", "necklace", "lace" }));
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一串以钻石为主体的项链，坠子雕琢成水滴形，周围镶著一圈碎钻，能随著走路的摇曳轻摆，化出炫目的光芒。\n");
                set("unit", "串");
                set("value", 28000);
                set("material", "diamond");
                set("armor_prop/armor", 7);
        }
        setup();
}       
