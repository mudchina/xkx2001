//Cracked by Roath
// xian. 冼老板

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
// inherit F_DEALER;

string ask_me();

void create()
{
        set_name("冼老板", ({ "xian laoban", "xian" }));
        set_color("$YEL$");
        set("title", "醉仙楼老板");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", 45);
        set("long", "洗老板经营祖传下来的醉仙楼已有多年。\n");
        set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
                __DIR__"obj/hdjiudai",
                __DIR__"obj/kaoya",
                __DIR__"obj/nuerhong",
                __DIR__"obj/ham",
                "/d/city/obj/yrou",
                "/d/city/obj/thfish",
                "/d/city/obj/santaoya",
        }));
        set("inquiry", ([
            "喜宴" : (: ask_me :),
            "喜酒" : (: ask_me :),
            "办喜宴" : (: ask_me :),
            "办喜酒" : (: ask_me :),
            "办酒席" : (: ask_me :),
        ]) );
                
        setup();
        add_money("gold", 1);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

int ask_me()
{
        object me, bride, *players;
        
        if (query_temp("busy")) {
                write("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");
                return 1;
        }
                                
        me = this_player();
        
        if( objectp(me->query_temp("marriage/accept")) ) {
                message_vision(CYN "$N笑眯眯地对$n说：新娘子怎么跑来了? 新郎官儿哪儿去了? \n" NOR,
                        this_object(), me);
                return 1;
        }       
        
        if( objectp(me->query_temp("marriage/ring")) ) {
                message_vision(CYN "$N笑眯眯地对$n说：喜酒都喝了，赶紧买戒指吧！\n" NOR,
                        this_object(), me);
                return 1;
        }       
                        
        if( !objectp(bride = me->query_temp("marriage/banquet")) ) {
                message_vision(CYN "$N笑眯眯地对$n说：办喜酒那可是俩个人的事。\n" NOR,
                        this_object(), me);
                return 1;
        }
                
        if( !objectp(present(bride, environment(me))) ) {
                message_vision(CYN "$N笑眯眯地对$n说：怎么不见新娘子? \n" NOR,
                        this_object(), me);
                return 1;
        }
        
        switch (MONEY_D->player_pay(me, 100000)) {
        case 0:
                message_vision(CYN "$N笑眯眯地对$n说：你先把钱准备好，我立刻就办！\n" NOR,
                        this_object(), me);
                return 1;
        default:
                set_temp("busy", 1);
                message_vision(CYN "$N笑眯眯地点点头说：我这就给你们办！\n" NOR,
                        this_object(), me);
                command("chat " + me->name() + "与" + bride->name() + 
                        "今日喜结良缘，醉仙楼上大开喜宴，还望各位赏光！");      
                log_file("test/marry",
                         sprintf("%s %s married %s %s on %s\n", me->name(), me->query("id"), bride->name(), bride->query("id"), ctime(time())));

                players = users();
                map_array(players, (: new(__DIR__"obj/kaoya")->move($1) :) );
                map_array(players,
                        (: tell_object($1, HIM"你得到一只烤鸭。\n"NOR) :) );
                map_array(players, (: new(__DIR__"obj/nuerhong")->move($1) :) );
                map_array(players,
                        (: tell_object($1, HIM"你得到一瓶女儿红。\n"NOR) :) );
                me->delete_temp("marriage/banquet");
                me->set_temp("marriage/ring", bride);
                bride->delete_temp("marriage/accept");
                bride->set_temp("marriage/ring", me);
        }        
                        
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);
        return 1;
}
int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
