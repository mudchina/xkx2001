//Cracked by Roath
// ronglu.c 熔炉
// by zhangchi

#include <ansi.h>
inherit ITEM;

int check_busy(object me);

#define OBJ_PATH "/d/kunlun/obj"

void create()
{
        set_name(HIR"熔炉"NOR, ({ "rong lu", "lu" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是座大熔炉，里面烈火燃烧，是用来打造火枪的。\n");
                set("unit", "座");
		set("value", 1);
		set("no_get", 1);
        }
}

void init()
{
	add_action("do_fang","fang");
	add_action("do_fang","put");
}

int do_fang(string arg)
{
        object me, ob, jingtie;
        string item, target; 

        me = this_player();
        ob = this_object();
        
        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("你正忙着呢。\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("你要将什么东西放进哪里？\n");

	if (item != "精铁" || target != "熔炉")
		return notify_fail("你要将什么东西放进哪里？\n");

	if ( !jingtie=present("jing tie",me) )
		return notify_fail("你身上并没有精铁。\n");

	if (query_temp("in_use"))
		return notify_fail("这个火炉已经有人在用了！\n");

	message_vision("$N把一"+jingtie->query("unit")+jingtie->query("name")+"放进熔炉。\n",me);
	destruct(jingtie);
	message_vision(HIR"$N放进燃料，拉起风箱，顷刻间就生起一炉熊熊大火！\n"NOR,me);
	
	set_temp("in_use",1);
	me->set_temp("pending/job_busy",1);
	me->set_temp("gun_making",1);

	remove_call_out("burning");
	call_out("burning",10+random(5),me,0);
	me->start_busy((: check_busy :));

	return 1;
}

void burning(object me, int stage)
{
	string *burning_msg=({
		HIC"炉火由红慢慢变青。\n"NOR,
		HIW"炉火由青渐渐转白。\n"NOR,
		HIW"精铁"+HIR"已经开始溶化了。\n"NOR,
		HIW"精铁"+HIR"已经全部溶化了，可以倒进模子了。\n"NOR,
	});

	message_vision(burning_msg[stage],me);
	
	if (stage != 3)
	{
		remove_call_out("burning");
		call_out("burning",10+random(5),me,++stage);
	}
	else
	{
		add_action("do_pour","dao");
		add_action("do_pour","pour");
		me->delete_temp("pending/job_busy");
		me->set_temp("pouring",1);
	}

}

int do_pour(string arg)
{	
	string item, target;
	int busy_time=0;
	object me=this_player();


        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("你正忙着呢。\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("你要将什么东西倒进哪里？\n");

	if (item != "铁水" || target != "火枪模子")
		return notify_fail("你要将什么东西放进哪里？\n");

	if (!present("huoqiang muzi",environment(this_object())) )
		return notify_fail("这里没有火枪模子。\n");

	if ( !me->query_temp("pouring") )
		return notify_fail("好象还没轮到你吧。\n");

	if (me->query("neili") < 50 || me->query("jingli") < 50)
		return notify_fail(RED"你已经精疲力竭了！\n"NOR);

	message_vision("$N用土勺把溶化的铁水小心翼翼的从炉子里盛出来，慢慢的倒进火枪模子里。\n",me);
	if (random(10) > 3)
	{
		message_vision("糟糕！$N一不小心，几滴铁水溅到了脚上，痛得$N哇哇大叫!\n",me);
		me->receive_wound("qi",100);
		busy_time=3;
	}
	me->add("jingli",-100);
	me->add("neili",-100);

	busy_time=busy_time+1;
	me->start_busy(busy_time);

	remove_action("do_pour","pour");
	remove_action("do_pour","dao");
	add_action("add_xiaohuang","add");

	return 1;
}

int add_xiaohuang(string arg)
{	
	string item, target;
	object xiaohuang;
	object me=this_player();

        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("你正忙着呢。\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("你要将什么东西放进哪里？\n");

	if (item != "硝磺" || target != "火枪模子")
		return notify_fail("你要将什么东西放进哪里？\n");

	if (!(xiaohuang=present("xiaohuang shi",me)) )
		return notify_fail("你身上并没有硝磺石。\n");

	if (!present("huoqiang muzi",environment(this_object())) )
		return notify_fail("这里没有火枪模子。\n");

	if ( !me->query_temp("pouring") )
		return notify_fail("好象还没轮到你吧。\n");

	if (me->query("neili") < 50 || me->query("jingli") < 50)
		return notify_fail(RED"你已经精疲力竭了！\n"NOR);

	message_vision("$N往火枪模子里添了一些硝磺。\n",me);
	destruct(xiaohuang);

	me->add("neili",-50);

	me->start_busy(1);

	remove_action("add_xiaohuang","add");
	remove_call_out("job_done");
	call_out("job_done",5+random(10),me);

	return 1;
}

void job_done(object me)
{
	object huoqiang;

	message_vision("$N揭开模子，看来铁水已经凝固。$N浇上一盆冷水，"+
			"只听哧哧声响，一阵刺鼻的浓烟过后，火枪已经制成。\n",me);
	huoqiang=new(OBJ_PATH"/huoqiang");
	huoqiang->move(me);
	remove_action("add_xiaohuang","add");
	delete_temp("in_use");
	me->delete_temp("gun_making");
	me->start_busy(3);

}

int check_busy(object me)
{
	if (me->query_temp("pending/job_busy"))
		return 1;
	return 0;
}

