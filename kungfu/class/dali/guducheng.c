//Cracked by Roath
// guducheng.c 古笃诚
// Cyz, Ryu, Acep , Mantian

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("古笃诚", ({ "gu ducheng", "gu"}));
	set("long", "　　他黄衫褚巾头，身着黄衣军服，满脸虬髯，神态威猛，腰间插着一对板斧，\n似是纯钢打制。\n");
	set("title","大理国武将");
	set("gender", "男性");
	set("age", 35);
	set("inquiry", ([
		"段正淳": "我家王爷生性风流。",
		"藤甲" : (: ask_me :),
	    ]));
	set_skill("cuff", 60);
	set_skill("jinyu-quan", 60);
	set_skill("dodge", 50);
	set_skill("duanshi-shenfa", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("buddhism", 65);
	set_skill("axe", 60);
	set_skill("kurong-changong",60);
	map_skill("cuff","jinyu-quan");
	map_skill("dodge","duanshi-shenfa");
	map_skill("force","kurong-changong");
	prepare_skill("cuff","jinyu-quan");
	set("str", 32);
	set("int", 21);
	set("con", 27);
	set("dex", 23);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 150000);
	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("大理段家", 15, "弟子");
	setup();
	carry_object("/d/dali/obj/ycloth")->wear(); 	
	carry_object("/d/dali/obj/gangfu")->wield();
}
string ask_me()
{
	mapping fam, log; 
	object ob, me=this_object(), who=this_player(), room=find_object("/d/dali/dinganfu6.c");

	if (!(fam = who->query("family")) 
		|| fam["family_name"] != "大理段家")
		return RANK_D->query_respect(who)+"与本派素无来往，不知此话从何谈起？";

	if (environment()!=room)
		return "对不起，藤甲都在库房里，我没带出来，你等我回去再来问我要吧。\n";

	if (room->query("tengjia_count") >= 5)
		return "藤甲来之不易，现在已经被别人拿光了。";

	if (ob=present("tengjia", who))
		return RANK_D->query_respect(who)+"你现在身上不是有藤甲吗，你一个人能穿几件啊？";

	log = room->query_temp("tengjia");
	if (mapp(log) && log[getuid(who)])
		return "你刚才不是来领过藤甲了吗，怎麽又来要了？";

	if (who->query("dali/rank")<3)
		return "你的级别不够，不能领取藤甲，还是在库房里找点其它的用吧。\n";
/* remove
	if (who->query("dali/tengjia_asked")) {
		if (who->query("dali/arrestmade") - who->query("dali/tengjia_asked") >= 30) {
		who->add("dali/tengjia_count", -1);
		who->delete("dali/tengjia_asked"); 
		return "看你工作勤勉，决定将再配发你一件藤甲，你要小心使用。\n";
		}
	}

	if (who->query("dali/tengjia_count")>=2) {
		if (!who->query("dali/tengjia_asked")) {
			who->set("dali/tengjia_asked",who->query("dali/arrestmade"));
			return "两件藤甲你都已经领走了，不能再要了，还是多作点事等着重新发配吧。\n";
			}
		else return "两件藤甲你都已经领走了，不能再要了，还是在库房里找点其它的用吧。\n";
		}

	if (who->query("dali/tengjia_count")<0)	{
		who->set("dali/tengjia_count", 0);
		}

	who->add("dali/tengjia_count", 1);
*/
	room->set_temp("tengjia/"+who->query("id"),1);
	room->add("tengjia_count", 1);
	ob = new("/d/dali/obj/tengjia.c");
	ob->move(me);
	command("give tengjia to "+getuid(who));
	return "拿去吧，这藤甲来之不易，你要小心使用，努力报国。";
}
void init()
{
	object ob;
    mapping myfam;

    if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if (!wizardp(ob)
			&& (!myfam || myfam["family_name"] != "大理段家")
			&& !ob->query("dali/employee")
			&& (environment(ob)==find_object("/d/dali/dinganfu6")))
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
	}
}
void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision("\n古笃诚看到$N闯进来，大喝一声：你不是大理弟子，给我滚出去，说着一斧头向你砸过来！\n\n", ob);
	call_out("kicking", 0, ob);
	if (interactive(ob = this_player()) && (int)ob->query_condition("dlkiller"))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
void kicking(object ob)
{
	if (!ob || environment(ob)!=environment()) return;
	ob->move("/d/dali/dinganfu2");
	message("vision","只听“乒”地一声，" + ob->query("name") +	"从小门里飞了出来。\n", environment(ob), ob);
}
int accept_object(object who,object ob)
{
	object me=this_object(),room=find_object("/d/dali/dinganfu6.c");

	if (who->query("family/family_name")!="大理段家"
		|| !present(ob,who)
		|| ob->is_character()
		|| userp(ob)
		|| ob->query("id")!="tengjia") return 0;

	command("nod "+who->query("id"));
	remove_call_out("destroying");
	call_out("destroying",1,ob);
//	who->add("dali/tengjia_count", -1);
	room->delete_temp("tengjia/"+who->query("id"));
	room->add("tengjia_count", -1);
	command("say 很好，"+RANK_D->query_respect(who)+"以后需要用藤甲，再来向我要好了。");
	return 1;
}

void destroying(object ob)
{
	destruct(ob);
}
int accept_fight(object me)
{
	mapping fam;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "大理段家")
	{
		command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
		me->apply_condition("dlkiller", 100);
		kill_ob(me);
		return 1;
	}
	else
	{
		command("say 你我本是同门，切搓一二到也无仿。\n");
		return 1;
	}
}
int accept_kill(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("dlkiller", 100);
	kill_ob(me);
	return 1;
}
void unconcious()
{
	message_vision("\n只见$N飞身一闪，从窗口跃了出去，消失无踪了。\n", this_object());
	destruct(this_object());
}
void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
#include "/kungfu/class/dali/master.h"
