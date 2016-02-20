//Cracked by Roath
// dealer.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("阿密特", ({ "amite", "seller", "man" }) );
	set_max_encumbrance(100000000);
	set_color("$YEL$");
	set("title", "回族商人");
	set("gender", "男性" );
	set("age", 30);
	set("long", "一位时常在巴扎交易货物的年青商人，你可以找他买卖各种商品。\n阿密特是回人最常用的男人名字。\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("no_get_from", 1);
	set("no_get", 1);
	set("str", 22);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("dealer", 1);
	set("attitude", "friendly");
	setup();
}

void init()
{
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void unconcious()
{
	message_vision("\n阿密特仓惶地逃入巴扎的人群中，很快地在人潮中不见了。\n", this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n阿密特仓惶地逃入巴扎的人群中，很快地在人潮中不见了。\n", this_object());
	destruct(this_object());
}