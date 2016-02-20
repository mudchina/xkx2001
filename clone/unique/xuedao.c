//Cracked by Roath
// xuedao.c  血刀

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(RED"血刀"NOR, ({ "xue dao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", RED"一柄长长的缅刀，刀身不住颤动，宛如活蛇一般。引光望去，刀刃上一片暗
红之色。\n" NOR);
		set("value", 7000000);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", RED "只听「唰」的一声，血刀脱鞘飞出，$N手中似是握住一条赤蛇泛着红光，弥漫着一片血气。\n" NOR);
		set("unwield_msg", RED " 蛇进刀鞘。\n" NOR);
		set("clone_ob", "/clone/weapon/xuedao");
	}
	::create();
	init_blade(100);
	setup();
}

void init()
{
        add_action("do_lian","lian");
        add_action("do_lian","practice");
}

int do_lian(string arg)
{
        object weapon, me = this_player();

	if (arg != "blade") return 0;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade" )
	return notify_fail( "你使用的武器不对。\n");

	if ( weapon != this_object() ) return 0;
	
	if ( arg == "blade" && !me->is_fighting()
        && (int)me->query("combat_exp") >= 50000  
	&& present("xuedao book", me)
        && ((int)me->query_skill("xue-dao",1) >= 50
	&& (int)me->query_skill("xue-dao",1) <= 200
        && me->query("family/master_id") == "xuedao laozu" )) {
		me->receive_damage("jingli",10);
		me->receive_damage("qi", 5);
                me->improve_skill("xue-dao", me->query("int")+10);
	if( me->query_skill("xue-dao",1) > 150 ) 
	me->receive_damage("jingli", 5 );
	me->receive_damage("qi", 5);

        if( me->query_skill("xue-dao",1) > 180 ) 
	me->receive_damage("jingli", 10);
	me->receive_damage("qi", 5);

        if( me->query_skill("xue-dao",1) > 200 ) 
	me->receive_damage("jingli", 15);
	me->receive_damage("qi", 5);
                tell_object(me,"你的血刀刀法进步了！\n", me);
	return 1;
        }
	else
	return notify_fail("血刀寒气逼人，你练得没什么进展。\n");
}
