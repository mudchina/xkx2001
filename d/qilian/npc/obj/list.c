//Cracked by Roath
// paper.c
inherit ITEM;

void create()
{
        set_name("日月神教要犯名单", ({"rysj list", "list"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "paper");
        }
}

