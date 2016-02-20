//Cracked by Roath
// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/26/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name("小毛驴", ({"donkey", "maolu", "lu"}));
        set_weight(15000);
        set_max_encumbrance(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", "一匹黑色的小毛驴，可以骑，也可以驮东西。\n");
                set("value", 400);
        }
}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("你要骑什么？\n");
        if (this_player()->query_temp("marks/骑") ) {
                       write("你已经骑在马上了。还想再骑驴?!\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "翻身上驴。毛驴一撩蹄子，"
                       "又把"+this_player()->name() + "掀下驴背。\n",
                        environment(me), ({me}) );
               write("你想骑毛驴，可它不让你骑。\n");
        return 1;
        }
}
