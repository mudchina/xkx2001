//Cracked by Roath
// pring.c 白金戒指

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIW"白金戒指"NOR, ({ "platinum ring", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 9900);
		set("material", "platinum");
		set("no_sell", 1);
		set("armor_prop/armor", 1);
	}
	setup();
}	

void init()
{
	object me = this_player();
        	
	// married but not wearing ring, must be just married or login
	if( me->is_married() && !me->query_temp("ring_worn") ) {
		if( me->query("gender") == "女性" )
			set("long", "戒指上刻着几个小字：「强极则辱  "
				+ me->query("spouse/name") + "」\n");
		else
			set("long", "戒指上刻着几个小字：「情深不寿  "
				+ me->query("spouse/name") + "」\n");
		set("no_drop", 1);
		set("no_get", 1);	
		wear();
		me->set_temp("ring_worn", this_object());
		add_action("disable_remove", "remove");
		remove_action("do_exchange", "exchange");
		remove_action("do_exchange", "huan");
	} else {
		set("long", "一枚亮闪闪的白金戒指，通常象征着夫妻之情天长地久。\n");
//		set("no_drop", 0);
//		set("no_get", 0);	
		add_action("do_exchange", "exchange");
		add_action("do_exchange", "huan");
		remove_action("disable_remove", "remove");
	}	
		
	return;
}

int disable_remove(string arg)
{
	if (!id(arg)) return notify_fail("你要脱掉什么？\n");
        
        write("这样东西取不下来。\n");
        return 1;
}        

int do_exchange(string arg)
{
	string name, id;
	object me, who, so, ob2;
	
	me = this_player();
	
	if( !arg
	|| sscanf(arg, "%s %s", name, id) != 2
	|| id != "platinum ring" && id != "ring"
	|| !objectp(who = present(name, environment(me))) )
		return notify_fail("你要跟谁交换戒指? \n");

	if( me->query_temp("marriage/ring") != who
	|| who->query_temp("marriage/ring") != me )
		return notify_fail("你还是先找好换戒指的人吧。\n");
		
	if( !objectp(so = present("platinum ring", who)) )
		return notify_fail("可惜对方没有戒指可以和你交换。\n");
		
	if( !living(who) ) 
                return notify_fail("你必须先把" + who->name() + "弄醒。\n");
			
	if( me->query("gender") == "女性" ) {		
		message_vision(HIM "$N红着脸将一枚白金戒指轻轻套在$n的无名指上。\n" NOR,
			who, me);
		message_vision(HIM "$N娇羞满面，将另一枚白金戒指套在$n的无名指上。\n" NOR,
			me, who);
	} else {
                message_vision(HIM "$N红着脸将一枚白金戒指轻轻套在$n的无名指上。\n" NOR,
                	me, who);
                message_vision(HIM "$N娇羞满面，将另一枚白金戒指套在$n的无名指上。\n" NOR,
                	who, me);
        }
                	
	me->delete_temp("marriage/ring");
	who->delete_temp("marriage/ring");
	MARRY_D->setup_marriage(me, who, this_object(), so);

// Newly weds can get free rides to different places. xbc 04/16/97

	me->set_temp("marriage/newly_wed", 1);
	who->set_temp("marriage/newly_wed", 1);

        ob2 = new("clone/obj/carm.c");
	ob2->move("/d/city/beidajie2");
	
	return 1;
}
