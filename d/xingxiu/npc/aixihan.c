//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("爱西翰", ({ "aixihan", "seller", "girl" }) );
	set("gender", "女性" );
	set("title", "花帽摊贩");
	set("age", 20);
	set("long", "一位卖花帽的回族少女。\n爱西翰是回人女子中最多用的名字，有如汉人的芬芳贞淑之类。\n");
	set("shen_type", 1);
	set("combat_exp", 1000);
	set("str", 22);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/xingxiu/obj/huamao2",
		"/d/xingxiu/obj/huamao1",
		"/d/xingxiu/obj/huamao3",
	}) );

	setup();
	add_money("coin", 100);
}

void init()
{	
	object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");

	if( interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	string msg;
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender") == "女性") {
		if(ob->query("age") < 20) msg = "森能尔";
		else if(ob->query("age") < 30) msg = "阿恰";
		else msg = "阿尼卡";
	}
	else {
		if(ob->query("age") < 20) msg = "扶康";
		else msg = "阿抗";
	}
	say ("爱西翰微微躬身，说道：您好，"+msg+"。\n");
	return;
}
