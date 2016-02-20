//Cracked by Roath
// j_waiter.c

inherit NPC;
inherit F_VENDOR;
void greeting(object ob);

void create()
{
	set_name("酒馆小二", ({ "xiao er", "xiao", "waiter", "jiuguan waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位酒馆小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
                __DIR__"obj/peanut",
                __DIR__"obj/tofu",
        }));
        set("inquiry", ([
        "打酒" : "嘿嘿，不是小的自夸，我们这的酒可全是上等的好酒！\n",
        "酒" : "客官要喝酒可真是来对地方了，您楼上雅座请。\n",
	]));
	
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
			remove_call_out("greeting");
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
//	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	switch( random(2) ) {
		case 0:
			say( "酒馆小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝点酒暖暖身子吧。\n");
			break;
		case 1:
			say( "酒馆小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进，我们这儿的可都是好酒啊。\n");
			break;
	}
}
