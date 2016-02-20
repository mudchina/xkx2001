//Cracked by Roath
// sun. 孙老板

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
	set_name("孙老板", ({ "sun laoban", "sun" }));
        set_color("$YEL$");
	set("title", "天宝阁老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 20);
	set("long", "孙老板一手创办的天宝阁在扬州可是大大的出名。\n");
	set("combat_exp", 10000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		__DIR__"obj/changchun",
	}));
            	
	setup();
        add_money("silver", 20);
	add_money("coin", 100);
}

void init()
{
	object ob;

        ::init();
        if ( interactive(ob=this_player()) ) {
                remove_call_out("greeting");
		call_out("greeting", 1, ob);
        }

        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("say 欢迎光临，这位"+RANK_D->query_respect(ob)+"请随便参观。");
}

int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
