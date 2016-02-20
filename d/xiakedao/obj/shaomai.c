//Cracked by Roath
// shaomai.c ÉÕÂô

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ÉÕÂô", ({"shao mai", "dumpling"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»µúÁîÈË²ö×ìµÄÉÕÂô¡£\n");
                set("unit", "µú");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
