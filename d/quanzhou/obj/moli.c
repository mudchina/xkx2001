//Cracked by Roath
// 茉莉花茶

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("茉莉花茶杯", ({"moli chabei", "bei", "cup"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个普通的茶杯。\n");
                set("unit", "个");
                set("value", 30);
		set("max_liquid", 4);
		set("worthless", 1);
		set("liquid", ([
        		"type": "tea",
			"name": "茉莉花茶",
			"remaining": 4,
			"drunk_supply": 0,
    		]));
        }
}
