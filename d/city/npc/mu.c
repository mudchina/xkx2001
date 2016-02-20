//Cracked by Roath
// /d/city/npc/mu.c
// by sdong 6 / 98

inherit NPC;
string ask_zhaoqing();
string ask_baoming();
int let(string arg);
int start(string host,string challenger);
int do_zhaoqing();
int do_zhongyi();
void full_all(object me);
int check_zhongyi(string girl,string host);
int ask_abandon();

void create()
{
		  set_name("穆易", ({ "mu yi", "mu" }) );
		  set("gender", "男性");
		  set("age", 50);
		  set("long",
"他腰粗膀阔，甚是魁梧，但背脊微驼，两鬓花白，满脸皱纹，神色间\n"+
"甚是愁苦，身穿一套粗布棉袄，衣裤上都打了补钉.\n");
		  set("combat_exp", 10000);
		  set("shen_type",  1);
		  set("attitude", "friendly");

		  set("str", 28);
        set("con", 30);
        set("int", 20);
        set("dex", 27);

        set("max_qi", 800);
		  set("max_jing", 300);
		  set("max_neili", 1000);
		  set("neili", 1000);
		  set("jiali", 30);

        set_temp("apply/armor", 40);

        set_skill("force", 100);
		  set_skill("dodge", 100);
		  set_skill("parry", 100);
		  set_skill("liuhe-qiang", 120);
        set_skill("pike", 120);
		  set_skill("unarmed", 100);

		  map_skill("pike", "liuhe-qiang");
		  map_skill("parry", "liuhe-qiang");

		  set("inquiry", ([
					 "郭啸天" : "他是我义兄。",
					 "包惜弱" : "她是我浑家。",
					 "杨康" : "这是一个道人给我未出世的儿女取的名字。",
					 "郭靖" : "这是我义兄郭啸天的骨肉。",
					 "李萍" : "她是我嫂子",
					 "比武招亲" : (: ask_zhaoqing :),
					 "bwzq" : (: ask_zhaoqing :),
					 "报名" : (: ask_baoming :),
					 "baoming" : (: ask_baoming :),
					 "不招了" : (: ask_abandon :),
					 "abandon" : (: ask_abandon :),
		  ]));

		  set_temp("fighting",0);

		  setup();

		  carry_object("/clone/weapon/qiang")->wield();
		  carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
		  object ob = this_player();

		  ::init();

		  if( interactive(ob) && ob->query("muyi") )
			{
				message("vision",
				"穆易向" + ob->name() +"笑道：我的乖女儿来看老爹啦！\n", ob );
				command("hug "+ob->query("id"));
			}

		  add_action("do_zhaoqing", "认");
		  add_action("do_zhaoqing", "ren");
		  add_action("do_zhongyi", "中意");
		  add_action("do_zhongyi", "want");
}

int ask_abandon()
{
	string name,boyname,host;
	object me,boy,ob;

	remove_call_out("auto_check");
	call_out("auto_check",0);
	me = this_player();

	if( !me->query_temp("zhaoqing") )
	{
		message_vision("$N向$n笑道：你又不在招亲.\n", this_object(), me);
		return 1;
	}


  if(	 query_temp("fighting") )
  {
		message_vision("$N向$n笑道：还在比武呢！比完再说吧。\n", this_object(), me );
		return 1;
  }

	if( (host=query_temp("host")) )
	{
		if( (boy=find_player(host)) )
		{
			if( base_name(boy) == "/d/city/npc/fighter" )
			{
				boy->quit(boy);
			}
			if( (boy=find_player(host)) )
				if(boy->query_temp("defeated")) boy->delete_temp("defeated");
		}
	}

	me->delete_temp("zhaoqing");

	command("say 好，不招就不招，下次再来！");

	if(query_temp("girl"))delete_temp("girl");
	if(query_temp("host"))delete_temp("host");
	if(query_temp("challenger"))delete_temp("challenger");
	if(query_temp("fighting"))delete_temp("fighting");
	return 1;
}


