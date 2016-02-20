//Cracked by Roath
// /clone/npc/xibei.c
// sdong, created 12/12/98

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

string *Robber_Name = ({
					 "土匪","山大王","路霸","山贼","毛贼","寨主","帮匪"
});
string *Biaohuo_Name = ({
					 "珍珠","玛瑙","金子","钻石","象牙","玉器","古玩"
});

int in_ask, answer;
int bCheckingRobot;

string ask_job();
string ask_jiebiao();
string ask_abandon();
void assign_xbiaotou(object me, object partner);
void setup_skill(object me,object obj);
int do_jobwith(string arg);
int auto_perform();
private int is_suitable_rob(object victim, object killer);
string QueryDest(object obj);
int assign_rob(object me);
void award2(object dest,object owner);
void award(object me, object ob, object obj);

private int is_suitable(object victim, object killer);

void create()
{
		  set_name("镇西北", ({ "zhen xibei", "zhen", "xibei" }));
		  set("gender", "男性");
		  set("age", 45);
		  set("long",
"    他就是「神鹰镖局」的总镖头－镇西北。他满脸大胡子，眼睛深陷，头包白布，不怒自威，长相
和中原人大不一样，原来是个胡人。据说他曾经受过雪山密宗高手的指点，武功深不可测，特别是天生
臂力惊人，据说一拳能打死一头耗牛。神鹰镖局近年在他的料理下，生意是蒸蒸日上，不但独霸西北，
据说还有挺进中原的野心。\n");

		  set("combat_exp", 900000);
		  set("shen_type", -1);

		  set("jiali", 50);

		  set("gender", "男性");
		  set("age", 45);
		  set("attitude", "peaceful");
		  set("class","lama");
		  set("shen_type", -1);
		  set("str", 45);
		  set("int", 40);
		  set("con", 40);
		  set("dex", 40);
		  set_temp("apply/armor", 90);

		  set("max_qi", 1500);
		  set("max_jing", 1500);
		  set("neili", 3000);
		  set("max_neili", 3000);
		  set("jiali", 100);

		  set_skill("force", 150);
		  set_skill("dodge", 150);
		  set_skill("parry", 150);
		  set_skill("staff", 150);
		  set_skill("strike", 150);
		  set_skill("longxiang-banruo", 150);
		  set_skill("huoyan-dao",150);
		  set_skill("shenkongxing", 150);
		  set_skill("jingang-chu", 160);
		  map_skill("force", "longxiang-banruo");
		  map_skill("parry", "huoyan-dao");
		  map_skill("staff", "jingang-chu");
		  map_skill("strike", "huoyan-dao");
		  map_skill("dodge", "shenkongxing");

		  prepare_skill("strike", "huoyan-dao");

		  set("chat_chance_combat", 40);
		  set("chat_msg_combat", ({
					 (: auto_perform :),
		  }) );


		  set("inquiry", ([
			"保镖" : (: ask_job:),
			"走镖" : (: ask_job:),
			"工作" : (: ask_job:),
			"job" : (: ask_job:),
			"jiebiao" : (: ask_jiebiao:),
			"劫镖" : (: ask_jiebiao:),
			"abandon" : (: ask_abandon:),
			"放弃" : (: ask_abandon:),
		  ]) );

		  set_temp("apply/attack", 50);
		  set_temp("apply/defense", 50);
		  set_temp("apply/damage", 15);
		  setup();
		  carry_object("/clone/weapon/tiezhang")->wield();
		  carry_object("/d/xingxiu/obj/diaoqiu")->wear();
}

void init()
{
		  object ob;

		  add_action("do_jobwith", "jobwith");

		  ::init();
		  if( interactive(ob = this_player()) && !is_fighting()) {
					 call_out("greeting", 1, ob);
		  }
}

void say_question(object ob)
{
	//object ob = this_player();
	int a, b, c, d;
	string oper;

	//if( in_ask || random(20) > 10 ) return;
	if( !ob || !userp(ob) )
	{
		bCheckingRobot = 0;
		return;
	}

	delete_temp("wrong");
	a = random(99) + 1;
	b = random(99) + 1;
	d = random(20) + 1;

	switch(random(5)) {
		case 0:
			if( a * b < 200 ) {

				if( b < a ) { c = b; b = a; a = c; }
				while( a > 1 && b%a > 1 ) {
					c = a;
					a = b%a;
					b = c;
				}
				answer = b%a == 1 ? 1 : a;
				answer = answer % 10;
				oper = chinese_number(a) + "和" + chinese_number(b)+ "的最大公因数的个位数是多少？";

			} else {
				answer = (a * b) % 10;
				answer = answer * d;
				oper = chinese_number(a) + "乘" + chinese_number(b)+ "的个位数然后再乘"+chinese_number(d)+"等於多少？";
			}
			break;
		case 1:
			answer = a % b;
			oper = chinese_number(a) + "除以" + chinese_number(b)+ "的余数是多少？";
			break;
		case 2:
			oper = chinese_number(a) + "和" + chinese_number(b)+ "的最大公因数是多少？";
			if( b < a ) { c = b; b = a; a = c; }
			while( a > 1 && b%a > 1 ) {
				c = a;
				a = b%a;
				b = c;
			}
			answer = b%a == 1 ? 1 : a;
			break;
		case 3:
			answer = (a + b)*d;
			answer = (answer % 100 - answer % 10)/10 ;

			oper = chinese_number(a) + "加上" + chinese_number(b)+ "然后再乘"+chinese_number(d)+"，十位数等于多少？";
			break;
		case 4:
			if (a < b) { c = b; b = a; a = c;}
			answer = a - b;
			answer = answer % d;
			oper = chinese_number(a) + "减去" + chinese_number(b)+ "然后再除以"+chinese_number(d)+"的余数是多少？";
			break;
	}
	//command("say " + oper + "，请在三十秒内作答(da <number>))。");
	message_vision("$N对$n提问道："+oper + "，请在三十秒内作答(da <number>))。\n",this_object(),ob);
	in_ask = 1;
	remove_call_out("say_answer");
	call_out("say_answer", 30, ob);
}

void say_answer(object ob)
{
	object env, *inv;
	int i;

	if( !ob || !userp(ob) )
	{
		bCheckingRobot = 0;
		return;
	}

	ob->add("robot_check_wrong", 1);
	call_out("ans_wrong", 1, ob);


	command("say 这么简单都不会？答案等于" + chinese_number(answer) + "。");
	in_ask = 0;
	remove_call_out("say_question");
	call_out("say_question", 1, ob);
}


int do_answer(string arg)
{
	object ob = this_player();
	string s;
	int ans;

	if( !in_ask ) return notify_fail("你必须等下一题。\n");
	if( !arg ) return notify_fail("请你回答一个数字。\n");

	message_vision( CYN "$N答道：" + arg + "\n" NOR, this_player());

	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add("robot_check", 1);
			command("say 答对了！");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query("robot_check") >= 3 ) {
				command("say 很好，你看起来倒不傻，你可以要个活干了。\n");
				this_player()->delete("robot_check");
				this_player()->delete("robot_check_wrong");
				ob->delete("robot_checking");
				bCheckingRobot = 0;
				return 1;
			}
			else
			{
				remove_call_out("say_question");
				call_out("say_question", 1, ob);
			}

		} else {
			command("say 错！");
			this_player()->add("robot_check_wrong", 1);
			add_temp("wrong/" + this_player()->query("id"), 1);
			call_out("ans_wrong", 0, ob);
			if( query_temp("wrong/" + this_player()->query("id")) > 2 ) {
				command("say " + this_player()->name() + "你再给我乱猜啊，去死吧。\n");
				this_player()->receive_wound("qi", 100, this_object());
				this_player()->set("jingli",-1);
				this_player()->set("qi",-1);
				this_player()->move("/d/island/icefire_land");
				ob->delete("robot_checking");
				ob->delete("robot_check");
				ob->delete("robot_check_wrong");
				bCheckingRobot = 0;
				in_ask = 0;
				remove_call_out("say_question");
				remove_call_out("say_answer");
			}

			//remove_call_out("say_question");
			//call_out("say_question", 1, ob);
		}
	}
	return 1;
}

