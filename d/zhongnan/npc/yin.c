//Cracked by Roath
// /kungfu/class/quanzhen/yin.c
// yin.c 尹志平
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("尹志平", ({ "yin zhiping", "yin" }));
	set("nickname", "清和真人");
	set("long",
		"他就是邱处机的大弟子尹志平，在全真教第三代弟子中算得上年轻有为。\n"
		"他长的倒是长眉俊目，容貌秀雅，面白无须，可惜朱雀和玄武稍有不和。\n"
		);
	set("gender", "男性");
	set("age", 46);
	set("attitude", "heroic");
	set("shen_type", 0);
	set("str", 25);
	set("int", 28);
	set("con", 28);
	set("dex", 25);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 0);

	set_skill("force", 100);
	set_skill("xiantian-gong", 100);
	set_skill("dodge", 110);
	set_skill("jinyangong", 110);
	set_skill("cuff", 110);
	set_skill("chunyang-quan", 110);
	set_skill("strike", 110);
	set_skill("sanhua-juding", 110);
	set_skill("parry", 110);
	set_skill("sword", 120);
	set_skill("quanzhen-jian", 120);
	set_skill("literate", 90);
	set_skill("taoism", 90);
	set_skill("beidou-zhenfa", 100);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 3, "弟子");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );


	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

init()
{
		  ::init();
		  add_action("do_kill_sb","kill");
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
				message_vision("$N一声冷笑：大胆狂徒！竟敢当着我面行凶伤人，当我全真教好欺负么？\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  //message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
		  return 0;
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

		  if ( victim->query("family/family_name") == "全真教"  && victim != this_object() ) {
				message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！看招！」\n", victim, me);
				message_vision( "$N一声冷笑：大胆狂徒！竟敢当着我面行凶伤人，当我全真教好欺负么？\n", this_object() );
				this_object()->kill_ob(me);
				return 1;
		  }


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

	if ((int)ob->query_skill("xiantian-gong", 1) < 30) {
		command("say 我全真教乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在玄门先天功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") < 5000) {
		command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	name = ob->query("name");
	new_name = name[0..01]+"清" + name[4..5];
	command("say 从今以后你就叫做" + new_name + "。");
	ob->set("name",new_name);
	command("recruit " + ob->query("id",1));
}


#include "auto_perform.h"
