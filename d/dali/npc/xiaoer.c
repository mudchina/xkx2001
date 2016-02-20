//Cracked by Roath
// waiter.c

#include <ansi.h>

inherit NPC;

string ask_me(string, object);
void do_up(object, object);

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这是一位台夷族的店小二，正笑咪咪地忙招呼客人。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");

	set("chat_chance", 1);
	set("chat_msg", ({
		"店小二道：这里就是南昭大理啦，您有什么想打听的尽管问我。\n",
		"店小二道：这里是大理南部啦，大理城就在北面，再往北可以到中原。\n",
		"店小二道：我们大理山清水秀，有很多地方值得游览哦。\n",
		"店小二道：大理矿藏很丰富，出产铜、铁、铅、金、银、光珠、虎魄、水精、琉璃等等。\n",
		"店小二道：我们这里盛产蚕桑，好多盛皮罗人来这里采购丝绸呢。\n",
	}) );

	set("inquiry", ([
		"巴的甸" : (: ask_me, "bdd" :),
		"星云湖" : (: ask_me, "xyh"  :),
		"天龙寺" : (: ask_me, "tls" :),
		"乌弄城" : (: ask_me, "wnc" :),
		"滇池"   : (: ask_me, "dc" :),
		"here"   : (: ask_me, "xzc":),
		"rumors" : (: ask_me, "yaoyan"  :),
        ]));

	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 500) 
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，小的给您头前引路，客官这就请上楼歇息。\n");
		who->set_temp("rent_paid",1);
		set_temp("leading", 1);
		remove_call_out("do_up");
		call_out("do_up", random(5), this_object(), who);
		return 1;
	}

	else if (ob->query("money_id") && ob->value() >= 10) 
	{
		tell_object(who, "小二忙堆起笑容，说道：多谢您老，有什么话，您尽管问！。\n");
		who->set_temp("ready_ask",1);
		return 1;
	}

	return 0;
}

string ask_me(string name, object ob)
{
	if ( !this_player()->query_temp("ready_ask") )
	return "嘻嘻嘻，嘻嘻嘻，客官 ... ！";

	if ( name == "yaoyan" )
	switch (random(3))
	{
	case 0:
		say(CYN "\n店小二道：您知道吗，大理皇家段氏原本是中原武林世家，经常招收些武林人世为家臣。\n\n" NOR);
	break;
	case 1:
		say(CYN "\n店小二道：大理山高路远，偏远的山村经常有强人出没，您到那些地方去可要小心点哦。\n\n" NOR);
	break;
	}

	if ( name == "xzc" )
		say(CYN "\n店小二道：这里就是喜州城了，往南去不远就是妃丽湖，再南还有龙口城，临元江，那可就是大理的南疆了。\n\n" NOR);

	if ( name == "bdd" )
		say(CYN "\n店小二道：巴的甸在大理西边，一个河谷里，是乌夷族人的地方，小的没去过，据说是大镇。\n\n" NOR);

	if ( name == "xyh" )
		say(CYN "\n店小二笑道：星云湖可是好地方，从大理城往东去好远才到，方圆十多里，风景如画，客官可是想去玩玩？\n\n" NOR);

	if ( name == "dc" )
		say(CYN "\n店小二笑道：滇池是我们大理的名景，客官难道不知道吗？从大理城往东不远就到，那边可热闹呢。\n\n" NOR);

	if ( name == "wnc" )
		say(CYN "\n店小二道：乌弄城可就远啦，在大理北疆呢，从下关城出剑川口再往北百里多才能到，都到川西了。\n\n" NOR);

	this_player()->delete_temp("ready_ask");

	return "这些秘密，小的只告诉您一个人，客官您尽管放心！";
}

int accept_kill(object obj)
{
	if (obj->is_killing(this_object()) ) return 1;
        command("chat 各位客官救命啊！ " + obj->name() + "这个" + RANK_D->query_rude(obj) + "要杀了我！");
}

void do_up(object me, object who)
{
	who->set_leader(me);
	command("go up");                        
	
	tell_object(who, "小二笑嘻嘻地说：客官您运气不错，我们这儿是喜州独一家客店，客房经常爆满哦。\n小二边说边从腰间摘下一大串钥匙，找出一把来给你开门。\n");

	remove_call_out("do_enter");
	call_out("do_enter", random(5), me, who);
}

void do_enter(object me, object who)
{
	who->set_leader(me);
	command("go enter");
	
	tell_object(who, "小二对你笑笑，说：这房间很不错吧！客官您好好休息，小的去忙了，有什么事尽管吩咐。\n");

	who->set_leader(0);
	command("go out");
	command("go down");
	me->set_temp("leading", 0);
}
