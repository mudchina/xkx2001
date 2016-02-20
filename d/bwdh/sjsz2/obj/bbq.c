//Cracked by Roath
// BBQ 
// Copy from /u/kane/obj/toast

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("烤肉", ({ "bbq" }) );
    set_weight(200);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "一块烤得金黄金黄的烤肉，光闻一闻就要流口水了。\n");
        set("unit", "块");
        set("value", 0);
        set("food_remaining", 2);
        set("food_supply", 50);
    }
    setup();
}
