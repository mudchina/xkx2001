//Cracked by Roath
// huamao
// maco 2/18/2000

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("玛尔江花帽", ({ "maerjiang huamao", "mao", "cap" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是维吾尔小女孩和姑娘们最为喜爱的一种花帽，帽上用各色小珍珠、亮片镶缀着各种各样的花样图案。\n");
		set("unit", "顶");
		set("value", 400);
		set("material", "cloth");
		set("armor_prop/armor", 4);
		set("armor_prop/personality", 5);
		set("wear_msg", "$N戴上一顶玛尔江花帽，帽上小珠子光彩夺目，犹如带着晶莹露珠盛开的鲜花。\n");
		set("female_only", 1);
	}
	setup();
}
