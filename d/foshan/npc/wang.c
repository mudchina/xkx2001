//Cracked by Roath
inherit NPC;
inherit F_DEALER;
string ask_me(object who);

void create()
{
	int skill = random(2);
	set_name("王老汉", ({ "wang laohan", "wang", "laohan" }));
	set("shen_type", 0);

	set("str", 30);
	set("con", 30);
	set("dex", 18);
	set("gender", "男性");
	set("age", 55);
	set("long",
		"他是一个头发花白的老头，忙着烤烧饼，头也不抬。\n");
	set("combat_exp", 400000 + 100000*skill); //Ryu: random its skill to give highhand some risk if wants to get the cake.
	set("PKS", 1000000);     //RYU: to avoid cake being begged away.
        set("max_qi", 1000);
        set("max_jing", 8000);    //RYU: to avoid cake being stolen away.
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set_skill("force", 110+skill*10);
	set_skill("huntian-qigong", 100+skill*10);
	set_skill("xiaoyaoyou", 100+skill*10);
	set_skill("club", 100+skill*10);
	set_skill("shexing-diaoshou", 100+skill*10);
	set_skill("hand",100+skill*10);
        set_skill("dodge", 100+skill*10);
        set_skill("parry", 100+skill*10);
	set_skill("san-sword", 120+skill*10);

	map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "shexing-diaoshou");
	map_skill("club", "san-sword");

        prepare_skill("hand", "shexing-diaoshou");

	set("attitude", "friendly");
	set("env/wimpy",70);

	set("inquiry", ([
		"玄铁令" : "啊……没听说过。\n",
		"谢烟客" : "听说是个功夫奇高的怪人。\n",
		"烧饼" : "我的烧饼又好吃又便宜的。\n",
		"油条" : "我的油条又好吃又便宜的。\n",
		"吴道通" : (: ask_me :),
	]));
	
	set("vendor_goods", ({
		__DIR__"obj/shaobing",
		__DIR__"obj/youtiao",
	}));

	setup();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
	::init();
	if (!query("asked")) {
        add_action("do_list", "list");
        add_action("do_sale", "buy");
	}
}

int do_sale(string arg)
{
        int value, val_factor;
        string ob_file, file;
        object ob, obj;

	if (query("asked"))
		return notify_fail("老子既然被人认出来了，就不在这装孙子卖烧饼油条了！\n");

        if (!arg)
                return notify_fail("你想买什么？ \n");
        else if ((ob_file = is_vendor_good(arg)) == "")
                return notify_fail("你想买的东西我这里没有。\n");

	ob = new(ob_file);

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");


        switch (MONEY_D->player_pay(this_player(), ob->query("value") *  val_factor / 10)) {
        case 0:
					 return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
                file = resolve_path(this_object()->query("cwd"), arg);
                set_temp("busy", 1);
					 message_vision("$N从$n那里买下了一" + ob->query("unit") +
                ob->query("name") + "。\n", this_player(), this_object());
					 ob->add("quantity", -1);
                if (ob->query("quantity") < 1){
                ob->move(this_player());
                }
                else {
                file = base_name(ob) + ".c";
                obj = new(file);
                obj->move(this_player());
                }
        }
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}


string ask_me(object who)
{
        int i;
	object cake;
	if (query("asked")) return ("少废话！\n");

		  if( (random(10) < 5) || is_fighting() )
					 return "我…不知道。\n";

		  message("vision",
		"王老汉道：你既然知道老子的名字，就该对我尊重些！纳命来吧！\n"
					 "吴道通大喝一声，叫道：“既然如此，老子今天反正豁出去，跟你拼了。”\n"
					 "吴道通取出一副判官笔握在手中。\n" ,
					 environment(), this_object() );

		  set("attitude", "aggressive");
	remove_action("do_buy", "buy");
		  remove_action("do_list","list");
		  set_name("吴道通", ({ "wu daotong", "wu", "daotong" }));
	kill_ob(this_player());
	//command("follow " + this_player()->query("id"));
		  carry_object("/clone/weapon/panguanbi")->wield();
	if (random(15)==1) cake = new(__DIR__"obj/shaobing2");
	else cake = new(__DIR__"obj/shaobing");
	cake->move(this_object());
	set("asked",1);
		  return "你既然知道老子的名字，就该对我尊重些！纳命来吧！\n";
}

void unconcious()
{
	object ob = this_object();
	object cake;

		  message_vision("\n突然，只见$N掏出一张烧饼吞进肚里！\n",
					 ob);
	if (cake = present("shaobing",ob)) destruct(cake);
//	ob->die();
	ob->disable_player(" <昏迷不醒>");
		  ob->set("jing", 0);
        ob->set("qi", 0);
		  COMBAT_D->announce(ob, "unconcious");

        call_out("revive", random(100 - query("con")) + 30);

}


varargs void revive(int quiet)
{
        remove_call_out("revive");
        while( environment()->is_character() )
                this_object()->move(environment(environment()));
        this_object()->enable_player();
        COMBAT_D->announce(this_object(), "revive");
}



