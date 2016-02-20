//Cracked by Roath
#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("老朝奉", ({ "lao chaofeng", "chaofeng" }));
        set_color("$YEL$");
//	set("title", "当铺老板");
	set("shen_type", 0);

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("max_jing", 10000);
	set("jing", 10000);
	set("age", 35);
	set("long",
		"一个衣着光鲜的老朝奉。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
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

void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
//        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

