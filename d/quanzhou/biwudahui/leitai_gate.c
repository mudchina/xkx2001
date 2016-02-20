//Cracked by Roath
// /d/quanzhou/leitai_gate 擂台大门

inherit ROOM;

void create()
{
        set("short", "擂台大门");
        set("long", @LONG
前面就是比武擂台了。为了办好近期的武林大会，「扬威武馆」特在
擂台外临时搭了一个大门。门上一块大木匾，上书「武林大会」四字，气
势磅礴。擂台前有几人穿着武馆衣服的大汉在收费，听说收来的金银将用
于奖励在此次「武林大会」获胜的江湖英雄。这里人来人往，去比武的，
去观战的，都老老实实地把钱放在门前的一只大箱子(xiang) 里。擂台东
边有一块空地，好象也聚了些人。
LONG
        );
	set("exits", ([
		"north" : __DIR__"leitai",
		"northeast" : __DIR__"leitai2",
		"south" : __DIR__"enyuan", 
	]));
	set("item_desc", ([
		"xiang" : "大箱子上写着参加武林大会的收费规矩：\n"
			"　　本大会按各人实战经历收取入场费。\n"
			"-----------------------------------------\n"
			"　　　实战经历（exp）　　　　　 入场费\n"
			"　　　　＜ 100	                 不准入场\n"
			"　　　　100 - 50k      （exp/100）两白银\n"
			"　　　　＞ 50k	                 五两黄金\n"        
			"       无限制入场卷 		 十两黄金\n"
			"例如：经验 25423 需付 254 两白银，打指令：pay 254 silver。\n\n"
			"提供换钱服务，恕不设找赎。\n\n",
	]));
	set("no_fight", 1);
        set("no_sleep_room",1);
	set("cost", 1);
        setup();
}

void init()
{
	add_action("do_pay", "pay");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        delete_temp("busy");
}

void enough_rest()
{
        delete_temp("busy");
}

int do_pay(string arg)
{
    	string item;
        object obj, me = this_player();
        int amount, fee;

	if( me->query("combat_exp") < 100) 
		fee = 0; 
	else if( me->query("combat_exp") > 100000) 
		fee = 1000;
	else 
		fee = (me->query("combat_exp"))/100;

        if( !arg || sscanf(arg, "%d %s", amount, item) != 2 )
                return notify_fail("你要付多少入场费？\n");

	if (!objectp(obj = present(item, me)) || !obj->query("money_id") )
		return notify_fail("你要付什么钱。\n");
	if (amount > obj->query_amount() )
		return notify_fail("你没有那么多的" + obj->name() + "。\n");

	obj->set_amount(obj->query_amount() - amount);
	message_vision( sprintf("$N将一%s%s放进大箱子里。\n", 
		obj->query("unit"), obj->name()), me );

	me->add_temp("amount_paid",amount*(int)obj->query("base_value")/100);

	if (me->query_temp("paid") )
		tell_object(me, "谢谢捐献。\n");
        if( me->query_temp("amount_paid") >= fee) 
               	me->set_temp("paid", 1);
	if( me->query_temp("amount_paid") >= 100000) 
                me->set_temp("apply/pass", 1);
       	return 1;

}
/*
int valid_leave(object me, string dir)
{
	if (dir == "north" || dir == "northeast")
	{
		if( me->query("combat_exp") < 100)
			return notify_fail("小家伙不要乱跑，比武可不是闹着完的，你爹娘呢？\n");

		if( !me->query_temp("paid") && !me->query_temp("apply/pass") && !wizardp(me))
			return notify_fail("一个看门的壮汉拦住了你：嘿，参加武林大会，你给钱了吗？\n");

		me->delete_temp("amount_paid");
		me->delete_temp("paid");

		if( me->query_temp("apply/pass") || wizardp(me))
			message_vision(
			"$N向看门的武师们点了点头。\n",me);
        }

        return ::valid_leave(me, dir);
}
*/
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}


int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，这儿正忙着呢……您请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	return notify_fail("命令格式：convert|duihuan <数量> <货币单位> to <新货币单位>\n");

	if ( to == "thousand-cash" || to == "cash" || to == "thousand-cash_money" )
	return notify_fail("武馆大汉说道：唉呀！前些时候有人私造假银票，是以银票已作废了。\n");

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
	return notify_fail("你想兑换成什么？\n");

	if (!from_ob)
	return notify_fail("你身上没有带这种钱。\n");

	if (amount < 1)
	return notify_fail("你想白赚啊？\n");

	if ((int)from_ob->query_amount() < amount)
	return notify_fail("你带的" + from_ob->query("name") + "不够。\n");
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	return notify_fail("这样东西不值钱。\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	return notify_fail("这些" + from_ob->query("name") + "不够换。\n");

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/clone/money/" + to);
		to_ob->set_amount(amount * bv1 / bv2);
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 / bv2);
	
	message_vision(sprintf("$N从身上取出%s%s%s，换成了%s%s%s。\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}

