//Cracked by Roath
// paomo.c —Ú»‚≈›‚… 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("—Ú»‚≈›‚…", ({"yangrou paomo", "yangrou", "paomo"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "“ªÕÎœ„≈Á≈Áµƒ—Ú»‚≈›‚…°£\n");
                set("unit", "ÕÎ");
                set("value", 70);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}
