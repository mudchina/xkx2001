// /NPC xuzhu.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();

void renewing();
string ask_me(string name);
string ask_book();

void create()
{
	set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "这是一个二十五六岁的年轻人, 浓眉大眼,\n"+
	    "大大的鼻子扁平下塌, 容貌颇为丑陋. \n"+
	    "身穿一件华贵雅致的长袍, 倒使他更显几分精神.\n"+
	    "他就是天山童姥的救命恩人.\n");
	set("title", "灵鹫宫尊主");
	set("gender", "男性");
	set("per", 16);
	set("age", 26);
	set("nickname",  "梦郎" );
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 24);
	set("int", 20);
	set("con", 30);
	set("dex", 26);

	set("max_qi", 6000);
	set("max_jing", 1200);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 10);

	set("combat_exp", 2500000);

	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",250);
	set_skill("strike", 250);
	set_skill("sword",250);
	set_skill("blade",250);
	set_skill("literate",100);
	set_skill("music",250);

	set_skill("zhemei-shou",250);
	set_skill("liuyang-zhang",250);
	set_skill("tianyu-qijian",250);
	set_skill("yueying-wubu",250);
	set_skill("bahuang-gong", 250);
	set_skill("ruyi-dao", 250);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	map_skill("blade", "ruyi-dao");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	set("book_count", 1);
	set("job_count",0);
        set("inquiry", ([
//		"灵鹫令" : (: ask_me, "lingjiu" :),
//		"进修" : (: ask_me, "lingjiu" :),
//		"小院" : (: ask_me, "lingjiu" :),
		"job" : "你去找梅剑吧，看看她有没有什么事情可以安排给你。",
//		"干不了" : (: ask_escape :), //for escape when in job;
//		"escape" : (: ask_escape :), 
		"秘籍" : (: ask_book :),        //bahuang-gong pu2;
        ]));
	set("ling_count", 1);

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("灵鹫宫",2,"尊主");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/d/lingjiu/obj/changpao")->wear();
 	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object me;

    ::init();
    
	me = this_object();

//    remove_call_out("checking");
//    call_out("checking", 1, me);
       
}
string ask_me(string name)
{
	mapping fam;
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) +
		"与本派素无来往，不知此话从何谈起？";

	if (query("ling_count") < 1)
		return "你来得不是时候，已经有人在练功了。";

	ob = new("/d/lingjiu/obj/" + name);
	ob->move(this_player());

	add("ling_count", -1);

	message_vision("虚竹给$N一个" + ob->query("name") + "。\n", this_player());

	return "拿去吧。";
}
void attempt_apprentice(object ob)
{
        	mapping fam = ob->query("family");

		if (ob->query("gender") != "女性") {
			command("say 我只收女弟子，"+RANK_D->query_respect(ob)+"请回吧。");
			return; 
		}
		if (!fam || fam["family_name"] != "灵鹫宫"){
                	command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                	return;
                }
		if((int)ob->query_skill("force", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                	return;
                }  
		if((int)ob->query_skill("bahuang-gong", 1) < 150) {
			command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
                	return;
                }  
		if((int)ob->query_skill("dodge", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("yueying-wubu", 1) < 150 || (int)ob->query_skill("lingbo-weibu", 1) < 150 ) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("sword", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("tianyu-qijian", 1) < 150) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                	return;
                }
		if (ob->query_con() < 20) {
			command("say 本门功法极为难练,你的根骨似乎不够.");
			return;
		}
		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say 我灵鹫宫虽不是名门正派，但也绝不于奸邪之人为伍。");
                	command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
        		return;
		}
		command("say 好吧，我就收下你了。希望你能行天地正道，将灵鹫宫发扬光大。"); 
        	command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
}

string ask_book()
{
	mapping fam; 
	object ob;
	
		
	if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
		if(this_player()->query("combat_exp")<50000)
			return RANK_D->query_respect(this_player()) +"的实战经验尚浅，此秘籍现时于你无用。";
		if(this_player()->query_skill("bahuang-gong",1)>100)
			return RANK_D->query_respect(this_player()) + "的八荒功已经出类拔萃，此秘籍已于你无用。";
	if (query("book_count") < 1)
		return RANK_D->query_respect(this_player()) +"来晚了，本派的内功秘籍不在此处。";
	add("book_count", -1);

	ob = new("/d/lingjiu/obj/bahuang2");
	ob->move(this_player());

	return "好吧，这本功谱你拿回去好好钻研，将来光大我派。哈哈！";
}

#include "/kungfu/class/lingjiu/auto_perform.h"
