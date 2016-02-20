//Cracked by Roath
inherit ITEM;
inherit F_LIQUID;

int check_value();

void create()
{
    set_name("大茶碗", ({"cha", "tea"}));
    set_weight(500);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "这是一个装大碗茶的磁碗，已经有些发黄了。\n");
	set("unit", "个");
	set("max_liquid", 3);
	set("value", 100);
	set("liquid", ([
		"type" : "tea",
		"name" : "大碗茶水",
		"remaining" : 3,
		"drunk_supply" : 5,
	]));
    }
}
