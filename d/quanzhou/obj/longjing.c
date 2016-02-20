//Cracked by Roath
// Áú¾®²è

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("Áú¾®²è±­", ({"longjing chabei", "bei", "cup"}));
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
			"name": "Áú¾®²è",
			"remaining": 4,
			"drunk_supply": 0,
    		]));
        }
}
