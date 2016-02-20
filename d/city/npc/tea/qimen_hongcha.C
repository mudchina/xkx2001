//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("祁门红茶", ({ "qimen hongcha","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"这是一杯祁门红茶，汤色红艳明亮滋味浓郁，其香气酷似果香，又带兰花香。\n");
                set("unit", "杯");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "祁门红茶",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

