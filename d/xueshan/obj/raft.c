//Cracked by Roath
// item: /d/qilian/obj/raft.c

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name("木筏", ({"raft", "mu fa"}));
        set_weight(35000);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个手工粗制的木筏，可以乘(ride)它过河。\n");
                set("value", 1000);
		set("no_get", "这样东西太沉了，你拿不动。\n");
        }
}

int do_ride(string arg)
{
	object  me = this_player();
        if (!id(arg))
                return notify_fail("你要乘什么？\n");

               message("vision",this_player()->name() + "跳上木筏。\n",
                        environment(me), ({me}) );
               write("你把木筏扔进水里，然後跳上去，慢慢地向前划。\n");
		me->move("/d/qilian/mufa");
		destruct(this_object());
        return 1;
}
