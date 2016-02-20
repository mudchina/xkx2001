//Cracked by Roath
// /kungfu/class/quanzhen/sun.c
// sun.c 清静散人孙不二
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("孙不二", ({ "sun buer", "sun" }));
	set("nickname", "清静散人");
	set("long",
		"她就是全真七子中的孙不二，道号清静散人，是马钰出家以前所娶的妻子。\n她道袍上绘着一个骷髅，原来当年王重阳点化孙不二之时，曾绘了一幅骷髅之图\n赐她，意思说人寿短促，倏息而逝，化为骷髅，须当修真而慕大道。孙不二纪念\n先师，将这图形绣在道袍之上。"
		);
	set("gender", "女性");
	set("age", 62);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 25);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("max_jingli", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set("combat_exp", 600000);
	set("score", 70000);

	set_skill("force", 150);
	set_skill("xiantian-gong", 150);
	set_skill("dodge", 150);
	set_skill("jinyangong", 150);
	set_skill("cuff", 140);
	set_skill("chunyang-quan", 145);
	set_skill("strike", 140);
	set_skill("sanhua-juding", 145);
	set_skill("parry", 140);
	set_skill("sword", 150);
	set_skill("quanzhen-jian", 150);
	set_skill("literate", 120);
	set_skill("taoism", 150);
	set_skill("beidou-zhenfa", 140);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 2, "弟子");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );


	setup();
	if (clonep()) carry_object("/clone/unique/cy-jian");
	carry_object("/d/wudang/obj/greyrobe")->wear();
}


init()
{
		  object ob = this_player();

		  ::init();

		  add_action("do_kill_sb","kill");
		  add_action("do_kill_sb","hit");
		  add_action("do_throw","throw");
}


int do_throw(string arg)
{
		  object victim, ob1, ob, me = this_player();
		  string what, who;

		  if( !arg
		  ||      sscanf(arg, "%s at %s", what, who)!=2)
					 return notify_fail("命令格式: throw <物品> at <某人>。\n");

		  ob = present(what, me);
		  if( !ob ) ob = present(arg, environment(me));
		  if( !ob ) return notify_fail("你要扔什么？\n");

		  if (ob->query("no_drop"))
					 return notify_fail("这个东西不能离开你。\n");

		  if (!(victim = present(who, environment(me))))
					 return notify_fail("这里没有你的目标。\n");

		  if (!victim)
					 return notify_fail("这里并无此人！\n");

		  if (!living(victim))
					 return notify_fail("这不是活物！\n");

		  if ( victim->query("id") == me->query("id")  ) {
					 return notify_fail("自己杀自己？\n");
		  }

		  if ( victim->query("family/family_name") == "全真教"  ) {
				message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！看招！」\n", victim, me);
				message_vision( "$N一声冷笑：大胆狂徒！竟敢当着我面行凶伤人，当我全真教好欺负么？\n", this_object() );
				this_object()->kill_ob(me);
				return 1;
		  }

	return 0;
}


int do_kill_sb(string arg)
{
		  object ob, ob1=this_object(), me = this_player();

		  if ( !arg || arg == "" ) return 0;

		  if ( !ob=present(arg, environment(me)) ) return 0;
		  if ( ob->query("id") == me->query("id")  ) {
					 return notify_fail("自己杀自己？\n");
		  }

		  if ( ob->query("family/family_name") == "全真教"  && ob != ob1 ) {
			  message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
				message_vision("$N一声冷笑：大胆狂徒！竟敢当着我面行凶杀人，当我全真教好欺负么？\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  //message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
		  return 0;
}


void attempt_apprentice(object ob)
{
	mapping fam;
	string name,new_name;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "全真教" )
	{
		command ("say " + RANK_D->query_respect(this_player())
			+ "并非我门中人，习武还是先从各位道长起吧！");
		return;
	}

	if ((int)ob->query_skill("xiantian-gong", 1) < 50) {
		command("say 我全真教乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在玄门先天功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") < 35000) {
		command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	name = ob->query("name");
	new_name = name[0..01]+"志" + name[4..5];
	command("say 从今以后你就叫做" + new_name + "。");
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}


int accept_kill(object me)
{
		  command("say 原来你是恶贼，今天我为民除害。\n");
		  if (present("chongyang jian", this_object())){
		  command("wield chongyang jian");
		  }
		  kill_ob(me);
		  return 1;
}


#include "auto_perform.h"
