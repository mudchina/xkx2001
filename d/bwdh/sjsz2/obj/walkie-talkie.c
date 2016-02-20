//Cracked by Roath
// walkie-talkie
// Apache 09/27/98

#include <ansi.h>

inherit ITEM;

void create() {
    set_name("对讲机", ({ "walkie-talkie","phone" }) );
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "部");
        set("long", "这是一部无线对讲机，可以多人同时通话。\n");
        set("material", "steel");
        set("value", 10000);
    }
    if( !wizardp(this_player()) ) {
        set("no_get", 1);
        set("no_drop", 1);
    }
    setup();
}

void init() {
    object ob = this_object();

    if ( !ob->query("channel") ) {
        ob->set("channel", 0);
    }

    add_action("do_set", "init"); // For wizard only
    add_action("do_talk", "talk");
    add_action("do_turn", "turn");
}

// Wizards:
// this function is not required for bwdh. Channel will be set
// in east/west 厢房. Channel 1 for east, channel 2 for west.
// "init #(1,2,3,4)" to set this walkie-talkie to channel 1,2,3,4
int do_set(string arg) {
    object ob = this_object();
    string str;

    if ( !wizardp(this_player()) ) return 0;
    if ( sscanf(arg, "%s", str) != 1) return 0;

    switch (str) {
        case "1" : ob->set("channel", 1);
                   write("你将对讲机设置在频道 1。\n");
                   break;
        case "2" : ob->set("channel", 2);
                   write("你将对讲机设置在频道 2。\n");
                   break;
        case "3" : ob->set("channel", 3);
                   write("你将对讲机设置在频道 3。\n");
                   break;
        case "4" : ob->set("channel", 4);
                   write("你将对讲机设置在频道 4。\n");
                   break;
        default : return notify_fail("只有四个频道(1,2,3,4)。\n");
    }
    return 1;
}

int do_turn(string arg) {
    object me = this_player();
    object ob = this_object();
    string str;

    if ( sscanf(arg, "%s walkie-talkie", str) != 1 && sscanf(arg, "%s", str) != 1 ) return 0;

    switch(str) {
        case "on"  : ob->set("owner", me->query("id"));
                     write("你打开了对讲机。\n");
                     return 1;
                     break;
        case "off" : ob->delete("owner");
                     write("你关上了对讲机。\n");
                     return 1;
                     break;
        default : return 0;
    }

    return 0;
}

int do_talk(string arg) {
    object me = this_player();
    object ob = this_object();
    object *player_list, *inv;
    int i, j;
    string msg;

    if ( !ob->query("owner") || ob->query("owner") != me->query("id") )
        return notify_fail("你还没有打开对讲机。\n");

    if ( !ob->query("channel") )
        return notify_fail("你需要设定一个频道。\n");

    if (!arg)
        return notify_fail("你要告诉你的同伴什么？\n");

    player_list = users();
    for (i = 0; i < sizeof(player_list); i++) {
        inv = all_inventory(player_list[i]);
        for (j = 0; j < sizeof(inv); j++) {
            if (inv[j]->query("id") == "walkie-talkie"
                && inv[j]->query("owner") == player_list[i]->query("id")
                && inv[j]->query("channel") == ob->query("channel") ) {
                switch(ob->query("channel")) {
                    case 1 : msg = "【对讲机《频道一》】";
                             break;
                    case 2 : msg = "【对讲机《频道二》】";
                             break;
                    case 3 : msg = "【对讲机《频道三》】";
                             break;
                    case 4 : msg = "【对讲机《频道四》】";
                             break;
                }
                msg = msg + me->query("name") + "(" + me->query("id") + ")：" + arg;
                tell_object(player_list[i], HIG"\n" + msg + "\n"NOR);
            }
        }
    }

    return 1;
}
