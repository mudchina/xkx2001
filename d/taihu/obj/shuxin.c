//Cracked by Roath
// 
inherit ITEM;

void create()
{
        set_name("书信", ({"shu xin", "xin"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","这是归云庄少庄主陆冠英的引荐信。\n");
                set("material", "paper");
        }
}

