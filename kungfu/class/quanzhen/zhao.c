//Cracked by Roath
// /kungfu/class/quanzhen/zhao.c
// zhao.c 赵志敬
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include "auto_perform.h"

string *bd_fighters = ({
					 ("/d/zhongnan/npc/wang-zd.c"),
					 ("/d/zhongnan/npc/shen.c"),
					 ("/d/zhongnan/npc/cui.c"),
					 ("/d/zhongnan/npc/chen-zy.c"),
					 ("/d/zhongnan/npc/li.c"),
					 ("/d/zhongnan/npc/yin.c")
});

string ask_me();
string ask_beidouzhen();
int start();
void killer_show(object me);
int do_throw(string arg);
int auto_perform();

void create()
{
	set_name("赵志敬", ({ "zhao zhijing", "zhao" }));
	set("long",
		"他就是王处一的大弟子赵志敬，在全真教第三代弟子中武功最高。\n"
		"他是一个长须道人，看起来却有些煞气。\n"
		);
	set("gender", "男性");
	set("age", 49);
	set("attitude", "heroic");
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 48);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 0);
	set("combat_exp", 400000);
	set("score", 0);

	set_skill("force", 110);
	set_skill("xiantian-gong", 110);
	set_skill("dodge", 120);
	set_skill("jinyangong", 120);
	set_skill("cuff", 120);
	set_skill("chunyang-quan", 120);
	set_skill("strike", 120);
	set_skill("sanhua-juding", 120);
	set_skill("parry", 120);
	set_skill("sword", 130);
	set_skill("quanzhen-jian", 130);
	set_skill("literate", 100);
	set_skill("taoism", 90);
	set_skill("beidou-zhenfa", 120);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("全真教", 3, "弟子");

	set("inquiry", ([
						"全真教" : "",
						"天罡北斗阵" : (: ask_beidouzhen :),
						"beidouzhen" : (: ask_beidouzhen :),
	]));



	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
}


init()
{
		  ::init();
		  add_action("do_kill_sb","kill");
		  add_action("do_kill_sb","hit");
		  add_action("do_throw","throw");
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
				command("halt");
				command("yun recover");
				ob1->kill_ob(me);
				return 1;
		  }

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
				command("halt");
				command("yun recover");
				this_object()->kill_ob(me);
				return 1;
		  }


	return 0;
}



string ask_beidouzhen()
{
	string msg, name;
	object me = this_player();

	command("look "+me->query("id"));

  if ( me->query("family/family_name") != "全真教" )
  {
		msg = "「天罡北斗阵」是我全真教的剑阵，威力无穷!";
		return msg;
  }

	if( me->query_temp("asked_beidouzhen") )
	{
	  msg="急什么？时辰一到就会开始练习「天罡北斗阵」！\n";
	  return msg;
	}

	if( !me->query_temp("qz/bdgranted" ) )
	{
		msg = "没有掌门人的许可，不得自行练习「天罡北斗阵!";
		return msg;
	}



	if( me->query_temp("pending/beidouzhen") )
	{
		msg="好好练习「天罡北斗阵」！\n";
		command("addoil " + me->query("id"));
		return msg;
	}

	if( query_temp("pending/beidouzhen") || query_temp("beidou_time") )
	{
		msg="没看到我正在忙吗？\n";
		return msg;
	}

	if( query("eff_qi") < query("max_qi")/2 )
	{
		msg="没看到我全身是伤吗？\n";
		return msg;
	}

	if(query_temp("count")>=6)
	{
		msg="可惜现在人已够了！\n";
		return msg;
	}

	if ( me->query_skill("quanzhen-jian",1) <60 || me->query("combat_exp",1)<50000 ||
		  me->query_skill("dodge") <60
		)
	{
		msg = "可惜"+me->query("name")+"武功太差，不够练习「天罡北斗阵」。\n";
		return msg;
	}


	me->set_temp("asked_beidouzhen",1);
	msg = "好，你先做好准备，等一会儿就让你跟随贫道一起练习「天罡北斗阵」！\n";
	set_temp("fighter/" + time(), me->query("id") );
	me->delete_temp("qz/bdgranted" );
	add_temp("count",1);

	command("halt");
	if( query("eff_qi") < query("max_qi") ) exert_function("heal");
	command("yun recover");
	command("dazuo 500");

	remove_call_out("start");
	call_out( "start", 30+ random(30) );
	return msg;
}


