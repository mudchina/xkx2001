//Cracked by Roath
// ÎÚÁú²è

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("²è±­", ({"cha bei", "bei", "cup"}));
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
			"name": "ÎÚÁú²è",
			"remaining": 4,
			"drunk_supply": 0,
    		]));
        }
}
