//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("君山银针", ({ "junshan yinzhen","yinzhen","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯君山银针，色泽鲜亮；香气高爽，汤色橙黄，滋味甘醇。\n");
                set("unit", "杯");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "君山银针",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

