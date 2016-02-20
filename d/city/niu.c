//Cracked by Roath
// niu. 牛掌柜

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
        set_name("牛掌柜", ({ "niu zhanggui", "niu" }));
        set_color("$YEL$");
        set("title", "聚金阁掌柜");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", 35);
        set("long", "牛掌柜一副精明能干的样子，各式金银珠宝他一眼便能说出价钱来。\n");
        set("combat_exp", 20000);
        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
                  __DIR__"obj/mirror",
                  __DIR__"obj/pring",
                  __DIR__"obj/ring-perl",
                  __DIR__"obj/ring-ivory",
                  __DIR__"obj/ring-jade",
                  __DIR__"obj/ring-silver",
                  __DIR__"obj/ring-iron",
                  __DIR__"obj/necklace",
                  __DIR__"obj/necklace-silver",
                  __DIR__"obj/necklace-amber",
                  __DIR__"obj/necklace-ivory",
                  __DIR__"obj/necklace-perl",
                  __DIR__"obj/earring-amber",
                  __DIR__"obj/earring-ivory",
                  __DIR__"obj/earring-jade",
                  __DIR__"obj/earring-perl",
                  
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

int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
