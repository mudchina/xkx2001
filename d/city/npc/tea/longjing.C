//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("西湖龙井", ({ "longjing","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯颜色明亮，滋味甘美的龙井，向有“黄金芽”和“无双品”之称。\n");
                set("unit", "杯");
                set("value", 25);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "西湖龙井",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

