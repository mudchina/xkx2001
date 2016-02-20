//Cracked by Roath
// longyanjiu.c 龙岩酒

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"酒瓶"NOR, ({"longyan jiu", "longyan", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
一个用来装龙岩酒的酒瓶。此酒不加糖而甜，不着色而颜红，不调香而芬芳。
酒质呈琥玻，甘甜醇后，风格独特。
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
		"name": "龙岩酒",
		"remaining": 20,
		"drunk_apply": 7,
	]));
}