int ans_wrong(object ob)
{
	if(ob->query("robot_check_wrong") > 5) {
		command("say " + ob->query("name") + "累了，该休息了。\n");
		ob->move("/d/island/icefire_land");
		ob->delete("robot_check_wrong");
		ob->delete("robot_check");
		ob->delete("robot_checking");
		bCheckingRobot = 0;
		in_ask = 0;
		remove_call_out("say_question");
		remove_call_out("say_answer");
	}
	return 1;
}


void greeting(object ob)
{
	int bonus,old_pot;
        string *skname;
        mapping skills;
        int i;

	if( !ob || environment(ob) != environment() ) return;

	if( ob->query("xbiao/bonus") )
	{
		bonus = ob->query("xbiao/bonus");
		command( "thumb "+ob->query("id") );
		message_vision( HIG"$N对着$n笑道：$n干的好！神鹰镖局就要你这样的人才。\n\n"NOR,this_object(),ob);

		if( ob->query("family/family_name") == "丐帮" ) bonus = bonus - 150; // 丐帮 ppl can send letter to get extra bonus

		ob->add("combat_exp", bonus );
		ob->delete("xbiao");

		old_pot = ob->query("potential");
		if(bonus>360)bonus=360;
		ob->add("potential", bonus );
		ob->remove_all_killer();
		ob->add("biaoju/succeed",1);

		if( ob->query("potential") > ob->query("max_potential") )
			ob->set("potential",ob->query("max_potential") );

		if(ob->query_condition("biaoju"))
			ob->clear_one_condition("biaoju");
		add_temp("xbiao", -1);
		log_file("/test/XBiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")在神鹰镖局保镖获得" + bonus + "经验和"+ (ob->query("potential")-old_pot) + "潜能\n" );
	}

	if( ob->query("master_name") == "镖师" || ob->query("master_name") == "趟子手")
	{
		command( "say 本镖局镖师不收徒弟，你得另拜名师！");
		message_vision("\n$N对着$n说道：从今天起，你得另拜名师！\n\n",
								this_object(), ob);

		  ob->delete("family");
		  ob->delete("title");
		  ob->delete("master_id");
		  ob->delete("master_name");
		  ob->set("score", 0);
		  skills = ob->query_skills();

		  if( mapp(skills) ) {
					 skname = keys(skills);
					 for(i=0; i<sizeof(skname); i++)
								skills[skname[i]] /= 2;
		  }
	}

	ob->delete_skill("lingbo-weibu");
	ob->delete_skill("dulong-dafa");

}


