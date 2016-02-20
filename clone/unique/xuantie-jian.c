//Cracked by Roath
// xuantie-jian 玄铁剑
// qfy July 5, 1996

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name("玄铁重剑",({ "xuantie jian", "xuantie", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 8000);
                set("material", "steel");
		set("rigidity", 10000);
                set("long", 
		"此剑黑黝黝的毫无异状，却是沉重之极。两边剑锋都是钝口，剑尖更圆圆的似是个半球。\n");
                set("wield_msg", HIY "$N举起$n，但见日月无光，沉雷郁郁，似乎要将一切生机压毁。\n" NOR);
                set("unwield_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
                set("unequip_msg", HIY "玄铁乍收，生机徒现。\n" NOR);
        }
	init_sword(140);
        setup();
	::create();
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

	if (arg != "sword") return 0;

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("name") != "玄铁重剑" )
		return 0;
	
	if (me->query("jingli") < 50)
		return notify_fail("你的精力不够！\n");

	if ( arg == "sword" && !me->is_fighting() 
	&& (int)me->query_skill("sword", 1) >= 50
	&& (int)me->query_skill("sword", 1) <= 120
	&& (int)me->query("combat_exp") >= 50000 ) {
	   me->receive_damage("jingli",50);
	   me->improve_skill("sword", me->query("int")+20);
	   tell_object(me,"你的基本剑法进步了！\n", me);
	
	   if ( (int)me->query_skill("dugu-jiujian",1) >= 30 
	   && (int)me->query_skill("dugu-jiujian",1) <= 120 
	   && me->query("family/master_id") == "feng qingyang" ) {
		me->improve_skill("dugu-jiujian", me->query("int")+20);
		tell_object(me,"你的独孤九剑进步了！\n", me);
   	   }
	return 1;
	}
	else {return 0;}
}
