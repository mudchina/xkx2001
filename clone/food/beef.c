//Cracked by Roath
// /d/emei/npc/obj/niurou.c Å£Èâ
// Shan: 96/07/09

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Å£Èâ", ({"niu rou", "beef", "rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "Ò»¿é¿¾µÃÏãÅçÅçµÄÅ£Èâ¡£\n");
                set("unit", "¿é");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}

