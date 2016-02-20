//Cracked by Roath
// laifu.c

inherit NPC;

string ask_me();

void create()
{
	set_name("来福儿", ({ "laifu er","laifu" }) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"他是钟万仇的家丁，大约三十岁年纪，在万劫谷里打杂。\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "peaceful");

	set("apply/attack", 30);
	set("apply/defense", 30);

	set_skill("unarmed", 55);
	set_skill("parry", 55);
	set_skill("dodge", 55);

	set("inquiry", ([
		"段氏"   : "嘘！小声点儿！老爷恨极了姓段的，千万不要在他面前提起“段”字，不然小命不保。",
		"姓段的" : "嘘！小声点儿！老爷恨极了姓段的，千万不要在他面前提起“段”字，不然小命不保。",
		"钟灵"   : "正是我家小姐。她可调皮了，经常出去惹祸，夫人老爷都拿她没办法。",
		"钟万仇" : "正是我家老爷，这儿的谷主。他脾气很坏，你小心些。",
		"夫人"   : "我家夫人名叫甘宝宝，她人可好了，但好象跟老爷有点那个 ... ...",
		"钟灵"   : "正是我家小姐。她可调皮了，经常出去惹祸，夫人老爷都拿她没办法。",
		"无量山" : "谷北就是，从来没去过。小姐好象不久前去了一回。",
//		"道路"   : (: ask_me :),
		]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
	object ling, who;
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (objectp(ling=present("zhong ling", find_object("/d/dali/wjg5.c")))
//	if ( !objectp(ling = find_object("/d/dali/npc/zhongling")) )
 //               ling = load_object("/d/dali/npc/zhongling");
		&& ling->query("bm_hints")==9) {
		command("hehe "+getuid(who));
		command("say 您看起来面挺善的，小的虽然没去过无量山，可是 ... ...");
		command("whisper "+getuid(who)+" 小姐上回打那儿回来以后，小的偶然听到她提起“南，西，南，北 ... 神农帮”等什么的。");
		who->set_temp("bmquest/got_hint1",1);
		return "小的就听到了这些，别的就什么也不知道了。\n";
	}
	else {
		command("shake "+getuid(who));
		return "远来是客，也当敬主，你这人胡扯闲聊，一点礼貌都没有。小心我禀告谷主赶你出去！";
	}
}
