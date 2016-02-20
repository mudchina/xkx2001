//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("铁观音", ({ "tie guanyin","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯铁观音，汤色金黄香气清冽，滋味浓郁；入口初感微苦，回味甜醇。\n");
                set("unit", "杯");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "铁观音",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

