//Cracked by Roath
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("草帽", ({"caomao", "hat"}));
    set_weight(500);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "一顶农家常见的草帽。\n");
	set("unit", "顶");
	set("material", "cloth");
	set("armor_type", "head");
	set("armor_prop/armor", 1);
	set("value", 100);
    }
}
