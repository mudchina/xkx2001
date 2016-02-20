//Cracked by Roath
// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
// wzfeng changed 2000 7. fix withdraw
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("黄真", ({"huang zhen", "zhen", "huang"}));
	set("nickname", "铜笔铁算盘");
	set("long","他是华山派穆仁清的大弟子，一派商人模样。\n");
	set("gender", "男性");
	set("age", 55);

	set("str", 28);
	set("int", 24);
	set("dex", 28);
	set("con", 28);
	set("max_jing", 100000);
	set("jing", 100000);

	set("shen", 1000);

	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);

	set_skill("cuff", 80);
	set_skill("dodge", 80);
	set_skill("hammer",80);
	set_skill("huashan-shenfa",70);
	set_skill("pishi-poyu",65);
        map_skill("dodge","huashan-shenfa");
	map_skill("cuff", "pishi-poyu");
        prepare_skill("cuff", "pishi-poyu");


        create_family("华山派",21,"弟子");
	setup();
	add_money("coin", 188);
	add_money("silver", 88);
//	add_money("gold", 1);
       carry_object("/d/forest/npc/obj/gebu-changpao")->wear();
	carry_object(__DIR__"obj/tiesuanpan")->wield();
}

void init()
{
	::init();
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	add_action("do_rob", "rob");
}

