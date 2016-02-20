//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("骰子", ({"touzi", "dice"}));
        set_weight(400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","这是一颗灌了铅的骰子。\n");
                set("unit", "颗");
                set("value",1000);
        }
}

