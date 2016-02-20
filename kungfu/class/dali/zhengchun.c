//Cracked by Roath
// Duan ZhengChun
// Cyz, acep , mantian , mantian
 
inherit NPC;
inherit F_MASTER;

#include "/kungfu/class/dali/auto_perform.h"
 
string ask_me();
string ask_me_1();
 
void create()
{
	set_name("段正淳", ({ "duan zhengchun", "zhengchun", "duan"}));
	set("long","他身形高大，一袭紫袍着身，衬得一张国字脸不怒自威。\n他就是当今皇上，亦是段氏俗家第一高手。\n");
	set("title", "大理第十五代文安皇帝");
	set("gender", "男性");
	set("age", 43);
	set("inquiry", ([
		"段誉" : "便是在下犬子，不久前负气离家出走，唉 ... 可问阁下知否他的下落？",
		"作官" : (: ask_me_1 :),
		]));

	set("dali/rank", 6);
	set_skill("finger", 150);
	set_skill("force", 130);
	set_skill("strike", 125);
	set_skill("dodge", 125);
	set_skill("parry", 125);
	set_skill("sword", 125);
	set_skill("cuff", 125);
	set_skill("buddhism", 130);
	set_skill("yiyang-zhi", 140);
	set_skill("duanjia-jian",140);
	set_skill("duanshi-shenfa",130);
	set_skill("kurong-changong",130);
	set_skill("qingyan-zhang", 140);
	set_skill("jinyu-quan", 120);
	map_skill("cuff","jinyu-quan");
	map_skill("sword","duanjia-jian");
	map_skill("dodge","duanshi-shenfa");
	map_skill("parry", "duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("strike","qingyan-zhang");
	map_skill("finger","yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");

	set("str", 28);
	set("int", 25);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("qi",1200);
	set("max_jing", 800);
	set("jing",800);
	set("max_neili", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 80);
	set("combat_exp", 700000);
	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("大理段家", 15 , "传人");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/dali/obj/zipao")->wear();
}
#include "/kungfu/class/dali/condition.h"

void attempt_apprentice(object ob)
{
	mapping fam;
	string jiachen;
	if (!mapp(fam=ob->query("family"))
		|| fam["family_name"] !="大理段家") {
		command("say "+RANK_D->query_respect(ob)+"还是先在段家做做别的事再来找我吧。");
		return;
	}

	if ((int)ob->query_skill("kurong-changong",1)<80) {
		command("say 我们段家的养气功夫是天南一绝，你还要多下下功夫。");
		return;
	}

	if ((int)ob->query_skill("finger", 1)<75) {
		command("say 我们大理段家向来以指法闻名。");
		command("say "+RANK_D->query_respect(ob)+"你的指法上还要多下下功夫。");
		return;
	}

	message_vision("$N双膝跪倒，对着$n说道：“皇上在上，在下誓死效忠！”\n\n$n哈哈大笑两声，爱卿平身，将$N从地上扶起。\n\n",ob,this_object());
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
    return;
}

string ask_me_1()
{
	mapping skl; 
	object ob, me=this_player();
	string *sname;
	int i, k;

	if (me->query("family/family_name")!="大理段家")
		return RANK_D->query_respect(me)+"如要投官，何不前往中原大宋国？";

	if (me->query("dali/rank")<2)
		return RANK_D->query_respect(me)+"资历尚浅，不够格申请晋升。";

	if (me->query("dali/rank")>=3)
		return RANK_D->query_respect(me)+"官品已高，无须再申请圣旨晋升了。";

	skl=me->query_skills();
    sname=sort_array( keys(skl), (: strcmp :) );
    for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]]<90) k++; }
	if (k>2)
		return RANK_D->query_respect(this_player())+"功力不够，不够资格领取圣旨。";

	if (me->query("family/family_name")!="大理段家"
		&& me->query("dali/employee")) {
		if (me->query("dali/arrestmade") < (me->query("combat_exp")*3/2000))
			return RANK_D->query_respect(me)+"还是请先为大理多出力再来申请升级吧。";
		if (me->query("dali/trust") < (100+me->query("dali/arrestmade")/20))
			return RANK_D->query_respect(me)+"在我大理当差，工作还不够努力啊。";
	}

	ob = new("/d/dali/obj/allow-letter3");
    ob->move(me);
	ob->set("applicant",me->query("id"));
    message_vision("$N获得一道圣旨。\n",me);
    return "好吧，凭这道圣旨，你可以去向卫士领队挑战。";
}
