//Cracked by Roath
// Summer, 10/16/96. 
inherit NPC;
string ask_me_1();
string ask_me_2();

void create()
{
	set_name("祖千秋", ({"zu qianqiu", "zu"}));
	set("long",
		"一个衣衫褴偻的落魄书生。焦黄脸皮，一个酒糟鼻，疏疏落落的几根胡子，\n"
		"两眼无神。衣衫上一片油光，右手拿了一把破折扇。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("jiali", 40);
	set("apply/attack", 125);
	set("apply/defense", 125);
	set("combat_exp", 50000);
	set("score", 100);
	set("chat_chance", 5);
        set("chat_msg", ({
                "祖千秋嘟哝道：最近手头紧，打酒的钱都没有。我老哥子阔，可一点儿也不接济我。\n",	
		"祖千秋对你说道：我老哥子摊上个女儿病的快不行了，整天尽喂她些归元丹、养心丸什麽的，可一点儿用也没有。\n",
	}) );
	set("inquiry", ([
		"养心丸" :    (: ask_me_1 :),
		"归元丹" :    (: ask_me_2 :),
		"草药" : "嗯。。。老头子的草药藏得紧，没机会下手。\n",
		"药丸" : "客官要能出好价钱，我倒是可以到我老哥子那儿问一问。\n",
	]));

	set("wan_count", 5);
	set("dan_count",  5);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me_1()
{
	object ob;

	if (  present("yangxin wan", this_player()) )
		return "我不是刚卖给你了吗？";

	if (query("wan_count") < 1) return "老头子看得紧，我自己想要都弄不到。";

	say("祖千秋叹了口气：这玩意儿我吃了太多。。。嗳！没想到。。。\n");
	this_player()->set_temp("marks/丸", 1);
	return "你想要就便宜卖给你吧。只要五十两银子。\n";
}
string ask_me_2()
{
        object ob;

        if (  present("guiyuan dan", this_player()) )
                return "我不是刚卖给你了吗？";

        if (query("dan_count") < 1) return "老头子看得紧，我自己想要都弄不到。";

        say("祖千秋叹了口气：这玩意儿我吃了太多。。。嗳！没想到。。。\n");
        this_player()->set_temp("marks/丹", 1);
        return "你想要就便宜卖给你吧。只要五十两银子。\n";
}
int accept_object(object me, object ob)
{
	object yang, gui;

	if(ob->query("money_id") && ob->value() >= 5000
        && me->query_temp("marks/丸") ) {
        yang = new("/d/qilian/obj/yangxin");
	if (!objectp(yang)) return 1;
        yang->move(me);
	add("wan_count", -1);
        me->delete_temp("marks/丸");
        message_vision("祖千秋从怀里掏出一粒养心丸递给$N。\n",me);
        return 1;
        }

	if(ob->query("money_id") && ob->value() >= 5000
        && me->query_temp("marks/丹") ) {
        gui = new("/d/qilian/obj/guiyuan");
        gui->move(me);
        add("dan_count", -1);
	me->delete_temp("marks/丹");
	message_vision("祖千秋从怀里掏出一粒归元丹递给$N。\n",me);
	return 1;
	}
	
	say(
	"祖千秋一面急忙把钱收起来，一面笑嘻嘻说道：" + RANK_D->query_respect(ob) + "想买甚麽药，尽管说，小的没有弄不到的。\n");
	return 1;
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
