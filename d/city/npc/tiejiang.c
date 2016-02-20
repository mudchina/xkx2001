//Cracked by Roath
// seller.c
// ryu added garbage collecting on 3/20/1997
// Mongol modifed him to be a charactor of Jin's novels.
// xbc added remove 铁链 on 1/21/99

inherit NPC;
inherit F_VENDOR;
int do_sell(string);
int do_removelian(string);
string ask_liancost();
void create()
{
	set_name("王铁匠", ({ "wang tiejiang", "wang" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long",
		"他打着赤膊，结实的肌肉高高愤起，两鬓微白，显然经历风霜，饱尝冷暖。"
		+ "\n他原是洞庭湖一带的一个铁匠，在程灵素的帮助下报了对姜铁山夫妇的仇，逃到这里。\n");
	set("combat_exp", 3000);
        set("str", 25);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/weapon/caidao",
		"/clone/weapon/tiebang",
		"/clone/weapon/dafu",
		"/d/taohua/obj/xiaotiefu",
	}) );
        set("inquiry", ([
		"姜铁山" : "姜铁山逼老子给他造铁屋，还打断老子三根肋骨，狗娘养的！",
		"薛鹊" : "姜铁山的老婆。\n",
		"铁屋" : "在洞庭湖畔。\n",
                "洞庭湖" : "我可不回去了。\n",
		"程灵素" : "程姑娘可是天下第一好人。\n",
		"铁链" : "想拿掉铁链？可得化一番功夫（ask 铁链价钱）。\n",
                "铁链价钱" : (:ask_liancost:),
	]));	

	set("chat_chance", 5);
        set("chat_msg", ({
	"王铁匠唱道：小妹子待情郎 —— 恩情深。\n",
	"王铁匠唱道：你莫辜负了妹子 —— 一段情。\n",
        "王铁匠唱道：你见她面时 —— 要待她好。\n",
        "王铁匠唱道：你不见她面时 —— 天天要十七八遍挂在心！\n",
        }) );

	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("unarmed", 30);
	
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 200);
}

void init()
{
	object ob;

        ::init();
	if ( interactive(ob=this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

        add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
	add_action("do_removelian", "removelian");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say 欢迎这位"+RANK_D->query_respect(ob)+"光临，请随便参观。");
}
int do_sell(string arg)
{
    object ob;

	if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要卖什么？\n");

	if (ob->query("material") != "steel" && ob->query("material") != "iron")
		return notify_fail("我这里只收废铁。\n");

	else {
                message_vision("$N卖掉了一" + ob->query("unit") +
                ob->query("name") + "给$n。\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), ob->query_weight()/70);
                        destruct(ob);
        }
        return 1;
}

int do_removelian(string arg)
{
        object ob;
	object me = this_player();

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要拿掉什么？\n");

	if (ob->query("name") != "铁链" && ob->query("id") != "tie lian") 
                return notify_fail("这个我不会拿。\n");

	if (!me->query_temp("lianpaid"))
		return notify_fail("这个，要花好一笔钱的（ask liancost）。\n");

        else {
                message_vision("$n把$N拉到旁边敲敲打打了好一阵，终于拿掉了铁链。"+
			"$N痛得昏了过去。\n", 
			this_player(), this_object());
                destruct(ob);
		me->delete_temp("liancost");
		me->delete_temp("lianpaid");
		me->unconcious();
        }
        return 1;
}

string ask_liancost()
{
	object me = this_player();
	int liancost;

	liancost = me->query("PKS");
	me->set_temp("liancost", liancost);

	return "这件事可要小心才行。这样吧，你给我 " + liancost +
		" 两黄金，我偷偷帮你拿掉。\n";

}

int accept_object(object who, object ob)
{

        if (!ob->query("money_id")) {
                command(":(");
                command("say 这个，给我做什么？");
                return 0;
        }

        else if (ob->value() < who->query_temp("liancost")*10000) {
                command("hmm");
                command("say 这些不够，怕不能帮您担当。");
                return 0;
        }

        command("look " + who->query("id"));
        command("secret " + who->query("id"));
        command("whisper " + who->query("id")+ " 好吧！别怕，干这个我拿手（removelian tie lian）。");
	who->set_temp("lianpaid", 1);

        return 1;
}

