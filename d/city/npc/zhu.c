//Cracked by Roath
// zhu.c 朱熹
// CLEANSWORD 1996/2/2
// Jay 9/11/96, added degree
//wzfeng 99/11/29 fixbug

#include <ansi.h>
inherit NPC;

string ask_degree();

void create()
{
	set_name("朱熹", ({ "zhu xi", "zhu" }));
        set_color("$YEL$");
	set("long", "朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
	set("age", 65);
        set("max_jing", 2000);
        set("max_qi", 2000);
	set_skill("literate", 500);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 30);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("inquiry", ([
		"学位" : (:ask_degree:),
		"科举" : (:ask_degree:),
	]));

	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
       carry_object("/d/city/obj/cloth")->wear();

}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N神色慌张地离开了。\n", this_object());
        this_object()->move("/d/city/shuyuan");
	message_vision("$N快步走了过来。\n", this_object());
}
	

void init()
{
        if( environment() != load_object("/d/city/shuyuan") ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
}	

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0; 
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{
        object wage;

        if (who->query_temp("biao/zhu") && ob->name()=="红镖") {
                who->delete_temp("biao/zhu");
		who->delete_temp("apply/short");
                command( "say 偏劳这位"+RANK_D->query_respect(who)+"了，请帮我向林总镖头问好。");
                wage = new("/clone/money/silver");
                wage->set_amount(1);
                wage->move(who);
                message_vision("朱熹给$N一两白银作为走镖的酬劳。\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }
	if (ob->query("id") == "hui mo") {
		command("jump");
		command("say 读书之人，先善其器而后读也。");

		if (who->query("连城诀") && !who->query("连城诀/朱熹")) {
	//		command("whisper " + who->query("id") +"以后你"+
		tell_object(who, "朱熹悄悄告诉你：以后你"+
				"来我这上学我额外多教你一倍！但这个优惠只能让"
			+"少数几个人知道，人多了我就不管了。\n");
			who->set("连城诀/朱熹",1);
		}	
		return 1;
	}

	if (who->query_temp("offend_zhu")) {
		message_vision("朱熹摇摇头对$N说：不尊师长，朽木不可雕也！\n", who);
		return 0;
	}
	if (who->query_skill("literate", 1) < 30){
		message_vision("朱熹摇摇头对$N说：你先去跟村里的老秀才学学识字，再到我这儿来吧。\n", who);
		return 0;
	}
//add by wzfeng  
	if (environment() != load_object("/d/city/shuyuan")){
		message_vision("朱熹笑着对$N说：到扬州书院来找我吧，那里是学习读书的好地方。\n", who);
		return 0;
	}
	
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (who->query_skill("literate", 1) < 60 
	&& ob->query("money_id") && ob->value() >= 2000) {
		message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 100);
		if (who->query("连城诀/朱熹")) 
                who->add_temp("mark/朱", ob->value() / 100);
		return 1;
	}
	if (who->query_skill("literate", 1) >= 60
	&& who->query_skill("literate", 1) < 90
        && ob->query("money_id") && ob->value() >= 2000) {
                message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 250);
                if (who->query("连城诀/朱熹")) 
                who->add_temp("mark/朱", ob->value() / 400);
                return 1;
        }
	if (who->query_skill("literate", 1) >= 90
	&& who->query_skill("literate", 1) < 120
        && ob->query("money_id") && ob->value() >= 2000) {
                message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 800);
                if (who->query("连城诀/朱熹"))
                who->add_temp("mark/朱", ob->value() / 800);
                return 1;
        }
	if (who->query_skill("literate", 1) >= 120
        && ob->query("money_id") && ob->value() >= 2000) {
                message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 1600);
                if (who->query("连城诀/朱熹"))
                who->add_temp("mark/朱", ob->value() / 1600);
                return 1;
        }
	return 0;
}

void destroy_it(object obj)
{
        destruct(obj);
}

int accept_kill(object me)
{
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

string ask_degree()
{
     object me = this_player();

     string title,newtitle;
     int index,level;

     	title = me->query("title");
     	if (title) {
       		index = strsrch(title,"、");
		if (index>1) 
			title = title[0..(index-1)];
  		else if (index!=-1)
			return ("你的称号太怪，我没法改。\n");
	}	
	me->set("title",title);

	level = me->query_skill("literate",1);
	if (level < 1 )
		newtitle = "文盲";
	else if (level < 10)
		newtitle = "学童";
	else if (level < 20)
		newtitle = "童生";
	else if (level < 30)
		newtitle = "书生";
	else if (level <40)
		newtitle = "秀才";
	else if (level < 50)
		newtitle = "举人";
	else if (level <60)
		newtitle = "解元";
	else if (level < 70)
		newtitle = "贡士";
	else if (level < 80)
		newtitle = "会元";
	else if (level < 90)
		newtitle = "进士";
	else if (level < 100)
		newtitle = "庶吉士";
	else if (level < 110)
		newtitle = "传胪";
	else if (level < 120)
		newtitle = "探花";
 	else if (level < 130)
		newtitle = "榜眼";
	else if (level < 140)
		newtitle = "状元";
        else if (level < 150)
                newtitle = "翰林";
        else if (level < 160)
                newtitle = "学士";
        else if (level < 170)
                newtitle = "内阁大学士";
        else if (level < 180)
                newtitle = "内阁首辅";
        else if (level < 190)
                newtitle = "文坛领袖";
        else if (level < 200)
                newtitle = "文学大宗师";
	else newtitle = "圣人";

	if (title && title!="") title = title+"、" + newtitle;
	else title = newtitle;
//	me->set("title", title);

	title = title + " " + me->query("name") + 
		"(" + capitalize(me->query("id")) + ")";
	me->set_temp("apply/short", ({title}));

	return "凭阁下的学识，依老夫看，你可以做一名"+newtitle+"。\n";
}

void unconcious()
{
        object obj, me = this_object();
        object ob = this_player();

	ob->delete_temp("mark/朱");
	ob->set_temp("offend_zhu", 1);

	me->disable_player(" <昏迷不醒>");
	me->set("jing", 0);
	me->set("qi", 0);
	COMBAT_D->announce(me, "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
        remove_call_out("revive");
        while( environment()->is_character() )
                this_object()->move(environment(environment()));
        this_object()->enable_player();
        COMBAT_D->announce(this_object(), "revive");
}
