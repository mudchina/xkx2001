//Cracked by Roath
// visitcard.c 拜帖
inherit ITEM;

void create()
{
        set_name("拜帖", ({"bai tie", "tie"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"这是张普通的拜帖。\n");
                set("material", "paper");
        }
}