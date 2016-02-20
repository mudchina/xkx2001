//Cracked by Roath
// food: /d/xingxiu/npc/obj/hamigua.c
// Jay 3/18/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¹şÃÜ¹Ï", ({"hamigua", "gua", "melon"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿ÅÏãÌğµÄ¹şÃÜ¹Ï¡£²»³Ô¹şÃÜ¹ÏµÈÓÚ°×À´Î÷Óò¡£\n");
                set("unit", "¿Å");
                set("value", 50);
                set("food_remaining", 1);
                set("food_supply", 50);
        }
}

