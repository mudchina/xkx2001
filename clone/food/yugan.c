//Cracked by Roath
//咸鱼干

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("咸鱼干", ({"yu gan", "yu", "fish"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一大块腌制好的咸鱼干\n");
                set("unit", "块");
                set("value", 100);
                set("food_remaining", 6);
                set("food_supply", 50);
        }
}

