//Cracked by Roath
#include <ansi.h>
inherit ITEM;

int do_climb(string arg);

void create()
{
        set_name("白杨树", ({ "baiyang shu", "tree" }) );
        set("long", "一棵笔直的白杨树，树顶枝叶茂盛．\n");
        set_weight(999999999);
        set_max_encumbrance(999999999);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("material", "wood");
                set("value", 0);
        }

        set("no_get", 1);
        set("no_steal", 1);
        // set("env/invisibility", 100);
        enable_commands();

        setup();
}

void debug(string msg)
{
    printf("debug: %s", msg);
}

void receive_message(string msgclass, string msg)
{
    object *inv, player;
    int i;

    inv = all_inventory(this_object());
    if (inv) {
        for (i=0; i<sizeof(inv); i++) {
	    player = inv[i];
            tell_object(player, msg);
	}
    }
}

void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    object me = this_object();
    object player = this_player();
    object *inv;

    if (!arg || arg == "") return 0;
    if (arg == "down") {
	if (environment(player) == me) {
 	    message_vision("$N往树下跳去．\n", player);
	    player->move(environment(me));
 	    message_vision("$N树上跳了下来．\n", player);
	    return 1;
	}
    }
    if (present(arg, environment(me)) != me) return 0;
    
    message_vision("$N提气纵身，往"+me->query("name")+ "上跃去．\n", 	
		player);
    inv = all_inventory(me);
    if (sizeof(inv) > 1) {
	return notify_fail(player->query("name")+
	    "刚离地不到一尺，便被树叉上的人一掌推了下来．\n");
    }
    player->move(me);
    message_vision("$N从树下跳了上来．\n", player);
    return 1;
}
