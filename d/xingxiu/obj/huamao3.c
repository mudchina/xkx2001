//Cracked by Roath
// huamao
// maco 2/18/2000

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("曲曼花帽", ({ "quman huamao", "mao", "cap" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是维吾尔族中常见的花帽，形状下圆上方，黑金丝绒帽沿，绿底白花，素净淡雅。\n");
		set("unit", "顶");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 2);
	}
	setup();
}
