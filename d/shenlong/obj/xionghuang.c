//Cracked by Roath
// xionghuang.c 雄黄
// ywz 08/31/96

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL "雄黄" NOR, ({"xionghuang", "huang"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "块");
		set("long", "这是一块雄黄，看上去黄澄澄的。\n");
		set("value", 500);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
		return notify_fail("你要吃什么？\n");

	return notify_fail("这东西不能这么吃。\n");

//	destruct(this_object());
        return 1;
}
