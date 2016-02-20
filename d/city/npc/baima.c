//Cracked by Roath
// baima.c 白马

inherit NPC_TRAINEE;

void create()
{
	set_name("白马", ({ "bai ma", "ma", "horse" }) );
	set("race", "家畜");
	set("age", 10);
	set("long", "这是一匹白色的大宛马，生得龙颈狮鬃，四蹄飞青，确是匹罕见的千里马。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，人立起来！");
	set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
	set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
	set("auto_follow",1);
	set("attitude", "peaceful");

	set("wildness", 3);
	
	set("str", 30);	
	set("con", 40);
	set("dex", 40);	
	set("int", 20);

	set("combat_exp", 10000);
	set_weight(100000);

	setup();
}

void init()
{	
	::init();
	add_action("do_ride", "ride");
	add_action("do_unride", "unride");
}

int do_ride()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( me->query_lord() == ob ) 
	{
		if( !ob->query_temp("riding") )
		{
			if( !me->query_temp("rider") ) 
			{
				ob->set_temp("riding", me->name());
				me->set_temp("rider",  ob->name());
				me->set_leader(ob);

				message_vision("\n$N一纵身，威风凛凛地骑在了" + me->name() +"身上。\n", ob);
				return 1;
			}
			else    return notify_fail( me->query_temp("rider") + "已经骑在它身上上了！\n");
		}
		else	return notify_fail("你已经骑在" + ob->query_temp("riding") + "上了！\n");
	}
	else return notify_fail("你不是它的主人！\n");

	return 0;
}

int do_unride()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( ob->query_temp("riding") == me->name() && me->query_temp("rider") == ob->name() ) 
	{
		ob->delete_temp("riding");
		me->delete_temp("rider" );
		message_vision("\n$N一纵身，从" + me->name() +"身上跃了下来。\n", ob);
		return 1;
	}
	else return notify_fail("你还没骑它呢！\n");

	return 0;
}
