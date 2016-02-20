//Cracked by Roath
inherit NPC;
inherit F_DEALER;
string ask_me(object who);

void create()
{
	set_name("王老汉", ({ "wang laohan", "wang", "laohan" }));
	set("shen_type", 0);

	set("str", 30);
	set("con", 30);
	set("dex", 18);
	set("gender", "男性");
	set("age", 55);
	set("long",
		"他是一个头发花白的老头，忙着烤烧饼，头也不抬。\n");
	set("combat_exp", 400000);
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set_skill("force", 110);
	set_skill("huntian-qigong", 100);
	set_skill("xiaoyaoyou", 100);
	set_skill("club", 100);
	set_skill("shexing-diaoshou", 100);
	set_skill("hand",100);
        set_skill("dodge", 100);
        set_skill("parry", 100);

	map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "shexing-diaoshou");

        prepare_skill("hand", "shexing-diaoshou");

	set("attitude", "friendly");
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
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string ask_me(object who)
{
        int i;
	object cake;
        if( (random(10) < 5) || is_fighting() )
                return "我…不知道。\n";

        message("vision",
		"王老汉道：你既然知道老子的名字，就该对我尊重些！纳命来吧！\n"
                "吴道通大喝一声，叫道：“既然如此，老子今天反正豁出去，跟你拼了。”\n" 
                "吴道通取出一副判官笔握在手中。\n" ,
                environment(), this_object() );

        set("attitude", "aggressive");
        set_name("吴道通", ({ "wu daotong", "wu", "daotong" }));
	kill_ob(this_player());
        carry_object("/clone/weapon/panguanbi")->wield();
	cake = new(__DIR__"obj/shaobing2");
	cake->move(this_object());
        return "你既然知道老子的名字，就该对我尊重些！纳命来吧！\n";
}

void unconcious()
{
	object ob = this_object();
	object cake;

        message_vision("\n突然，只见$N掏出一张烧饼吞进肚里，随即钻地道跑了！\n",
                ob);
	if (cake = present("shaobing",ob)) destruct(cake);
	ob->unconcious();
}

void die()
{
        object ob = this_object();
        object cake;

        message_vision("\n突然，只见$N掏出一张烧饼吞进肚里，随即钻地道跑了！\n",
                ob);
        if (cake = present("shaobing",ob)) destruct(cake);
        destruct(ob);
}

	

