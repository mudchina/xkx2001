// /NPC meijian.c
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();

string ask_job();
string ask_escape();
int doing_job(object ob); 
int add_bandit(object ob);
int do_kill(object me, object dest);
int checking(object me);

void create()
{
	set_name("梅剑", ({ "mei jian", "mei"}));
	set("long",
	    "这是个容貌姣好的女子, 瓜子脸蛋,\n"+
	    "眼如点漆, 清秀绝俗.\n"+
	    "你总觉得在哪见过她.\n");
	set("gender", "女性");
	set("per", 28);
	set("age", 18);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 32);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 10000);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("hand",180);
	set_skill("strike", 180);
	set_skill("sword",180);
	set_skill("literate",100);
	set_skill("music",180);

	set_skill("zhemei-shou",180);
	set_skill("liuyang-zhang",180);
	set_skill("tianyu-qijian",180);
	set_skill("yueying-wubu",180);
	set_skill("bahuang-gong", 180);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	set("job_count",0);
        set("inquiry", ([
		"job" : (: ask_job :),
		"守门" : (: ask_job :),
		"工作" : (: ask_job :),
		"放弃" : (: ask_escape :), 
		"干不了" : (: ask_escape :), //for escape when in job;
		"escape" : (: ask_escape :), 
        ]));

	create_family("灵鹫宫",3,"弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/city/npc/obj/doupeng")->wear();
	add_money("silver",15);
}
void init()
{
	object me, ob;
	mapping fam;

	::init();
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ((fam = ob->query("family")) && fam["family_name"] != "灵鹫宫" )
	&& me->query("biao/owner"))
	{
		if( !ob->query_temp("warned") ) {
		command("say 尊主有令：外人不得进入灵鹫宫，速速离开！");
			ob->set_temp("warned", 1);
	}
		else if( ob->query_temp("stay")<5 ) ob->add_temp("stay",1);
		else {
			command("say 大胆狂徒，竟敢擅闯灵鹫宫！！！\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}
	remove_call_out("checking");
	call_out("checking", 1, me);
}

string ask_escape()
{
	mapping fam;
	object ob;

	ob=this_player();
	if (!(fam = ob->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？";

	if((ob->query("job_status"))==1)
	{
		command("say 好吧，你现在可以走了。");
		add("job_count", -1);
		ob->set("job_status",0);
	}
	else  
		command( "say 你又没有在这里看守大门，这话从何说起？");
		
	return "今后要好好干！\n";
}

string ask_job()
{
	mapping fam;
	object ob;
	
	ob=this_player();

	if (!(fam = ob->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？";

	if((ob->query("job_status"))==2)
		return "你还没有完成童姥的工作，又来问什么？\n";

	if((ob->query("combat_exp"))<10000)                             //      exp<10k  can not do meijian's job; 
		return "你经验不够，在此守门有危险。等经验够了再来问我。\n";

	if((ob->query("job_status"))==1)
	{
//		command("say 重新开始吧。好好干！");
//		remove_call_out("doing_job");
		command("say 如果你干不了我派给你的活，可以直接跟我说你干不了。");

	}
	else  if(query("job_count")>=4)
		  return "你来晚了，守门的位置已经分派完了。过一会再来看看。\n";
    else{
		command( "say 你就在这里看守大门吧。");
		ob->set("job_status", 1);
		add("job_count",1);
	 }

	
	if(random(4)==1)
		call_out("add_bandit",0,ob); //bandit has 1/4 chance;

	call_out("doing_job",500,ob); //use call out and set time 10 minitues.
	return "打起精神，不要偷懒。\n";
}

int doing_job(object ob)//, int second)
{
	if((ob->query("job_status"))==1)
	{
	ob->add("combat_exp", 50+random(100));
	ob->add("potential",50 + random(50));

	if ( ob->query("potential") > ob->query("max_potential") )
	ob->set("potential", ob->query("max_potential"));

	ob->set("job_status",0);

	command("say 时间到了，"+ob->query("name")+"，你可以走了。今后还要多多努力！");
	add("job_count", -1);
	}
	return 1;
}

int add_bandit(object ob)               //if bandit come, player can 'ask mei about 干不了' and then escape.
{
	object me;
	object *inv;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

//              write("begin load bandit\n"); //for test;

	me = load_object("/d/lingjiu/npc/bandit");
	me->move("/d/lingjiu/damen");
			
//              write("finish load bandit\n"); //for test;
/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]/4*5);
		}
	}

/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}

/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]-2+random(4));
	me->set("int", hp_status["int"]-2+random(4));
	me->set("con", hp_status["con"]-2+random(4));
	me->set("dex", hp_status["dex"]-2+random(4));

	me->set("max_qi",    hp_status["max_qi"]/5*7);
	me->set("eff_qi",    hp_status["max_qi"]/5*7);
	me->set("qi",        hp_status["max_qi"]/5*7);
	me->set("max_jing",  hp_status["max_jing"]/5*7);
	me->set("eff_jing",  hp_status["max_jing"]/5*7);
	me->set("jing",      hp_status["max_jing"]/5*7);
	me->set("max_neili", hp_status["max_neili"]);
	me->set("neili",     hp_status["max_neili"]);
	me->set("jiali",     hp_status["jiali"]/2);
	me->set("combat_exp",hp_status["combat_exp"]/7*9);
	me->set("shen",      hp_status["shen"]*(-1));
	
//		write("突然,从横梁上跳下一个蒙面大汉!\n");
//	write( "蒙面人抽出一柄长剑,指着你道:拿命来!\n" );
	message_vision(HIR"突然山下冲上一个$N，二话不说向守卫们发起攻击！\n"NOR, me);
	message_vision(CYN"$N抽出一柄长剑喝道：赶快叫童姥交出生死符的解药来！\n"NOR, me);

	me->kill_ob(ob);
	
		return 1;
		    
    
}

int do_kill(object me, object dest)
{

//      write("begin kill bandit\n"); //for test

	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		command( "say 大胆狂徒，竟敢在灵鹫宫撒野，还不快快缚手就擒！");
		me->kill_ob(dest);
		dest->fight_ob(me);
	}
	
	call_out("checking", 0,  me, dest);
	
	return 1;
}

int checking(object me)
{
	object ob;

//      write("begin check bandit\n"); //for test

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	    return 1;
	}

	if( objectp(ob = present("bandit", environment(me))))
	{
		call_out("do_kill", 1, me, ob);
	return 1;
	}
	
	call_out("checking", 1, me);
	return 1;
}
#include "/kungfu/class/lingjiu/jianbi.h"
#include "/kungfu/class/lingjiu/auto_perform.h"