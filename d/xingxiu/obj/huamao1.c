//Cracked by Roath
// huamao
// maco 2/18/2000

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("朵巴花帽", ({ "duoba huamao", "mao", "cap" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顶黑底白花的花帽，维吾尔族中年以上的男子常戴这种花帽，古朴大方，庄重典雅。\n");
		set("unit", "顶");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/personality", 3);
	}
	setup();
}
