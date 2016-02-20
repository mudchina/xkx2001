//Cracked by Roath
// huaduai.c 花雕酒

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(YEL"酒瓶"NOR, ({"huadiao", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
一个用来装花雕酒的酒瓶。黄酒中的上品半干类，酒质厚浓，风味优良，可长久
贮藏。
LONG
        );
		set("unit", "个");
		set("value", 130);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "花雕酒",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}
