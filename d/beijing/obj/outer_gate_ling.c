//Cracked by Roath
// /d/beijing/obj/outer_gate_ling.c
// chu: the lingpai that allows npc/player to enter beijing with weapon

#include <ansi.h>

inherit ITEM;

int do_allow(string);

void init()
{
    if (!wizardp(this_player())) {
        set("no_get", "算了吧，检个令牌丢条命，何苦呢？\n");
	set("no_drop", "想把令牌给扔了？你不要命了？\n");
    }
    add_action("do_allow", "allow");
}

void create()
{
    set_name("城防令牌", ({"lingpai"}));
    set_weight(600);
    if (clonep())
	set_default_object(__FILE__);
    else{
        set("unit", "只");
        set("long", "这是兵部的城防令牌，用它可以特准 (allow) 百姓携铁具入城\n");
        set("value", 0);
        set("material", "bamboo");
    }
    setup();
}

int do_allow(string name)
{
    object ling=this_object(), me=this_player(), obj;

    if (!name || name=="") {
	return notify_fail("你想让谁进门？\n");
    }
    
    if(!objectp(obj = present(name, environment(me))))
         return notify_fail("这里没有这个人。\n");

    if (!obj->is_character() || obj->is_corpse())
         return notify_fail("看清楚点，这不是活人。\n");

    message_vision("$N对着$n大大咧咧地说道："
	"今天官爷心情好，就破例让你进城吧。\n",	me, obj);
    obj->set_temp("outer_gate_allowed", 1);
    return 1;
}