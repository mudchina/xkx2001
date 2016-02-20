//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"药材"NOR, ({"yaocai"}));
	set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "一包含多种药物的药材，计有老山参、雪莲子、鹿茸、田七、丹砂等等。\n");
                set("value", 10000);
		set("medicine", 1);
        }
        setup();
}
