//Cracked by Roath
// fotiao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("·ğÌøÇ½", ({"fo tiao qiang", "fo"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "·ğÌøÇ½ÊÇÈªÖİÑÌÓêÂ¥µÄÃû²Ë¡£\n");
                set("unit", "Íë");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 100);
        }
}

