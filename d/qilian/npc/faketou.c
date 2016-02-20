//Cracked by Roath
// Summer, 10/16/96. 

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();

void create()
{
	set_name("老头子", ({"laotou zi", "laotou"}));
	set("long",
		"此人极矮极胖，头颈是绝计没有的，一个既扁且肥的脑袋横安在双肩之上，\n"
		"便似初生下地之时，给人重重当头一棰，打得他脑袋挤下，面颊鼻孔全部，\n"
		"横扯了开去一般。\n"
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
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 40);
	set("combat_exp", 500000);
	set("score", 100);
	set("chat_chance", 8);
        set("chat_msg", ({
                "老头子嘟哝道：这是甚麽破店？一点儿象样的药也没有。连店老板也不知躲到哪里去了。\n",	
		"老头子对你说道：这位客官可有见到这儿的店老板？。。嗳！我女儿病的快不行了，我想到这儿来找点儿药。\n",
		"老头子突然放低声音，把你拉到一旁：客官想买甚麽药？不如问我吧，他这儿啥也没有。\n",
	}) );
	set("inquiry", ([
		"千年首乌" :    (: ask_me_1 :),
		"老山参" :    (: ask_me_2 :),
		"灵芝" :   (: ask_me_3 :),
		"草药" : "你想知道啥？就问我吧，天下的药我都见过，象什麽千年首乌、灵芝、老山参。。等等。\n",
	]));

	set("wu_count", 3);
	set("shan_count",  3);
	set("ling_count", 3);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me_1()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return "对不起，这东西都让我女儿用光了。";

	if (  present("heshou wu", this_player()) )
		return "我不是刚卖给你了吗？";

	if (query("wu_count") < 1) return "对不起，这东西都让我女儿用光了。";

	say("老头子叹了一口气：嗳！千年的首乌我女儿都用下了，也不见什麽起色...\n");
	this_player()->set_temp("marks/首", 1);
	return "我这里只有一支初具人形的，我女儿也用不了了。只要一两黄金，便宜卖给你。\n";
}
string ask_me_2()
{
	object ob;

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
	return "对不起，这东西都让我女儿用光了。";

	if (  present("lao shanshen", this_player()) )
	return "我不是刚卖给你了吗？";
		
	if (query("shan_count") < 1) return "对不起，这东西我女儿都用光了。";
	this_player()->set_temp("marks/山", 1);
	say("老头子喃喃道：我女儿已吃了无数的这东西，只见病情越来越坏。。。\n");
	return "这东西我倒有，你想要我就卖给你，一两黄金，不过客官千万别多吃，吃多了不好。\n";
}
string ask_me_3()
{
	object ob;
	
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return  "灵芝可是神药，很难采到，我这现在没有。";

	if (  present("ling zhi", this_player()) )
		return  "灵芝可是神药，很难采到，我这现在没有。";

	if (query("ling_count") < 1) return  "灵芝可是神药，很难采到，我这现在没有。";
	this_player()->set_temp("marks/灵", 1);
	say("老头子抬起头，把你上上下下打量了一番，「嘿嘿嘿」的干笑了几声...\n");
	return "灵芝可是很贵重的唷，就怕你买不起，要二两黄金，不二价。\n";
}
int accept_object(object me, object ob)
{
	object wu, shan, ling;
	if(ob->query("money_id") && ob->value() >= 20000
        && me->query_temp("marks/灵") ) {
        ling = new("/d/qilian/obj/lingzhi");
        ling->move(this_player());
        me->delete_temp("marks/灵");
        message_vision("老头子打开皮囊从里边掏出一枚灵芝递给$N。\n",me);
        return 1;
        }

	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/首") ) {
        wu = new("/d/qilian/obj/fakewu");
        wu->move(me);
        add("wu_count", -1);
	me->delete_temp("marks/首");
	message_vision("老头子打开皮囊从里边掏出一棵何首乌递给$N。\n",me);
	return 1;
	}
	
        if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/山") ){
        shan = new("/d/qilian/obj/fakeshen");
        shan->move(me);
        add("shan_count", -1);
        me->delete_temp("marks/山");
        message_vision("老头子打开皮囊从里边掏出一棵老山参递给$N。\n",me);
        return 1;
        }  
	say(
	"老头子一面急忙把钱收起来，一面笑嘻嘻说道：" + RANK_D->query_respect(ob) + "想买甚麽药，尽管说，小的没有弄不到的。\n");
	return 1;
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
