//Cracked by Roath
// /kungfu/class/quanzhen/wang-zd.c
// wang-zd.c  王志坦
// sdong 08/01/98

inherit NPC;

void create()
{
	set_name("王志坦", ({ "wang zhidan", "wang" }));
	set("long",
		"他是一位全真教第三代弟子。\n"
		);
	set("gender", "男性");
	set("age", 46);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 6000);

	set_skill("force", 100);
	set_skill("xiantian-gong", 100);
	set_skill("dodge", 100);
	set_skill("jinyangong", 100);
	set_skill("cuff", 100);
	set_skill("chunyang-quan", 100);
	set_skill("strike", 90);
	set_skill("sanhua-juding", 90);
	set_skill("parry", 100);
	set_skill("sword", 110);
	set_skill("quanzhen-jian", 110);
	set_skill("literate", 80);
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



	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

init()
{
		  object ob = this_player();

		  if( interactive(ob))
		  {

		  }

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

		  if ( victim->query("family/family_name") == "全真教"  && victim != this_object() ) {
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

		  if ( ob->query("family/family_name") == "全真教"  && ob != this_object() ) {
			  message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
				message_vision("$N一声冷笑：大胆狂徒！竟敢当着我面行凶杀人，当我全真教好欺负么？\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  //message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
		  return 0;
}


int accept_object(object me, object obj)
{
		  object ob = this_player();

		  command( "say "+obj->name()+"?");

		  if (
				 obj->query("id") == "ling pai" &&
				 obj->query("name") == "全真教令牌"
			)
			{

			  if ( ob->query("family/family_name") == "全真教" ) {
					 call_out("reward_dest", 1, obj, ob);
			  }
			  else {
					 call_out("thank_dest", 1, obj, ob);
			  }

			  return 1;
		  }

		  if ( obj->query("id") == "ouyang feng" )
		  {
			  if ( ob->query("family/family_name") == "全真教" ) {
					 call_out("reward_feng", 1, obj, ob);
			  }
			  else {
					 call_out("thank_feng", 1, obj, ob);
			  }
			  return 1;
		  }

		  command( "hmm" );
		  command( "say 你给我这东西做什麽？" );

		  return 0;
}

void close_door()
{
	object here = environment(this_object());
	here->delete("exits/down");
	message_vision("$N用手在石壁上一摸，吱地一声，关上了小门。\n", this_object());
}

void reward_dest(object lingpai,object me)
{
	object here = environment(this_object());
	if(lingpai)destruct(lingpai);
	command( "pat "+me->query("id"));

	if( me->query_temp("qz/feng") )
	{
		command( "say "+me->query("name")+"既然有掌门令牌，请带领欧阳锋进去点化吧！\n");
		here->set("exits/down", "/d/zhongnan/yuxuhole.c");
		message_vision("$N用手在石壁上一摸，吱地一声，打开一道小门。\n", this_object());
		call_out("close_door",3);
	}
	else
		command( "say "+me->query("name")+"既然有掌门令牌，请找到欧阳锋进去点化吧！\n");
}


void thank_dest(object obj,object ob)
{
	command( "jump");
	command( "say 多谢啦！\n");
	destruct(obj);
}

void reward_feng(object obj,object ob)
{
	command( "jump");
	command( "say 真没想到你能将欧阳锋擒来，太好啦！\n");

	command( "thumb "+ob->query("id"));
	command( "say 虽然欧阳锋作恶多端，不过丘掌门有令：我道家一向以替天行道，救世渡人为己任，\n若能点化欧阳锋一定功德无量。师兄不如你把他带进玉虚洞化点时间点化吧！\n");
	command("drop feng");

	command( "say 只要你有掌门人令牌就可以进去。\n");

	ob->set_temp("qz/feng",1);
}

void thank_feng(object obj,object ob)
{
	command( "jump");
	command( "say 真没想到你能将欧阳锋擒来，多谢啦！\n");
	call_out("do_destroy",1,obj);
}


void do_destroy(object ob)
{
		  if( ob ) destruct(ob);
}


