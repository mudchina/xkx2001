//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("颂词", ({ "songci" }));
        set("weight", 1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
"这是一篇假造的颂词。\n"
"瞎扯大唐贞观年间卫国公李靖料定千年后神龙教教主洪某，得蒙天恩。\n");
                set("unit", "幅");
                set("value", 20);
        }
        setup();
}
