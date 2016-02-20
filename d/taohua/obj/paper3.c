//Cracked by Roath
// paper.c
inherit ITEM;

void create()
{
        set_name("卷轴", ({"scroll"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "束");
                set("long",
"今有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二，问物几何？\n");
                set("material", "paper");
        }
}

//三人同行七十希，五树梅花二十一枝，七子团圆正半月，除百零五便得知。
