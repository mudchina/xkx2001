//Cracked by Roath
// /kungfu/class/dali/zhuwanli.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("褚万里", ({ "zhu wanli", "zhu"}));
    set("long","他是一位身穿黄衣的军官，约莫三十来岁年纪，脸上英气逼人。手持一根铁杆。\n");
	set("title","大理国武将");
    set("gender", "男性");
    set("age", 35);
    set("inquiry", ([
		"投身" : (: ask_me :),
		"效命" : (: ask_me :),
		]));

	set("no_get","王府门口就想抢人吗？");
	set_skill("cuff", 65);
    set_skill("jinyu-quan", 65);
    set_skill("dodge", 65);
    set_skill("duanshi-shenfa", 65);
    set_skill("parry", 60);
    set_skill("force", 60);
    set_skill("staff", 65);
	set_skill("buddhism",70);
    set_skill("kurong-changong",60);
	set_skill("duanjia-jian",70);
    map_skill("cuff","jinyu-quan");
    map_skill("dodge","duanshi-shenfa");
    map_skill("force","kurong-changong");
	map_skill("staff","duanjia-jian");
	map_skill("parry","duanjia-jian");
	prepare_skill("cuff","jinyu-quan");
    set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);
    set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
    set("max_neili", 500);
    set("jiali", 30);
    set("combat_exp", 120000);
    set("attitude", "peaceful");
    set("shen_type", 1);
    create_family("大理段家", 15, "弟子");

    setup();
	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/dali/obj/diaogan")->wield();
}

string ask_me()
{
	object me=this_object(), who=this_player(), room=find_object("/d/dali/wangfu1.c");

	if (who->query("family/family_name")== "大理段家"
		|| who->query("dali/employee")) {
		message_vision("$N瞧了$n一眼，奇怪道：“你已经是大理军官了呀，还来问我作什么？”\n", me, who);
		return RANK_D->query_respect(who)+"闲得没事儿，去看看有什么军务需做，不要来找我捣乱。";
	}

	if (environment(me)!=room)
		return "对不起，我只在王府办理军务，你等我回去再来找我吧。";

	if (who->query("gender")=="无性")
		return "这位公公还是另谋高就吧。";

	if (who->query("class") && who->query("class")!="officer")
		return RANK_D->query_respect(who)+"怎么可以当差，请不要拿卑职开玩笑。";

	if (who->query("combat_exp")<15000)
		return "这位。"+RANK_D->query_respect(who)+"手无缚鸡之力，如何当差？还是请回吧。";

	if (who->query("dali/betrayer"))
		return "你这叛徒，还有脸回来？！";

	if (who->query("family/family_name")== "丐帮")
		return "大理虽是蛮荒之地，可皇家收留乞丐成何体统？"+RANK_D->query_respect(who)+"还是请回吧。";

	if (who->query("shen")>(who->query("combat_exp")/10)
		|| who->query("combat_exp")>350000
		|| who->query("family/family_name")== "桃花岛")
		return RANK_D->query_respect(who)+"已是江湖上赫赫有名的高手，大理偏蛮小国，怎敢劳阁下屈尊？";

	if (who->query("shen")<(-who->query("combat_exp")/50)
		|| who->query("family/family_name")== "白驼山"
		|| who->query("family/family_name")== "星宿派"
		|| who->query("family/family_name")== "雪山派"
		|| who->query("family/family_name")== "血刀门"
		|| who->query("sg/spy")
		|| (who->query("PKS")>20
		&& who->query("combat_exp")/who->query("PKS") < 10000))
		return RANK_D->query_rude(who)+"还敢来投官？大理境内可容不得你这种艰险小人！";

	who->set("dali/employee",1);
	who->set("dali/trust",100);

	command("say 好吧，我收你为王府家臣，希望"+RANK_D->query_respect(me)+"为大理勤勉出力，保国安民。");
	return RANK_D->query_respect(who)+"可要记住，大理国不比江湖门派，你一定要严守法规，否则会被立即开除的。";
}

void attempt_apprentice(object ob)
{
	mapping fam;
    string dldj;

	if (ob->query("family/family_name")=="大理段家") {
		command ("look "+ob->query("id"));
		if (ob->query("shen")<0) {
			command("say 大理境内容不得你这等阴险小人！");
			return;
		}
		command("hehehe "+getuid(ob));
		command("say 你我本是同府共事，想找我学些功夫当然没问题。");
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
		return;
	}

	if ((!ob->query("family/family_name") || ob->query("family/family_name")=="无")
		&& ob->query("dali/trust")>=150) {
		command("say "+RANK_D->query_respect(ob)+"在我府供职多日，勤勉出力，有目共睹，我就替王爷收你做个挂名弟子吧。");
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
		ob->set("class","officer");
		command("addoil "+ob->query("id"));
		return;
	}

	command("shake "+ob->query("id"));
	command("say 我早已投身大理为臣，不再涉足江湖俗务，不能收徒了。");
    return;
}

#include "/kungfu/class/dali/sangong.h"