int accept_object(object me, object obj)
{
		  object ob = this_player();

		  if ( (obj->name() == "镖货" ) && obj->query("id") == "biao huo" ) {
					 call_out("award", 1, this_object(), ob, obj );
					 return 1;
		  }

		  command( "say 这东西我不感兴趣。" );
		  return 0;
}

void award2(object dest,object owner)
{
	object wage;
	object here = environment(dest);

	if(userp(owner))
	{
		wage=new("/clone/money/gold");
		wage->set_amount( 10 + random(10) );
		wage->move(owner);
		message_vision(HIY"$N"+HIY"递给$n几锭黄金，说：“这是你的赏金，找个地方玩乐去吧！”\n"NOR,dest,owner);
		command("hehe");
		owner->delete_temp("riding");
	}
}


void award(object me, object ob, object obj)
{
	int bonus,old_pot;

	if( !ob || environment(ob) != environment() ) return;

	message_vision( HIY"$N把镖货打开，发现是一堆"+Biaohuo_Name[random(7)]+"。\n"NOR,me);

	if( obj->query("owner") != ob->query("id") )
	{
		message_vision( HIY"$N奸笑道：哪儿拣来的？不过既然落到我手，可没有再还你的道理喔！\n"NOR,me);
		destruct(obj);
		return;
	}

	destruct(obj);

	command( "thumb "+ob->query("id") );
	message_vision( HIG"$N对着$n笑道：$n干的好！神鹰镖局就要你这样的人才。\n\n"NOR,me,ob);
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	ob->delete_temp("apply/short");
	ob->delete_temp("apply/id");
	if(ob->query_condition("biaoju"))
		ob->clear_one_condition("biaoju");
	ob->remove_all_killer();
	ob->add("biaoju/succeed",1);
	call_out("award2",1,me,ob);

	bonus = 1800 + random(1200);
	ob->add("combat_exp", bonus );

	old_pot = ob->query("potential");
	ob->add("potential", bonus/2 );

	if( ob->query("potential") > ob->query("max_potential") )
		ob->set("potential",ob->query("max_potential") );

	log_file("/test/XBiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")在神鹰镖局劫镖获得" + bonus + "经验和"+ (ob->query("potential")-old_pot) + "潜能\n" );
	if(ob->query_condition("biaoju"))
		ob->clear_one_condition("biaoju");
	ob->delete("xbiao");
	add_temp("xbiao", -1);
}


