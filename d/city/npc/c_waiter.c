//Cracked by Roath
// c_waiter.c 茶馆小二
// xQin 6/00

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("茶馆小二", ({ "chaguan xiaoer", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位茶馆小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("no_get", "1");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ({
        	__DIR__"tea/qimen_hongcha",
        	__DIR__"tea/tie_guanyin",
        	__DIR__"tea/wuyi_yancha",
        	__DIR__"tea/xinyang_maojian",
        	__DIR__"tea/maojian",
        	__DIR__"tea/yinzhen",
        	__DIR__"tea/guapian",
        	__DIR__"tea/maofeng",
        	__DIR__"tea/longjing",
                __DIR__"tea/biluo_chun",
                __DIR__"obj/baozi",
                __DIR__"obj/gaodian",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "丐帮" 
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "茶馆小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，有什么吩咐？\n");
                        break;
                case 1:
                        say( "茶馆小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，我们这都是极品好茶，您要点什么？\n");
                        break;
        }
}

