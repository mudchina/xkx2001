//Cracked by Roath
// daobaifeng.c 刀白凤
// Acep, Mantian

inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
	set_name("刀白凤", ({ "dao baifeng", "dao"}));
	set("long", 
"这是个容貌秀丽的中年道姑，是个摆夷族女子，颇有雍容气质。\n她本是大理国皇帝段正淳的正房原配夫人。\n因恼丈夫风流不羁，沾花惹草，一怒之下跑到这里出了家。");
	set("title","大理国王妃");
	set("nickname","玉虚散人");
	set("gender", "女性");
	set("age", 35);
	
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 300000);

	set("attitude", "peaceful");
	set("shen_type", 1);
	
	set_skill("strike", 80);
	set_skill("qingyan-zhang", 80);
	set_skill("dodge", 80);
	set_skill("duanshi-shenfa", 80);
	set_skill("parry", 80);
	set_skill("force", 70);
	set_skill("buddhism", 80);
	set_skill("sword", 70);
	set_skill("kurong-changong",70);
	set_skill("duanjia-jian", 70);
	set_skill("whip", 120);
	set_skill("feifeng-bian", 130);
	
	
	map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("parry","duanjia-jian");
	map_skill("strike","qingyan-zhang");
	map_skill("whip","feifeng-bian");
	prepare_skill("strike","qingyan-zhang");
	
	set("inquiry", ([
		"飞凤鞭法" 		:  (: ask_me :),
		"段正淳"			: "提那个负心人做什么？",
		"段誉"			: "唉，我好久没见到誉儿啦。",
		]));
        
	create_family("大理段家", 15, "弟子");
	setup();

	carry_object("/d/wudang/obj/greenrobe")->wear();	
	carry_object("/d/quanzhou/obj/fuchen")->wield();
}

void attempt_apprentice(object ob)
{
	string current_title;
	object me = this_player();
	current_title=ob->query("title");

	command ("look "+ob->query("id"));

        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="女性")
                        command ("say 师太是峨嵋派的高手，大理荒僻之乡不敢多留。");
                else
                        command ("say 大师是少林派的高手，大理荒僻之乡不敢多留。");
                return;
        }

        if( ob->query("family/family_name") == "丐帮") {
                command ("say 大理虽是荒蛮之地，但皇家收留乞丐成何体统？");
        	return;
        }
	
	if (ob->query("gender")!="女性") {
		command("shake "+ob->query("id"));
		command("say 你还是去王府找那些家臣学艺吧。");
		return;
	}
	if (me->query("family/family_name")!="大理段家") {
		command("hmm "+ob->query("id"));
		command("say 你不是大理弟子啊，跑到我这里来干什么？");
		return;
        }

	command("say 好吧，我就收下你了，希望你好好学艺，不要给那些负心薄幸的臭男人欺负。");
	command("recruit " + ob->query("id"));
	ob->set("title", current_title);
	return;
}
string ask_me()
{
    object me=this_player();

	if (me->query("family/family_name")!="大理段家")	return RANK_D->query_respect(me)+"对不起，你不是大理弟子，跑到我这里来干什么？\n";
	if (me->query("gender")!="女性") return "对不起，我无法回答你的问题。\n";
	if (me->query_skill("feifeng-bian",1)) return "你不是已经会了吗，怎么还来问我？\n";
	if (me->query("family/master_id") != "yideng dashi" && me->query("family/master_name") != "一灯大师"){
		command("recruit " + me->query("id"));
		return "好吧，我就收下你了，希望你好好学艺，不要给那些负心薄幸的臭男人欺负。\n";
		}
	add_action("do_qingjiao", "qingjiao");
	command("consider");
	return "飞凤鞭法是一种外刚内柔鞭法，既然你这么有心，我就指导你一下吧。\n";
}

int do_qingjiao(string arg)
{
	object obj=this_object(), me=this_player();
	int skill, myint;

	if (!arg) return notify_fail("你想向刀白凤请教什么功夫？\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if (me->is_fighting()) return notify_fail("临阵磨枪？来不及啦。\n");
	if (obj->is_fighting() || obj->is_busy()) return notify_fail("她正忙着呢，没工夫教你。\n");
	if (!living(obj)) return notify_fail("嗯 ... 你得先把她弄醒再说。\n");
	if (arg!="feifeng-bian") return notify_fail("刀白凤根本不会这门功夫，无法指导你。\n");
	if ((int)me->query("jing") <500 ) return notify_fail("精力不够，无法请教刀白凤任何东西。\n");
	if ((int)obj->query("jing") <100 ) return notify_fail("刀白凤太累了，无法指导你。\n");

	message_vision("$N向$n请教飞凤鞭法，似乎有所领悟。\n", me, obj);
    remove_action("do_qingjiao", "qingjiao"); 
	me->set_skill("feifeng-bian", 1);
	me->receive_damage("jing", 400);
	return 1;
}
