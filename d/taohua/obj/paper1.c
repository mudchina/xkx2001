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
"乞丐何曾有二妻？邻家焉得许多鸡？当时尚有周天子，何事纷纷说魏齐。\n");
                set("material", "paper");
        }
}

