//Cracked by Roath
// youlong.c

#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
        set_name("游龙剑", ({ "youlong sword", "youlong", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
			"这是把看起来很普通的长剑，但仔细一看，剑身上有几条细纹闪烁不定。\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", 
			"只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(70);
        setup();
	::create();
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
	&& me->query("jing", 1) > 50
	&& (int)me->query("combat_exp") >= 50000 )
	{
		me->receive_damage("jing", 30);
		me->improve_skill("sword", me->query("int"));
		tell_object(me, "只见剑身化作一条白龙，光焰闪动间，你对剑道的领悟又深了一层！\n", me);
		return 1;
	}

	return 0;
}

