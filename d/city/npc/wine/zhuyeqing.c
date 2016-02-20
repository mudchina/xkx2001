//Cracked by Roath
// zhuyeqing.c 竹叶青

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("酒瓶", ({"zhuye qing", "zhuye", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
一个用来装竹叶青的酒瓶。此酒据说源于 “杏花村”，酒色青绿，晶莹透明。
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
		"name": "竹叶清",
		"remaining": 20,
		"drunk_apply": 8,
	]));
}
