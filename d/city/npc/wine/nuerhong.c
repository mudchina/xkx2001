//Cracked by Roath
// nuerhong.c  女儿红 

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"酒瓶"NOR, ({"nuerhong", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
一个用来装女儿红的酒瓶。绍兴人家生了女儿，大多会酿上几坛好酒埋在地下，等
到女儿出嫁那天才起出，所以酒味醇厚。据说后劲也特别大。
LONG
        );
		set("unit", "个");
		set("value", 160);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "女儿红",
		"remaining": 20,
		"drunk_apply": 8,
	]));
}
