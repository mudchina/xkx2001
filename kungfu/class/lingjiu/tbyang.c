// /d/lingjiu/npc/tbyang.c 阳天部 符敏仪
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>
int auto_perform();
inherit NPC;
string ask_me();
void create()
{
	set_name("符敏仪", ({ "fu mingyi", "fu"}));
	set("long",
	    "她是「灵鹫宫」九天九部中阳天部的首领.\n"+
	    "她号称「针神」.\n");
	set("title", "阳天部首领");
	set("gender", "女性");
	set("nickname", HIG "针神" NOR);
	set("age", 20);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 21);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 20);

	set("combat_exp", 300000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("literate",100);
	set_skill("music",100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	set("inquiry", ([
		"木人"     : (: ask_me :),
		"修理"	   : (: ask_me :),
		"修木人"   : (: ask_me :)
	]));

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("灵鹫宫",4,"弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",25);
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

	command("say 是这个木人吧？ 唔，我来瞧瞧！ 你在边上呆着，看能帮我什么忙。");
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);

	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	if( ob->query("damaged") )
	{
		message_vision(GRN "\n符敏仪对着木人瞧了一会，又试着扳动木人的四肢和脑袋，嘴里喃喃念叨着什么。\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}
	else
	{
		command("say 这木人好端端地又没坏！");
		command("follow none");

		message_vision(GRN "\n符敏仪气鼓鼓地走了。\n" NOR, me);
		me->move("/d/lingjiu/caifeng");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}

	return 1;
}
	
int repairing_3(object me, object ob)
{
	command("say 唔，原来如此，我来修修看吧！");
	message_vision(GRN "\n只见她接着从怀里掏出一根细细的金针，打开木人的身体，摆弄了几下。\n\n" NOR, me);

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
		message_vision(GRN "\n符敏仪叹了口气，说道：看来不行，这木人损坏得太厉害了，没法子修了！\n" NOR, me);

	command("say 好，那我走了！");
	command("wave");
	command("follow none");

	message_vision(GRN "\n符敏仪走了出去。\n" NOR, me);
	me->move("/d/lingjiu/caifeng");

	remove_call_out("do_back");
	call_out("do_back", random(15), me);

	return 1;
}

int do_back(object me)
{
	me->move("/d/lingjiu/caifeng");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(ob) + 
		"与本派素无来往，不知此话从何谈起？";

	command("say 木人打坏了是吧？ 好吧，我跟你去看看。");
	command("follow " + ob->query("id"));

	return "我们走罢！\n";
}

#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"