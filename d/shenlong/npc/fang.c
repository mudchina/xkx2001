//Cracked by Roath
// fangyi.c  方怡

inherit NPC;
// inherit F_MASTER;

int do_work();
string *fjob = ({"毒蛇", "蟒蛇", "腹蛇", "金环蛇", "水蛇", "银环蛇", "竹叶青"});

void create()
{
	set_name("方怡", ({ "fang yi","fang" }));
//      set("nickname", "");
	set("long",
		"一张瓜子脸，容貌甚美。\n");
	set("gender", "女性");
	set("age", 18);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 23);
	set("int", 25);
	set("con", 25);
	set("dex", 26);
	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("jingli", 600);
	set("max_jingli", 600);
	set("jiali", 30);
	set("combat_exp", 50000);
//      set("score", 50000);
//      set("shen", -3000);

	set_skill("force", 30);
	set_skill("dulong-dafa", 20);
	set_skill("dodge", 40);
	set_skill("lingshe-shenfa", 60);
	set_skill("strike", 30);
	set_skill("kick", 30);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("jueming-tui", 40);
	set_skill("literate", 40);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("kick", "jueming-tui");

	prepare_skill("kick", "jueming-tui");

	create_family("神龙教", 3, "赤龙门弟子");

        set("inquiry", ([
                "教主" : (: do_work :),
                "神龙教" : (: do_work :),
                "jiao" : (: do_work :),
        ]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhou/obj/qun")->wear();

}

void init()
{
        add_action("do_comfort", "comfort");
}


int do_work()
{
        object me = this_player();
        string fword, fwant;

        if( !me->query("sg/spy") ) {
                say("方怡哼了一声说：假仁假义的东西，还不给我滚！\n");
                return 1;
        }

        if( me->query_temp("marks/方a") ) {
                say("方怡不耐烦地说道：有完没完了？\n");
                return 1;
        }

        if( time() < me->query("marks/方c") + 180 ) {
                command("slap " + me->query("id"));
                say("方怡大怒道：蠢猪，这么快就忘了！\n");
                return 1;
        }

        me->set_temp("marks/方a", 1);
        me->set("marks/方c", time());

        fwant = fjob[random(sizeof(fjob))];
        fword = sprintf("方怡叹了口气，说道：奉教主之命，捉%s来配药。\n", fwant);
        say(fword);
        me->set_temp("marks/毒蛇", fwant);
        return 1;
}

int do_comfort(string arg)
{
        object me = this_player();

        if( !arg || !(arg == "fang yi" || arg == "fang") )
                return notify_fail("");

        message_vision("$N笑嘻嘻地安慰着方怡。\n", me);

        if( !me->query_temp("marks/方a") )  {
                say("方怡冷笑道：别假惺惺了。\n");
                return 1;
        }

        me->delete_temp("marks/方a");

        message_vision("$N道：方姑娘，请放心！我这就给你去抓。\n", me);
        command("thank " + me->query("id"));
        me->set_temp("marks/方b", 1);

        return 1;
}

int accept_object(object who, object ob)
{
        int expgain, faccept;

        if( !who->query("marks/方b") )
                return 0;

        if( ob->query("name") != who->query_temp("marks/毒蛇") ) {
                command("angry " + who->query("id"));
                command("disapp " + who->query("id"));
                return 0;
        }

        who->delete_temp("marks/方b");
        who->delete_temp("marks/毒蛇");

        call_out("destroy_it", 1, ob);

        command("jump " + who->query("id"));
        command("secret " + who->query("id"));

        message_vision("方怡在$N耳边悄悄的说了几句话。\n", who);
        if( who->query_skill("medicine", 1) < 30 )
                 who->improve_skill("medicine", random(2 * who->query("int")));

        if( (expgain = who->query("combat_exp")) > 50000 )
                 return 1;

        who->add("sg/exp", 1);
        expgain = (50000 - expgain) / 200;
        who->add("combat_exp", expgain + random(expgain));

        return 1;              
}

void destroy_it(object ob)
{
        if(ob)
        destruct (ob);
}
