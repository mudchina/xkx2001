//Cracked by Roath
// Kane 13/8/98

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("蛇毒", ({"she du", "du"}));
        set_weight(180);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "一瓶炼制好的蛇毒。\n");
                set("unit", "瓶");
                set("poison_type", "snake_poison");
		set("poison_applied", 100);
		set("value", 0);
//		set("no_get", 1);
        }
}

void init()
{
   add_action("do_coat", "coat");
   add_action("do_coat", "tu");
}

int do_coat(string arg)
{
        object me, ob, obj;
        function f;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要干什么？\n");

        if ( ob->query("weapon_type") != "arrow" )
                return notify_fail("蛇毒可不能瞎涂。\n");

        if ( ob->query("poison_applied") > 0)
                return notify_fail("这样东西上已经喂有毒药了。\n");

/*
        if (this_player()->query_skill("poison", 1) < 100)
                return notify_fail("你还没有掌握在武器上喂毒的技能。\n");
*/

	me = this_player();
	obj = this_object();
        message_vision(RED"$N小心翼翼地把"+ob->query("name")+"在$n中搅了一会儿。\n"NOR, me, obj);
        
	if( me->query_skill("poison",1) < random(100) ) {
		message_vision(HIR"$N一不小心溅了一些$n在手上！\n"NOR,me,obj);
		me->apply_condition(obj->query("poison_type"),
		obj->query("poison_applied")/2);
	}

	ob->set("poison_applied", obj->query("poison_applied"));
        ob->set("poison_type", obj->query("poison_type"));
	ob->set("no_sell");
        ob->set("long", ob->query("long") + BLU"上面似乎喂有剧毒。\n"NOR);
        call_out("destroy_it", 1, this_object());
        return 1;
}

void destroy_it(object obj)
{
        destruct(obj);
        return;
}
