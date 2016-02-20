//Cracked by Roath
// pine_bole.c 红松树干 
// By Marz@XKX 11/11/96

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"红松树干"NOR,({ "bole", "pine bole" }));
	set_weight(70000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一根红松树干，是制造香火的好材料。\n");
		set("unit", "根");
		set("value", 100);
		set("material", "wood");
		set("self_destruct", 1);
    	}
	
	setup();
}


int value()
{
	return 1;
}

// End of File
