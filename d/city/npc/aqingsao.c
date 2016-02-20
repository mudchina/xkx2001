//Cracked by Roath
// aqingsao.c 阿庆嫂

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("阿庆嫂", ({ "aqing sao", "sao" }));
	set("title", "茶馆老板娘");
	set("nickname", "扬州一支花");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 25);
	set("long",
		"阿庆嫂是扬州城里有名的大美人，因为爷儿们总喜欢往她这儿逛，\n"
		"所以她对城里的一举一动都了如执掌。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
		"阿庆" : "我们家阿庆去北边做生意去了耶。\n",
		"生意" : "这个么……。\n",
	]));
	
	set("vendor_goods", ({
		__DIR__"obj/peanut",
		__DIR__"obj/tofu",
	}));

	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
//	add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("阿庆嫂笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进来喝杯热茶。\n");
		break;
	case 1 :
		say("阿庆嫂说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！本店有刚炸好的五香花生出售。\n");
		break;
	}
}

int accept_kill(object obj)
{
        command("chat 胡司令，救命啊！ " + obj->name() + "这个" + RANK_D->query_rude(obj) + "要杀了我！");
}
