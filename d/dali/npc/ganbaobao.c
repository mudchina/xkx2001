//Cracked by Roath
// ganbaobao.c 甘宝宝

inherit NPC;

string ask_me();

void create()
{
	set_name("甘宝宝", ({ "gan baobao","gan" }));
	set("nickname", "俏夜叉");
	set("long", 
		"她是钟万仇的夫人，钟灵的母亲，甘宝宝。\n"
		"她容貌清秀，看起来大约有三十六七岁。\n");
	set("gender", "女性");
	set("age", 36);
	set("str", 20);
	set("int", 30);
	set("con", 20);
	set("dex", 30);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 15);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("score", 5000);

	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("unarmed", 60);
	set_skill("parry", 60);

	set("inquiry", ([
		"段氏"   : "嘘，小声点儿，外子恨极了段氏，千万不要在他面前提“段”字。",
		"姓段的" : "嘘，小声点儿，外子恨极了段氏，千万不要在他面前提“段”字。",
		"钟灵"   : "那就是小女灵儿啊，她调皮得很，经常外边瞎跑惹祸，唉。",
		"无量山" : "就是北面那片山啦，山高路险。灵儿不久前去了一回，经历了不少危险才回得来。",
//		"道路"   : (: ask_me :),
		]));

	setup();
	carry_object("/d/dali/obj/gcloth")->wear();
	add_money("gold", 1);
}

string ask_me()
{
	object ling, who;
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (objectp(ling=present("zhong ling", find_object("/d/dali/wjg5.c")))
		&& ling->query("bm_hints")==5) {
		command("sneer "+getuid(who));
		command("say 你看起来苯头苯脑的，乱问这些干什么。");
		command("whisper "+getuid(who)+" 灵儿回来以后提起过，走南，西，南，北，还有什么神农帮等等。");
		who->set_temp("bmquest/got_hint1",1);
		return "好象只有这些了，你可别出去乱说啊。\n";
	}
	else {
		command("shake "+getuid(who));
		return "你这人问东问西，定然不怀好意，我什么也不知道，就是知道，也不会告诉你的。";
	}
}
