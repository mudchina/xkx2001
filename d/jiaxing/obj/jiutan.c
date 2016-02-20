//Cracked by Roath
// 

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("酒坛", ({"jiutan", "tan"}));
	set_weight(70000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的大酒坛。\n");
		set("unit", "个");
		set("value", 50);
		set("max_liquid", 50);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "米酒",
		"remaining": 50,
		"drunk_apply": 3,
	]));
}
