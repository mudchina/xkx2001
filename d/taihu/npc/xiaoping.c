//Cracked by Roath
// Npc: 
// Date: 

#include <ansi.h>

inherit NPC;

string ask_me();
int repairing_1(object, object);
int repairing_2(object, object);
int repairing_3(object, object);
int repairing_4(object, object);
int do_back(object);

void create()
{
	set_name("小萍", ({
		"xiao ping",
		"ping",
	}));
	set("long",
		"这是一个看起来十分伶俐乖巧的小丫环，柳叶眉，削肩膀，水蛇腰，十足一个美人胚子，但举手投足之间似乎身有武功。\n"
		"据说她本是嵩山脚下一个孤女，被陆老庄主收养，经常侍奉陆少庄主习练武艺。\n"
	);


	set("gender", "女性");
	set("attitude", "friendly");

	set("age", 18);
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
	set_skill("dodge", 50);
	set_skill("strike", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("literate", 50);


	set("inquiry", ([
		"木人"     : (: ask_me :),
		"修理"	   : (: ask_me :),
		"修木人"   : (: ask_me :)
	]));

	setup();

//        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/taihu/obj/red_cloth")->wear();
}

void init()
{	
	object me, ob;

	me = this_object();

	::init();
	if( objectp(ob = present("mu ren", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}

int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	command("say 是这个木人吧？ 唔，我来瞧瞧！ 你在边上老实呆着，别打岔。");
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);

	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	if( ob->query("damaged") )
	{
		message_vision(GRN "\n小萍对着木人瞧了一会，又试着扳动木人的四肢和脑袋，皱着眉头想了一会儿。\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}
	else
	{
		command("say 大笨瓜，这木人好端端地又没坏！ 还大老远地拖着我过来！");
		command("follow none");

		message_vision(GRN "\n小萍嘟着嘴，气鼓鼓地走了。\n" NOR, me);
		me->move("/d/taihu/liangong");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}

	return 1;
}
	
int repairing_3(object me, object ob)
{
	command("say 唔，是这样耶，我来修修看吧！");
	message_vision(GRN "\n小萍接着从怀里掏出一大堆工具来，打开木人的身体，摆弄了几下。\n\n" NOR, me);

	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);

	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(1) == 0 ) 
	{		
		command("say 好，修好了！");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\n木人的身体吱吱地扭动了几下，恢复了正常站立的姿态。\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\n小萍叹了口气，说道：看来不行，这木人损坏得太厉害了，没法子修了！\n" NOR, me);

	command("say 好，那我走了！");
	command("wave");
	command("follow none");

	message_vision(GRN "\n小萍走了出去。\n" NOR, me);
	me->move("/d/taihu/liangong");

	remove_call_out("do_back");
	call_out("do_back", random(15), me);

	return 1;
}

int do_back(object me)
{
	me->move("/d/taihu/huayuan");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if ((!(fam = ob->query("family")) || fam["family_name"] != "桃花岛") && !ob->query_temp("allow_repair") )
		return RANK_D->query_respect(ob) + 
		"与本庄素无来往，不知此话从何谈起？";

	command("say 木人又打坏了是吧？ 你可真麻烦，好吧，我这就跟你去看看。");
	command("follow " + ob->query("id"));

	return "我们走罢！\n";
}
/*
int accept_object(object me, object ob)
{
	command("smile");
	command("say 阿弭陀佛，多谢" + RANK_D->query_respect(me) + "了 ！");

	if(ob->query("money_id") && ob->value() >= 10000 && me->query("class") != "bonze" )
	me->set_temp("allow_repair", 1);

	return 1;
}
*/
