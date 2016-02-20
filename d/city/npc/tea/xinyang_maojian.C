//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("信阳毛尖", ({ "xinyang maojian","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯信阳毛尖，茶芽叶细嫩有峰梢，精制后紧细有尖，并有白毫，茶香沁人如肺。\n");
                set("unit", "杯");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "信阳毛尖",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

