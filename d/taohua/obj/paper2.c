//Cracked by Roath
// paper.c
inherit ITEM;

void create()
{
        set_name("信笺", ({"letter paper", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"天长地久，人生几时？先后无觉，从尔有期。\n");
                set("material", "paper");
        }
}

