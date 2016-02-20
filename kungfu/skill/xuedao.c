//Cracked by Roath
// xuedao.c  血刀

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

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
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", RED "只听「唰」的一声，血刀脱鞘飞出，$N手中似是握住一条赤蛇泛着红光，弥漫着一片血气。\n" NOR);
		set("unwield_msg", RED " 蛇进刀鞘。\n" NOR);
		set("shaolin", 1);
//		set("no_drop", 1);
	}
	init_blade(200);
	setup();
}
void init()
{
        object me = this_player();

        if ( !me->query_skill("xue-dao") )  {

        }

        add_action("do_lian","lian");
        add_action("do_lian","practise");
}

int do_lian(string arg)
{
        object weapon, me = this_player();

        if ( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade" )
	return notify_fail( "你使用的武器不对。\n");
	
	if ( arg == "blade" && !me->is_fighting()
        && (int)me->query("combat_exp") >= 50000  
	&& present("xuedao book", me)
        && ((int)me->query_skill("xue-dao",1) >= 50
	&& (int)me->query_skill("xue-dao",1) <= 200
        && me->query("family/master_id") == "xuedao laozu" )) {
		me->receive_damage("jingli",10);
                me->improve_skill("xue-dao", me->query("int")+10);
	if( me->query_skill("xue-dao",1) > 150 ) me->receive_damage("jingli", 5 );
        if( me->query_skill("xue-dao",1) > 180 ) me->receive_damage("jingli", 10);
        if( me->query_skill("xue-dao",1) > 200 ) me->receive_damage("jingli", 15);
                tell_object(me,"你的血刀刀法进步了！\n", me);
        }
	else
		tell_object(me,"什麽？\n",me);
	
        return 1;
}
