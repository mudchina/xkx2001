//Cracked by Roath
// incense.c 香火
// xbc 97/02/03

inherit ITEM;

void create()
{
        set_name("香火",({"incense"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一枝香火，还带着松枝的香气。\n");
                set("unit", "枝");
                set("value", 0);
        }
        setup();
}

