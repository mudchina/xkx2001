//Cracked by Roath
// xiangxue.c 香雪酒

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(WHT"酒瓶"NOR, ({"xiangxue jiu", "xiangxue", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
一个用来装香雪酒的酒瓶。此酒又被称为“封缸酒”，酒质甘甜淳厚。
LONG
        );
		set("unit", "个");
		set("value", 300);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "香雪酒",
		"remaining": 20,
		"drunk_apply": 5,
	]));
}
