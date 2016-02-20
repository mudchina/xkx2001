//Cracked by Roath
// Npc: 
// Date: 

inherit NPC;

string ask_me_1(string);
string ask_me_2(string);

void create()
{
	set_name("书童", ({"shu tong","tong",}));
	set("long","他是庄主的随身书童，平素看管藏书。\n");

	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 40);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("strike", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
      set_temp("apply/attack", 20);
      set_temp("apply/defense", 20);

        set("inquiry", ([
		"易经序卦篇" : (: ask_me_1, "yijing1" :),
            "易经说卦篇" : (: ask_me_2, "yijing2" :)
        ]));

	set("yijing1_count", 3);
	set("yijing2_count", 1);

	setup();

        carry_object("/d/taihu/obj/cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "桃花岛")
		return RANK_D->query_respect(this_player()) + 
		"与敝庄素无来往，不知此话从何谈起？";

	if (  present("yi jing", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有吗，怎么又来要了？ 真是无聊！";

	if (query("yijing1_count") < 1)
		return "抱歉，你来得不是时候，书已被取走了。";

	ob = new("/d/taohua/obj/" + name);
	ob->move(this_player());

	add("yijing1_count", -1);

	message_vision("书童给$N一本" + ob->query("name") + "。\n", this_player());

	return "拿去吧。小心别弄丢了。";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "桃花岛")
		return RANK_D->query_respect(this_player()) + 
		"与敝庄素无来往，不知此话从何谈起？";

	if (query("yijing2_count") < 1)
		return "抱歉，你来得不是时候，书已被取走了。";

	ob = new("/d/taohua/obj/" + name);
	ob->move(this_player());

	add("yijing2_count", -1);

	message_vision("书童给$N一本" + ob->query("name") + "。\n", this_player());

	return "拿去吧。小心别弄丢了。";
}
