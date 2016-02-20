//Cracked by Roath
//  poison: shachongke.c
// Jay 3/17/96

// more work needed to use this object to make poison

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("毒蛛丝", ({"Du zhusi", "zhusi", "silk"}));
        set("unit", "团");
        set("long", "这是一团一只毒蜘蛛死後吐出的丝，是制备毒药的原料。\n");
        set("value", 200);
	set("medicine", 1);
//        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        return notify_fail("你找死啊。\n");
}

