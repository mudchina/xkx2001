//Cracked by Roath
// zhenwu.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name("真武剑", ({ "zhenwu sword", "zhenwu", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
			"只见长剑剑鞘铜绿斑斓，以铜丝嵌着两个篆文：“真武”。\n");
                set("value", 7000);
                set("material", "steel");
		set("rigidity", 1500);
                set("wield_msg", 
			"只听见「飕」地一声，顿觉寒气扑面，$N的手中已经多了一把宝剑——$n。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(120);
        setup();
}

void init()
{
	if( this_player() == environment() )
		add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

	if ( arg != "youlong sword" && arg != "youlong" && arg != "sword")
	return notify_fail("你要学什么？\n");

	if ( me->is_fighting() 
	&& (int)me->query_skill("sword", 1) >= 30 
	&& (int)me->query_skill("sword", 1) <= 100
	&& (int)me->query("combat_exp") >= 50000 )
	{
		me->receive_damage("jing", 30);
		me->improve_skill("sword", me->query("int"));
		tell_object(me, "只见剑身化作一条白龙，光焰闪动间，你对剑道的领悟又深了一层！\n", me);
		return 1;
	}

	return 0;
}

