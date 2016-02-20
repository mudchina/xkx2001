//Cracked by Roath
// modified by kane

#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

int ask_xueyi();

void create()
{
	set_name("曲三", ({ "qu san", "san", "qu" }));
	set("title", "酒店老板");
	set("nickname", "跛子");
	set("shen_type", 1);

	set("str", 30);
	set("con", 30);
	set("dex", 18);
	set("gender", "男性");
	set("age", 25);
	set("long",
		"他是最近新搬到此地的一个跛子。他无精打彩地招呼着客人，眼睛不时呆呆地看着天空。\n");
	set("special_npc",1);
	set("combat_exp", 700000);
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 50);
        set_skill("force", 120);
	set_skill("bitao-xuangong", 120);
	set_skill("luoying-shenfa", 120);
	set_skill("qimen-dunjia", 120);
	set_skill("hand", 120);
	set_skill("throwing",200);
	set_skill("lanhua-fuxue", 120);
	set_skill("strike", 140);
	set_skill("kick", 100);
	set_skill("luoying-shenjian", 140);
	set_skill("xuanfeng-saoye", 100);
        set_skill("dodge", 110);
        set_skill("parry", 120);

	map_skill("force", "bitao-xuangong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");
        map_skill("strike", "luoying-shenjian");
	map_skill("kick", "xuanfeng-saoye");

        prepare_skill("strike", "luoying-shenjian");

	set("attitude", "friendly");
	set("inquiry", ([
		"黄药师" : "我师…，什么？我这里不卖药。\n",
		"卖药" : "不卖药就是不卖药。\n",
		"曲灵风" : "啊！我，……你说的人我不认识。\n",
		"生意" : "这个么……。\n",
		"学艺" : (: ask_xueyi :),
	]));
	
//	create_family("桃花岛", 2, "弟子");
	set("vendor_goods", ({
		"/d/city/obj/peanut",
		"/d/jiaxing/npc/obj/yadan",
	}));

	setup();
	carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/taohua/obj/bagua");
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
        add_action("do_buy", "buy");
//	add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	say("曲三有气无力地说道：这位" + RANK_D->query_respect(ob) + 
			"，买点五香花生下酒吧。\n");
}

/*
void unconcious()
{
	object ob;
	object who = this_player();

        message_vision("\n突然，只见曲三用尽最后一丝气力向$N打出一个铁八卦！\n",
                who);
	who->receive_damage("qi",100);
	who->receive_wound("qi",100);
	ob = new (__DIR__"obj/tiebagua");
        ob->move(environment(this_object()));
	:: unconcious();
}
*/

int accept_object(object me, object obj)
{
	call_out("accept_obj", 2, me, obj);
	return 1;
}

int accept_obj(object me, object obj)
{
	if( obj->query("name") == "黄药师手谕" ) {
		command("ah");
		message_vision(CYN"$N双手颤抖的展开书信，急匆匆的读了起来。\n", this_object());
		message_vision(CYN"$N一边读，一边热泪盈眶！\n", this_object());
		command("cry");
		command("say 多谢"+ RANK_D->query_respect(me) +"了。\n");
		me->set_temp("huang_shouyu",1);
	}

	if( obj->query("name") == "长命锁" ) {
		command("ah");
		command("say 这不是我女儿的东西吗？她现在怎麽样了？！");
		me->set_temp("shagu_amulet", 1);
	}

	if( me->query_temp("huang_shouyu") 
	&& me->query_temp("shagu_amulet") ) {
		command("say 曲某不肖，不为师父分忧，反劳师父日夜牵挂；有劳"+
		RANK_D->query_respect(me) +"费心奔走了。\n");	
		command("thank " + me->query("id"));	
        	if( me->query("family/family_name") == "桃花岛"
        	&& me->query("family/master_name") != "黄药师" ) {
		command("say "+RANK_D->query_respect(me)+"天资不错，在下身无"+
		"长物，唯有一身武艺，若不嫌我武功低浅，可点拨"+RANK_D->query_respect(me)+"一二。");
		command("say "+RANK_D->query_respect(me)+"只需向我询问『学艺』即可。");
		me->set("help_lingfeng",1);
		me->delete_temp("huang_shouyu");
		me->delete_temp("shagu_amulet");	
		me->set_temp("lingfeng_teach",1);
		}
	}	
	destruct(obj);
	return 1;
}

int ask_xueyi()
{
	object me, *ob;
	int i,k=0;

	me = this_player();
	if( !me->query_temp("lingfeng_teach") 
	&& (me->query("family/master_name") != "曲灵风") ){
		command("say "+RANK_D->query_respect(me)+"说笑了，在下只是个穷卖酒的，有啥可教的？");
		return 1;
	}

	if(base_name(environment(me)) != "/d/hangzhou/jiudian"){
		command("say 这得回到酒店再说。");
		return 1;
	}

        ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) ) continue;
		k++;
	}

	if( k > 2 ) {
		command("whisper "+me->query("id")+" 这里耳目众多，实不是传功授艺之所，还是先打发了周围闲人再说。");
		return 1;
	}

	command("say "+RANK_D->query_respect(me)+"随我来。");
	tell_object(me,CYN"曲三脱下破旧的布衣，换上一身青袍，在脸上摸了几把。\n"NOR);
	tell_object(me,CYN"曲三打开碗橱，将一只碗向右旋转，忽听得喀喇喇一声响，橱壁向两旁分开，露出黑黝黝的一个洞来。\n"NOR);

        me->move("/d/hangzhou/mishi");

	return 1;
}
