//Cracked by Roath
// fengguan.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "凤冠" , ({ "feng guan", "headress", "fengguan", "guan" }) );
        set_color("$HIY$");
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("long", "这是一个凤冠，金珠琉璃，银翅乱颤，是新娘的头冠。\n");
                set("value", 10000);
                set("material", "cloth");
       		set("wear_msg", HIY "$N含泪穿戴上凤冠，惑说道：我嫁的人是谁，他能爱我一生一世吗？\n" NOR);
		set("unequip_msg", HIY "$N轻轻地摘下凤冠。\n" NOR);
                set("armor_prop/armor", 4);
		set("female_only", 1);
        }
        setup();
}
