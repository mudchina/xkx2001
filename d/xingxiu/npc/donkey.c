//Cracked by Roath
inherit NPC_TRAINEE;

void create()
{
    set_name("小毛驴", ({"donkey", "maolu", "lu"}));
    set("race", "家畜");
    set("age", 10);
    set("auto_follow",1);
    set("attitude", "peaceful");

    set("wildness", 1);

    set("str", 30);
    set("con", 40);
    set("dex", 40);
    set("int", 20);
    set("combat_exp", 1000);

    set_weight(15000);
    set("unit", "匹");
    set("long", "一匹黑色的小毛驴，可以骑，也可以驮东西。\n");
    setup();
}

void init()
{
    ::init();
    add_action("do_ride", "ride");
    add_action("do_unride", "unride");
}

int do_ride(string arg)
{
    object me, ob;
    me = this_object();
    ob = this_player();

    if (!id(arg))
        return notify_fail("你要骑什么？\n");
    if( me->query_lord() == ob )  {
        if( !ob->query_temp("riding") ) {
            if( !me->query_temp("rider") )  {
                ob->set_temp("riding", me->name());
                me->set_temp("rider",  ob->name());
                me->set_leader(ob);

                message("vision",this_player()->name() + "翻身上驴。毛驴一撩蹄子，"
                       "差一点把"+this_player()->name() + "掀下驴背。\n",
                        environment(me), ({me}) );
                write("你翻身骑上毛驴，它一撩蹄子，把你吓出一身冷汗。\n");
                return 1;
            }
            else return notify_fail( me->query_temp("rider") + "已经骑在它身上上了！\n");
        }
        else return notify_fail("你已经骑在" + ob->query_temp("riding") + "上了！\n");
    }
    else return notify_fail("你不是它的主人！\n");

    return 0;
}

int do_unride()
{
        object me, ob;
        me = this_object();
        ob = this_player();
        if( ob->query_temp("riding") == me->name() && me->query_temp("rider") == ob->name() ) 
        {
                ob->delete_temp("riding");
                me->delete_temp("rider" );
                message_vision("\n$N一纵身，从" + me->name() +"身上跃了下来。\n", ob);
                return 1;
        }
        else return notify_fail("你还没骑它呢！\n");

        return 0;
}