string ask_zhaoqing()
{
	string msg, name;
	object me;

	me = this_player();

	command("look "+me->query("id"));

	if( me->query("gender")=="男性" || me->query("gender")=="无性" )
	{
		message("vision",
	"穆易向" + me->name() +"怒道：你无聊不无聊呀。臭男人还想比武招亲！\n", me );
		command("kick " + me->query("id"));
		msg = "滚蛋!";
		return msg;
	}

	if( me->query("age")<16 )
	{
		message("vision",
	"穆易向" + me->name() +"笑道：小姑娘这麽小就想婆家啦?羞不羞！\n", me );
		command("laugh " + me->query("id"));
		msg = "呵呵呵!";
		return msg;
	}

	if( me->query("age")>80 )
	{
		message("vision",
	"穆易向" + me->name() +"笑道：您老人家这么老还招亲?羞不羞！\n", me );
		command("laugh " + me->query("id"));
		msg = "呵呵呵!";
		return msg;
	}

	if ( me->is_married() )
	{
		message("vision",
	"穆易向" + me->name() +"笑道：想墙外开花也不必这么大张旗鼓！\n", me );
		command("laugh " + me->query("id"));
		msg = "呵呵呵!";
		return msg;
	}

  if( me->query("class") == "bonze" )
  {
		message("vision",
	"穆易向" + me->name() +"道：你身在佛门，这婚嫁之事嘛，不提也罢！\n", me );
		command("walkby " + me->query("id"));
		msg = "呵呵呵!";
		return msg;
	}

//  if( me->query("muyi") > 0)
//  {
//		message("vision",
//	"穆易向" + me->name() +"笑道：哪能天天比武招亲？再好的花也黄了！\n", me );
//		command("laugh " + me->query("id"));
//		msg = "呵呵呵!";
//		return msg;
//	}


	if( query_temp("girl") == me->query("id") )
	{
		msg="爹正在帮你组织比武招亲，不要急！\n";
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return msg;
	}

	if(query_temp("girl"))
	{
		msg="有人正在比武招亲，待会再来吧！\n";
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return msg;
	}

	me->set_temp("zhaoqing",1);
	msg = "好，你愿不愿意认我为干爹?(type 认 or ren)";
	return msg;
}

int do_zhaoqing()
{
	string msg, name;
	object me;


	me = this_player();
	if(!me->query_temp("zhaoqing"))
	{
		message("vision",
		"穆易向" + me->name() +"笑道：这怎么敢当？\n", me );
		return 1;
	}

	if(query_temp("girl"))
	{
		command("say 有人正在比武招亲，待会再来吧！\n");
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	}


	me->set_temp("admitted",1);
	name = me->query("name")+"("+me->query("id")+")";
	command("say " + "小女" + name + "年已及笄，尚未许得婆家。现在开始比武招亲.\n");
	command("say " + "凡年在八十岁以下，尚未娶亲，能胜得小女一拳一脚的，并技压群雄，在下即将小女许配于他.");
	command("chat " + "小女" + name + "年已及笄，尚未许得婆家。现在开始比武招亲.\n");
	command("chat " + "凡年在八十岁以下，尚未娶亲，能胜得小女一拳一脚的，并技压群雄，在下即将小女许配于他.");

	set_temp("girl",me->query("id"));
	set_temp("host",me->query("id"));
	remove_call_out("let");
	call_out("let",0,me->query("id") + " play " + me->query("id"));

	remove_call_out("auto_check");
	call_out("auto_check",30);

	return 1;
}

