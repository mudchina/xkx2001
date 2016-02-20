//Cracked by Roath
// zi_shoes.c 双梁紫缎面鞋子 
 
#include <armor.h>
#include <ansi.h>

inherit BOOTS;
 
void create()
{
	set_name(MAG"紫缎面鞋子"NOR, ({ "shoes"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("long", "这是一双绣著「寿」字的双梁紫缎面鞋子。\n");
		set("value", 5000);
		set("armor_prop/dodge", 8);
	}
	setup();
}