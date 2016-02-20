//Cracked by Roath
// pine.c 松树 
// By Marz@XKX 11/11/96

#include <ansi.h>

inherit ITEM;


int start_collapse = 0;
int chop_times = 0; 

void create()
{
	set_name(HIR"红松树"NOR,({"pine"}));
	set_weight(900000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一棵古老的红松树。\n");
		set("unit", "棵");
		set("value", 8);
		set("no_get", 1);
    	}
	
	setup();
}

void init()
{
	add_action("do_chop", "chop");
	add_action("do_chop", "砍");
}

int do_chop(string arg)
{
	object weapon, me = this_player();
	
	if( !arg || arg!="pine" && arg != "树" )
		return notify_fail("你要砍甚么？\n");

	if( !objectp(weapon = me->query_temp("weapon")) )
	{
        message_vision(HIR"$N挥手朝松树一阵猛砍，弄得双手鲜血淋淋。\n"NOR, me);
		me->receive_damage("qi", 50, "流血过多死了");
		return 1;
	} else if ((string)weapon->query("skill_type") != "sword"
		&& (string)weapon->query("skill_type") != "blade" 
		&& (string)weapon->query("skill_type") != "axe" )
	{
        message_vision(HIW"$N挥起手中" + weapon->name() 
			+"朝松树一阵猛砍。\n"NOR, me);
		message_vision(HIW"结果「啪」地一声，$N手中的" + weapon->name()
			+ "已经断为两截！\n"NOR , me );

		weapon->unequip();
		weapon->move(environment(me));
		weapon->set("name", "断掉的" + weapon->query("name"));
		weapon->set("value", 0);
		weapon->set("weapon_prop", 0);
		
		return 1;
	}
	
	message_vision(HIW"$N操起手中" + weapon->name()
		 + "，吭吃吭吃地砍树。\n"NOR, me);
	me->receive_damage("jingli", 5+random(35-(int)me->query("str")),
		 "砍树累死了");

	chop_times++;

	if ( !start_collapse && random(chop_times) ) 
	{
		start_collapse = 1;
		chop_times = 0;
		message_vision(HIC"松树开始松动起来，吱吱呀呀发出响声。\n"NOR,
			 this_object());

		call_out("collapse", 20, me);
	}		

	return 1;
}  

void collapse(object me)
{
	object ob, obn;
	object *inv;
	int i;
	
	ob = this_object();
	if ( !objectp(me) ) return;

	if ( chop_times <= 0 || random(chop_times) < 2)
	{
		message_vision(HIC"松树摇摆了两下，又站住了。\n"NOR, ob);
		start_collapse = 0;	
		return;
	} 

	message_vision(RED"松树轰的一声倒了下来…\n"NOR, ob);

	if ( random(chop_times) > 5 ) 
	if ( present(me, environment(ob)) )   
	{
		message_vision(HIR"正砸在$n头上！\n"NOR, ob, me);
		me->receive_damage("qi", 30*chop_times, "被松树干砸死了");
		me->receive_wound("qi", 20*chop_times, "被松树干砸死了");
	} else 
	{
		inv = all_inventory(environment(ob));
		
		for (i = 0; i < sizeof(inv); i++)
		if (userp(inv[i]))
		{
			message_vision(HIR"正砸在$n头上！\n"NOR, ob, inv[i]);
			inv[i]->receive_damage("qi", 30*chop_times, "被松树干砸死了");
			inv[i]->receive_wound("qi", 20*chop_times, "被松树干砸死了");
		
		}
	}

	if (chop_times >= 13) chop_times = 13;
	me->set("job/wage", chop_times);
	
	if ( objectp(environment(ob)) )
	{
		obn = new(__DIR__"pine_bole");
		obn->move(environment(ob));
	}

	destruct(ob);
}
// End of File 
