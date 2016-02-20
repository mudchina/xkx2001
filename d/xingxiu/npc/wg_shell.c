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
        set_name("蜈蚣壳", ({"wugong ke", "ke", "shell"}));
        set("unit", "只");
        set("long", "这是一只蜈蚣的干壳，是制备毒药的原料。\n");
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

