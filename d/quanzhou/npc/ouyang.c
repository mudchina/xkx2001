//Cracked by Roath
// 欧阳詹
// modified by aln 2 / 98

#include <ansi.h>
inherit NPC;

string ask_degree();

void create()
{
	set_name("欧阳詹", ({ "ouyang zhan", "zhan", "ouyang"  }));
        set_color("$YEL$");
	set("long", "。\n");
	set("gender", "男性");
	set("age", 45);
        set("max_jing", 2000);
        set("max_qi", 2000);
        set("neili", 2000);
        set("jiali", 100);
	set_skill("literate", 165);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"欧阳詹说道：知错能改，善莫大焉。\n",
		"欧阳詹说道：尊师重道，礼仪廉耻。 \n",
	}) );
}

private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N神色慌张地离开了。\n", this_object());
        this_object()->move("/d/quanzhou/xuetang");
	message_vision("$N快步走了过来。\n", this_object());
}
	

void init()
{
        if( environment() != load_object("/d/quanzhou/xuetang") ) {
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

        if( base_name(ob) == "/d/hangzhou/obj/mh_book" ) {
                if( !ob->query("checked") ) {
                       command("say 这本明史未经顾先生修撰，里面谬误一定很多吧。");
                       return 0;
                }

                if( time() < (int)query("mh_time") + 300 ) {
                       command("say 我刚拿到了一本，你还是给别人吧。");
                       return 0;
                }

                command("joythank " + who->query("id"));
                set("mh_time", time());
                wage = new("/clone/money/silver");
                wage->set_amount(3 + random(5));
                wage->move(who);
                message_vision("$N封了一包银子给$n。\n", this_object(), who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	if (who->query_temp("offend_ouyang")) {
		message_vision("欧阳詹摇摇头对$N说：不尊师长，朽木不可雕也！\n", who);
		return 0;
	}
	if (who->query_skill("literate", 1) < 30){
		message_vision("欧阳詹摇摇头对$N说：你先去跟村里的老秀才学学识字，再到我这儿来吧。\n", who);
		return 0;
	}
	if (who->query_skill("literate", 1) >= 160){
		message_vision("欧阳詹摇摇头对$N说：你最好去向杨州的朱熹先生求教，我已没什么可教你的了。\n", who);
		return 0;
        }
	if (environment() != load_object("/d/quanzhou/xuetang")){
		message_vision("欧阳詹摇摇头对$N说：到泉州学堂来找我吧，那里是学习读书的好地方。\n", who);
		return 0;
	}

	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (who->query_skill("literate", 1) < 60 
	&& ob->query("money_id") && ob->value() >= 2000) {
		message_vision("欧阳詹同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 100);
		return 1;
	}
	if (who->query_skill("literate", 1) >= 60
	&& who->query_skill("literate", 1) < 90
        && ob->query("money_id") && ob->value() >= 2000) {
                message_vision("欧阳詹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 500);
                return 1;
        }
	if (who->query_skill("literate", 1) >= 90
	&& who->query_skill("literate", 1) < 120
        && ob->query("money_id") && ob->value() >= 2000) {
                message_vision("欧阳詹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 1000);
                return 1;
        }
	if (who->query_skill("literate", 1) >= 120
	&& who->query_skill("literate", 1) < 160
        && ob->query("money_id") && ob->value() >= 2000) {
                message_vision("欧阳詹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 2000);
                return 1;
        }
	return 0;
}

int accept_kill(object me)
{
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

void unconcious()
{
        object obj, me = this_object();
        object ob = this_player();

	ob->delete_temp("mark/朱");
	ob->set_temp("offend_ouyang", 1);

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

void destroy_it(object obj)
{
        destruct(obj);
}
