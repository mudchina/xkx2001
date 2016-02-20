//Cracked by Roath
//水桶
//xiaojian May 25,2000
//Fix ppl useing other piao get more exp mantian may/17/2001

#include <ansi.h>
inherit ITEM;
string long_desc();
void create()
{
	int water_level;
	set_name("水桶", ({"shui tong", "tong", "bucket"}));
	set_weight(1000);
	if(clonep())
		set_default_object(__FILE__);

	else {
		set("long", (: long_desc :));
		set("unit", "个");
		set("material", "wood");
		set("value", 5000);
		set("no_sell", 1);
		set("no_give",0);
		set("no_get",1);
	        set("no_refresh", 1);

	}
}
string long_desc()
{
	string descrp;
	object ob;
	ob = this_object();
	descrp = 
		HIW"这副木桶有些特别，桶底尖尖的，根本立不稳。两只桶由一条细麻绳穿连起来，样子有些怪怪的。\n"NOR;
	if (ob->query("water_level") == 0)
		descrp += HIC"桶里面一滴水都没有。\n"NOR;
	else if (ob->query("water_level") <= 1)
		descrp += HIC"里面有一点点水。\n"NOR;
	else if (ob->query("water_level") <= 3)
		descrp += HIC"里面有半桶水。\n"NOR;
	else if (ob->query("water_level") <= 4)
		descrp += HIC"里面的水快满了。\n"NOR;
	else
		descrp += HIC"木桶轻轻地晃了晃，里面的水满了，有些立不稳。 \n"NOR;
	return descrp;
}

int init()
{
	add_action("do_tiao", "carry");
	add_action("do_tiao", "tiao");
	add_action("do_fang", "putdown");
	add_action("do_fang", "fang");
	add_action("do_dao", "dao");
}

int do_tiao(string arg)
{
	object me, ob;
	me = this_player();
	if(!arg || (arg != "shui tong" && arg!= "tong" && arg != "bucket"))
		return notify_fail("你要挑什么? \n");
	ob = present("shui tong", environment(me));
	if(!ob)
		return notify_fail("这里附近没有这样东西。\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(ob->query("owner") != me->query("id") && (!wizardp(me)))
		return notify_fail("这个不是你的水桶。\n");
	message_vision(HIR"$N把麻绳挑在肩上，然后扎了个马步，气聚丹田，双臂用力，木桶被平平提起。\n"NOR,me);
	me->receive_damage("jingli",5+random(5));
	//tong has been carried, so the position factor is not applied
	ob->delete("tong_pos");
	ob->move(me);
	me->start_busy(random(3));
	return 1;
}

int do_fang(string arg)
{
	object me, ob;
	me = this_player();
	if(!arg || (arg != "shui tong" && arg != "tong" && arg != "bucket"))	
		return notify_fail("你要放下什么? \n");
	ob = present("shui tong", me);
	if( !ob)
		return notify_fail("你并没有挑着任何东西。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢! \n");
	message_vision(HIB"$N把木桶从肩上放下，一手扶住，凝力于臂，然后吐气开声，拍向木桶边缘。\n"NOR,me);
	message_vision(HIC"$N听到“啪啪”两声轻响，木桶稳稳地插在地上。\n"NOR,me);
	me->receive_damage("qi",(10+random(10)),"被木桶砸死了");
	ob->move(environment(me));
	//tong has been putdown, so set tong to be good position,compared to drop tong,tong won't be 竖直的
	ob->set("tong_pos",1);
	me->start_busy(1);
	return 1;
}
int do_dao(string arg)
{
	int water_level,max;
	object me,ob1,ob2;
	string what, target;
	me = this_player();

	if( !arg
        ||      sscanf(arg, "%s to %s", what, target)!=2)
                return notify_fail("命令格式: dao <物品> to <物品>。\n");

	ob1 = present("shui piao", me);
	ob2 = present(target, environment(me));
	if(!ob1)
		return notify_fail("你要用什么倒水? \n");
	if(!ob1->query("water_filled"))
		return notify_fail("水瓢里没有水怎么倒? \n");
	if( !ob2 )
		return notify_fail("你要往哪里倒水? \n");
	if (what != "shui" && what != "water")
		return notify_fail("你要倒什么? \n");
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(ob2->query("full"))
		return notify_fail("水桶已经满了。\n");
	if(ob2->query("owner") != me->query("id") && (!wizardp(me)))
		return notify_fail("这个不是你的水桶。\n");
	if(!ob2->query("tong_pos"))
		return notify_fail("你必须把桶放下(putdown),桶才能竖立起来。\n");
	if(ob1->query("owner/id") != me->query("id"))
	{
		message_vision("$N用着"+ob1->query("owner/name")+"的水瓢把一瓢水倒进了水桶。\n",me);
		if(me->query_condition("tiaoshui") >5)
			me->apply_condition("tiaoshui",me->query_condition("tiaoshui")-5);
	}
	else message_vision("$N把一瓢水倒进了水桶。\n",me);
	ob1->set("water_filled",0);
	ob2->add("water_level",1);
	ob2->set("long", (: long_desc :));
	if (ob2->query("water_level") ==5 )
	ob2->set("full",1);
	me->start_busy(2+ random(2));
	me->receive_damage("jingli", (10+ random(5)));
	return 1;
}