int do_check()
{
	string what;
	int amount;
	object what_ob;
	object me = this_player();
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");

	if (!total || total < 0) {
		this_player()->set("balance", 0);
//		return notify_fail("您在敝商号没有存钱。\n");
		write("黄真笑道：查也白查，您在敝商号没有存钱。\n");
		return 1;
	}
	write("黄真告诉你：您在弊商号共存有" +
		MONEY_D->money_str(total) + "\n");

	if ( me->query("balance") > 10000000 )
	{
		write("黄真告诉你：您的金子太多了，多半是偷来的，不如分我一些，好处大家拿！\n");
		me->set("balance",10000000);
      total = (int)this_player()->query("balance");
		write("黄真告诉你：您在弊商号现在只有" +
			MONEY_D->money_str(total) + "\n");
		command("hehe");
	}

	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob,money_temp;
	object me;
	
	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	return notify_fail("命令格式：convert|duihuan <数量> <货币单位> to <新货币单位>\n");

//	if ( from == "cash" || from == "thousand-cash" || from == "thousand-cash_money" )
//      return notify_fail("黄真说道：唉呀！前些时候有人私造假银票，客官这银票正是伪造的，杨知府已下令所有银票作废！\n");

	if ( to == "thousand-cash" || to == "cash" || to == "ten-cash" || to == "hundred-cash" || to == "thousand-cash_money" )
	return notify_fail("黄真说道：唉呀！前些时候有人私造假银票，是以银票已作废了。\n");

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (from == to)
	return notify_fail(from_ob->query("name") +"换"+to_ob->query("name")+"，你无聊不无聊啊？\n");

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
//	printf("数量=%d\n 转换后的数量是=%d\n",amount,amount *bv1 / bv2);


		money_temp = new("/clone/money/" + to);
/*		printf("自己的负重=%d\n钱的重量=%d\n自己的最大负重=%d/t",me->query_encumbrance(),
	amount *bv1 / bv2*(money_temp->weight()),me->query_max_encumbrance());
*/

	if((me->query_encumbrance()+amount *bv1 / bv2*(money_temp->weight()))>me->query_max_encumbrance())
	{
		destruct(money_temp);
		return notify_fail("你带不了那么多钱，太重了。\n");
	}
	destruct(money_temp);



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

	return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob, me;

	me = this_player();

	if (me->query("family/family_name") == "丐帮")
	return notify_fail("黄真说道：丐帮的兄弟帮闯王打天下，你还是把钱亲自交到闯王营中吧！\n");

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	return notify_fail("命令格式：deposit:cun <数量> <货币单位>\n");

	if ( what == "cash" || what == "thousand-cash" || what == "thousand-cash_money" )
	return notify_fail("黄真说道：唉呀！前些时候有人私造假银票，客官这银票正是伪造的，杨知府已下令所有银票作废！\n");

	what_ob = present(what + "_money", me);
	if (!what_ob)
	return notify_fail("你身上没有带这种钱。\n");

	if (amount < 1)
	return notify_fail("你想存多少" + what_ob->query("name") + "？\n");

	if ((int)what_ob->query_amount() < amount)
        return notify_fail("你带的" + what_ob->query("name") + "不够。\n");

	if ( (me->query("balance") + amount * what_ob->query("base_value")) >= 10000000 )
	return notify_fail("你的钱这么多，莫非是石梁温家堡的人？！\n");

	if (amount * what_ob->query("base_value") >= 3000000)
        log_file("MONEY", sprintf("%s(%s)于%s在钱庄存了%s两%s。\n",
                me->query("name"), getuid(me), ctime(time()), chinese_number(amount), what_ob->query("name")));

	// Depositing the Money

	what_ob->add_amount(-amount);

	me->add("balance", what_ob->query("base_value") * amount);
	message_vision(sprintf("$N拿出%s%s%s，存进了银号。\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);

	return 1;
}

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	me = this_player();
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	return notify_fail("命令格式：withdraw|qu <数量> <货币单位>\n");

	if (amount < 1)
	return notify_fail("你发疯啦，取负数？\n");

	if (amount > 1000)
	return notify_fail("你每次最多允许取一千两。\n");

	if (file_size("/clone/money/" + what + ".c") < 0)
	return notify_fail("你想取出什么钱？\n");

	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
	return notify_fail("你存的钱不够取。\n");

	//wight
//	printf("自己的负重=%d\n钱的重量=%d\n自己的最大负重=%d/t",me->query_encumbrance(),
//	amount *(what->weight()),me->query_max_encumbrance());
	if((me->query_encumbrance()+amount *(what->weight()))>me->query_max_encumbrance())
		return notify_fail("你带不了那么多钱，太重了。\n");


	me->add("balance",  -v);
//	MONEY_D->pay_player(me, v = v * 9 / 10);
// Disable bank charge.
	MONEY_D->pay_player(me, v);

	message_vision(sprintf("$N从银号里取出%s。\n", MONEY_D->money_str(v)),
		me);

	return 1;
}

int do_rob(string arg)
{
		  int amount, v;
        string what, victim, item;
        object me, ob;

        me = this_player();

        if (!arg || sscanf(arg, "%s %s", victim, item) != 2)
		  return notify_fail("命令格式：rob <人物> <数量> <货币单位>\n");

	if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");

	if(!objectp(ob = present(victim, environment(me))) || !living(ob))
                return notify_fail("这里没有这个人。\n");

    if( ob->query_condition("xs_necromancy") < 0 || !ob->query_temp("block_msg/all", 1) 
                || (me->query("id") != ob->query("xueshan/necromancy_singer")) )
//	if (!ob->query_temp("cursed", 1) || !ob->query_temp("block_msg/all", 1))
                return notify_fail("此人不会乖乖地听你话取钱给你！\n");

	if ( me->query_skill("necromancy", 1) < 60)
		return notify_fail("你降伏法火候不够！\n");

	if(sscanf(item, "%d %s", amount, what)==2) {
		  if (amount < 1)
		  return notify_fail("你想让此人取出多少钱？\n");
		  if (file_size("/clone/money/" + what + ".c") < 0)
		  return notify_fail("你想让此人取出什么钱？\n");

	if (amount > 1000)
	return notify_fail("此人每次最多允许取一千两。\n");

		  what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > ob->query("balance"))
        return notify_fail("此人存的钱不够取。\n");

		if((me->query_encumbrance()+amount *(what->weight()))>me->query_max_encumbrance())
		return notify_fail("你带不了那么多钱，太重了。\n");


        ob->add("balance",  -v);
// Disable bank charge
      //  MONEY_D->pay_player(me, v = v * 9 / 10);
		  MONEY_D->pay_player(me, v);
	message_vision(HIR"$N诡笑中低下头在" +ob->query("name") +"耳边轻声念了几句密咒。\n" NOR,  me);
		  message_vision(sprintf(ob->query("name") +"从银号里取出%s乖乖地交给$N。\n", MONEY_D->money_str(v)), me);

		  return 1;
	}
}
void unconcious()
{
		  message_vision("\n突然，只见$N闪身拉开柜台下一道暗门，钻了进去，咔嚓从里
边把门锁上了。\n",
					 this_object());
        destruct(this_object());
}

void attempt_apprentice(object ob)
{
        command("haha");
        command("say 想白学功夫？蚀本生意我可不做！");
        return;
}

