//Cracked by Roath
// Npc: /kungfu/class/shaolin/dao-xiang2.c
// Date: YZC 96/01/19

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();

void create()
{
	set_name("道象禅师", ({
		"daoxiang chanshi",
		"daoxiang",
		"chanshi",
	}));
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 40000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("luohan-quan", 50);
        set_skill("hand", 50);
	set_skill("fengyun-shou", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
        map_skill("hand", "fengyun-shou");
	map_skill("parry",  "fengyun-shou");

	prepare_skill("cuff", "luohan-quan");
        prepare_skill("hand", "fengyun-shou");

	create_family("少林派", 39, "弟子");

	set("inquiry", ([
		"金创药" :    (: ask_me_1 :),
		"小还丹" :    (: ask_me_2 :),
		"大还丹" :    (: ask_me_3 :)
	]));

	set("jin_count", 10);
	set("xiao_count",5);
	set("da_count",  3);

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

string ask_me_1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

        if (  present("bu dai", this_player()) )
                return "对不起，金创药已经发完了";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if (  present("jin chuangyao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";

	if (query("jin_count") < 1) return "对不起，金创药已经发完了";

	ob = new(DRUG_D("sl_jinchuang"));
	ob->move(this_player());

	add("jin_count", -1);

	message_vision("$N获得一包金创药。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";

}

string ask_me_2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present("bu dai", this_player()) )
		return "对不起，小还丹已经发完了";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if (  present("xiaohuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";

	if (query("xiao_count") < 1) return "对不起，小还丹已经发完了";

	ob = new(DRUG_D("xiaohuan-dan"));
	ob->move(this_player());

	add("xiao_count", -1);

	message_vision("$N获得一颗小还丹。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";

}

string ask_me_3()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

        if (  present("bu dai", this_player()) )
                return "对不起，大还丹已经发完了";

	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

	if (  present("dahuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";

	if (query("da_count") < 1) return "对不起，大还丹已经发完了";

	ob = new(DRUG_D("dahuan-dan"));
	ob->move(this_player());

	add("da_count", -1);

	message_vision("$N获得一颗大还丹。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";

}



