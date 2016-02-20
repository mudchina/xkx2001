//Cracked by Roath
// Jay 10/7/96

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_camel();

void create()
{
        set_name("钱眼开", ({ "qian yankai","qian","yankai" }));
        set("long", "他是白驼山庄的账房先生，前一段时间被欧阳峰派到扬州"
		"城开了一家钱庄，骗了不少钱，使欧阳峰得以翻修白"
		"驼山庄。他一袭长衫，虽形像猥琐，但其实武功高强。\n");
        set("gender", "男性");
	set("title","白驼山庄账房先生");
        set("nickname", "铁公鸡");
        set("age", 35);

        set_skill("cuff", 50);
	set_skill("lingshe-quan", 50);
        set_skill("dodge", 60);
	set_skill("chanchubu", 60);
        set_skill("parry", 50);
        set_skill("force", 50);
	set_skill("hamagong", 50);
	set_skill("strike",50);
	set_skill("poison",40);
	set_skill("training",50);
	map_skill("cuff","lingshe-quan");
        map_skill("dodge","chanchubu");
	map_skill("force","hamagong");
	prepare_skill("cuff","lingshe-quan");

        set("str", 28);
        set("int", 21);
        set("con", 27);
        set("dex", 21);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 550);
        set("max_neili", 550);
        set("jiali", 40);
        set("combat_exp", 100000);

        set("attitude", "peaceful");
        set("shen_type", -1);
        set("inquiry", ([
                "工钱" : (: ask_me :),
		"骆驼" : (: ask_camel :),
		"坐骑" : (: ask_camel :),
        ]));

        create_family("白驼山", 3 , "弟子");
	setup();
	carry_object("/d/city/obj/cloth")->wear();
	add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        mapping fam;
	string ttt;

	command ("look "+ob->query("id"));
	if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="女性")
		command ("say 小师太练蛤蟆功，不怕别人叫你秃头蛤蟆吗？");
	     else
		command ("say 大师傅练蛤蟆功，不怕别人叫你秃头蛤蟆吗？");
	     return;
	}
        if( ob->query("family/family_name") == "丐帮") {
		command ("say 庄主平生最恨叫化子，我可不想收你。");
		return;
	}
        if ( ob->query("family/family_name") == "武当派") {
		command ("say 老道练蛤蟆功，不怕别人叫你牛鼻子蛤蟆吗？");
		return;
	}

	if (ob->query("combat_exp") > 30000) {
		command ("say "+ RANK_D->query_respect(ob) + 
                           "是武林高手，拜我为师？别取笑于在下了。");
		return;
	}
	if (ob->query("int") <25) {
                command ("say "+ RANK_D->query_respect(ob) + 
                           "生性憨直，做不好帐房里的事的。");
                return;
        }


	if (ob->query("gender")=="女性") ttt="婢女";
	else  ttt = "家丁";
	command("say 好吧，你就在我山庄做个" + ttt + "吧。");
        command("recruit " + ob->query("id"));
	ob->set("title","白驼山庄"+ttt);
	return;
}

string ask_me()
{
	object wage;
	object ob = this_player();
	if (ob->query("family/family_name")!="白驼山") {
		command("say 你是哪里来的" + RANK_D->query_rude(ob) +
			"到我们庄来混食？快给我滚！");
		command("kick " + ob->query("id"));
		return ("小心我宰了你！");
	}
	if (ob->query("family/generation")<3) 
		return ("少庄主，应该是你给小的我发工钱呀。");
	if (!ob->query("combat_exp")) return ("先干点什么再领钱。");
	if (ob->query("family/generation")>3) {
	if (ob->query("bt_exp") < ob->query("combat_exp") - 99) {
		wage = new("/clone/money/silver");
                wage->set_amount(1);
                wage->move(ob);
		ob->set("bt_exp",ob->query("combat_exp"));
		return("这是你打杂的酬劳，好好干！");
	}
	else return("从上次领薪水到现在你光吃饭不干活儿，没你的工钱！");
	}
	if (ob->query("bt_exp") < ob->query("combat_exp") - 999) {
                wage = new("/clone/money/silver");
                wage->set_amount(10);
                wage->move(ob);
                ob->set("bt_exp",ob->query("combat_exp"));
                return("这是你当武师的酬劳，好好干！");
        }
        else return("从上次领薪水到现在你光吃饭不干活儿，没你的工钱！");
}
string ask_camel()
{
	object ob, me=this_player();
	
	if (me->query("family/family_name")!="白驼山") {
                command("say 你是哪里来的" + RANK_D->query_rude(me) +
                        "到我们庄来混食？快给我滚！");
                command("kick " + me->query("id"));
                return ("小心我宰了你！");
        }

	if (me->query("rided") || me->query_temp("mark/驼")){
		return("你不是有坐骑了吗？");
	}	

	if (query("camel_count") > 20)
		return("骆驼都让你师兄弟们骑走了，"+ RANK_D->query_respect(me)+
		       "要出山，等他们回来在说吧。");

	ob=new("/clone/horse/btcamel");
	ob->move("/d/xingxiu/btgate");
	add("camel_count", 1);
	ob->set_lord(me);
	ob->set_leader(me);
	me->set_temp("mark/驼", 1);
		command("nod");
		say("钱眼开吩咐家丁到草房牵出一匹骆驼来交给你。\n");
		return(RANK_D->query_respect(me) + "路上小心，早去早归！");
}
