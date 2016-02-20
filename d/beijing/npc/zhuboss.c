//Cracked by Roath
// zhuseller 杨掌柜

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
	set_name("杨掌柜", ({ "yang zhanggui", "yang" }));
        set_color("$YEL$");
	set("title", "珠宝店掌柜");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 35);
	set("long", "杨掌柜一副精明能干的样子，各式金银珠宝他一眼便能说出价钱来。\n");
	set("combat_exp", 20000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		  "/d/city/obj/mirror",
		  "/d/city/obj/pring",
                  "/d/city/obj/necklace",
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

        command("say 欢迎光临，这位"+RANK_D->query_respect(ob)+"请随便参观。小店保证货真价实。");
}
