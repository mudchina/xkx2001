//Cracked by Roath
// zhudanchen.c

inherit NPC;
inherit F_MASTER;

string ask_xialuo();
string ask_tan();
string ask_path();

void create()
{
	set_name("朱丹臣", ({ "zhu danchen", "zhu"}));
	set("long", "他手拿一册诗书，正在用心诵读，腰畔插着一对判官笔。\n");
	set("title","大理国武将");
	set("gender", "男性");
	set("age", 35);
	set("inquiry", ([
		"段正淳": "我家王爷生性风流。",
		"段誉"  : "我家小王子最近跑丢了，怎么也找不到。唉，阁下若是知道我家王子的下落，定请相告。",
		"下落"  : (: ask_xialuo :),
		"黑龙潭": (: ask_tan :),
		"生机"  : (: ask_path :),
        ]));
	set_skill("strike", 60);
	set_skill("qingyan-zhang", 60);
	set_skill("dodge", 60);
	set_skill("duanshi-shenfa", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("buddhism", 80);
	set_skill("sword", 60);
	set_skill("kurong-changong",60);
	set_skill("duanjia-jian", 60);
	map_skill("cuff","jinyu-quan");
	map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("parry","duanjia-jian");
	prepare_skill("strike","qingyan-zhang");

	set("str", 28);
	set("int", 29);
	set("con", 27);
	set("dex", 23);
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 550);
	set("max_neili", 550);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("chat_chance", 5);
	set("chat_msg", ({
"朱丹臣想想说道，“公子常在书房读易经，可惜我不能懂奇门八卦之术。”\n",
"朱丹臣手指掐算着什么，自言自语道：“宫象之数倍以生机，当可得生路。周千之数窃去宫数可得生机。嗯 ...”\n",
"朱丹臣面有得色地自言自语：“... 内含五行，得生机，或倍，或除，但取五数即可。”\n",
	}) );

	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("大理段家", 15, "弟子");
	setup();
	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/dali/obj/panguanbi")->wield();
}

void attempt_apprentice(object ob)
{
	mapping fam;
	string dldj;

        command ("look "+ob->query("id"));
        if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="女性")
                command ("say 师太是峨嵋派的高手，大理荒僻之乡不敢多留。");
             else
                command ("say 大师是少林派的高手，大理荒僻之乡不敢多留。");
             return;
        }
        if( ob->query("family/family_name") == "丐帮") {
                command ("say 大理虽是荒蛮之地，但皇家收留乞丐成何题统？");
                return;
        }
        if ( ob->query("family/family_name") == "武当派" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say 大理之处崇尚佛教，这位道兄还是另请高明吧。");
                return;
        }

       if ( ob->query("family/family_name") == "星宿派" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say 你这星宿恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }
      if ( ob->query("family/family_name") == "白驼山" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say 你这白驼恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }
       if ( ob->query("family/family_name") == "华山派" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say 大理之处崇尚佛教，这位道兄还是另请高明吧。");
                return;
        }
if ( ob->query("family/family_name") == "血刀门" && ob->query("combat_exp") 
>= 10000 ) {
                command ("say 
你这血刀门的恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }
if ( ob->query("family/family_name") == "神龙教" && ob->query("combat_exp") 
>= 10000 ) {
                command ("say
你这神龙教的恶贼也敢来我大理境内倡狂？速速离去!");
                return;
        }

        if (ob->query("shen") <0) { command ("say 大理境内容不得你这等阴险小人!");
                return;
        }
        


        if (ob->query("gender")=="女性") dldj="婢女";
        else  dldj = "家丁";
        command("say 好吧，我就斗胆代王爷收下你做个" + dldj + "吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","大理国平南王府"+dldj);
        return;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "朱丹臣笑咪咪地说道：这位" + 
RANK_D->query_respect(ob)
                                + "，欢迎来到大理。\n");
                        break;
                case 1:
                        say( "朱丹臣拱手说道：这位" + 
RANK_D->query_respect(ob)
                                + 
"，请问可有看到一位二十岁上下的年青公子。\n");
                        break;
        }
}

string ask_xialuo()
{
	object me;
	me=this_player();

	if (!me->query_temp("mazepath") && !me->query_temp("ydquest/query1")) {
		me->set_temp("ydquest/query1",1);
		return "公子出走好几天了，一点消息也没有。... ... \n我刚刚听说城西南黑龙潭有位隐居老妇，可能知道点什么，得去打听打听。\n";
	}
	else return "这个... 我不太清楚，你还是问问别人吧。";
}

string ask_tan()
{
	object me;
	me=this_player();

	if (me->query_temp("ydquest/query1") && !me->query_temp("ydquest/query2")) {
		me->delete_temp("ydquest/query1");
		me->set_temp("ydquest/query2",1);
		return "黑龙潭就在南门外西边，可是地处隐密，深在一片密林之中，那片林中的路径好象是按奇门八卦人工设制的。\n";
	}
	return "对不起，你问的事我实在没有印象。\n";
}

string ask_path()
{
	object me;
	int passwd,path;
	me=this_player();
	passwd=random(998)+2;
	path=passwd*(1000-passwd);
	if (path>99999) path=path/10;
	if (path<10000) path=path*10;
 
	if (me->query_temp("ydquest/query2")) {
		write("朱丹臣对你仔细端详了一阵。伏到你耳边。\n");
		command("whisper "+getuid(me)+" 你现在的星数是"+CHINESE_D->chinese_number(passwd));
		me->set_temp("mazepath", path);
		me->delete_temp("ydquest/query2");
		return "人各有命，"+RANK_D->query_respect(me)+"的天命照在下算来，就是如此了，请好自为之。\n";
	}
	return "对不起，你问的事我实在没有印象。\n";
}
