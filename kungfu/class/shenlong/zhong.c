//Cracked by Roath
// bailong shi 白龙使
// ALN Sep / 97

inherit NPC;

// int auto_perform();
string ask_ob(string);
void apply_gift(object, int);

void create()
{
	set_name("钟志灵", ({ "zhong zhiling","bailong shi", "shi","zhong" }));
	set("nickname", "白龙使");
	set("long",
		"魁梧大汉，一看就知是关东人。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 32);
	set("int", 26);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jingli", 1200);
	set("max_jingli", 1200);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 50000);
	set("shen", -20000);

	set_skill("force", 100);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 80);
	set_skill("lingshe-shenfa", 80);
	set_skill("strike", 100);
	set_skill("huagu-mianzhang", 80);
	set_skill("parry", 90);
	set_skill("hook", 150);
	set_skill("ruyi-gou", 100);
//	set_skill("digging", 80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("hook", "ruyi-gou");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教", 2, "使者");
/*
        set("chat_chance", 20);
        set("chat_msg_combat",({
                (:auto_perform:),
        }));
*/
        set("inquiry", ([
                "神龙教" : (:ask_ob, "jiao":),
                "洪安通" : "这三个字是你说的吗？",
                "洪教主" : "洪教主仙福永享，寿与天齐，洪教主神目如电，烛照四方。",
                "豹胎易筋丸" : (:ask_ob, "wan":),
                "效命"   : (:ask_ob, "task":),
                "任务"   : (:ask_ob, "task":),
                "功劳"  : (:ask_ob, "exp":),
                "苏荃"   : "没规没矩的。",
                "胖头陀" : (:ask_ob, "pang":),
                "夫人" : (:ask_ob, "su":),
                "陆高轩" : (:ask_ob, "lu":),
                "陆大夫" : (:ask_ob, "lu":),
                "神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
        ]));

	setup();

	carry_object("/clone/weapon/hook")->wield();
	carry_object("/clone/misc/cloth")->wear();        
}

void init()
{
        ::init();

        add_action("do_leave", "leave");
}

int do_leave(string arg)
{
        if( !arg || arg != "shenlong"
        ||  !this_player()->query_temp("zhong/nod") )
                return 0;

        if( this_object()->is_fighting() || this_object()->is_busy() )
                return notify_fail("你没见我正忙着？\n");

        this_player()->delete("sg");
        this_player()->delete("sgjob");
        this_player()->delete("yijin_wan");
        this_player()->set("sg/cured", 1);
        apply_gift(this_player(), 0);

        command("congra " + this_player()->query("id"));
        message_vision("$N从衣袋里掏出一粒药丸塞进了$n的嘴里。\n", this_object(), this_player());
        command("say " + "望你日后在江湖上好自为之吧。");
        command("bye " + this_player()->query("id"));
        call_out("destroy_zhong", 1, this_object());
        return 1;
}

void destroy_zhong(object zhong)
{
        if( !zhong ) return;

        message("vision",
                zhong->name() + "一转眼便消失了。\n",
                environment(zhong), ({zhong}));

        destruct(zhong);
}

string ask_ob(string arg)
{
        if( this_player()->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !this_player()->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！";

        return "关于教中的详情，你去问胖头陀或瘦头陀。";
}

void apply_gift(object me, int flag)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex;
        mapping my = me->query_entire_dbase();

        tmpstr = tmpint = tmpcon = tmpdex = 10 + flag;

        for (i = 0; i < 40; i++) {
                switch (random(4)) {
                        case 0: tmpstr++; break;
                        case 1: tmpint++; break;
                        case 2: tmpcon++; break;
                        case 3: tmpdex++; break;
                }
        }

        if (tmpstr <= 30) my["str"] = tmpstr;   else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint;   else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon;   else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex;   else my["dex"] = 30;
}