int start()
{
	object me = this_object();
	object ob1,ob2,ob3,ob4,ob5,ob6,ob7,ob;
	object here = environment(me);
	mapping fighter;
	int i, *times,j;
	string arg;

	if( !(fighter = me->query_temp("fighter")) )
	{
		return 0;
	}

	times = keys(fighter);
	j = 0;
	for(i = 0; i < sizeof(times); i++) {

	  if( !( ob = present( fighter[times[i]],here) ) )
	  {
		  if( ( ob = find_player( fighter[times[i]]) ) )
		  {
				tell_object(ob,"赵志敬告诉你：跑哪儿去了？不好好跟我练习阵法，当心我告诉掌教真人！\n");
				ob->delete_temp("asked_beidouzhen");
		  }
		  continue;
	  }

	  message_vision(HIY"$N道：$n请做好准备！\n"NOR, me,ob);
	  ob->delete_temp("asked_beidouzhen");
	  ob->move("/d/zhongnan/dajiaochang");
	  if(j==0)ob1=ob;
	  else if(j==1)ob2=ob;
	  else if(j==2)ob3=ob;
	  else if(j==3)ob4=ob;
	  else if(j==4)ob5=ob;
	  else if(j==5)ob6=ob;
	  else if(j==6)ob7=ob;
	  j++;
	}

	command("halt");
	command("yun recover");
	message_vision(HIY"$N道：来人呐！\n"NOR, me);

	for( i = j;i<6;i++)
	{
	  if(i==0){
			if( !(ob1 = present( "wang zhidan",here ) ) )
			{
				ob1=new( bd_fighters[i] );
				ob1->move(environment(me));
				message_vision(HIY"$N快步走了过来，作楫道：有劳各位道兄久等了！\n"NOR, ob1);
			}
		}
	  else if(i==1)
		{
			if( !(ob2 = present( "shen zhifan",here ) ) )
			{
				ob2=new( bd_fighters[i] );
				ob2->move("/d/zhongnan/dajiaochang");
				message_vision(HIY"$N快步走了过来，作楫道：有劳各位道兄久等了！\n"NOR, ob2);
			}
		 }
	  else if(i==2){
			if( !(ob3 = present( "cui zhifang",here ) ) )
			{
				ob3=new( bd_fighters[i] );
				ob3->move("/d/zhongnan/dajiaochang");
				message_vision(HIY"$N快步走了过来，作楫道：有劳各位道兄久等了！\n"NOR, ob3);
			}
		}
	  else if(i==3){
			if( !(ob4 = present( "chen zhiyi",here ) ) )
			{
				ob4=new( bd_fighters[i] );
				ob4->move("/d/zhongnan/dajiaochang");
				message_vision(HIY"$N快步走了过来，作楫道：有劳各位道兄久等了！\n"NOR, ob4);
			}
		}
	  else if(i==4){
			if( !(ob5 = present( "li zhichang",here ) ) )
			{
				ob5=new( bd_fighters[i] );
				ob5->move("/d/zhongnan/dajiaochang");
				message_vision(HIY"$N快步走了过来，作楫道：有劳各位道兄久等了！\n"NOR, ob5);
			}
		}
	  else if(i==5){
			if( !(ob6 = present( "yin zhiping",here ) ) )
			{
				ob6=new( bd_fighters[i] );
				ob6->move("/d/zhongnan/dajiaochang");
				message_vision(HIY"$N快步走了过来，作楫道：有劳各位道兄久等了！\n"NOR, ob6);
			}
	  }
	}


	arg = me->query("id") + "," + ob1->query("id") + "," + ob2->query("id") + "," +
		ob3->query("id") + "," + ob4->query("id") + "," + ob5->query("id") + "," +
		ob6->query("id");

	message_vision(HIG"$N清了清喉咙，大声说道：好，时辰已到，现在开始练习「天罡北斗阵」！\n"NOR,me);

	"/d/zhongnan/dajiaochang"->do_beidouzhen2( arg );

	me->delete_temp("fighter");
	me->delete_temp("count");

	remove_call_out("killer_show");
	call_out( "killer_show",random(10),me );
}


void killer_show(object me)
{
  object ob;


  if( !(me->query_temp("pending/beidou")) ) return;
  if( this_object()->query("eff_qi") < this_object()->query("max_qi")*1/3 ) return;

  ob=new("/d/zhongnan/npc/killer.c");
  ob->move("/d/zhongnan/dajiaochang");
  message_vision(HIR"\n突然山下冲上一个$N!\n"NOR, ob);
  ob->kill_ob(me);
  me->kill_ob(ob);

  if( random(2) == 1)
  {
	  remove_call_out("killer_show");
	  call_out( "killer_show",30+random(15),me );
  }
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
	command("recruit " + ob->query("id"));
}



