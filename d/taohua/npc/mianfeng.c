//Cracked by Roath
// 武眠风
// Modified by mantian to forbid the abuse of ask yulu-wan may/11/2001

inherit NPC;
string ask_me_1(string name);
string ask_me_2(string name);
void create()
{
	set_name("武眠风", ({ "wu mianfeng", "wu" }));
	set("long","
他是黄药师的五弟子武眠风，他身材瘦小，沉默寡言，在江湖
上名声不响，但却极得黄药师信任，顾而命他掌管桃花岛药房
重地。他在桃花弟子中尤精剑法。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 400000);

	set_skill("force", 120);
	set_skill("bitao-xuangong", 120);
	set_skill("dodge", 120);
	set_skill("luoying-shenfa", 120);
	set_skill("strike", 120);
	set_skill("kick", 120);
	set_skill("luoying-shenjian", 120);
	set_skill("qimen-dunjia", 120);
	set_skill("xuanfeng-saoye", 120);
	set_skill("hand", 120);
	set_skill("lanhua-fuxue", 120);
	set_skill("sword",120);
	set_skill("yuxiao-jian", 120);
	set_skill("literate", 80);

	map_skill("force", "bitao-xuangong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("strike", "luoying-shenjian");
	map_skill("parry", "yuxiao-jian");
	map_skill("hand", "lanhua-fuxue");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("sword","yuxiao-jian");

	prepare_skill("strike", "luoying-shenjian");

	create_family("桃花岛", 2, "弟子");
	setup();
        set("inquiry", ([
		"田七鲨胆散" : (: ask_me_1, "tianqi-san" :),
		"无常丹" : (: ask_me_1, "wuchang-dan" :),
            	"九花玉露丸" : (: ask_me_2, "yulu-wan" :)
        ]));

	set("drug_count", 3);
//	set("yulu_count", 1);

	carry_object("/d/xixia/obj/robe")->wear();
	carry_object("/d/taohua/obj/tiexiao")->wield();
}


string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "桃花岛")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (query("drug_count") < 1)
		return "抱歉，你来得不是时候，已经发完了。";

	if (this_player()->query_condition("work") > 0)
		return "我不是才给过你药吗？怎麽又来要了，真是贪得无厌！";

	ob = new(DRUG_D(name));
	ob->move(this_player());
	this_player()->apply_condition("work", 30);

	add("drug_count", -1);

	message_vision("武眠风给$N一粒" + ob->query("name") + "。\n", this_player());

	return "拿去吧。小心别弄丢了。";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "桃花岛")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if ( this_player()->query("family/master_name") != "黄药师" )
		return "你功夫不够，还是不要为妙。";		

//	if (query("yulu_count") < 1)
//		return "抱歉，你来得不是时候，已经发完了。";
//	if (this_player()->query_condition("work") > 0)
//		return "我不是才给过你药吗？怎麽又来要了，真是贪得无厌！";

	if (this_player()->query("th_ask_drug") >= 1)
	{
		ob = new("/d/taohua/obj/"+name);
		ob->move(this_player());
//		this_player()->apply_condition("work", 5);
//		add("yulu_count", -1);
		this_player()->set("th_ask_drug",0);
		message_vision("武眠风给$N一粒" +ob->query("name")+ "。\n", this_player());
		return "拿去吧。小心别弄丢了。";
	}
	else return "抱歉，九花玉露丸不能给你这种好吃懒做的人，你走吧。";
}
// only give yulu wan to those who do yapu job.  mantian may/09/2001
int accept_kill(object me)
{
	if (me->query("family/family_name") == "桃花岛"){
        command("say 你我本是同门，如何要加害于我！\n");
	me->set("th_killer", 1);
        kill_ob(me);
        return 1;
	}
	return 0;
}
void unconcious()
{
	object ob, me=this_object();

	if ( objectp(ob = me->query_temp("last_damage_from"))
	&& ob->query("family/family_name") == "桃花岛")	
	ob->set("th_killer", 1);

	::unconcious();
}
