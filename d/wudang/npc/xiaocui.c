//Cracked by Roath
// d/wudang/npc/xiaocui.c
// By Marz 04/01/96

inherit NPC;


void create()
{
	set_name("小翠", ({"cui", "xiao cui"}) );
	set("nickname", "伺茶道童");
	set("gender", "女性" );
	set("age", 12+random(6));
	set("long",
	  "这是个年年龄不大的小姑娘，但宽松的道袍也遮不住她过早发育的身体。\n"
	  "一脸聪明乖巧，满口伶牙俐齿。见有人稍微示意，便过去加茶倒水。\n");
	set("attitude", "friendly");
    set("shen_type", 1);

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

		set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("武当派", 5, "弟子");

        set("inquiry", ([
            "女儿香" : "这「女儿香」珍贵得很，连宋大侠的儿子也不能随便喝着．\n"
            	+ "不过如果你能从西面茶园老张那里弄些「女儿香」茶叶来，\n"
            	+ "我倒是可以为你沏一壶。他见你从我这儿去，大概不会难为你\n",
        ]));

        setup();
        
		carry_object("/d/wudang/obj/greenrobe")->wear();
		carry_object("/d/city/obj/necklace");
}

void init()
{	
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	say("小翠笑吟吟地说道：这位" + RANK_D->query_respect(ob)
	     + "请先入座，" + "我这就给您上茶。\n");
}

int accept_object(object who, object ob)
{
	object obn;
	
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。");

	if (  (string)ob->query("name") == "茶叶"
		|| (string)ob->query("name") == "金项链"  ) 
	{
		if ( (string)ob->query("name") == "金项链" ) 
		{
			command("kiss " + (string)who->query("id")); 
			command("wear lace");
		}

		if ( who->query_temp("marks/sit") )
		{
			if ((int)who->query_temp("tea_cup") > 0)	
	   		{
				command("smile " + who->query("id"));
				} else
			{
				say("小翠作了个揖道：" + RANK_D->query_respect(who)
					+ "请稍候，小女子这就给您换香茶。\n");
			}

			who->set_temp("tea_cup", 5);
			remove_call_out("serve_tea");
			call_out("serve_tea", 1, who);

		} else 
		{
			who->set_temp("tea_cup", 5);
	    	say("小翠道了个万福：" + RANK_D->query_respect(who)
	       	+ "请先入上座，小女子这就给您去泡香茶。\n");
		}

		return 1;
	}

	if ((string)ob->query("name") == "「女儿香」茶叶") 
	{
		if ( who->query_temp("marks/sit") )
		{
			command("dance " + who->query("id"));
		} else 
		{
			message_vision("小翠引$N到窗边风景最好的桌边坐下．\n", who);
		}
		
		who->set_temp("tea_cup", 10);
		who->set_temp("marks/sit", 1);
	 	obn = new(__DIR__"../obj/nuerxiang");
		obn->move(who);

		return 1;
	}


	command("? " + who->query("id"));
	command("smile cui");
	return 0;
}


void serve_tea(object who)
{
	object obt, obc, obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

	if ( (int)who->query_temp("tea_cup") <= 0 )
	{
		if (objectp(obt = present("wan", environment())))
			destruct(obt);
		
	 	obn = new("d/wudang/obj/dawancha");
		obn->move(room);
		message_vision("小翠搬出个大茶壶来，将桌上的大碗茶倒满．\n",
			who);
	} else 
	{
		who->add_temp("tea_cup", -1);
	 	obn = new("d/wudang/obj/xiangcha");
		obn->move(room);
		message_vision("小翠拿出个绍兴小茶壶，沏了杯香茶，放在桌上．\n",
			who);
	}

	if (!present("tao", environment()))
	{
 		obn = new("d/wudang/obj/mitao");
		obn->move(room);
		message_vision("小翠拿出一碟新鲜的水蜜桃，放在桌上．\n", who);
	}
	
	return;
}
