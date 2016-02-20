//Cracked by Roath
// d/gaibang/npc/cook.c 丐帮二袋弟子
// xbc 06/22/1997

#include <ansi.h>

inherit NPC;

string ask_me(string, object);

void create()
{
	set_name("小叫化", ({"beggar", "jiao hua", "cook"}));
	set("title", "丐帮二袋弟子");
	set("gender", "男性");
	set("age", 17);
	set("long", 
		"这个少年乞丐，长得浓眉大眼，额头上尽是汗珠。他手上握着一把大勺，正在烧菜做饭。\n");

	set("chat_chance", 1);
	set("chat_msg", ({
		"小叫化自言自语道：今天做什么菜好呢？\n",
		"小叫化抓起一块抹布，把大锅擦了擦，放到灶上开始炒菜。\n",
		"小叫化坐在一块大石头上，望着面前的竹林发起呆来。 \n",
		"听到一阵悉悉簌簌的脚步声，小叫化四周望了望，警觉地提起大勺来。\n",
	}) );

        set("inquiry", ([
                "here"   : (: ask_me, "zhulin":),
                "rumors" : (: ask_me, "yaoyan"  :),
		"炒菜" : (: ask_me, "cook" :),
		"烧菜" : (: ask_me, "cook" :),
		"做饭" : (: ask_me, "cook" :),
		"洪七公" : (: ask_me, "hong" :),
		"洪老帮主" : (: ask_me, "hong" :),
		"牛肉条" : (: ask_me, "beef"  :),
		"玉笛谁家听落梅" : (: ask_me, "beef" :),
                "好逑汤"   : (: ask_me, "soup" :),
		"炒白菜" : (: ask_me, "baicai" :),
		"蒸豆腐" : (: ask_me, "doufu" :),
		"二十四桥明月夜" : (: ask_me, "doufu" :),
        ]));

	set("attitude", "friendly");
	set("str", 20);
	set("int", 18);
	set("con", 21);
	set("dex", 21);

	set("rank", 2);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 180);
	set("max_neili",180);
	set("jiali", 20);
	
	set("combat_exp", 12000);
	
	set_skill("force", 25); 
	set_skill("huntian-qigong", 25); 
	set_skill("hand", 25); 
	set_skill("shexing-diaoshou", 25); 
	set_skill("dodge", 25); 
	set_skill("xiaoyaoyou", 25); 
	set_skill("parry", 25); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("丐帮", 19, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(1);
	carry_object("/d/gaibang/obj/budai")->wear();
}

string ask_me(string name, object ob)
{
	if ( name == "yaoyan" )
		return "洪老帮主来了扬州，听说是想找黄蓉给他烧菜吃。";

	if ( name == "zhulin" )
		return "这片竹林可是咱丐帮的地盘。我这两天在这里帮洪老帮主烧些小菜。你来帮忙吗？";

	if ( name == "hong" )
		return "洪老帮主最是贪吃。他整天念叨着黄蓉和她烧的菜，说她特会烧。
小叫化又道：听说谁要烧了洪帮主爱吃的菜，他可能就会指点些武功，还有可能收为徒弟！
小叫化叹了口气说：唉，我在这里烧了好几个月的菜了，可洪帮主还是没教我些啥。";

	if ( name == "cook" )
		return "你会烧菜吗？帮我一下吧。你先去找好材料，来这里烧（cook）。基本调料我这里有。";

	if ( name == "beef" )
		return "黄蓉给洪老帮主烧过牛肉条，说叫什么玉笛谁家听落梅，听说有四五样肉做成呢。";

	if ( name == "soup" )
		return "好逑汤？听洪老帮主提起过，说是用荷叶、竹笋、樱桃啥的烧的，好吃极了。";

        if ( name == "baicai" )
		return "炒白菜谁不会做！可听洪老帮主说，黄蓉炒的就不同一般，用了鸭掌和鸡油。";

	if ( name == "doufu" ) 
		return "啊，黄蓉做过的蒸豆腐，说叫什么二十四桥明月夜，不知道有啥特别的。";
	
}

