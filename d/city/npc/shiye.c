//Cracked by Roath
// shiye.c 知府师爷

#include <ansi.h>

inherit NPC;

#define PRICE 8880000      // price for name change (unit: coin).

string do_ask(object);
int do_say(string);
int do_change(string);
int do_rebalance(string);
int do_confirm(object);
int do_payment(string);
int accept_object(object, object);

string new_name;

void create()
{
        set_name("谭友纪", ({ "tan youji", "tan" }));
        set("title", "知府师爷");
        set("gender", "男性");
        set("age", 57);

	set("long", 
		"他就是扬州知府的师爷，眯着一双小眼睛，\n"
		"坐在一张木案前。听说此人极贪，想找他\n"
		"办事，钱财是免不了的。\n");
 	set("attitude", "peaceful");
	
        set("combat_exp", 30000);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage",  20);
        set("shen_type", 0);
 
	set("inquiry", ([
		"更名" : (: do_ask :),
		"改名" : (: do_ask :),
		"换名" : (: do_ask :),
	]));
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	::init();

	ob = this_player();
	ob->delete_temp("paycash");
	ob->delete_temp("processing");
}

int accept_kill(object me)
{
        command("say 也不看看这是什么地方，竟敢在此行凶杀人！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

string do_ask(object me)
{
	me = this_player();
	if ( me->query("name_changed") && !wizardp(me) )
		return "你已经换过一次名字了，再换一次五万两金子！\n";
	
	if ( me->query_temp("processing") )
		return "我正在帮你办。\n";

	add_action("do_da", "da");
	me->set_temp("processing", 1);
	return "这换名字吗，嘿嘿，看你也挺可怜的，就收你"+chinese_number(PRICE/10000)+"两金子吧。你愿意吗？(da 愿意)\n";
}

int do_da(string arg)
{
	object me;

	me = this_player();

	remove_action("do_da", "da");
	
	if (arg == "愿意") {
		tell_object(me, CYN"谭友纪说道：“你想换成什么名字？” (change 名字)\n"NOR);
		add_action("do_namecheck", "change");
	}
	else {
		say(CYN "谭友纪说道：“不愿意就算了！”\n"NOR);
		me->delete_temp("processing");
	}

	return 1;
}

int do_namecheck(string name)
{
	string f_name, old_name;
	int f_gen;
	object me;

	remove_action("do_namecheck", "change");

	me = this_player();
	old_name = me->query("name", 1);
	f_name = me->query("family/family_name", 1);
	f_gen = me->query("family/generation", 1);

	if (name == old_name) {
		tell_object(me, CYN "谭友纪说道：“名字一样，还换什么？”\n"NOR);
		add_action("do_namecheck", "change");
		return 1;
	}
	
	if (!is_chinese(name)) {
		tell_object(me, CYN "谭友纪说道：“这不是中文名字！从想一个吧。”\n"NOR);
		add_action("do_namecheck", "change");
		return 1;
	}
	
	if (strlen(name) > 8) {
		tell_object(me, CYN "谭友纪说道：“这名字太长，最多四个字！”\n"NOR);
		add_action("do_namecheck", "change");
		return 1;
	}
	
	if (f_name == "星宿派" && f_gen == 2) 
		name = name[0..3] + "子";

	if (f_name == "桃花岛" && f_gen == 2) 
		name = name[0..3] + "风";

	if (f_name == "少林派" && (string)me->query("class")=="bonze" ) 
		name = old_name[0..1] + name[0..1];

	if (f_name == "峨眉派" && (string)me->query("class")=="bonze" )
		name = old_name[0..1] + name[0..1];

	if (f_name == "全真教" && (string)me->query("class")=="taoist")
		name = name[0..1] + old_name[2..3] + name[4..5];
		
	tell_object(me, CYN "谭友纪点了点头，说：“你改叫" + name + "，行吗？”(da 行)\n"NOR);
	new_name = name;
	add_action("do_payment", "da");

	return 1;
}

int do_payment(string arg)
{
	object me;

	me = this_player();

	remove_action("do_payment", "da");

	if (arg != "行") {
		say(CYN "谭友纪说道：“回家再想一个吧！”\n"NOR);
	}

	else {
		say(CYN "谭友纪说道：“你是付现钱还是从帐里转？(da 现钱 或 转帐)”\n"NOR);
		add_action("do_rebalance", "da");
	}

	return 1;
}

int do_confirm(object me)
{
	tell_object(me, CYN "谭友纪把你的户口本拿出来，在上面用毛笔画了几个字，说道：“行了，从此以后你就叫"+new_name+"。”\n"NOR);
	message("vision", CYN "谭友纪把" + me->name() + "的户口本拿出来，在上面用毛笔画了几个字，说道：“行了，从此以后你就叫"+new_name+"。”\n"NOR,
		environment(me), me);

	command("chat 自今日起，" + me->query("name") + "(" + me->query("id") + ")"
		+ "改名为" + new_name + "，各位别认错人了。");
	log_file("Name_changer",sprintf("%s(%s) changed name to %s on %s.\n", 
		me->name(), geteuid(me), new_name, ctime(time()) ) );

	me->set("name", new_name);
	me->set("name_changed", 1);
	me->delete("colorname");

	me->delete_temp("processing");	

	return 1;
}

int do_rebalance(string arg)
{
	object me = this_player();	
	int balance;
	
	remove_action("do_rebalance", "da");

	if (arg == "现钱") {
		me->set_temp("paycash", 1);
		say(CYN "谭友纪说道：“那就给钱吧？”\n"NOR);
		return 1;
	}

	else if (arg == "转帐") {
		balance = me->query("balance");
	
		if (balance < PRICE) {
			tell_object(me, CYN"谭友纪说道：“你帐里的钱不够，等存够了在来吧。”\n"NOR);
			message("vision", CYN"谭友纪对" + me->name() + "说道：“你帐里的钱不够，等存够了在来吧。”\n"NOR, 
				environment(me), me);
			return 1;
		}
		else {
			me->add("balance", -PRICE);
			do_confirm(me);
			return 1;
		}
	}

	say(CYN "谭友纪不耐烦道：“你到底是付现钱还是从帐里转？”\n"NOR);
	add_action("do_rebalance", "da");

	return 1;
}

int accept_object(object me, object money)
{
        if(!money->query("money_id")) return 0;

        if( me->query_temp("paycash")) {
		if( money->value() >= PRICE ) {
                        say(CYN"谭友纪忙说：“够了够了，我这就给您换。”\n"NOR);
			me->delete_temp("paycash");
			do_confirm(me);
                        return 1;

                } 
		else {
                        say(CYN"谭友纪摇头道：“你的钱不够！”\n"NOR);
                        return 0;
                }
        } 
	else {
                say(CYN"谭友纪点头笑道：“这，这多不好意思，要办什么事您就吩咐吧。”，说着就把钱揣进口袋。\n"NOR);
                return 1;
        }
}
