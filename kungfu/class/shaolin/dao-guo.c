//Cracked by Roath
// Npc: /kungfu/class/shaolin/dao-guo.c
// Date: YZC 96/01/19  AceP: 97/8/3

#include <ansi.h>
inherit NPC;

string ask_me();
int repairing_1(object, object);
int repairing_2(object, object);
int repairing_3(object, object);
int repairing_4(object, object);
int do_back(object);
int do_return(object, object);
int do_remind(object, object);
int forget_lier(object, object);

void create()
{
	set_name("道果禅师", ({
		"daoguo chanshi",
		"daoguo",
		"chanshi",
	}));

	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
		);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("luohan-quan", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei-dao", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 39, "弟子");
	set("inquiry", ([
		"木人"     : (: ask_me :),
		"修理"	   : (: ask_me :),
		"修木人"   : (: ask_me :)
		]));

	setup();

	carry_object("/clone/weapon/jiedao")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()
{	
	object me, ob;
	me = this_object();

	::init();

	if (environment()==find_object("/d/shaolin/shanmen.c"))
	{
		command("hmm");
		command("say 我还有重要的活要干，不能出寺去。我回去了。");
		say("道果匆匆忙忙离开了。\n");
		command("follow none");

		me->move("/d/shaolin/guangchang3");
		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}


	if( objectp(ob = present("mu ren", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}



int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 
	command("say 是这个木人吧？ 唔，我来瞧瞧！ 你在边上呆着，看能帮我什么忙。");
	set_temp("in_repair",1);
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);
	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 
	if( ob->query("damaged") )
	{
		message_vision(GRN "\n道果禅师对着木人瞧了一会，又试着扳动木人的四肢和脑袋，嘴里喃喃念叨着什么。\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}

	else
	{
		command("say 这木人好端端地又没坏！ 还大老远地拖着我过来！");
		command("follow none");

		message_vision(GRN "\n道果禅师气鼓鼓地走了。\n" NOR, me);
		me->move("/d/shaolin/guangchang3");
		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}
	return 1;
}

int repairing_3(object me, object ob)
{
	command("say 唔，原来如此，我来修修看吧！");
	message_vision(GRN "\n他接着从怀里掏出一大堆工具来，打开木人的身体，摆弄了几下。\n\n" NOR, me);
	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);
	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(2) == 0 ) 
	{		
		command("say 好，修好了！");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\n木人的身体吱吱地扭动了几下，恢复了正常站立的姿态。\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\n道果禅师叹了口气，说道：看来不行，这木人损坏得太厉害了，没法子修了！\n" NOR, me);

	command("say 好，那我走了！");
	command("wave");
	command("follow none");
	delete_temp("in_repair");
	message_vision(GRN "\n道果禅师走了出去。\n" NOR, me);
	me->move("/d/shaolin/guangchang3");
	remove_call_out("do_back");
	call_out("do_back", random(15), me);
	return 1;
}



int do_back(object me)
{
	me->move("/d/shaolin/twdian");
	return 1;
}

int do_remind(object me, object ob)
{
	if (	objectp(ob)
		&& me->query_leader()==ob
		&& !me->query_temp("in_repair")
		&& present(ob, environment(me)))
	{
		command("push "+getuid(ob));
		command("say 怎么还没到你的木人的地方啊？快点，我还有别的活干呢！");
	}
	return 1;
}

int do_return(object me, object ob)
{
	if ( me->query_leader() == ob && ob && !me->query_temp("in_repair"))
	{
		if (present(ob, environment(me)))
		{
			command("angry "+getuid(ob));
			command("say 你到底有没有木人要我修啊？是不是在骗我啊？！我回去了！");
			set_temp("lier",getuid(ob));
			remove_call_out("forget_lier");
			call_out("forget_lier", 300, me, ob);
		}

		message_vision(GRN "\n道果禅师气鼓鼓地走了。\n" NOR, me);
		command("follow none");
		me->move("/d/shaolin/guangchang3");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}
	return 1;
}

int forget_lier(object me, object ob)
{
	if (query_temp("lier")==getuid(ob))
		delete_temp("lier");
	return 1;
}


string ask_me()
{
	mapping fam; 

	object ob, me;
	ob = this_player();
	me = this_object();

	if ((!(fam = ob->query("family")) || fam["family_name"] != "少林派") && !ob->query_temp("allow_repair") )
		return RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？";

	if (query_leader() && present(query_leader(), environment()))
		return "对不起，我现在有活在身，你等会儿去天王殿找我吧。";

	if (getuid(ob)==query_temp("lier"))
		return "你这家伙刚刚骗我跑了半天，却没有木人要修。我现在正忙，你等会儿再说吧。";

	command("say 木人打坏了是吧？ 好吧，我跟你去看看。");
	command("follow " + ob->query("id"));

	remove_call_out("do_remind");
	call_out("do_remind", 50, me, ob);

	remove_call_out("do_return");
	call_out("do_return", 100, me, ob);
	
	return "我们走罢！\n";
}

int accept_object(object me, object ob)
{
	command("smile");
	command("say 阿弭陀佛，多谢" + RANK_D->query_respect(me) + "了 ！");
	
	if(ob->query("money_id") && ob->value() >= 10000 && me->query("class") != "bonze" )
	me->set_temp("allow_repair", 1);

	return 1;
}
