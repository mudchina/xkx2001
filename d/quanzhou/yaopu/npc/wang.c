//Cracked by Roath
// zhanggui.c

inherit NPC;
inherit F_DEALER;

int ask_me(string);
int ask_yaofang();

void create()
{
	set_name("王通治", ({ "wang tongzhi", "wang"}));
	set("title","药铺掌柜");
	set("gender", "男性" );
	set("age", 62);
	set("long",
		"这是位面目和善的老人，据称医术还过得去。\n");
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("str", 12);
	set("int", 25);
	set("con", 23);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("max_neili", 800);
	set_skill("ding-force", 80);
	set_skill("force", 80);
	map_skill("force", "ding-force");

	set("attitude", "friendly");
	set("rank_info/respect", "大老板");

	set("vendor_goods", ({
		"/d/dongtinghu/obj/badou",
		"/d/dongtinghu/obj/baotai",
		"/d/dongtinghu/obj/chantui",
		"/d/dongtinghu/obj/chuanbei",
		"/d/dongtinghu/obj/chuanshanjia",
		"/d/dongtinghu/obj/fangfeng",
		"/d/dongtinghu/obj/fuling",
		"/d/dongtinghu/obj/gouzhizi",
		"/d/dongtinghu/obj/heshouwu",
		"/d/dongtinghu/obj/heye",
		"/d/dongtinghu/obj/huanglian",
		"/d/dongtinghu/obj/jugeng",
		"/d/dongtinghu/obj/jy-hua",
		"/d/dongtinghu/obj/niuhuang",
		"/d/dongtinghu/obj/renshen",
		"/d/dongtinghu/obj/shadan",
		"/d/dongtinghu/obj/shengdi",
		"/d/dongtinghu/obj/tianqi",
		"/d/dongtinghu/obj/xiongdan",
		"/d/dongtinghu/obj/xionghuang",
		"/d/dongtinghu/obj/xuelianzi",
		"/d/dongtinghu/obj/zhh-hua",
	}));

    set("inquiry", ([
		"药方" : (: ask_yaofang :),
        "金创药" : (: ask_me, "jc-yao" :),
        "养心丸" : (: ask_me, "yx-wan" :),
        "养精丹" : (: ask_me, "yj-dan" :),
        "清心散" : (: ask_me, "qx-san" :),
        "蛇药"   : (: ask_me, "she-yao" :),
        "百草丹" : (: ask_me, "bc-dan" :),
        "九花玉露丸" : (: ask_me, "none" :),
        "田七鲨胆散" : (: ask_me, "none" :),
        "续命八丹" : (: ask_me, "none" :),
        "黑石玉洞丹" : (: ask_me, "none" :),
        "玉真散" : (: ask_me, "none" :),
        "大力丸" : (: ask_me, "none" :),
        "三黄宝蜡丸" : (: ask_me, "none" :),
        "通犀地龙丸" : (: ask_me, "none" :),
        "白云熊胆丸" : (: ask_me, "none" :),
        ]) );
	setup();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			command(query("name")+"笑咪咪地说道：这位" + 
RANK_D->query_respect(ob)+ "，可要买什么药？\n");
			break;
		case 1:
			say( query("name")+"笑咪咪地拱了拱手，说道：这位" + 
RANK_D->query_respect(ob)+ "，请进请进。\n");
			break;
	}
}

int ask_yaofang()
{
	object me = this_player();
    if (!me->query_temp("zg_mark"))
    {
	command("say 老朽不才，医术平平，开不出什么药方。\n");
	    return 1;
    }
	command("say "+RANK_D->query_respect(me)+"要问什么药的方子，尽管说吧。\n");
	return 1;
}

int ask_me(string name)
{
	object me = this_player();
	string myid;
	myid = me->query("id");

        if (!me->query_temp("zg_mark"))
        {
        	
command("say "+RANK_D->query_respect(me)+"要买什么药尽管说，至于这药方嘛………\n");
			return 1;
		}
		
        if ( name == "none" ) 
		{
			command("doubt "+query("id"));
			command ("say 这个。。这个。。。我可实在不知道了。\n");
			return 1;
		}
		
		
		if (name == "jc-yao")
		{
			switch (random(5))
			{
				case 0:
	                command("whisper " + myid + " " + "川贝两钱加生地一钱，加水煎熬就可制成一包金创药。");
					break;
				case 1:
	                command("whisper " + myid + " " + "枸枳子四包，外加生地一钱，加水煎熬就可制成一包金创药。");
					break;
				case 2:
	                command("whisper " + myid + " " + "枸枳子两包，川贝一钱，外加生地一钱，加水煎熬就可制成一包金创药。");
					break;
				case 3:
	                command("whisper " + myid + " " + "川贝两钱加防风三钱，加水煎熬就可制成一包金创药。");
					break;
				case 4:
	                command("whisper " + myid + " " + "枸枳子两包川贝一钱，再加防风一钱，加水煎熬就可制成一包金创药。");
					break;
			}
		}
		
        if (name == "yx-wan")
        {
	    	command("whisper " + myid + " " + "川贝一钱，枸枳子一包，菊梗一钱，加水煎熬就可制成。");
		}
        
        if (name == "yj-dan")
        {
	    	command("whisper " + myid + " " + "荷叶一张，菊梗一钱，加水熬干就可制成。");
		}
        	
        if (name == "qx-san")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "雄黄一钱，以巴豆为清泻剂，加水熬干就可制成。");
					break;
				case 1:
	                command("whisper " + myid + " " + "菊梗两钱，以巴豆为清泻剂，加水熬干就可制成。");
					break;
			}
		}
        
        if (name == "she-yao")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "牛黄一钱，雄黄一钱，加水熬干就可制成。");
					break;
				case 1:
	                command("whisper " + myid + " " + "牛黄一钱，菊梗两钱，加水熬干就可制成。");
					break;
			}
		}
 
        if (name == "bc-dan")
       {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "藏红花一钱，生地两钱，加水熬干就可制成。");
					break;
				case 1:
	                command("whisper " + myid + " " + "藏红花一钱，穿山甲一只，加水熬至成型即可。");
					break;
			}
		}
 	me->delete_temp("zg_mark");
 	return 1;
 }

int accept_object(object who, object ob)
{
	int i;
	if ( ob->query("money_id") )
    {
    	if ( ob->value() >= 10000 )
        {
			
command 
("say 既承"+RANK_D->query_respect(who)+"重金之惠，有何疑问尽管说出，我是知无不言，言无不尽。\n");
           	who->set_temp("zg_mark",1);
			return 1;
		}

		command(":)");
		return 1;
	}

	return 0;
}		

