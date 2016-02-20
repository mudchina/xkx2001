//Cracked by Roath
// yezike  椰子壳
// ssy

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("椰子壳", ({"yezi ke", "yezi", "ke"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个大椰子壳，可以用来装水。\n");
                set("unit", "个");
                set("value", 200);
                set("max_liquid", 10);
        }

        set("liquid", ([
			"type": "tea",
			"name": "椰子汁",
			"remaining": 10,
			"drunk_apply": 0,
        ]));
}