private int is_suitable(object victim, object killer)
{
		  string *no_kill_list = ({
					 "mu ren",
					 "huang zhen",
					 "juexin dashi",
					 "fighter dummy",
					 "xie yanke",
					 "ren woxing",
					 "zuo lengchan",
					 "ouyang zhan",
					 "seng bing",
					 "ding chunqiu",
					 "ouyang feng",
					 "ye erniang",
					 "ouyang ke",
                "shi wei",
                "shiwei",
                "shiren wushi",
					 "mengmian ren",
					 "black gargoyle",
					 "white gargoyle",
                "figure",
					 "zhen xibei",
					 "niao shi",
					 "mengmian ren",
					 "murong bo",
					 "tangzi shou",
					 "wugeng daoren",
					 "pang toutuo",
                "du laoban",
		"bangzhong",
		  });

		  if(  !victim || !clonep(victim) || !living(victim) || userp(victim)
			|| victim->query("race") != "人类"
			|| victim->query("shen") >= 0
			|| victim->query("attitude") == "aggressive"
			|| victim->query("winner")
			|| strsrch(base_name(victim), "/kunfu/skill/") != -1
			|| strsrch(base_name(victim), "/clone/") != -1
			|| strsrch(base_name(victim), "/u/") != -1
			|| strsrch(base_name(victim), "/d/xiakedao/") != -1
			|| victim->query("combat_exp") < killer->query("combat_exp") * 1/4
			|| victim->query("combat_exp") > killer->query("combat_exp")*7/4
			|| victim->query("family/family_name") == "桃花岛"
			|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
		  {
					 return 0;
		  }
		  return 1;
}

void do_leave(object ob)
{
		if( objectp(ob) )
		{
			if( ob->is_busy() || ob->is_fighting())
			{
				message_vision("$N向后一跳，跳出战圈！\n",ob);
				message_vision("$N说道：风紧，扯呼！俺回去报信求援，\n你们坚守就是胜利，千万不要堕了神鹰镖局的威名！\n",ob);
			}
			if(!living(ob))ob->revive(0);
			message_vision("$N急急忙忙离开了。\n",ob);
			destruct(ob);
		}
}


void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) ) return;

	if( obj->query("combat_exp") < me->query("combat_exp") )
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(50) )  );
	}

	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 4000 )
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 30000)
	{
		level = level/2 + random(level/4);
	}
	else if( obj->query("combat_exp") < 60000)
	{
		level = level/2 + random(level/4);
	}
	else if( obj->query("combat_exp") < 300000)
	{
		level = level/2 + random(level/5);
	}
	else
		level = level/3 + random(level/6);

	skills = obj->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
	  obj->set_skill(names[i], level);
	}

	obj->set( "title", "神鹰镖局" );
	obj->delete( "nickname");
	obj->delete( "long");
	obj->delete( "family");
	obj->delete( "name" );
	obj->delete( "short" );

	if( obj->query("combat_exp") < 500000 )
		obj->set_name("趟子手", ({ "tangzi shou", "shou" }));
	else
		obj->set_name("镖师", ({ "biao shi", "biaoshi" }));

	call_out("do_leave",1000,obj);
}


