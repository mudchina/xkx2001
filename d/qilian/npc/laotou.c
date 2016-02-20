//Cracked by Roath
// Summer, 10/16/96. 

inherit F_UNIQUE;
inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();
string ask_me_4();
string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
        "/d/shaolin/fzlou",
        "/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/taishan/huima",
        "/d/huashan/laojun",
        "/d/village/square",
        "/d/xingxiu/tianroad3",
        "/d/forest/bank3",
        "/d/emei/baoguomen",
        "/d/emei/xixiang",
        "/d/qilian/qilian",
	"/d/xixia/square",
});

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
	set("shen_type", 0);
	set("str", 26);
	set("int", 23);
	set("con", 24);
	set("dex", 26);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_neili", 1200);
	set("jiali", 60);
	set("combat_exp", 550000);

	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("ding-dodge", 150);
	set_skill("ding-force", 150);
	set_skill("force", 150);
	set_skill("ding-unarmed", 150);

	map_skill("force", "ding-force");
	map_skill("dodge", "ding-dodge");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 15);
        set("chat_msg", ({
//                "老头子嘟哝道：这是甚麽破店？一点儿象样的药也没有。连店老板也不知躲到哪里去了。\n",	
		(: random_move :),
//		"老头子对你说道：这位客官可有见到这儿的店老板？。。嗳！我女儿病的快不行了，我想到这儿来找点儿药。\n",
//		"老头子突然放低声音，把你拉到一旁：客官想买甚麽药？不如问我吧，他这儿啥也没有。\n",
	"老头子不怀好意地紧紧盯着你的钱袋，一边笑嘻嘻地踱过来答讪。\n",
	"老头子紧紧抱着自己的钱袋，走路，吃饭，连做梦都乐得笑出声儿来。\n",
	}) );
	set("inquiry", ([
		"千年首乌" :    (: ask_me_1 :),
		"老山参" :    (: ask_me_2 :),
		"灵芝" :   (: ask_me_3 :),
		"草药" : "你想知道啥？就问我吧，天下的药我都见过，象什麽千年首乌、灵芝、老山参。。等等。\n",
		"续命八丹" :  (: ask_me_4 :),
	]));

	set("stay_chance", 1);

        set("no_clean_up", 1);
	set("wu_count", 5);
	set("shan_count",  5);
	set("ling_count", 3);
	set("dan_count", 1);
	setup();
        ::create();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        ::init();
        set_heart_beat(1);
}
string ask_me_1()
{
	object ob;


	if ( (int)this_player()->query_condition("drug_purchase" ) > 0 )
		return "我不是刚卖给你了吗？";

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

	if ( (int)this_player()->query_condition("drug_purchase" ) > 0 )
                return "我不是刚卖给你了吗？";

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
	
	if ( (int)this_player()->query_condition("drug_purchase" ) > 0 )
                return "我不是刚卖给你了吗？";

	if (  present("ling zhi", this_player()) )
		return  "我不是刚卖给你了吗？";

	if (query("ling_count") < 1) return  "灵芝可是神药，很难采到，我这现在没有。";
	this_player()->set_temp("marks/灵", 1);
	say("老头子抬起头，把你上上下下打量了一番，「嘿嘿嘿」干笑了几声...\n");
	return "灵芝可是很贵重的唷，就怕你买不起，要二两黄金，不二价。\n";
}
string ask_me_4()
{
        object ob, me = this_player();
        if (  present("xuming badan", this_player()) )
        return "我不是刚卖给你了吗？";

        if (me->query_condition("xx_poison") < 50
	&& me->query_condition("snake_poison") < 50 
	&& me->query_condition("sl_poison") < 50
	&& me->query_condition("insect_poison") < 50)
	 return "这位" + RANK_D->query_respect(this_player())+
	"看起来不象有何重病，要这药做甚？\n";

	if (query("dan_count") < 1)
	return "对不起，我现在这里没有。";
        say("我多年来采集千年人参、伏苓、灵芝、当归、鹿茸、首乌、熊胆、三七、麝香种种珍贵药材，九蒸九晒, 制成八颗起死回生的续命八丹。。。\n");
	ob = new(DRUG_D("badan"));
	ob->move(me);
	message_vision("老头子从怀里边掏出一粒续命八丹递给$N。\n",me);
	add("dan_count", -1);
	add("stay_chance", -1);
        return "该当阁下命不该绝，碰到了老头子我，这颗续命八丹你拿去服用吧，即使不能起死回生，也能延你几天寿命吧。\n";
}
int accept_object(object me, object ob)
{
	object where = environment();
	 object *chars = ({});
	object wu, shan, ling;
	if (!clonep()) return 1;

        ::chat();

        if (add("tick", 1)%3 == 1) return 1;

	if(ob->query("money_id") && ob->value() >= 20000
        && me->query_temp("marks/灵") ) {
        ling = new(DRUG_D("lingzhi"));
        ling->move(this_player());
	add("ling_count", -1);
        me->delete_temp("marks/灵");
	me->apply_condition("drug_purchase", 30);
        message_vision("老头子打开皮囊从里边掏出一枚灵芝递给$N。\n",me);
	add("stay_chance", -1);
	if ((int)query("tick") > 600 ) {
                set("tick", 0);
                return_home(where);
        }

        if (sizeof(chars)<1 && me->query("stay_chance")<1)
        {
                set("stay_chance", 1+random(3));
                random_move();
        }

        return 1;
        }

	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/首") ) {
        wu = new(DRUG_D("shouwu"));
        wu->move(me);
        add("wu_count", -1);
	add("stay_chance", -1);
	me->delete_temp("marks/首");
	me->apply_condition("drug_purchase", 30);
	message_vision("老头子打开皮囊从里边掏出一棵何首乌递给$N。\n",me);
	return 1;
	}
	
        if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/山") ){
	shan = new(DRUG_D("shanshen"));
        shan->move(me);
        add("shan_count", -1);
	add("stay_chance", -1);
        me->delete_temp("marks/山");
	me->apply_condition("drug_purchase", 30);
        message_vision("老头子打开皮囊从里边掏出一棵老山参递给$N。\n",me);
        return 1;
        }  
	say(
	"老头子一面急忙把东西收起来，一面笑嘻嘻说道：" + RANK_D->query_respect(ob) + "想买甚麽药，尽管说，小的没有弄不到的。\n");
	return 1;
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
int return_home(object home)
{
                // Are we at home already?
        if( !environment()
	||      environment()==home )
                return 1;

        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting() ) return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                environment(), this_object());

        home = load_object(homes[random(sizeof(homes))]);
        if (home) return move(home);
        return 0;
}
