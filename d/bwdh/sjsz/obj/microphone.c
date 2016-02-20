//Cracked by Roath
// Microphone to broadcast in sjsz
// Apache 10/98

inherit ITEM;

void create() {
    set_name("话筒", ({ "huatong" }));
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "用这个话筒可以宣布(announce)一些通知给试剑山庄的人。\n");
        set("material", "steel");
        set("weight", 5000);
        set("value", 10000000);
        set("no_get", 1);
    }
    setup();
}

int init() {
    add_action("do_announce", "announce");
}

int do_announce(string arg) {
    object me = this_player();
    string msg;

    if(!wizardp(me))
        return 0;
    if(!arg)
        return notify_fail("你想宣布什么？\n");

    msg = "一个空洞的声音传了过来：“" + arg + "”。\n";

    tell_room("/d/bwdh/sjsz/square", msg);
    tell_room("/d/bwdh/sjsz/gamble_room", msg);
    tell_room("/d/bwdh/sjsz/kantai_s", msg);
    tell_room("/d/bwdh/sjsz/kantai_n", msg);
    tell_room("/d/bwdh/sjsz/kantai_e1", msg);
    tell_room("/d/bwdh/sjsz/kantai_e2", msg);
    tell_room("/d/bwdh/sjsz/kantai_e3", msg);
    tell_room("/d/bwdh/sjsz/kantai_e4", msg);
    tell_room("/d/bwdh/sjsz/kantai_e5", msg);
    tell_room("/d/bwdh/sjsz/kantai_w1", msg);
    tell_room("/d/bwdh/sjsz/kantai_w2", msg);
    tell_room("/d/bwdh/sjsz/kantai_w3", msg);
    tell_room("/d/bwdh/sjsz/kantai_w4", msg);
    tell_room("/d/bwdh/sjsz/kantai_w5", msg);
    tell_room("/d/bwdh/sjsz/east_xiangfang", msg);
    tell_room("/d/bwdh/sjsz/west_xiangfang", msg);

    return 1;
}



