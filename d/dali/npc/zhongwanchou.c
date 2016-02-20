//Cracked by Roath
// zhongwanchou.c 钟万仇

inherit NPC;

string ask_me();

void create()
{
	set_name("钟万仇", ({ "zhong wanchou","zhong","wanchou" }));
	set("nickname", "马王神");
	set("long", 
		"他就是这万劫谷的谷主了，身着黑衣，身形极高极瘦，一双小扇子般的大手垂在身旁。\n"
		"手上满是青筋暴露着，他看起来四十多岁了，相貌平平。\n");
	set("gender", "男性");
	set("age", 45);
	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 20);
	set("combat_exp", 300000);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 90);

	set("inquiry", ([
		"段氏"   : "不许在这里提姓段的！再提我杀了你！",
		"姓段的" : "不许在这里提姓段的！再提我杀了你！",
		"钟灵"   : "正是小女，调皮得很，整天在外边瞎跑，不听话。",
		"无量山" : "北面那片山就是，山高沟深。小女不久前去了一回，经历了不少危险才回得来。",
//		"道路"   : (: ask_me :),
		]));

	setup();
	carry_object("/d/dali/obj/bcloth")->wear();
	add_money("gold", 1);
}

string ask_me()
{
	object ling, who;
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (objectp(ling=present("zhong ling", find_object("/d/dali/wjg5.c")))
		&& ling->query("bm_hints")==3) {
		command("sneer "+getuid(who));
		command("say 你看起来苯头苯脑的，乱问这些干什么。");
		command("whisper "+getuid(who)+" 我只记得小女回来以后提起过，走南，西，南，北，好象跟神农帮有关。");
		who->set_temp("bmquest/got_hint1",1);
		return "我就知道这些了，你不要再烦我，快滚吧。\n";
	}
	else {
		return "你这家伙鬼头鬼脑，问东问西，想干什么？快滚！滚得不快，老子杀了你！";
	}
}
