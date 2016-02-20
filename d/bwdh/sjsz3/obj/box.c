//Cracked by Roath
// box.c 铁盒

#include <ansi.h>
inherit ITEM;

void create() {
    set_name("铁箱", ({"box"}));
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "只");
        set("long", "此盒高约一尺见方，不知道里面装着什么东西。\n");
        set("material", "steel");
        set("value", 100);
        set("no_get", 1);
   }
}

void init() {
    object ob = this_object();

	 //if (!ob->query("flag"))
	 ob->set("flag", 0);
    add_action("do_open", "open");
}

int do_open(string arg) {
    object ob = this_object(), flag, npc, me=this_player();

    if ( !arg || arg != "box" )
        return notify_fail("你要将什么打开？\n");

    if ( me->query_skill("dodge") > 200 && me->query("jingli") > me->query("max_jingli")/2 ) {
        if (ob->query("flag") == 1) {
            message_vision("$N打开铁箱，发现箱中有一面旗帜。\n", me);
            message_vision(HIR"$N“哗啦”一下展开了武林大旗！\n"NOR, me);
            me->start_busy(7 + random(5));
            flag = new(__DIR__"flag");
            flag->move(me);
            ob->set("flag", 0);
            return 1;
        }
        else {
            message_vision("$N打开铁箱，发现里面是空的。\n", me);
            me->start_busy(7 + random(5));
            return 1;
        }
    }
    else {
        message_vision(HIR"$N打开铁箱，突然铁箱中射出三支硬努，全部射在了$N身上！\n"NOR, me);
        me->receive_wound("qi", me->query("max_qi")+ 1);
        return 1;
    }

        return notify_fail("你要打开什么？\n");
}
