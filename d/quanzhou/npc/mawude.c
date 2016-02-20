//Cracked by Kafei
// mawude.c 马五德
// qfy August 1, 1996

inherit NPC;
int do_ask(string);
int do_say(string);

void create()
{
	set_name("马五德", ({ "ma wude", "ma", "wude" }));
	set("long", "馆主马五德豪富好客，颇有孟尝之风，人缘甚佳。\n");
	set("gender", "男性");
	set("age", 55);

	set_skill("literate", 50);

	set_skill("hand", 70);
	set_skill("dodge", 60);
	set_skill("force", 75);
	set_skill("parry", 70);
	set_skill("blade", 75);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("inquiry", ([
		"学武" : "学武只须付五两银子，并可住在武馆里。",
		"学费" : "只须付五两银子。",
		"陈浒" : "他是二当家，擅于棒法(stick)，杖法(staff) 及拳法(cuff)。",
		"龙铨" : "他是刀刃部教头，以刀法(blade)和爪法(claw)见称。",
		"刘虹瑛" : "她是剑部教头，以剑法(sword)和掌下(strike)出名。",
		"萧飞" : "他是暗器部教头，擅于暗器(throwing)及指法(finger)。",
	]) );

	set("chat_chance", 10);
	set("chat_msg", ({
		"马五德说道：「欢迎到来扬威武馆。」\n",
		"马五德说道：「学武只须付五两银子，并可住在武馆里。」\n",
		"马五德说道：「在此可学到内功，拳脚，兵器，轻功和招架。」\n",
		"马五德说道：「二当家陈浒是棒杖部教头，拳法亦是一绝。」\n",
		"马五德说道：「龙铨是刀刃部教头，以刀法和爪法见称。」\n",
		"马五德说道：「刘虹瑛是武馆的剑部教头，同时掌下败将无数。」\n",
		"马五德说道：「萧飞是武馆的暗器部教头，并擅于指法。」\n",
	}) );	
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	add_action("do_ask", "ask");
	add_action("do_say", "say");
}

int do_ask(string arg)
{
	object me;
	me=this_player();

	if (arg=="ma about 无量剑派"
		|| arg=="ma about 无量剑") { 
                me->set_temp("asked",1); 
		write("你向马五德打听有关『无量剑派』的消息。\n");
		command( "?");}
	if (arg=="ma about 比武"
		|| arg=="ma about 斗剑"
		|| arg=="剑会"
		&& me->query_temp("aksed")) {
		me->set_temp("asked", 2); 
		write("你向马五德打听有关『斗剑』的消息。\n");
		command( "nod2");}
	if (arg=="ma about 观礼" && me->query_temp("asked")==2) {
		me->set_temp("asked", 3); 
		write("你向马五德打听有关『观礼』的消息。\n");
		command( "oh " + this_object()->query("id") + "");}
	if (arg=="ma about 同去" && me->query_temp("asked")==3) {
		me->set_temp("asked", 4); 
		write("你向马五德打听有关『同去』的消息。\n");
		command( "shake " + me->query("id") + "");
		command( "say 我武馆里还有很多事情要打典，没有时间。");}
	if (arg=="ma about 独去" && me->query_temp("asked")==4) {
		me->set_temp("asked", 5); 
		write("你向马五德打听有关『独去』的消息。\n");
		command( "en " + me->query("id") + "");}
	return 1;
}

int do_say(string arg)
{
	object me;
	me=this_player();

	if (arg=="我非常想去观礼" && me->query_temp("asked")==5) {
		write("你拉着马五德央求，非要去无量山观礼不可。\n");
		me->set_temp("asked",6);
		command( "consider");
		command( "say 你怎么也得表示一下你的诚意吧。");
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	object bt;

	if (who->query_temp("asked",6) && ob->name()=="黄金") {
                command( "consider");
                command( "ok " + this_object()->query("id") + "");
                command( "say 我给你写封拜贴，你自己去吧。");
		who->delete_temp("asked");
		bt=new("/d/dali/obj/baitie");
		bt->move(who);
                message_vision("马五德给了" + who->query("name") + "一封拜贴。\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	if ((int)who->query("combat_exp") > 3500) {
		command( "say "+RANK_D->query_respect(who)+"功夫已有根底，我怕你在我这儿学不了多少东西，还请另投明师吧。");
		return 0;
	}

	if (!(int)who->query_temp("mark/马")) who->set_temp("mark/马", 0);

	if (ob->query("money_id") && ob->value() >= 500) {
		command( "say "+RANK_D->query_respect(who)+"不远千里而来，真是赏脸，请到后院学习你所喜欢的功夫吧。");
		who->set_temp("mark/马", 1);
		return 1;
	}

	return 0;
}

void destroying(object me, object obj)
{
	destruct(obj);
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/马"))
                return 0;
        return 1;
}
