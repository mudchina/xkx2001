//Cracked by Roath
// kungfu/class/misc/santa.c
// sdong, 12/24/98

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
string ask_gift();
void greeting();

void create()
{
	seteuid(getuid());
	set_name(HIR"圣诞老人"NOR, ({ "shengdan laoren","santa","laoren"}) );
	set("gender", "男性" );
	set("age", 63);
	set("long", HIR"一位红光满面，笑呵呵的白胡子老爷爷。\n"NOR);
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 100);
	set("kar", 100);

	set("max_qi", 50000);
	set("max_jing", 100);
	set("neili", 50000);
	set("max_neili", 50000);
	set("shen_type", 1);
   set("env/yield","yes");

	set("startroom","/d/city/wumiao");

	set("combat_exp", 100000);

	set_skill("force", 400);
	set_skill("hand", 40);
	set_skill("sword", 50);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("huntian-qigong", 400);

	map_skill("force", "huntian-qigong");

	set("chat_chance", 20);
	set("chat_msg", ({
		"圣诞老人笑呵呵说道: 圣诞快乐！快乐！~~\n",
		"圣诞老人快活地唱道: 叮叮铛，叮叮铛，铃儿响叮铛~~\n",
		"圣诞老人笑呵呵说道: 想要礼物吗？我就是神派来送圣诞礼物的。 \n",
		"圣诞老人笑道: 只要是乖孩子，就有圣诞礼物。 \n",
		(: random_move :),
		(: greeting :),
	}) );

	set("inquiry", ([
					 "gift" : (: ask_gift :),
					 "圣诞礼物" : (: ask_gift:),
					 "礼物" : (: ask_gift:),
				  ]) );



	setup();

	::create();
}


void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1);
	}
}

string ask_gift()
{
	object ppl = this_player();
	object santa = this_object();
	object ob;

	if( ppl->query_condition("santa") )
	{
		message_vision("$N对着$n笑道：你才拿到礼物，就又想要啦？\n",santa,ppl);
		random_move();
		return "呵呵呵\n";
	}

	if( ppl->query("combat_exp") < 300 )
	{
		random_move();
		return "DUMMY是不需要礼物的:)";
	}

	seteuid(getuid());

	if (random(8) == 1) {
		 ob = new("/clone/drug/lingzhi");
		 ob->move(santa);
	}
	else if (random(16) == 1) {
		 ob = new("/clone/drug/puti-zi");
		 ob->move(ppl);
	}
	else if (random(16) == 1) {
		 ob = new("/clone/drug/sheli-zi");
		 ob->move(santa);
	}
	else if (random(6) == 1) {
		 ob = new("/clone/drug/xueteng");
		 ob->move(santa);
	}
	else if (random(6) == 1) {
		 ob = new("/clone/drug/xuelian");
		 ob->move(santa);
	}
	else if (random(6) == 1) {
		 ob = new("/clone/drug/cb_renshen");
		 ob->move(santa);
	}
	else if (random(6) != 1) {
		 ob = new("/clone/drug/renshen_guo");
		 ob->move(santa);
	}
	else
	{
		 ob=new("/clone/money/gold");
		 ob->set_amount( 3 + random(5) );
		 ob->move(santa);
	}

	command("pat "+ppl->query("id"));
	if( ppl->query("env/no_accept") )
	{
		command("hmm");
		command("say "+ppl->name()+"不想接受任何东西？");
	}
	else
		command( "give "+ob->query("id")+" to "+ ppl->query("id")  );

	ppl->apply_condition( "santa",20+random(10) );

	return "祝你圣诞快乐！快乐！~~\n";
}

void destroy_me(object me)
{
	destruct(me);
}

void greeting()
{
	object me = this_object();

	command("say 祝你圣诞快乐！快乐~~\n");

	if( strsrch(base_name(environment()), "/d/city/") == -1 )
	{
		message_vision(HIY"$N"+HIY"乘坐风车凌空飞去，转眼就不见了.\n"NOR,me);
		me->move("d/city/wumiao");
		message_vision(HIG"只听空中一阵铃铛声响，$N"+HIG"乘坐风车凌空飞来.\n"NOR,me);
	}

	if( strsrch(ctime(time()), "Dec 25") == -1 )
	{
		message_vision(HIY"$N"+HIY"凄婉地说：圣诞节结束了，我也该回天堂了.\n"NOR,me);
		command("goodbye");
		message_vision(HIY"$N"+HIY"乘坐风车凌空飞去，转眼就不见了.\n"NOR,me);
		call_out("destroy_me",1,me);
	}

	if( random(150) == 0 )
	{
		message_vision(HIY"$N"+HIY"乘坐风车凌空飞去，转眼就不见了.\n"NOR,me);
		call_out("destroy_me",1,me);
	}
}

int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
			 command("smile");
			 command("say 多谢啦 ! 你好心必有好报的 !");
	}

	return 0;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "，老头子我是不打架的:)ⅵ\n");
	return 0;
}

int accept_kill(object victim)
{
		  object me = this_object();
		  object player = this_player();
		  int flag;

		  command("say " + RANK_D->query_respect(player) + "，怎么这么凶？不该不该呀！\n");
		  command("benger " + player->query("id") );
		  if (player->query("env/immortal"))
				flag=1;
		  player->delete("env/immortal");
		  player->unconcious();
		  if (flag) player->set("env/immortal",1);
        command("halt");
		  random_move();
		  return 0;
}



