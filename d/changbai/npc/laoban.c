//Cracked by Roath
// laoban.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("酒馆老板", ({ "lao ban"}) );
	set("gender", "男性" );
	set("age", 50);
	set("long",
		"这是一个鲜族人，头缠一条白毛巾，满脸带着笑容。\n");

	set("combat_exp", 3000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");

	set("vendor_goods", ({
                "/d/changbai/obj/cbs_map",
		"/d/changbai/obj/grtang",
                "/d/changbai/obj/gourou",
	}) );

	setup();

        carry_object("clone/misc/cloth")->wear();
	add_money("silver", 2);
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

        say("酒馆老板得意的说道：“这么冷的天，喝碗狗肉汤是最能暖和身子的！\n");
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        say("\n酒馆老板大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/changbai/nancheng");
        message("vision","只听“乒”地一声，" +  ob->query("name") +
                "被人从香肉馆里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}

int accept_kill(object obj)
{
        command("chat 各位客官救命啊！ " + obj->name() + "这个" 
        + RANK_D->query_rude(obj) + "要杀了我！");
}
