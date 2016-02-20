//Cracked by Roath
// song.c 宋老板

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
	set_name("宋老板", ({ "song laoban", "song"}));
	set_color("$YEL$");
	set("title", "太和居老板");
	set("shen_type", 1);
	set("str", 20);
	set("gender", "男性");
	set("age", 55);
	set("long", "　　宋老板看上去一副精明强干的样子。\n");
	set("combat_exp", 60000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set("vendor_goods", ({
		"d/city/obj/hdjiudai",
		"d/dali/obj/qiguoji",
		"d/dali/obj/guoqiao",
		}));
	setup();
	carry_object("/d/city/obj/xiupao")->wear();            
	add_money("gold", 1);
}
void init()
{
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
int accept_kill(object me)
{
	command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
	me->apply_condition("killer", 100);
	kill_ob(me);
	return 1;
}
