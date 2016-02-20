//Cracked by Roath
// Wan
// Apache 09/28/98

inherit ITEM;

void create() {
    set_name("大海碗",({ "wan"}) );
    set_weight(50);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "满满的一大碗烧酒，喝起来一定爽的很。\n");
        set("unit", "个");
        set("value", 0);
    }
    setup();
}

void init() {
    add_action("do_drink", "drink");
}

int do_drink(string arg) {
    object me = this_player();

    if( !this_object()->id(arg) ) return 0;

    if( (int)me->query("water") >= (int)me->max_water_capacity() )
        return notify_fail("你已经喝太多了。\n");

    me->add("water", 50);

    write("你一扬头，把一碗烧酒喝的干净，却感觉没什么味道。\n");
    write("你喃喃地骂道：“他奶奶的，这算什么？兑了多少水？！\n");
       
    destruct(this_object());

    return 1;
}
