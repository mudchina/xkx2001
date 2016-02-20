//Cracked by Roath
// Npc: /kungfu/class/shaolin/xuan-bei.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("玄悲大师", ({
		"xuanbei dashi",
		"xuanbei",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材甚高，\n"
		"但骨瘦如柴，顶门高耸，双目湛然有神。\n"
	);

	set("nickname", "达摩院主持");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1200000);
	set("score", 500000);

	set_skill("force", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
        set_skill("cuff", 120);
        set_skill("luohan-quan", 120);
        set_skill("club", 120);
        set_skill("weituo-gun", 120);
        set_skill("strike", 120);
        set_skill("sanhua-zhang", 120);
        set_skill("hand", 160);
        set_skill("qianye-shou", 160);
        set_skill("claw", 160);
        set_skill("yingzhua-gong", 160);
	set_skill("parry", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 150);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("club", "weituo-gun");
        map_skill("strike", "sanhua-zhang");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "yingzhua-gong");
	map_skill("parry", "yingzhua-gong");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "yingzhua-gong");

	create_family("少林派", 36, "弟子");

	set("inquiry", ([
		"三长老"       : (: ask_me :),
	]));

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄") 
	||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "玄") )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "，你辈份不合，不能越级拜师。");
		return;
	}

	return;
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		command("nod " + ob->query("id"));
	}
}

string ask_me()
{
	mapping fam, skill; 
	object ob, mengzhu, room;
	string *sname, name;
	int i, ready;
	
	name = this_player()->query("name");

	if ( name[0..1] == "玄" )
		return RANK_D->query_respect(this_player()) + 
		"已是玄字辈弟子，何苦跟老衲开这等玩笑！";

	if ( this_object()->query_temp("calling") || this_player()->query_temp("calling"))
		return "我已经叫人去请三位长老了，" 
		+ RANK_D->query_respect(this_player()) + "请耐心等候十天，定有分晓。";

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

        if ( (int)this_player()->query("guilty") > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你累犯数戒，身带重罪，如何配升玄字辈与我等同列！";

	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        seteuid(getuid(this_player()));
        if( !objectp(mengzhu = present("mengzhu", room)) )
        mengzhu = new("/clone/npc/meng-zhu");
        if (userp(this_player()) && this_player()->query("id") == mengzhu->query("winner") ){
        return "阁下身为武林盟主，三长老就不必见了！";
        }

	skill = this_player()->query_skills();
	sname  = keys(skill);

	for(i=0; i<sizeof(skill); i++) {
		if ( skill[sname[i]] < 100 ) 
		return RANK_D->query_respect(this_player()) + 
		"的基本功力未达精深之境，我看尚不够资格晋见三位长老。";
	}

	if ( skill["force"] < 120
	||   skill["hunyuan-yiqi"] < 120	    
	||   skill["dodge"] < 120	    
	||   skill["shaolin-shenfa"] < 120	    
	||   skill["parry"] < 120 )	    
		return RANK_D->query_respect(this_player()) + 
		"如能百尺竿头，再进一步，凭这份修为，我担保三位长老必能有所垂青！";

        if ( (int)this_player()->query_skill("buddhism",1) < 120 )
		return RANK_D->query_respect(this_player()) + 
		"的佛法修为未臻大乘，必然无法获得三位长老的青睐，我看还是不见为好。";

	if( fam["master_name"] != this_object()->name() )
		command("say " + fam["master_name"] + "的徒弟有志气！ 都让我们老头子们没脸混下去了，哈哈哈 ！");
	else 	command("say 好徒儿，有志气！ 都让我们老头子们没脸混下去了，哈哈哈 ！");

	message_vision("$N侧过身跟身边的小沙弥说了几句话，小沙弥点点头，走了出去。\n",this_object());

	this_object()->set_temp("calling", 1);
	this_player()->set_temp("calling", 1);

	ob = present("xiao shami", environment(this_object()) );
	ob->move("/d/shaolin/qyping");

//	ready = 3600 + random(3600);
	ready = 100;
	
	call_out("calling", 1, 0, ready);
	call_out("leaving", 1, 0, ready + 900);

	return "好吧，我派他知会三位长老，他们有空就会下山来走走，届时你在此等候便是。";

}

int calling(int time, int ready)
{
	object room, ob;
	
	if ( time < ready ) {
		time = time + 100;
		call_out("calling", 100, time, ready);
                return 1;
	}
	else {
                if(!( room = find_object("/d/shaolin/fumoquan")) )
                room = load_object("/d/shaolin/fumoquan");

		this_object()->delete_temp("calling");

		switch( random(3) ) {
		case 0:
			ob = present("du nan", room);
			ob->move("/d/shaolin/dmyuan2");
			break;
		case 1:
			ob = present("du jie", room);
			ob->move("/d/shaolin/dmyuan2");
			break;
		case 2:
			ob = present("du e", room);
			ob->move("/d/shaolin/dmyuan2");
			break;
		}
		return 1;
	}	
}

int leaving(int time, int ready)
{
	object room, ob;
	
	if ( time < ready ) {
		time = time + 100;
		call_out("calling", 100, time, ready);
                return 1;
	}
	else {
                if(!( room = find_object("/d/shaolin/dmyuan2")) );
                room = load_object("/d/shaolin/dmyuan2");

		if( objectp(ob = present("du nan", room)) 
		||  objectp(ob = present("du jie", room))
		||  objectp(ob = present("du e",   room)) ) 
		{
			message_vision( ob->name() + "点点头，说道：此间事已了，我去了。\n" + 
					"他说罢大袖飘飘，扬长而出，只一会便消失了踪迹。\n", ob);
			ob->move("/d/shaolin/fumoquan");
		}

		return 1;
	}	
}
#include "/kungfu/class/shaolin/auto_perform.h"
