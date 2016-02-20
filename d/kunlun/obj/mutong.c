//Cracked by Roath
// mutong.c 木桶

#define max_volume 3
inherit ITEM;

void create()
{
	set_name("木桶", ({"mu tong", "tong", "bucket"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装水的木桶。\n");
		set("unit", "个");
		set("amount", 0);
		set("no_drop",1);
	}

}

string extra_long()
{	
	string str;

	switch(query("amount"))
	{
		case 0: 
			str="里面什么也没有。\n";
			break;
		case 1:
			str="里面有少许的冰水。\n";
			break;
		case 2:
			str="里面的冰水快满了。\n";
			break;
		case 3:
			str="里面装满了冰水。\n";
			break;
	}
	
	return str;
}

void init()
{
	add_action("do_fill","fill");
	add_action("do_fill","zhuang");
	add_action("do_pour","pour");
	add_action("do_pour","dao");
}

int do_fill(string arg)
{
	object me=this_player();

	if (!arg) return 0;

	if (arg!="tong"&& arg!="bucket") return 0;

	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	if (environment(me)->query("short")!="碧水寒潭")
		return notify_fail("这里没有冷水。\n");

	if (query("amount") >= max_volume)
		return notify_fail("木桶已经装满水了。\n");

	if (me->query("neili") < 50)
		return notify_fail("你已经精疲力竭了。\n");

	message_vision("$N小心翼翼地从碧水寒潭里舀了些冰水上来。\n",me);
	add("amount",1);
	if ( random(me->query_con()) > 20)
	{
		message_vision("一股寒气从潭底直冒上来，冻得$N打了个哆嗦！\n",me);
		me->receive_wound("qi",random(50),"被冻死了！");
		me->receive_damage("qi",random(100),"被冻死了！");
	}
	me->add("neili",-30);
	me->start_busy(3);

	return 1;
}

int do_pour(string arg)
{
	object gang;
	object me=this_player();
	string item,target;
	int amount;

	if (!arg) return 0;

	if (sscanf(arg, "%s into %s", item, target) != 2)
		return 0;

	if (me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");

	if ((item != "水" && item!="water") || (target!="水缸" && target!="gang"))
		return notify_fail("你要将什么东西倒进哪里？\n");

	if (!(gang=present("shui gang",environment(me))))
		return notify_fail("这里没有水缸。\n");
	
	if (!(amount = query("amount")))
		return notify_fail("木桶里什么都没有。\n");

	message_vision("$N把木桶里的水全部倒进大水缸里。\n",me);
	set("amount",0);
	gang->add("amount",amount);
	me->add_temp("water_amount",amount);

	return 1;
}