//Cracked by Roath
// 陆乘风 test job用
// mantian //add more path and make job counter may/11/2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

#include "/d/REGIONS.h";

int ask_xfsy();
string ask_me();
string ask_me_2(string name);
int ask_yapu();
int ask_abandon();
void create()
{
	set_name("陆乘风", ({ "lu chengfeng", "lu" }));
	set("title", "归云庄主");
	set("long",
		"他是黄药师的四弟子陆乘风，他脸色枯瘦，似乎身体不大好，\n"
		"且双足似有残疾，一直坐在椅上，但身材甚高，即便坐着也和\n"
		"常人差不多高。他在桃花弟子中尤精奇门遁甲。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 200000);
	set("shen", 0);

	set_skill("force", 150);
	set_skill("bitao-xuangong", 150);
	set_skill("dodge", 120);
	set_skill("luoying-shenfa", 120);
	set_skill("strike", 120);
	set_skill("luoying-shenjian", 120);
	set_skill("qimen-dunjia", 120);
	set_skill("hand", 120);
	set_skill("lanhua-fuxue", 120);
	set_skill("whip",120);
	set_skill("canglang-bian", 120);
	set_skill("literate", 80);
	set_skill("parry", 120);	

	map_skill("force", "bitao-xuangong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("strike", "luoying-shenjian");
	map_skill("parry", "luoying-shenjian");
	map_skill("hand", "lanhua-fuxue");

	prepare_skill("strike", "luoying-shenjian");

	create_family("桃花岛", 2, "弟子");
	set("bagua_count", 5);
	set("yulu_count", 5);
	set("inquiry", ([
		"梅超风" :"这贼婆娘害得我好苦。她不要脸偷汉，那也罢了，干吗要偷师父的《九阴真经》？",
		"陈玄风" :"他和梅超风都是师门叛徒，有何好说？这两人害得我好苦！我半身不遂，就是拜受这两人之赐。",
		"曲灵风" :"灵风师兄专于武技，不过育有一女，不知如今下落如何？",
		"冯默风":"你可持桃花本门信物前往寻找默风，冯师弟天性淡泊，但外和内刚，恐怕需用非常手段才能逼他表露身份．．．",
		"黄药师" : "当年师父一怒之下，将我们师兄弟四人一齐震断脚筋，逐出桃花岛。",
		"桃花岛" : (: ask_me :),
		"九花玉露丸" : (: ask_me_2, "yulu-wan" :),
		"旋风扫叶腿心法" : (:ask_xfsy:),
		"哑仆" : (:ask_yapu:),
		"放弃" : (:ask_abandon:),
		"yapu" : (:ask_yapu:),
		"abandon" : (:ask_abandon:),
	]));
	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	carry_object("/d/taohua/obj/bagua");
}

void init()
{
	::init();
	add_action("do_recite", "recite");
}

void attempt_apprentice(object me)
{
	if ((string)me->query("family/family_name") == "丐帮" && me->query("rank") > 1 )
	{
		command("say "+RANK_D->query_respect(me)+"是丐帮高手，恕我不能收你。");
		return;
	}
	if( me->query("family/family_name") == "桃花岛"
		&& me->query("family/master_name") == "黄药师" )
	{
		command ("say "+RANK_D->query_respect(me)+"是本派高手，我可不敢收留！");
		return;
	}
	if (me->query("class") && (me->query("class") != "beggar" && me->query("class") != "officer") 
		|| (me->query("family/family_name") != "桃花岛" && me->query("combat_exp") >= 10000) )
	{
		command("say "+RANK_D->query_respect(me)+"是它方高士，何必还到敝庄混饭。\n");
		return;
	}       
	if( me->query_temp("pending/recite") )
	{
		command("say 你粗鄙不文，见识浅薄，本庄主怎会收你？");
		return;
	}
	else
	{
		command("say 一位异人曾在本庄花厅留诗半阙，如果你能补全，也不枉来归云庄一遭");
		message_vision("陆庄主凝视着$N，说道：快把你的下阙大声朗诵(recite)出来吧。\n",
		this_player());
		me->set_temp("pending/recite", 1);
	}
}

int do_recite(string arg)
{
	string name, new_name, ttt;
	if( !this_player()->query_temp("pending/recite") ) return 0;
	if( !arg ) return notify_fail("你说什么？\n");
	this_player()->set_temp("pending/recite", 0);
	message_vision("$N大声说道：" + arg + "\n", this_player());
	if( arg == "无人争晓渡残月下寒沙")
	{
		command("smile");
		if (this_player()->query("gender") == "男性") ttt = "门生";
		else  if (this_player()->query("gender") == "女性") ttt = "青衣";
		else
		{
			command("sigh");
			command("say "+"卿本佳人，奈何自宫，本庄与东厂概无关联，你去吧！");
			return 0;
		}
		command("say "+"好！好！"+RANK_D->query_respect(this_player())+"果然博闻强记。敝人就收你做个" + ttt +"吧。");
		command("recruit " + this_player()->query("id"));
		this_player()->set("title", "归云庄" + ttt);
	}
	else
	{
		command("say 你这白丁，待在这里，没的脏了我的屋子！");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] !="桃花岛")
		return RANK_D->query_respect(this_player()) +"与敝庄素无来往，不知此话从何谈起？";
	if (query("bagua_count") < 1)
		return "今天我太累了，有什么事明天再说吧。";
	if (  present("tie bagua", this_player()) || this_player()->query_temp("get_bagua"))
		return "现在你可以上桃花岛试一试，看有没有福份见到我师傅。";
	if (this_player()->query_skill("qimen-dunjia", 1) < 60
		|| this_player()->query_skill("bitao-xuangong", 1) < 60)
		return "桃花岛上机关重重，你功夫不够，还是不去为妙。";
	add("bagua_count", -1);
	ob = new("/d/taohua/obj/bagua");
	ob->move(this_player());
	this_player()->set_temp("get_bagua",1);
	message_vision("陆乘风递给$N一块铁八卦。\n", this_player());
	return "上岛之后千万小心，万事靠自己，我也帮不上什么忙了。";
}

string ask_me_2(string name)
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "桃花岛")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";

	if (this_player()->query("combat_exp") < 5000)
		return "你功夫不够，还是不要为妙。";

	if (query("yulu_count") < 1)
		return "抱歉，你来得不是时候，已经发完了。";

	if (this_player()->query_condition("work") > 0)
		return "我不是才给过你药吗？怎麽又来要了，真是贪得无厌！";

	ob = new(DRUG_D(name));
	ob->move(this_player());
	this_player()->apply_condition("work", 30);

	add("yulu_count", -1);
	message_vision("陆乘风给$N一粒" + ob->query("name") + "。\n", this_player());

	return "拿去吧。小心别弄丢了。";
} 
/*
void unconcious() 
{
	message_vision("\n突然，只见$N伸手在太师椅扶手上一掀，背后墙壁一下子裂开，连人带椅都缩进复壁，影踪不见。\n",this_object());
	destruct(this_object());
}
*/
int accept_kill(object me)
{
	if (me->query("family/family_name") == "桃花岛")
	{
		command("say 你我本是同门，如何要加害于我！\n");
		me->set("th_killer", 1);
		kill_ob(me);
		return 1;
	}
	return 0;
}