void assign_xbiaotou(object me, object partner)
{
  object ob,here;
  object *target_list;
  int i;

  if( !userp(me) ) return;
  here = environment(me);

  if(!here) return;
  if( strsrch(base_name(here), "/d/") == -1 ) return;

  target_list = filter_array(livings(), "is_suitable", this_object(), me);
  if( sizeof(target_list) == 0 ) {
		  // try again in 5 secs.
		 call_out("assign_xbiaotou", 5, me,partner);
		 return;
  }

  do
  {
	  i = random(sizeof(target_list));
	  ob=new( base_name(target_list[i]) + ".c" );
  }
  while( !living(ob) );

  ob->move(here);
  setup_skill(me,ob);
  ob->set_temp("xbiao/owner",me->query("id") );

  if(partner)ob->set_temp("xbiao/owner2",partner->query("id") );

  ob->set_leader(me);
  message_vision("\n$N快步走了过来!\n", ob);
  message_vision("\n$N对$n抱拳道：“"+RANK_D->query_respect(me)+"，总镖头派我跟着您。俺是粗人，不过对总镖头是忠心耿耿，从今以後，您指东俺绝不往西。“\n\n", ob,me);
}



int do_jobwith(string arg)
{
  object xbiaoche, ob = this_player(), me = this_object(), partner,here=environment(me);
  float diff;
  int penalty;


  if(!arg) return notify_fail("你要和谁搭档？\n");

  partner = present(arg,here);
  if(!partner) return notify_fail("这人不在这里，怎么搭档？\n");

  if( !userp(partner) ) return notify_fail("这人不是真人，怎么搭档？\n");

  message_vision("$N向$n请示说：请问总镖头，我可不可以和"+partner->query("name")+"搭裆走一回镖？\n",ob,me);
  if( partner == ob) return notify_fail("自己和自己搭档？\n");


  if ( ob->query("xbiao/fail") ) {
		ob->delete("xbiao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		ob->apply_condition( "xbiao", penalty );
		ob->add("biaoju/fail",1);
		return notify_fail("你这不中用的家伙，亏你还有脸回来见我要求走镖！\n");
  }


  if ( ob->query_condition("xbiao") )
  {
		return notify_fail("我这里倒有几桩差事，可是暂时信不过你去干！\n");
  }

  if( ob->query("shen") >0 || ob->query("biao/dest") ){
		return notify_fail(RANK_D->query_rude(ob)+"难道是福威镖局派来卧底的？\n");
  }

  if ( ob->query("xbiao") ) {
		command( "angry" );
		return notify_fail("你还没完成任务，怎么便想讨多桩差事？\n");
  }


  if ( ob->query("combat_exp") < 100000 ) {
	command( "hmm" );
	return notify_fail("你武功这麽差，怎么配在本镖局任事？\n");
  }


  if ( ob->query("combat_exp") > 1800000 ) {
	command( "hmm" );
	return notify_fail("你武功这么高，还要两人才能保这份镖？\n");
  }


  if( partner->query("shen") >0 || partner->query("biao/dest") ){
		return notify_fail(RANK_D->query_rude(partner)+"难道是福威镖局派来卧底的？\n");
  }

  if ( (int)partner->query("xbiao/fail") ) {
		partner->delete("xbiao");
		penalty = ( 1 + partner->query("biaoju/fail") * 10 / ( 1+ partner->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		partner->apply_condition( "xbiao", penalty );
		partner->add("biaoju/fail",1);
		return notify_fail("那不中用的家伙，亏还有脸回来见我要求走镖！\n");
  }

  if ( partner->query_condition("xbiao") )
  {
		return notify_fail("我这里倒有几桩差事，可是暂时信不过那家伙去干！\n");
  }


  if ( (int)partner->query("xbiao") ) {
		command( "angry" );
		return notify_fail("那不中用的家伙，还没完成任务，怎么便想讨多桩差事？\n");
  }

  /*

  if( ob->query("robot_checking") )
  {
	command("say 你还是先把问题答完再想别的吧! \n");
	if(bCheckingRobot == 0)
	{
		add_action("do_answer", "answer");
		add_action("do_answer", "da");
		bCheckingRobot = 1;
		call_out("say_question",1,ob);
	}
	return 1;
  }

  if( partner->query("robot_checking") )
  {
	command("say 那不中用的家伙还是先把问题答完再想别的吧! \n");
	if(bCheckingRobot == 0)
	{
		add_action("do_answer", "answer");
		add_action("do_answer", "da");
		bCheckingRobot = 1;
		call_out("say_question",1,partner);
	}
	return 1;
  }

  if( random( 5 ) == 1 && bCheckingRobot == 0)
  {
	command("say 本座不收无用之辈。想在我这儿效命得通过考试才行！");
	add_action("do_answer", "answer");
	add_action("do_answer", "da");
	//if( !wizardp(ob) ) add_action("block_cmd","",1);
	ob->set("robot_checking",1);
	bCheckingRobot = 1;
	call_out("say_question",1,ob);
	return 1;
  }
  */


  if( random(16) == 0 && assign_rob(ob) > 0 )
  {
		command("say 你单独一个人去干好了，要小心行事，务必在限定的时间内完成任务！");
		return 1;
  }

  diff = (float)(partner->query("combat_exp") - ob->query("combat_exp"))*10/(float)(partner->query("combat_exp") + ob->query("combat_exp"))*2.0 ;
  if( diff > 2 || diff < -2) return notify_fail("你们武功差距太大，不宜搭档。\n");

  command( "say 好吧，你来得正是时候，我这儿正缺人用。");
  switch( random(5) ) {
	case 0:
		ob->set("xbiao/dest", "dao baifeng");
		ob->set("xbiao/dest2", "/d/dali/yuxuguan");
		command("say 你把这份东西送到大理王妃刀白凤那儿，这份镖非同小可，一定要小心。");
		break;
	case 1:
		ob->set("xbiao/dest", "hu laoye");
		ob->set("xbiao/dest2", "/d/xingxiu/house");
					 command("say 这是北疆小镇巴依托送的重镖，你得多加小心，丢了可赔不起！");
		break;
	case 2:
		ob->set("xbiao/dest", "ye erniang");
		ob->set("xbiao/dest2", "/d/xixia/dawu");
					 command("say 这份重镖是送到西夏叶二娘的，你得亲自交给她。");
		break;
	case 3:
		ob->set("xbiao/dest", "feng yiming");
		ob->set("xbiao/dest2", "/d/foshan/yxhuiguan");
					 command("say 这有份要送给佛山英雄会馆凤一鸣的镖货，你帮我走一趟吧。");
		break;
	case 4:
		ob->set("xbiao/dest", "wang tongzhi");
		ob->set("xbiao/dest2", "/d/quanzhou/yaopu");
					 command("say 这是泉州济世堂老店所重托的红镖，非同小可。你千万不可大意，务必交到药铺掌柜王通治手里。");
		break;
  }

  message_vision( "$N高声叫道：来人呐！\n", me);
  ob->set_temp("apply/short", ({HIW"神鹰镖局镖师  "NOR+ob->name()+"("+ob->query("id")+")"}));
  ob->delete_temp("riding");
  ob->remove_all_killer();
  ob->apply_condition("biaoju",40);

  if(partner)
  {
	  partner->set_temp("apply/short", ({HIW"神鹰镖局镖师  "NOR + partner->name()+"("+partner->query("id")+")"}));
	  partner->delete_temp("riding");
	  partner->set("xbiao/dest", ob->query("xbiao/dest") );
	  partner->set("xbiao/dest2",ob->query("xbiao/dest2") );
	  partner->remove_all_killer();
	  partner->apply_condition("biaoju",40);
  }


  xbiaoche = new(__DIR__"obj/xbiaoche");
  xbiaoche->move("/d/qilian/lanzhou");
  xbiaoche->set_owner(ob,partner);

  me->add_temp("xbiao", 1);
  assign_xbiaotou(ob,partner);

  command("say 镖车就在外面等着你们。你们要小心行事，所谓镖在人在，镖亡人亡，务必在限定的时间内完成任务！");

  return 1;
}


string ask_abandon()
{
  object ob = this_player(), me = this_object();
  int penalty;

  if( !ob->query("xbiao") ) return "你又没有任务，放弃什么？\n";

  command("angry");
  command("disapp "+ob->query("id") );

  ob->delete("xbiao");
  if(ob->query_condition("biaoju"))
	  ob->clear_one_condition("biaoju");
  ob->delete_temp("apply/name");
  ob->delete_temp("apply/long");
  ob->delete_temp("apply/short");
  ob->delete_temp("apply/id");
  ob->remove_all_killer();
  penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
  ob->apply_condition( "xbiao", penalty );
  ob->add("biaoju/fail",1);

  return "你真是不中用，下回再要差事，我可要考虑考虑！\n";
}

string ask_job()
{
  object xbiaoche, ob = this_player(), me = this_object();
  int penalty;

  if ( ob->query("xbiao/fail") ) {
		ob->delete("xbiao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30 + random(30) ) ;
		ob->apply_condition( "xbiao", penalty );
		ob->add("biaoju/fail",1);
		return "你这不中用的家伙，亏你还有脸回来见我要求走镖！\n";
  }

  if ( ob->query_condition("xbiao") )
  {
		return "我这里倒有几桩差事，可是暂时信不过你去干！\n";
  }

  if ( (int)me->query_temp("xbiao") >= 50000 ) {
	return "今天所有的镖都已送完了，你明天早点来吧。";
  }

  if( ob->query("shen") >0 || ob->query("biao/dest") ){
	return RANK_D->query_rude(ob)+"难道是福威镖局派来卧底的？\n";
  }


  if ( ob->query("xbiao") ) {
		command( "angry" );
		return "你还没完成任务，怎么便想讨多桩差事？\n";
  }

  if ( ob->query("combat_exp") < 100000 ) {
	command( "hmm" );
	return "你武功这麽差，怎么配在本镖局任事？";
  }

  /*

  if( ob->query("robot_checking") )
  {
	if(bCheckingRobot == 0)
	{
		add_action("do_answer", "answer");
		add_action("do_answer", "da");
		bCheckingRobot = 1;
		call_out("say_question",1,ob);
	}
	return "你还是先把问题答完再想别的吧! \n";
  }

  if( random( 5 ) == 1 && bCheckingRobot == 0)
  {
	command("say 本座不收无用之辈。想在我这儿效命得通过考试才行！");
	add_action("do_answer", "answer");
	add_action("do_answer", "da");
	//if( !wizardp(ob) ) add_action("block_cmd","",1);
	ob->set("robot_checking",1);
	bCheckingRobot = 1;
	call_out("say_question",1,ob);
	return "\n";
  }

  */


  if( random(16)==0 && assign_rob(ob) > 0 ) return "你要小心行事，务必在限定的时间内完成任务！";

  if ( ob->query("combat_exp") < 500000 ) {
	command( "hmm" );
	return "你武功差了点，必须至少两人才能保这份镖。再去找一位搭档吧！";
  }

  command( "say 好吧，你来得正是时候，我这儿正缺人用。");

  switch( random(5) ) {
	case 0:
		ob->set("xbiao/dest", "dao baifeng");
		ob->set("xbiao/dest2", "/d/dali/yuxuguan");
		command("say 你把这份东西送到大理王妃刀白凤那儿，这份镖非同小可，一定要小心。");
		break;
	case 1:
		ob->set("xbiao/dest", "hu laoye");
		ob->set("xbiao/dest2", "/d/xingxiu/house");
					 command("say 这是北疆小镇巴依托送的重镖，你得多加小心，丢了可赔不起！");
		break;
	case 2:
		ob->set("xbiao/dest", "ye erniang");
		ob->set("xbiao/dest2", "/d/xixia/dawu");
					 command("say 这份重镖是送到西夏叶二娘的，你得亲自交给她。");
		break;
	case 3:
		ob->set("xbiao/dest", "feng yiming");
		ob->set("xbiao/dest2", "/d/foshan/yxhuiguan");
					 command("say 这有份要送给佛山英雄会馆凤一鸣的镖货，你帮我走一趟吧。");
		break;
	case 4:
		ob->set("xbiao/dest", "wang tongzhi");
		ob->set("xbiao/dest2", "/d/quanzhou/yaopu");
					 command("say 这是泉州济世堂老店所重托的红镖，非同小可。你千万不可大意，务必交到药铺掌柜王通治手里。");
		break;
  }

  message_vision( "$N高声叫道：来人呐！\n", me);
  ob->set_temp("apply/short", ({HIW"神鹰镖局镖头  "NOR+ob->name()+"("+ob->query("id")+")"}));
  ob->delete_temp("riding");
  ob->remove_all_killer();
  ob->apply_condition("biaoju",40);


  xbiaoche = new(__DIR__"obj/xbiaoche");
  xbiaoche->move("/d/qilian/lanzhou");
  xbiaoche->set_owner(ob);

  me->add_temp("xbiao", 1);

  assign_xbiaotou(ob,ob);

  return "镖车就在外面等着你们。你们要小心行事，所谓镖在人在，镖亡人亡，务必在限定的时间内完成任务！";
}

private int is_suitable_rob(object victim, object killer)
{
		  if(  !userp(victim)
			|| victim->query("race") != "人类"
			|| victim->query("shen") < 0
			|| victim->query("biao/dest2") == 0
			|| strsrch(base_name(victim), "/u/") != -1
			|| strsrch(base_name(victim), "/d/xiakedao/") != -1
			|| victim->query("combat_exp") < killer->query("combat_exp") * 4/5
			|| victim->query("combat_exp") > killer->query("combat_exp") * 5/4
			|| victim->query_condition("biaoju") < 25
			)
		  {
					 return 0;
		  }
		  return 1;
}

string QueryDest(object obj)
{
	if ( obj->query("biao/dest") == "dao baifeng" ) return "大理王妃刀白凤";
	else if ( obj->query("biao/dest") == "hu laoye" ) return "北疆小镇巴依";
	else if ( obj->query("biao/dest") == "ye erniang" ) return "西夏叶二娘";
	else if ( obj->query("biao/dest") == "feng yiming" ) return "佛山英雄会馆凤一鸣";
	else if ( obj->query("biao/dest") == "wang tongzhi" ) return "泉州济世堂老店";

	return "神秘地带";
}

string ask_jiebiao()
{
  object xbiaoche, ob = this_player(), me = this_object();
  int penalty;

  if ( ob->query("xbiao/fail") ) {
		ob->delete("xbiao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30 + random(30) ) ;
		ob->apply_condition( "xbiao", penalty );
		ob->add("biaoju/fail",1);
		return "你这不中用的家伙，亏你还有脸回来见我要活干！\n";
  }

  if ( ob->query_condition("xbiao") )
  {
		return "我这里倒有几桩差事，可是暂时信不过你去干！\n";
  }


  if( ob->query("shen") >0 ){
	return RANK_D->query_rude(ob)+"难道是福威镖局派来卧底的？\n";
  }


  if ( ob->query("xbiao") ) {
		command( "angry" );
		return "你还没完成任务，怎么便想讨多桩差事？\n";
  }

  if ( ob->query("combat_exp") < 100000 ) {
	command( "hmm" );
	return "你武功这麽差，怎么配在本镖局任事？";
  }

  if( assign_rob(ob) > 0 ) return "你要小心行事，务必在限定的时间内完成任务！";

  return "现在福威镖局居然没有镖货可让你去劫！看来本镖局已经快要一统江湖了！哈哈哈！";
}


int assign_rob(object me)
{
  object ob,here;
  object *target_list;
  int i;
  string rename;

  if( !userp(me) ) return;
  here = environment(me);

  if(!here) return;
  if( strsrch(base_name(here), "/d/") == -1 ) return;

  target_list = filter_array( users(), "is_suitable_rob", this_object(), me);
  if( sizeof(target_list) == 0 ) {
		 return -1;
  }

  do
  {
	  i = random(sizeof(target_list));
	  ob= target_list[i];
  }
  while( !userp(ob) );

  rename = Robber_Name[random(7)];

  command( "say 好吧，你来得正是时候，我这儿正缺人用。");
  message_vision( "$N说道：扬州福威镖局一直独霸江南和中原，是本镖局进军中原的头号拌脚石。\n", this_object());
  message_vision( "$N接着说道：听说扬州福威镖局的正有重镖由"+ob->query("name")+"运往"+ QueryDest(ob) +"，不如你扮成"+rename+"去抢他几把，让他们破财伤名！\n", this_object());

  me->set_temp("apply/short", ({rename+"(robber)"}));
  me->set_temp("apply/short", ({rename+"(robber)"}));
  me->set_temp("apply/name", ({rename}) );
  me->set_temp("apply/long",  ({"一个黑布蒙面，神秘兮兮的家伙。\n"}));
  me->set_temp("apply/id", ({"robber","zei"}) );
  me->remove_all_killer();
  me->delete_temp("riding");
  me->set("xbiao/owner",ob->query("id"));
  me->set("xbiao/dest",ob->query("biao/dest"));
  me->apply_condition("biaoju",40);
  return 1;
}

#include "/kungfu/class/xueshan/auto_perform.h"