string ask_baoming()
{
	string msg, name;
	object me;
	string host,challenger,girl;
	int i, age = 0;

	remove_call_out("auto_check");
	call_out("auto_check",0);

	me = this_player();

	command("look "+me->query("id"));

	if( me->query("gender")=="女性" )
	{
		message("vision",
		"穆易向" + me->name() +"怒道：你无聊不无聊呀。我女儿不是同性恋！\n", me );
		command("kick " + me->query("id"));
		msg = "滚!";
		return msg;
	}


	if( me->query("gender")=="无性" )
	{
		msg = "公公不受欢迎!";
		return msg;
	}

	if( me->query("age")<18 )
	{
		message("vision",
	"穆易向" + me->name() +"笑道：小孩子这麽小就想姑娘啦?羞不羞！\n", me );
		command("laugh " + me->query("id"));
		msg = "呵呵呵!";
		return msg;
	}

	if( me->query("age")>80 )
	{
		message("vision",
	"穆易向" + me->name() +"怒道：您老人家这么老还来,老牛吃嫩草?\n", me );
		command("laugh " + me->query("id"));
		msg = "滚蛋!";
		return msg;
	}

	if ( me->is_married() )
	{
		message("vision",
	"穆易向" + me->name() +"笑道：想墙外开花也不必这么大张旗鼓！\n", me );
		command("laugh " + me->query("id"));
		msg = "呵呵呵!";
		return msg;
	}

  if( me->query("class") == "bonze" )
  {
		message("vision",
	"穆易向" + me->name() +"道：你身在佛门，这婚嫁之事嘛，不提也罢！\n", me );
		command("walkby " + me->query("id"));
		msg = "呵呵呵!";
		return msg;
	}

	if( !(girl=query_temp("girl")) )
	{
		msg="现在没有人比武招亲！\n";
		return msg;
	}

	if( me->query_temp("admitted") )
	{
	  msg="你已经报名。急什么？到时会叫你上. \n";
	  return msg;
	}

	if( me->query_temp("defeated") )
	{
		msg="败将一边去！\n";
		return msg;
	}



	if( !(host=query_temp("host")) )
	{
		msg="好，现在你是擂主！\n";
		me->set_temp("admitted",1);
		name = me->query("name")+"("+me->query("id")+")";
		set_temp("host",me->query("id") );
		host = me->query("id");

		remove_call_out("let");
		call_out("let",0,me->query("id") + " play " + me->query("id"));
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return msg;
	}

	if( query_temp("fighting"))
	{
		me->set_temp("admitted",1);
		msg="好。现在有人正在比武，轮到你时会叫你！\n";
		set_temp("boy/" + time(), me->query("id") );
		return msg;
	}


	me->set_temp("admitted",1);
	name = me->query("name")+"("+me->query("id")+")";
	set_temp("challenger",me->query("id") );
	challenger = me->query("id");

	remove_call_out("let");
	call_out("let",0,me->query("id") + " play " + me->query("id"));

	remove_call_out("start");
	call_out("start",20,host,challenger);
	set_temp("fighting",1);
	msg = name + "符合条件，许参加招亲比武.";

	remove_call_out("auto_check");
	call_out("auto_check",30);

	return msg;
}

int start(string host,string challenger)
{
	object ob1,ob2;
	ob1=find_player(host);
	ob2=find_player(challenger);
	if( base_name(ob2) != "/d/city/npc/fighter" ||
	base_name(ob1) != "/d/city/npc/fighter" ) return 0;
	message_vision("一声锣响，穆易宣布$N和$n比赛开始。\n",ob1,ob2);

	if(ob1 && ob2)
	{
		full_all(ob1);
		full_all(ob2);
		ob1->kill_ob(ob2);
		ob2->kill_ob(ob1);
		ob1->set_temp("bwzq",1);
		ob2->set_temp("bwzq",1);
	}
	else
	{
		message_vision("$N和$n有人断线了。\n",ob1,ob2);
		remove_call_out("start");
		call_out("start",10,host,challenger);
	}

	set_temp("fighting",1);
	remove_call_out("auto_check");
	call_out("auto_check",30);
}


