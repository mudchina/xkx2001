// cunzhang.c

inherit NPC;
//inherit F_SKILL;
int zao(string msg);
int xiu(string msg);
int chai();

void create()
{
	set_name("桃花村长", ({ "cun zhang", "zhang" }));
	set("gender", "男性");
	set("age", random(10) + 40);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "他是桃花村长，谁想在桃花村造屋安家，都要经过他老人家的
同意。他是个面目慈善的老汉。很得全村人的尊重。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	set("inquiry", ([
		"造屋" : "造屋就是 (zao 屋名 屋子说明) 就可以了。\n",
		"修屋" : "如果对屋子陈设不满意了，(xiu 新屋名 屋子新描述) 就会重新装修了。\n",
		"拆屋" : "不想要房子了或钥匙丢了就(chai)吧。\n",
	]));

	setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob=this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("zao","zao");
	add_action("xiu","xiu");
	add_action("chai","chai");
}

void greeting(object ob)
{
	if (ob->query("age")>17)
say ("村长笑咪咪地说：这位"+RANK_D->query_respect(ob) + "，欢迎到桃花村来。
你可以造屋(zao)，也可以修改屋里的装修(xiu)，如果丢了钥匙
就得拆除房屋(chai)了。屋内装修该换行的地方请用 $ 代替。\n");
        else
say ("村长笑咪咪地说：这位"+RANK_D->query_respect(ob) + "，还不够年龄修造自己的房子呢。\n");
        return;
}

int zao(string msg)
{
	object obj, ob = this_player();
	string homename, homedesc, tmpdesc;

	if (ob->query("age")<17)
	{
		write("\n村长说道：你还没成人呢，不能造私宅的。\n");
		return 1;
	}
	if (ob->query("home") )
	{
		write("\n村长说道：你在已经本村有房屋了，不能再造了。\n");
		return 1;
	}
	if( !msg ) return notify_fail("你要造什么东西？\n");
	if( sscanf(msg ,"%s %s" ,homename, tmpdesc) != 2)
		 return notify_fail("zao 屋名 屋中陈设说明\n");
	homedesc = replace_string(tmpdesc, "$", "\n");
	ob -> set("home/home_name", homename);
	ob -> set("home/home_desc", homedesc);
	ob -> save();
        obj = new("/d/taohuacun/obj/key");
	obj -> move(ob);
	write("\n村长说道：我马上派人去桃花坪帮你造屋，这是钥匙，你
退出游戏后再连进来就可以去看看了。\n");
	return 1;
}

int xiu(string msg)
{
	object obj, ob = this_player();
	string homename, homedesc, tmpdesc;

	if (!ob->query("home") )
	{
		write("\n村长说道：你在本村根本没有房屋了，修什么修？\n");
		return 1;
	}
	if( !msg ) return notify_fail("你要修什么东西？\n");
	if( sscanf(msg ,"%s %s" ,homename, tmpdesc) != 2)
		 return notify_fail("xiu 新屋名 屋中陈设的新说明\n");
	homedesc = replace_string(tmpdesc, "$", "\n");
	ob -> set("home/home_name", homename);
	ob -> set("home/home_desc", homedesc);
	ob -> save();
	write("\n村长说道：我马上派人去桃花坪帮你改装房屋，你马上就可以去看看了。\n");
	return 1;
}

int chai()
{
	object ob = this_player();
	ob->delete("home");
	write("\n村长说道：好吧，你这里的房屋我已经派人去拆了。\n");
	return 1;
}
