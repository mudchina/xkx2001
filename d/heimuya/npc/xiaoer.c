//Cracked by Roath
// xiaoer.c

#include <ansi.h>

inherit NPC;

string ask_me(string, object);

void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");

        set("chat_chance", 3);
        set("chat_msg", ({
                "店小二道：客官，如果你想知道详情的话，问我可是找对人了！ 不过， 嘻嘻嘻 ... \n",
                "店小二道：这阵子本店生意好做得很， 南来北往的大爷们随便赏小的们几个钱，都有得花了！\n",
        }) );

        set("inquiry", ([
                "黑木崖"   : (: ask_me, "heimuya" :),
                "黑木林" : "唉，北边的不远有个黑木林，以前有很多樵夫去伐木却再也没有回来过。\n",
                "日月教"   : (: ask_me, "ryj" :),
                "日月神教"   : (: ask_me, "rysj" :),
                "rumors" : (: ask_me, "yaoyan"  :),
                "here" : (: ask_me, "fengtu"  :),
        ]));

        setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 500) 
        {
                tell_object(who, "小二一哈腰，说道：多谢您老，小的给您头前引路，客官这就请上楼歇息。\n");
                who->set_temp("rent_paid",1);
                set_temp("leading", 1);
                remove_call_out("do_up");
                call_out("do_up", random(5), this_object(), who);
                return 1;
        }

        else if (ob->query("money_id") && ob->value() >= 10) 
        {
                tell_object(who, "小二忙堆起笑容，说道：多谢您老，有什么话，您尽管问！。\n");
                who->set_temp("ready_ask",1);
                return 1;
        }

        return 0;
}

string ask_me(string name, object ob)
{
        if ( name == "heimuya" )
        command("fear");

        if ( name == "ryj" )
        command("fear");

        if ( name == "rysj" )
        command("fear");

        if ( name == "yaoyan" )
        command("shake2");

        if ( name == "fengtu" )
        command("smile2");

        return 0;
}

int accept_kill(object obj)
{
        command("chat 各位客官救命啊！ " + obj->name() + "这个" + RANK_D->query_rude(obj
) + "要杀了我！");
}

void do_up(object me, object who)
{
        who->set_leader(me);
        command("go up");                        
        
        tell_object(who, "小二笑嘻嘻地说：客官您算找对地方了，我们这儿是本地最干净的客店。
小二边说边从腰间摘下一大串钥匙，找出一把来给你开门。\n");

        remove_call_out("do_enter");
        call_out("do_enter", random(5), me, who);
}

void do_enter(object me, object who)
{
        who->set_leader(me);
        command("go enter");
        
        tell_object(who, "小二对你笑笑，说：这房间很不错吧!
客官您好好休息，小的去忙了，有什么事尽管吩咐。\n");

        who->set_leader(0);
        command("go out");
        command("go down");
        me->set_temp("leading", 0);
}