int accept_object(object me, object obj)
{
	call_out("accept_obj", 2, me, obj);
	return 1;
}

int accept_obj(object me, object obj)
{
	if( obj->query("name") == "旋风扫叶腿心法" )
	{
		command("ah");
		message_vision(CYN"$N双手颤抖的展开薄纸，仔仔细细的读了起来。\n",this_object());
		message_vision(CYN"$N一边读，一边热泪盈眶！\n",this_object());
		command("cry");
		command("say 多谢"+ RANK_D->query_respect(me) +"了。\n");
		set("xfsy_xinfa_reading",1);
		set("xfsy_xinfa_accept",1);
		if( me->query("family/family_name") == "桃花岛" )
		me->set("help_chengfeng",1);
	}
	call_out("finish_reading", 100+random(50), obj);
	return 1;
}     

void finish_reading(object obj)
{
	delete("xfsy_xinfa_reading");
	destruct(obj);
}

int ask_xfsy()
{
	object me, obj;

	me = this_player();
	if( query("xfsy_xinfa_reading") )
	{
		command("say 对不住，我还没读完恩师所传心法．");
		return 1;
	}

	if( me->query("family/family_name") == "桃花岛" 
		&& query("xfsy_xinfa_accept") )
	{
		obj = new("/d/taohua/obj/xfsy_xinfa2");
		obj->move(me);
		command("say 这套心法我做了一些注解，"+RANK_D->query_respect(me)+"可拿回去自行参悟。");
		message_vision("$N递给$n一张薄纸。\n",this_object(),me);
		delete("xfsy_xinfa_accept");
	}
	else command("say 旋风扫叶腿心法已不在我这里。");
	return 1;
}

