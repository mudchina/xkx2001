//Cracked by Roath
#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("喷火筒", ({ "huo qiang", "qiang", "gun" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一把喷火筒，颜色黑中透紫，是用乌金炼出的
精铁打造而成。后边还连着一个铁箱。\n"
);
                set("unit", "把");
		set("bullet", 5);
//		set("no_get", 1);
//		set("no_drop", 1);


        }

}

void init()
{
	add_action("do_load","load");
	add_action("do_aim","aim");
	add_action("do_fire","shoot");
}

int do_load()
{
	object me=this_player();

	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");

	if (query_temp("loaded"))
		return notify_fail("石油已经装好了。\n");

	if (query("bullet") <= 0)
		return notify_fail("石油已经用尽了。\n");

	message_vision("$N给喷火筒里上了一些石油。\n",me);
	set_temp("loaded",1);
	me->start_busy(3+random(3));
	
	return 1;
}

int do_aim(string target)
{
	object ob;
	object me=this_player();

	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");

	if( !target)
		return notify_fail("你想射谁？\n");

	if(!objectp(ob = present(target, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !ob->is_character() || ob->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if( !query_temp("loaded"))
		return notify_fail("你还没装石油呢。\n");

	message_vision(HIW"$N将喷火筒对准了$n。\n"NOR,me,ob);

	set_temp("aimed",target);
	me->start_busy(3+random(3));
	
	return 1;
}

int do_fire()
{
	string target;
	object ob;
	object me=this_player();

	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");

	if (!(target=query_temp("aimed")) )
		return notify_fail("你先瞄准了再开火。\n");

	if (!objectp(ob = present(target,environment(me))))
		return notify_fail("你的目标已经离开了。\n");

	if( !ob->is_character() || ob->is_corpse() )
		return notify_fail("你的目标已经死了。\n");

	message_vision(HIY"$N嘿嘿一声奸笑，扣动机关，一条火焰向$n直喷过去。\n"NOR,me,ob);
	
	add("bullet",-1);
	remove_call_out("shoot_target");
	call_out("shoot_target",1,me,target);
	me->start_busy(5);

	return 1;
}

int shoot_target(object me, string target)
{
	object ob;
	string *limbs;
	int damage;

	if (!objectp(ob = present(target,environment(me))))
		return notify_fail("一阵浓烟过去，好象什么也没打着。\n");

	if( !ob->is_character() || ob->is_corpse() )
		return notify_fail(target+"已经死了。\n");

	if (me->query("combat_exp") < random(ob->query("combat_exp")*2) )
	{
		message_vision(HIY"$N只觉一股热浪扑面而来，忙使一招野驴打滚，狼狈万分的躲了开去！\n"NOR,ob);
	}
	else
	{
		limbs=ob->query("limbs");
		message_vision(HIR"一股烧焦的气味传来，只见$N的"+
				limbs[random(sizeof(limbs))]+"已被火焰喷中，"+
				"顷刻间皮破肉烂，变成焦炭模样。"+
				"$N立时跌倒，狂叫悲呼。\n"NOR,ob);
		damage=me->query("max_qi")+ob->query("max_qi");
		damage=random(damage);
		ob->receive_wound("qi",random(damage));
		ob->receive_damage("qi",damage,"被火烧死了");
	}

	ob->kill_ob(me);
	me->start_busy(random(5));
	
	delete_temp("aimed");
	delete_temp("loaded");

	return 1;
}