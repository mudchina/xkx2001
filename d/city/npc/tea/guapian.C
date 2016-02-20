//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("六安瓜片", ({ "guapian","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯六安瓜片，茶汁色泽翠绿、香气清高、滋味鲜甘。\n");
                set("unit", "杯");
                set("value", 25);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "六安瓜片",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