int ask_yapu()
{
	string* yapu_room = ({
		"/d/hangzhou/yuhuang"+(1+random(3)),
		"/d/hangzhou/road41",
		"/d/hangzhou/road"+(63+random(4)),
		"/d/hangzhou/road78",
		"/d/hangzhou/lingyin0",
		"/d/hangzhou/suti"+(1+random(7)),
		"/d/hangzhou/kedian",
		"/d/foshan/street"+(1+random(4)),
		"/d/foshan/qzroad"+(1+random(7)),
		"/d/foshan/dlroad"+(1+random(7)),
		"/d/foshan/beidi",
		"/d/foshan/cunkou",
		"/d/foshan/road"+(1+random(4)),
		"/d/quanzhou/zhongxin",
		"/d/quanzhou/xiqiao",
		"/d/quanzhou/yaopu",
		"/d/quanzhou/tumen",
		"/d/quanzhou/shijiefu",
		"/d/quanzhou/yongning",
		"/d/quanzhou/gangkou2",
		"/d/quanzhou/tudi",
		"/d/quanzhou/shanlu"+(1+random(6)),
		"/d/quanzhou/enyuan",
		"/d/huanghe/bank"+(1+random(8)),
		"/d/taishan/daizong",
		"/d/taishan/yitian",
		"/d/huanghe/bank7",


	});

	string region, id;	
	object me, ob, jiading, weapon, room; 
	int exp;
	mapping fam;

	me = this_player();
	exp = me->query("combat_exp");
	id = me->query("id");

	if (me->query("family/family_name") != "桃花岛")
	{
		command("say 桃花岛上的哑仆个个都是忘恩负义的奸恶之徒，我恩师事先查访确实，才一一擒至岛上，割哑刺聋，以供役使。");
		return 1;
	}
	if(me->query("combat_exp") < 20000)
	{
		command("say 你也想捉哑仆麽？志气可嘉，不过还是把功夫练好再说。");
		return 1;
	}
	
	if(me->query("id")!="maco" && base_name(environment(me)) != "/d/taihu/shufang")
	{
		command("en lu chengfeng");
		command("say 先等我回归云庄再说。");
		message_vision("陆乘风招了招手，两名家丁抬著竹榻过来，让陆乘风坐著，离开了。\n",me);
		move("/d/taihu/shufang");
		message("vision", "陆乘风坐在竹榻上，由两名家丁抬著进了书房来。\n", environment(this_object()),this_object());
		return 1;
	}

	if(me->query("th_yapu_ok"))
	{
		if(me->query("th_help_yapu"))
		{
			command("thumb " +me->query("id"));
			command("say 辛苦了！与你同去的家丁已经把那个"+me->query("find_yapu")+"带了回来。");
			command("say 我已命人将这个"+me->query("find_yapu")+"留在庄里，看看是否有改过之意，再行定夺。");
			me->delete("th_help_yapu");
		}
		else
		{
			command("applaud " +me->query("id"));
			command("say 辛苦了！与你同去的家丁已经把那个"+me->query("find_yapu")+"带了回来。");
			command("say 我会派人送上桃花岛去，交由恩师处置。");
		}
		me->delete("find_yapu");
		me->delete("th_yapu_ok");
		me->delete("zangbu_yapu");
		me->delete("th_discuss"); //可继续discuss
		me->add("th_yapu_job", 1);
		if (me->query("th_yapu_job") >= 5)
		{
			me->set("th_yapu_job",0);
			me->set("th_ask_drug",1);
		}
		me->apply_condition("th_yapu_job", 0);

		set("yapu_ok/"+id,1);
		add("yapu_enough/"+id,1);
		call_out("wait_job", 10, id);
		if (query("yapu_enough/"+id) >= 5)
		call_out("wait_job2", 180, id);

		return 1;
	}

	else if (query("yapu_ok/"+id))
	{
		command("say "+ RANK_D->query_respect(me) +"才刚刚回来，还是请先稍事歇息罢。");
		return 1;
	}
	else if (query("yapu_enough/"+id) >= 5)
	{
		command("say 时常烦劳"+ RANK_D->query_respect(me) +"，如何过意得去？此事"+ RANK_D->query_respect(me) +"就不必太过操心了。");
		return 1;
	}
	else if ((int)me->query_condition("th_yapu_fail") > 0)
	{
		command("hmm " +me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"还是先歇歇，让别人处理这事罢。");
		return 1;
	}
	else if(me->query("find_yapu"))
	{
		command("say 先前的"+me->query("find_yapu")+"你还没找到吧？");
		return 1;
	}
	else
	{
		ob = new("/d/taohua/npc/yapu_npc");
		jiading = new("/d/taohua/npc/jiading");
		room = load_object(yapu_room[random(sizeof(yapu_room))]);
		if ( strsrch(file_name(room), "/d/") != 0	
			||  undefinedp(region = region_names[explode(file_name(room), "/")[1]]))
		region = "";

		command("say 最近有个"+ob->query("real_name")+"时常在"+region+"一带为恶。");
		message_vision("陆乘风招了招手，一个庄丁走进了大厅，向$N作了个揖。\n",me);
		jiading->move(environment(me));
		command("say 他曾在"+room->query("short")+CYN"发现此人行踪，看来便像寻常的"+ob->name()+"打扮，你可带他到那附近找找看。"NOR);
		command("say 要是能指认(ren)出来，就把这"+ob->query("real_name")+"擒下，割哑刺聋，照桃花岛上那些哑仆一般处理罢。");
		me->apply_condition("th_yapu_job", 10);
		me->set("zangbu_yapu",ob->query("id"));
		me->set("find_yapu",ob->query("real_name"));

		jiading->set("find_yapu",ob->query("name"));
		jiading->set("find_yapu_real",ob->query("real_name"));
		jiading->set_leader(me);
		jiading->set("job_master",me->query("id"));
		jiading->set("start",1);
		jiading->set("yapu_region",region);
		jiading->set("yapu_room",room->query("short"));
		jiading->start_check(me);

		ob->move(room);
		ob->set("yapu_target",me->query("id"));
		message("vision", ob->query("name")+"快步走了过来。\n", room, ob);
		ob->random_move();

		//moon is maco's dummy
		if( me->query("id") == "maco" || me->query("id") == "moon" )
		{
			tell_object(me,"此人所在是"+base_name(room) +"\n");
			ob->move(environment(me));
		}
	return 1;
	}
}

int ask_abandon()
{
	object me, ob, jiading, weapon, room; 
	int exp;
	me = this_player();
	exp = me->query("combat_exp");
	if(!me->query("find_yapu"))
	{
		command("? " +me->query("id"));
		return 1;
	}
	else if(me->query("th_yapu_ok"))
	{
		command("haha " +me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"说笑了，这"+me->query("find_yapu")+"已经被你拿下了，不是吗？");
		return 1;
	}

	else if(me->query_condition("th_yapu_job") > 0)
	{
		command("hmm " +me->query("id"));
		command("say 才刚刚要你去捉那"+me->query("find_yapu")+"，怎麽就要放弃？");
		return 1;
	}

	else
	{
		command("say 捉不到那个"+me->query("find_yapu")+"？");
		command("sigh " +me->query("id"));
		command("say 算了，你休息一下，这件事我派其他人处理罢。");
		me->delete("find_yapu");
		me->apply_condition("th_yapu_fail", 10);
		return 1;
	}

}

void wait_job(string id)
{
	delete("yapu_ok/"+id);
}

void wait_job2(string id)
{
	delete("yapu_enough/"+id);
}
