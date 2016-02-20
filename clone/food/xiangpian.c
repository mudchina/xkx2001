//Cracked by Roath
// ÏãÆ¬

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("ÏãÆ¬²è±­", ({"xiangpian chabei", "bei", "cup"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¸öÆÕÍ¨µÄ²è±­¡£\n");
                set("unit", "¸ö");
                set("value", 30);
		set("max_liquid", 4);
		set("worthless", 1);
		set("liquid", ([
        		"type": "tea",
			"name": "ÏãÆ¬",
			"remaining": 4,
			"drunk_supply": 0,
    		]));
        }
}
