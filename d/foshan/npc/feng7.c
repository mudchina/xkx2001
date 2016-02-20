//Cracked by Roath

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("凤七", ({ "feng qi", "feng" }));
	set("title", "酒楼老板");
	set("shen_type", -1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"凤七是凤天南的远房祖弟，在这英雄楼当掌柜。武功没有什么，为人却极是机灵。\n");

	set("combat_exp", 200);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		"/d/city/obj/kaoya",
		"/d/city/obj/tofu",
		"/d/city/obj/peanut",
		"/d/city/obj/jiudai",
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
	say("凤七笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
		"，快请进来。\n");
}
