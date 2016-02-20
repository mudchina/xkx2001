//Cracked by Roath
// xiaoer2.c 酒店小二

inherit NPC;
inherit F_DEALER;

string ask_me(string);

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
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/baozi",
	}));
        set("inquiry", ([
            "鸡油" : (: ask_me, "oil" :),
            "鸭掌" : (: ask_me, "duck" :),
        ]) );

	setup();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "丐帮" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
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

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n店小二大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/city/beidajie2");
	message("vision","只听“乒”地一声，" +  ob->query("name") +
		"被人从醉仙楼里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
int accept_kill(object obj)
{
//      玩家利用此flood，故改动。   Sure
        command("say 各位客官救命啊！ " + obj->name() + "这个" 
	+ RANK_D->query_rude(obj) + "要杀了我！");
}

string ask_me(string name)
{
	object me = this_player();

	if ( name == "oil" ) {
		me->set_temp("ask_oil", 1);
		return "嘻嘻嘻，赏给小的几两银子，俺就去厨房打些给您老。";
	}

	if ( name == "duck" )
		return "鸭掌？您上楼买些烤鸭，把鸭掌切下来不就得了？";
}

int accept_object(object who, object ob)
{
        if ( ob->query("money_id") ) {
		if ( ob->value() >= 700 && who->query_temp("ask_oil") ) {
			tell_object(who, "店小二一哈腰，说道：多谢您老，小的这就给您打些鸡油来。\n");
			remove_call_out("get_oil");
			call_out("get_oil", 2, this_object(), who);
			return 1;
		}

		tell_object(who, "店小二一哈腰，说道：多谢您老！\n");
		return 1;
	}

	return 0;
}		

void get_oil(object ob, object me)
{
        object ob1 = new("clone/food/jiyou");

	message_vision("$n到厨房转了一圈，拿给$N一罐东西。\n", me, ob);
	ob1->move(me);
	me->delete_temp("ask_oil");
}

