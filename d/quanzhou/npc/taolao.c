//Cracked by Roath
// taolao.c 陶老人

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("陶老人", ({ "tao lao", "tao", "lao" }));
	set("title", "淘然茶居老板");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 55);
	set("long",
		"陶老人是出名的老好人，他卖的茶又香又好，价钱公道，\n"
		"所以城里的人都喜欢到他那买茶。\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		__DIR__"obj/wulong",
		__DIR__"obj/guanying",
		__DIR__"obj/longjing",
		__DIR__"obj/moli",
		__DIR__"obj/xiangpian",
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
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("陶老人笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进来喝杯热茶。\n");
		break;
	case 1 :
		say("陶老人说道：哟！这位" + RANK_D->query_respect(ob) + 
			"，今天刚运到了一批新鲜茶叶，来尝尝吧。\n");
		break;
	}
}
