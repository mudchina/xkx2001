//Cracked by Roath
// ping.c 平一指

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "药铺老板");
	set("nickname","杀人神医");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 50000);
	set("attitude", "peaceful");

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 50);

	set("vendor_goods", ({}));

	setup();
	add_money("gold", 1);
}

void init()
{
	object ob;

	::init();
        if( present("shou jiao", this_player()) && !this_player()->query_temp("jiao_giver") ) {
		message_vision("\n平一指突然回过头来，目光炯炯地瞪着$N，缓缓说道：“你身上可有件大宝贝呀，愿意卖给我吗？”\n" +
				   "他边说边连连搓着手，满脸放光，露出极为焦急兴奋的神情。\n\n", this_player());

		ob = new("/clone/money/thousand-cash");
		ob->set_amount(3);
		ob->move(this_player());

		message_vision("“我给你三千两换它，怎么样？！” 平一指不等$N反应过来，就掏出一叠银票，塞到$N手中。\n", 
					this_player());
	}
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	if( obj->query("id") == "shou jiao" && ob->query_temp("jiao_giver") ) {
		message_vision("\n平一指微笑道：“好小子，稍等一会，我这就替你做一颗辟水灵珠！\n", ob);
		message_vision("\n平一指转身走进药铺内堂。\n", ob);
		call_out("do_make", 60, this_object(), this_player());
		return 1;
	}

	if( obj->query("id") == "shou jiao" && !ob->query_temp("jiao_giver") ) {
		message_vision("\n平一指欢呼一声，接过兽角，飞也似地跑到药柜旁，摸出一个大铁盒，把兽角塞了进去，再重新锁好。\n", ob);
		ob->set_temp("jiao_giver", 1);
		return 1;
	}

	if( obj->query("id") == "thousand-cash" && obj->query_amount() == 3 && ob->query_temp("jiao_giver") ) {
		message_vision("\n平一指满脸狐疑地瞪着$N瞧了半饷。说道：“你不收钱？！ 那你到底想要什么？ 你倒说说看！\n", ob);
		ob->set_temp("cash_giver", 1);
		add_action("do_say", "say");
		return 1;
	}

	return 0;
}

int do_say(string arg)
{
	object me, ob;

	ob = this_player();
	me = this_object();
		
	if( !ob->query_temp("jiao_giver") || !ob->query_temp("cash_giver") ) return 0;

	if( arg=="辟水灵珠" ) {
		message_vision("\n平一指冷笑道：“一株兽角只能做一颗辟水珠，我能得什么好处？！ 除非你能再给我弄一株来！”\n", ob);
		return 1;
	}
	else	message_vision("\n平一指斜眼看着$N，冷笑道：“我不懂你在说些什么！”\n", ob);
	
	return 0;
}

int do_make(object me, object ob)
{
	object zhu;

	message_vision("\n平一指走了出来，说道：“辟水灵珠做好了，这就给你吧！ 前途珍重！”\n", ob);
	command("hehe");

	zhu=new("/d/shaolin/obj/pishui-zhu");
	zhu->move(ob);

	message_vision("\n平一指交给$N一颗辟水灵珠。\n", ob);
	return 1;
}
