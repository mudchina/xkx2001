//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("甲骨文", ({ "jiaguwen" }));
        set("weight", 1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
"纸上一个个字都如蝌蚪一般。\n"
"这是从五台山锦绣峰普济寺中石碣上拓下来的甲骨文\n");
                set("unit", "幅");
                set("value", 20);
        }

        setup();
}


					  
