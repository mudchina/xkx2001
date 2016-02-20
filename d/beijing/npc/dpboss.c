//Cracked by Roath
// dpboss 当铺老板 
// Ssy

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("当铺老板", ({ "dangpu boss", "boss" }));
        set_color("$YEL$");
	set("shen_type", 0);

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"一个肥胖汉子。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set("jing", 100000);
	set("max_jing", 100000);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
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
	message_vision("\n突然，只见$N闪身拉开柜台下一道暗门，钻了进去，咔嚓从里边把门锁上了。\n",
		this_object());
	destruct(this_object());
}