int auto_check()
{
		  object ob1,ob2;
		  object me,ob;
		  mapping boy;
		  int i, *times;
		  string host,girl,challenger,name;

		  if( !( girl=query_temp("girl")) )
				return 0;

		  if( !( host=query_temp("host")) )
				return 0;

		  me=find_player(girl);
		  if(!me)
			{
				command("say 咦，比武招亲的女主人"+girl+"跑了？\n");
				ob1=find_player(host);
				if(ob1 && ob1->query_temp("bwzq") && base_name(ob1) == "/d/city/npc/fighter" )
				  ob1->quit(ob1);

				if( ( challenger=query_temp("challenger")) )
				{
				  ob2=find_player(challenger);
				  if(ob2 && ob2->query_temp("bwzq") && base_name(ob2) == "/d/city/npc/fighter" )
					  ob2->quit(ob2);
				}

				command("say 不玩了，比武招亲的女主人"+girl+"都跑了。\n");
				delete_temp("girl");
				delete_temp("host");
				delete_temp("challenger");
				delete_temp("fighting");
				return 0;
		  }

		  name = me->query("name") + "(" + girl +")";
		  command("say " + name + "比武招亲.\n");


		  set_temp("fighting",1);

		  ob1=find_player(host);
			if(ob1 && ob1->query_temp("bwzq") && base_name(ob1) == "/d/city/npc/fighter" )
				 command("say " + ob1->query("name") + "("+host+ ")" + "是现在的擂主.\n");
			else
			{
				delete_temp("host");
				ob1->delete_temp("admitted");
				ob1->set_temp("defeated",1);
				set_temp("fighting",0);
			}

		  if( ( challenger=query_temp("challenger")) )
				{
				  ob2=find_player(challenger);
				  if( ob2)
				  {
					 if( !( host=query_temp("host")) )
					  if(ob2->query_temp("bwzq") && base_name(ob2) == "/d/city/npc/fighter")
					 {
					  set_temp("host",challenger);
					  delete_temp("challenger");
					  host = challenger;
					  command("say " + ob2->query("name")+"("+host+")" + "是现在的擂主.\n");
					 }

					  if(!ob2->query_temp("bwzq") || !(base_name(ob2) == "/d/city/npc/fighter") )
					  {
						 ob2->set_temp("defeated",1);
						 delete_temp("challenger");
						 set_temp("fighting",0);
					  }

					}
					else
					{
						delete_temp("challenger");
					  if(ob1)
					  {
						 command("say " + "咦，攻擂的跑了？\n");
					  }
					  else
					  {
						 command("say " + "咦，没人打擂？\n");
					  }
					  set_temp("fighting",0);
					  remove_call_out("auto_check");
					  call_out("auto_check",1);
					  return 0;
					}
				}
			else set_temp("fighting",0);


		  if( query_temp("fighting") )
		  {
			  command("say 比武正在进行.\n");
			  remove_call_out("auto_check");
			  call_out("auto_check",30);
			  return 0;
		  }



		  if( !(boy = query_temp("boy")) )
		  {
				return check_zhongyi(girl,host);
		  }

		  times = keys(boy);
		  for(i = 0; i < sizeof(times); i++) {
					 if( !(me = find_player( boy[times[i]] ) ) )
								continue;
					 break;
		  }

		  if( i >= sizeof(times) )
		  {
			  return check_zhongyi(girl,host);
			}

		  map_delete(boy, times[i]);

	if(objectp(me))
	{
		name = me->query("name")+"("+me->query("id")+")";
		command("say " + name + "符合条件，现在开始和"+host+"比武.\n");
		set_temp("challenger",me->query("id") );
		challenger = me->query("id");

		remove_call_out("let");
		call_out("let",0,me->query("id") + " play " + me->query("id"));

		set_temp("fighting",1);
		remove_call_out("start");
		call_out("start",20,host,challenger);
		return 1;
	 }

	return check_zhongyi(girl,host);
}

int check_zhongyi(string girl,string host)
{
		  object ob1,ob2;
        string challenger;

		  ob1=find_player(girl);
		  ob2=find_player(host);

		  if(!ob1)
		  {
				command("say 咦，比武招亲的女主人"+girl+"跑了？\n");
				ob1=find_player(host);
				if(ob1 && ob1->query_temp("bwzq") && base_name(ob1) == "/d/city/npc/fighter" )
				  ob1->quit(ob1);

				if( ( challenger=query_temp("challenger")) )
				{
				  ob2=find_player(challenger);
				  if(ob2 && ob2->query_temp("bwzq") && base_name(ob2) == "/d/city/npc/fighter" )
					  ob2->quit(ob2);
				}

				command("say 不玩了，比武招亲的女主人"+girl+"都跑了。\n");
				delete_temp("girl");
				delete_temp("host");
				delete_temp("challenger");
				delete_temp("fighting");
				return 0;

		  }
		  else if(host != girl && ob2)
		  {
				tell_object(ob1, "穆易告诉你：" + RANK_D->query_respect(ob1)+
				"，现在的比武擂主是"+ob2->query("name")+"("+host+"). 你中意他吗？\n(if yes, please type 中意 or want)\n");

				tell_object(ob2, "穆易告诉你：" + RANK_D->query_respect(ob2)+
				"，现在没有人攻擂，你可以问" + ob1->query("name")+"("+girl+")中意你吗，\n不想再玩的话，可以giveup.\n");
		  }

		  command("say 现在正在比武招亲. 赶快报名(ask mu about baoming)。\n");

		  remove_call_out("auto_check");
		  call_out("auto_check",30);
		  return 0;
}

