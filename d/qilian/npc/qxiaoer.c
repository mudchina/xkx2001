//Cracked by Roath
// waiter.c

#include <ansi.h>

inherit NPC;

string ask_me(string, object);

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");

	set("chat_chance", 3);
	set("chat_msg", ({
		"店小二道：客官，如果你想知道详情的话，问我可是找对人了！ 不过， 嘻嘻嘻 ... \n",
		"店小二道：这阵子本店生意好做得很， 南来北往的大爷们随便赏小的们几个钱，都有得花了！\n",
		"店小二道：您知道吗，最近我发现几个家伙在城里古古怪怪的，好象在找什么东西！\n",
	}) );

        set("inquiry", ([
		"少林寺" : (: ask_me, "shaolin" :),
		"武当山" : (: ask_me, "wudang"  :),
		"星宿派" : (: ask_me, "xingxiu" :),
                "丐帮"   : (: ask_me, "gaibang" :),
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
//        else if (ob->query("money_id") && ob->value() >= 20)
//	{
//		tell_object(who, "小二一哈腰，说道：多谢您老，要去小白菜婚姻介绍所，小的这就给您开门去。\n");
//		write("只见小二拉开一道侧门，让你走了进去。\n");
//		who->move("/u/xbc/broker.c");		
//		return 1;
//	}

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
	switch( random(2) ) 
	{
	case 0:
	say(CYN "\n店小二道：您知道吗，最近我发现几个家伙在城里古古怪怪的，好象在找什么东西！\n\n" NOR);
	break;
	case 1:
	say(CYN "\n店小二道：沿着北大街，西边有个岳王庙， 听说岳爷爷常常显灵，还有人在那儿捡到过银子呢！\n\n" NOR);
	break;
	}


	if ( name == "shaolin" )
	say(CYN "\n店小二笑道：要去少林寺哪，得出了城，一直往北走，接著是条大河，那条河呢，就是汉江，\n"
		"            等渡过了河，就到了南阳城，再往北，往西，过了汝州，就是少室山了。 楼上 \n"
		"            有位爷台好象就是从少林寺来的，你不妨去向他打听一下。 不过这爷台看上去 \n"
		"            有点凶，小的胆儿小，可不敢陪您上去了。\n\n" NOR);

	if ( name == "wudang" )
	say(CYN "\n店小二笑道：武当山在扬州城的南面，出了城往西南走，经过一条黄土路，再上山，就是武当\n"
		"            山的三清殿了。不过这条路上常有杀人越货的山大王出没，客官此去定要小心，\n"
		"            最好能带些兵器防身，找几个人结伴同行。\n\n" NOR);

	if ( name == "xingxiu" )
	say(CYN "\n店小二笑道：你要找星宿派？！ 嘻嘻，问我可问对人了，前一阵子碰巧有个怪模怪样的家伙来\n"
		"            这吃酒，先用两手指在酒里浸了半天才喝，满座的酒菜一丝儿都没动！ 你说这家\n"
		"            伙怪不怪？！ 後来来了两个同伙，小的竖起耳朵听了半天，才知道他们就是星宿\n"
		"            派，住在西北边的大雪山边上，好象就叫星宿海。\n\n" NOR);

	if ( name == "gaibang" )
	say(CYN "\n店小二笑道：看你样子穿得光光鲜鲜的，问那些叫化子干什么？！ 不过您既然问了，我就告诉\n"
		"            你吧。叫化子平时都散步各处，有时就躲在城东头的土地庙里， 城中广场中有棵\n"
		"            大榕树，树底下有个大树洞，里面好象也有叫化们进进出出。 有时还听他们念叨\n"
		"            些怪话，天堂，地狱什么的。\n\n" NOR);

	this_player()->delete_temp("ready_ask");

	return "这些秘密，小的只告诉您一个人，客官您尽管放心！";
}

int accept_kill(object obj)
{
        command("chat 各位客官救命啊！ " + obj->name() + "这个" + RANK_D->query_rude(obj
) + "要杀了我！");
}

void do_up(object me, object who)
{
	who->set_leader(me);
	command("go up");                        
	
	tell_object(who, "小二笑嘻嘻地说：客官您算找对地方了，我们这儿是本地最干净的客店。
小二边说边从腰间摘下一大串钥匙，找出一把来给你开门。\n");

	remove_call_out("do_enter");
	call_out("do_enter", random(5), me, who);
}

void do_enter(object me, object who)
{
	who->set_leader(me);
	command("go enter");
	
	tell_object(who, "小二对你笑笑，说：这房间很不错吧!
客官您好好休息，小的去忙了，有什么事尽管吩咐。\n");

	who->set_leader(0);
	command("go out");
	command("go down");
	me->set_temp("leading", 0);
}
