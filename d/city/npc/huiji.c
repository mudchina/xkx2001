//Cracked by Roath
// huoji. 药铺伙计

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		__DIR__"obj/jinchuang",
		__DIR__"obj/sheyao",
		__DIR__"obj/yangjing"
	}));

	setup();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
