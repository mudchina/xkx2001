//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("黄山毛峰", ({ "maofeng","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"只见茶汁清澈微黄雾气结顶，清香四溢。\n");
                set("unit", "杯");
                set("value", 25);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "黄山毛峰",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

