//Cracked by Roath
// /kungfu/class/quanzhen/qiu.c
// qiu.c 丘处机
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_job();
void reward_dest(object obj,object ob);
void thank_dest(object obj,object ob);

int auto_perform();

void create()
{
	set_name("丘处机", ({ "qiu chuji", "qiu" }));
	set("nickname", "长春子");
	set("long",
		"他就是全真七子中最负盛名的丘处机，道号长春子，现任全真教掌教真人。\n"
		"他已年近七十，身材魁梧，满脸红光，气宇不凡。\n");
	set("gender", "男性");
	set("age", 69);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 27);
	set("int", 25);
	set("con", 25);
	set("dex", 26);


		  set("max_qi", 3200);
        set("max_jing", 2100);
        set("neili", 2800);
        set("max_neili", 2800);
		  set("jiali", 80);
		  set("combat_exp", 1000000);
		  set("score", 5000);

		  set_skill("force", 170);
		  set_skill("dodge", 150);
		  set_skill("parry", 150);
		  set_skill("sword", 160);
		  set_skill("strike", 150);
		  set_skill("cuff", 150);

	set_skill("xiantian-gong", 170);
	set_skill("jinyangong", 150);
	set_skill("chunyang-quan", 150);
	set_skill("sanhua-juding", 150);
	set_skill("quanzhen-jian", 160);
	set_skill("literate", 150);
	set_skill("taoism", 160);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	set("class","taoist");

	create_family("全真教", 2, "弟子、掌教真人");

	set("inquiry", ([
		"秘籍" : (: ask_me :),
		"miji" : (: ask_me :),
		"任务" : (: ask_job :),
		"job" : (: ask_job :),
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("book_count", 3);
	set_temp("job_pos",10);


	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
	mapping fam;
	string name,new_name;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "全真教" )
	{
		command ("say " + RANK_D->query_respect(this_player())
			+ "并非我门中人，习武还是先从各位道长起吧！");
		return;
	}

	if ((int)ob->query_skill("xiantian-gong", 1) < 80) {
		command("say 我全真教乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在玄门先天功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") < 50000) {
		command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	command("say 好吧，贫道就收下你了。");
	name = ob->query("name");
	new_name = name[0..01]+"志" + name[4..5];
	command("say 从今以后你就叫做" + new_name + "。");
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob, *obs,ob2 ;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
		return RANK_D->query_respect(this_player()) +
		"与本派素无来往，不知此话从何谈起？";

	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";

	obs = filter_array(children(__DIR__"force_book.c"), (: clonep :));
		  if (sizeof(obs) > 2)
		return "你来晚了，本派的内功心法不在此处。";

	ob=new(__DIR__"force_book");
	ob->move(this_player());
	add("book_count", -1);
	command ("rumor "+this_player()->query("name")+"弄到了一册玄门内功心法。");
	return "好吧，这本「玄门内功心法」你拿回去好好钻研。";
}


string ask_job()
{
	  mapping job_stat;
	  object ob2;
	  object ob = this_player();
	  object me = this_object();

	  job_stat = ob->query_temp("qz_caiyao");

	  if ( ob->query("family/family_name") != "全真教" )
					 return "这位"+RANK_D->query_respect(ob)+"非我全真教弟子，岂敢劳烦。\n";

	  if(job_stat){
				command("hmm "+ob->query("id"));
				return "你还没完成任务，就又想要新的？\n";
	  }

	  if ( me->query_temp("job_pos") == 0 ) {
					 return "现在没什么要紧的事去作，你去休息吧。\n";
	  }

	  me->add_temp("job_pos", -1);

	  command("nod");
	  command("say 好，最近炼丹用的草药都用完了，你去山下树林里去采一些回来。");
	  ob2 = new("/d/zhongnan/obj/yaochu");
	  ob2->move(me);
	  ob->set_temp("qz_caiyao",1);
	  command("give yao chu to "+ob->query("id"));

	  return "早去早回，路上要小心一些！\n";
}

int accept_object(object me, object obj)
{
		  object ob = this_player();

		  command( "say "+obj->name()+"?");

		  if (
				 obj->query("id") == "chuanbei" ||
				 obj->query("id") == "fuling" ||
				 obj->query("id") == "gouzhi zi" ||
				 obj->query("id") == "heshouwu" ||
				 obj->query("id") == "huanglian" ||
				 obj->query("id") == "jugeng" ||
				 obj->query("id") == "jinyin hua" ||
				 obj->query("id") == "shengdi"
			)
			{

			  if ( ob->query("family/family_name") == "全真教" ) {
					 remove_call_out("reward_dest");
					 call_out("reward_dest", 1, obj, ob);
			  }
			  else {
					 remove_call_out("thank_dest");
					 call_out("thank_dest", 1, obj, ob);
			  }

			  return 1;
		  }

		  command( "hmm" );
		  command( "say 你给我这东西做什麽？" );

		  return 0;
}

void reward_dest(object obj,object ob)
{
	object yaochu = present("yao chu",this_player() );
   if(yaochu)destruct(yaochu);
	command( "pat "+ob->query("id"));
	command( "say "+ob->query("name")+"干的不错，下去休息一下吧！\n");
	if(ob->query_temp("qz_caiyao",1) )
	{
		ob->delete_temp("qz_caiyao");
		add_temp("job_pos", 1);
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	command( "jump");
	command( "say 我们很需要这些药材，多谢啦！\n");
	destruct(obj);
}





#include "auto_perform.h"

