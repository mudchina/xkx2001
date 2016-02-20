//Cracked by Roath
// teller.c

inherit NPC;

int tell_fortune();

int do_forge();
int write_card();

void create()
{
	set_name("李铁嘴", ({ "li tiezui", "li"}) );
	set("gender", "男性" );
	set("age", 48);
	set("long", 
"李铁嘴是个买卜算卦的江湖术士，兼代客写书信、调幅。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
	set("shen_type", -1);

        set_skill("unarmed", 30);
	set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);

	set("attitude", "peaceful");
        set("inquiry", ([
		"算命" : (: tell_fortune :),
		"算卦" : (: tell_fortune :),
		"相面" : (: tell_fortune :),
		"拜帖" : (: write_card :),
		"写信" : "李铁嘴说道：代客写信，每页五十文。\n",
		"写调幅" : "李铁嘴说道：可以用各家字迹写调幅，每幅五两白银。\n",
		"伪造" : (: do_forge :),
        ]) );

	setup();
	add_money("silver", 5);
}
 CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*
60) * 60) );


int tell_fortune()
{
	object me=this_player();
	int k;

	if (me->query_temp("tell_fortune")) {
	command("say 算了，我知道你也不知道你的八字，你爹是谁你都不知道吧。");
	command("hehe li tiezui");
	k = (me->query("kar")) ;
	if (k < 15) {
	command ("say " + RANK_D->query_respect(me) + "生不逢时，正是「黄龙未捣，武穆蒙冤，汉室方扶，五丈星殒。」");
	command("nocry " + me->query("id"));
	}
	else if (k < 20) {
	command ("say " + RANK_D->query_respect(me) + "面相平常，身怀绝技，虽屡受坎坷，最终还是可以成功的。");
	command("sigh");
	}
	else if (k < 25) {
	command("say " + RANK_D->query_respect(me) + "生辰阴阳相济，青龙在左，白虎在右，朱雀和玄武稍有不和，总得说来还是不错的，必能左右逢源。");
	command("nod");
	}
	else if (k < 31) { 
	command("say " + RANK_D->query_respect(me) + "印堂发亮，双耳垂间，生就龙凤之相，前途不可限量！");
	command("congra");
	}
	else {
	command("say " + RANK_D->query_respect(me) + "仙风道骨，贵命非是小人可以算出的。");
	command("fear");
	}
	me->delete_temp("tell_fortune");
	return 1;
	}
	else	
	switch (MONEY_D->player_pay(me, 1000)) {
	case 0:
		command("say 算命要收十两银子，不二价。");
		return 1;
	case 2:
		command("say 您的零钱不够了，银票又没人找得开。\n");
		return 1;
        default:
		command("say 甘罗发早子牙迟，彭祖颜回寿不齐，范丹贫穷石崇富，八字生来各有时。\n");
	        message_vision("李铁嘴收了$N十两银子，揣在怀里。\n",me);
		command("say 把你的生辰八字告诉我吧。");
		me->set_temp("tell_fortune",1);
		return 1;
	}
}

int write_card()
{
	say("李铁嘴双手搓了搓干笑道：哦，想拜见华山岳掌门人。。。好吧，就\n"
"三两白银吧。\n");
	this_player()->set_temp("card", 1);
	return 1;
}

int do_forge()
{
	say("李铁嘴两只眼睛四下扫了扫，「嘿嘿嘿」的干笑了几声...\n");
	write(
"李铁嘴轻声跟你说道：不是我吹牛，保证蓦的跟原来字体一模一样，每封信\n"
"	            五十两白银，不二价。\n");
	this_player()->set_temp("marks/李", 1);
	return 1;
}

int accept_object(object who, object ob)
{
	object letter, wage, card;
	letter = new(__DIR__"obj/letter");

        if (who->query_temp("biao/li") && ob->name()=="红镖") {
                who->delete_temp("biao/li");
		who->delete_temp("apply/short");
                command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
                wage = new("/clone/money/silver");
                wage->set_amount(4);
                wage->move(who);
                message_vision("李铁嘴给$N四两白银作为走镖的酬劳。\n", who);
                remove_call_out("destroy");
                call_out("destroy", 1, ob);
                return 1;
        }

	if ((string)ob->query("name")=="信纸") {
	        if( who->query_temp("marks/李") ) {
			this_player()->set_temp("marks/李3", 1);
			write(
"李铁嘴对你说道：造封信容易，先拿五十两银子来。\n");
			this_player()->set_temp("marks/李", 0);
                call_out("destroy", 1, ob);
			return 1;
		} else if( who->query_temp("marks/李2") ) {
                        write(
"李铁嘴皮笑肉不笑的对你说道：伪造这封信可是关系重大啊，得多收五十两。\n");
                        this_player()->set_temp("marks/李4", 1);
			this_player()->set_temp("marks/李2", 0);
                call_out("destroy", 1, ob);
                        return 1;
                }
//              say("李铁嘴说：这是写好了的信，给我干什么?\n");
                return 0;
	}
       
	if( ob->value() >= 5000 ) {
		 if( who->query_temp("marks/李4") ) {
			write(
"李铁嘴对你说道：这封信是造好了，但" + RANK_D->query_respect(who) + 
"要是出了事，千万别把我说出来呀。\n");
			say("李铁嘴给了" + who->query("name") + "一封手信。\n");
			this_player()->set_temp("marks/李4", 0);
			letter->move(who);
			return 1;
		}
		if( who->query_temp("marks/李3") ) {
			write(
"李铁嘴皮笑肉不笑的对你说道：伪造这封信可是关系重大啊，得多收五十两。\n");
			this_player()->set_temp("marks/李4", 1);
			this_player()->set_temp("marks/李3", 0);
			return 1;
		} 
		if( who->query_temp("marks/李") ) {
			write(
"李铁嘴对你说道：你想伪造什么啊? 总得拿个样子来吧。\n");
		this_player()->set_temp("marks/李2", 1);
		this_player()->set_temp("marks/李", 0);
		return 1;
		}
                say(
"李铁嘴一面急忙把钱收起来，一面笑嘻嘻说道：" + RANK_D->query_respect(ob) + 
"，这怎么敢当。\n");
		return 1;
	}
        if( ob->value() >= 500 ) {
		say(
"李铁嘴笑嘻嘻说道：调幅写好了，请您收起来吧，多谢关照。\n");
		return 1;
	}
	if( ob->value() >= 300 && this_player()->query_temp("card") ) {
		say(
"李铁嘴双手接过银两，马上抽出一张大红帖子，摇头幌脑地写起字来。\n"
"一会儿，李铁嘴抬起头来笑嘻嘻地交过拜帖，说道：拜帖写好了，请快\n"
"上华山去吧，多谢关照。\n");
		this_player()->delete_temp("card");
		card = new(__DIR__"obj/visitcard");
		card->move( this_player() );
		return 1;
	}
	if( ob->value() >= 50 ) {
		say(
"李铁嘴笑嘻嘻说道：信写完了，您收好了，多谢关照。\n");
		return 1;
	}
	return 0;
}

void destroy (object ob)
{
        destruct(ob);
        return;
}
