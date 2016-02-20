//Cracked by Roath
// xuantie-jian 玄铁剑
// qfy July 5, 1996

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("玄铁重剑",({ "xuantie jian", "xuantie", "sword", "jian" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 8000);
                set("material", "steel");
                set("long", 
		"此剑黑黝黝的毫无异状，却是沉重之极。两边剑锋都是钝口，剑尖更圆圆的似是个半球。\n");
                set("wield_msg", HIY "$N举起$n，但见日月无光，沉雷郁郁，似乎要将一切生机压毁。\n" NOR);
                set("unwield_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
                set("unequip_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
        }
	init_sword(800);
        setup();
}

void init()
{
	object me = this_player();
	
	if ( !me->query_skill("dugu-jiujian") )  {
	
	}

	add_action("do_lian","lian");
	add_action("do_lian","practise");
}

int do_lian(string arg)
{
	object weapon, me = this_player();

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" )
	   return notify_fail( "你使用的武器不对。\n");
	
	if ( arg == "sword" && !me->is_fighting() 
	&& (int)me->query_skill("sword", 1) >= 50
	&& (int)me->query_skill("sword", 1) <= 120
	&& (int)me->query("combat_exp") >= 50000 ) {
	   me->receive_damage("qi",50);
	   me->improve_skill("sword", me->query("int")+20);
	   tell_object(me,"你的基本剑法进步了！\n", me);
	
	   if ( (int)me->query_skill("dugu-jiujian",1) >= 30 
	   && (int)me->query_skill("dugu-jiujian",1) <= 120 ) {
		me->improve_skill("dugu-jiujian", me->query("int")+20);
		tell_object(me,"你的独孤九剑进步了！\n", me);
   	   }
	}

	return 1;
}
