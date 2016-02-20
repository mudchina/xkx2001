//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("都匀细毛尖", ({ "dujun ximaojian","maojian","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯都匀细毛尖，茶芽沉于杯底，白毫浮游水中，汤色嫩绿明亮，品清香馥郁，醇厚回甜。\n");
                set("unit", "杯");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "都匀细毛尖",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

