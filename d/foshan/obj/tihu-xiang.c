//Cracked by Roath
//tihu-xiang.c 醍醐香
//白花，花香醉人，闻得稍久，便和饮了烈酒一般
//by Apache

#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIW "醍醐香" NOR, ({ "tihu xiang", "xiang" }) );
    set("weight", 10);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "一朵小白花，花香浓郁。\n");
        set("unit", "朵");
        set("material", "wood");
    }
    setup();
}

void init() {
    add_action("do_smell", "smell");
}

int do_smell(string arg) {
    object me = this_player();

    if(!id(arg))
        return notify_fail("你要闻什么？\n");

    me->apply_condition("drunk", (int)me->query_condition("drunk") + random(20));

    message_vision(HIG "$N闻了闻醍醐香，一股浓郁的香气直冲头顶。\n" NOR, me);

    return 1;
}