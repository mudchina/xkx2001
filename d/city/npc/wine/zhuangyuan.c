//Cracked by Roath
// zhuangyuan.c 状元红

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"酒瓶"NOR, ({"zhuangyuan hong", "zhuangyuan", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
一个用来装状元红的酒瓶。据说此酒后劲颇大。
LONG
        );
		set("unit", "个");
		set("value", 170);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "状元红",
		"remaining": 20,
		"drunk_apply": 8,
	]));
}