int do_zhongyi()
{
	string name,boyname,host;
	object me,boy,ob,p_ring1,p_ring2;

	me = this_player();
	ob = this_object();


  if( !( host=query_temp("host")) )
	{
		message("vision",
		"穆易向" + me->name() +"笑道：你中意谁呀？\n", me );
		return 1;
	 }

	boy=find_player(host);
	if(!boy || host == me->query("id") )
	{
		message("vision",
		"穆易向" + me->name() +"笑道：你中意谁呀？\n", me );
		return 1;
	 }

	if(!me->query_temp("zhaoqing") || me->query_temp("admitted"))
	{
		message("vision",
		"穆易向" + me->name() +"笑道：你中意谁呀？\n", me );
		return 1;
	}

  if(	query_temp("fighting"))
  {
		message("vision",
		"穆易向" + me->name() +"笑道：还在比武呢！比完再说吧。\n", me );
		return 1;
  }


	boy->quit(boy);
	boy=find_player(host);
	boy->delete_temp("admitted");

	me->delete_temp("zhaoqing");
	me->set("muyi",1);
	name = me->query("name")+"("+me->query("id")+")";
	boyname = boy->query("name")+"("+boy->query("id")+")";

	command("say 哈哈哈，" + boyname+ "技压群雄，武功出众，在下即将小女许配于他.");

	command("chat 哈哈哈，" + "小女" + name + "比武招亲.\n");
	command("chat " + boyname+ "技压群雄，武功出众，在下即将小女许配于他.");


	command("say 好，干爹送你们白金戒指作为嫁妆. 祝你们白头携老，早生贵子！");
	p_ring1 = new("/d/city/obj/pring");
	p_ring1->move(me);
	p_ring2 = new("/d/city/obj/pring");
	p_ring2->move(boy);
	message_vision("$N给$n一枚白金戒指。\n", ob,me);
	message_vision("$N给$n一枚白金戒指。\n", ob,boy);

	if(!me->query("muyi"))
	{
		message_vision("难得父女一场，$N再指点$n几招祖传枪法。\n", ob,me);
		me->set_skill("pike",20+me->query_skill("pike"));
		me->set_skill("liuhe-qiang",20+me->query_skill("liuhe-qiang"));
		message_vision("$N的枪法进步了。\n", me);
	}

	me->move("d/city/zuixianlou2");
	boy->move("d/city/zuixianlou2");

	delete_temp("girl");
	delete_temp("host");
	delete_temp("challenger");
	delete_temp("fighting");
	return 1;
}


int let(string arg)
{
	object ob, dummy,r_guo;
	string pl1, pl2;

	if(!arg) return 0;
	if(sscanf(arg, "%s play %s", pl1, pl2) != 2) {
		pl1 = arg;
		pl2 = arg;
	}

	ob = find_player(pl1);
	if(!ob)
	{
		command("say 没有"+pl1+"这个玩家！ player not found\n");
		return 0;
	}
	dummy = new("/d/city/npc/fighter");
	dummy->set("id", pl2);
	if(!dummy->restore()) {
		destruct(dummy);
		command("say 没有"+pl1+"这个玩家！cannot restore dummy\n");
		return 0;
	}
	dummy->set_temp("link_ob", ob);
	ob->set_temp("body_ob", dummy);
	ob->set_temp("netdead", 1);
	exec(dummy, ob);
	dummy->set_name(dummy->name(1), ({pl2, "fighter dummy"}));
	dummy->setup();
	dummy->move("/d/city/leitai");
	dummy->set_temp("bwzq",1);
	message_vision("$N进入擂台代表$n。\n", ob, dummy);

//	command("chat "+ob->query("name")+"进入擂台代表" + dummy->query("name") );


	tell_object(dummy, "穆易告诉你：" + RANK_D->query_respect(dummy)+
								"，请从武器架上取武器(look jia; get armor from jia and get weapon from jia).\n");

	//r_guo = new("/d/quanzhou/obj/renshen-guo");
	//r_guo->move(dummy);

	return 1;
}

void full_all(object me)
{
	  me->set("eff_jing", (int)me->query("max_jing"));
	  me->set("jing", (int)me->query("max_jing"));
	  me->set("eff_qi", (int)me->query("max_qi"));
	  me->set("qi", (int)me->query("max_qi"));
	  me->set("jingli", (int)me->query("max_jingli"));
	  me->set("neili", (int)me->query("max_neili"));
	  me->set("food", (int)me->max_food_capacity());
	  me->set("water", (int)me->max_water_capacity());
     me->clear_condition();
}
