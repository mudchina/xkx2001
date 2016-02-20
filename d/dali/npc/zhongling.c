//Cracked by Roath
// zhongling.c

inherit NPC;

string ask_me();

void create()
{
	set_name("钟灵", ({ "zhong ling","ling" }) );
	set("gender", "女性");
	set("age", 16);
	set("long",
		"她就是钟万仇的女儿，钟灵，瓜子脸，笑魇如花，十分秀气。\n发现你瞧着她，她也用圆圆的大眼睛上下打量你。\n");
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("apply/attack", 20);
	set("apply/defense", 20);

	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	set("bm_hints", random(10)+1);
        
	set("inquiry", ([
		"段誉"   : "我上次偷跑出去玩，在无量山遇到了段大哥，乱闹了一场，嘻嘻，可有趣了。",
		"无量山" : "就是北面那片山了，没啥好玩的，一群神农帮弟子正在和无量剑作对。嗯 ... 那儿的路很难走。",
//		"道路"   : (: ask_me :),
		]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
	object me, who;
	me=this_object();
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (me->query("bm_hints")==1) {
		command("nod "+getuid(who));
		command("say 你看起来象是个好人，那我就告诉你吧。");
		command("whisper "+getuid(who)+" 我们走南，西，南，北，发现了神农帮聚集的地方。");
		who->set_temp("bmquest/got_hint1",1);
		return "那地方不容易找，你试试看？可千万别告诉别人哟。嘻嘻。\n";
	}
	else {
		return "你随便闯进别人的卧室里来，不象是个好东西，快走开，我什么也不会告诉你的！";
	}
}
