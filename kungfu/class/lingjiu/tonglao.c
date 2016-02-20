// /NPC tonglao.c
/*Notes:                
	a.拜师条件：    1. 女子;
					2. 八荒功180级;
	b.JOB:                  1. 100k以下;
					2. 100k~1M;
					3. >1M;
					必须把尸体交给tong;

	*/

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
//inherit SKILL;
int ask_shengsi();
string ask_job();
string ask_escape();
int accept_object(object who, object ob);
mapping query_namelist(int i);
int auto_perform();

void create()
{
	set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "她就是「灵鹫宫」的开山祖师.\n"+
	    "乍一看似乎是个十七八岁的女子,可神情却是老气横秋.\n"+
	    "双目如电,炯炯有神,向你瞧来时,自有一股凌人的威严.\n");

	set("title", "灵鹫宫主人");
	set("gender", "女性");
	set("per", 33);
	set("age", 96);
	set("nickname", "唯我独尊" );
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 35);
	set("con", 30);
	set("dex", 30);

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 200);

	set("combat_exp", 3200000);
	set("score", 200000);

	set_skill("force", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("hand",350);
	set_skill("strike", 350);
	set_skill("sword",350);
	set_skill("blade",350);
	set_skill("literate",350);
	set_skill("music",350);

	set_skill("zhemei-shou",350);
	set_skill("liuyang-zhang",350);
	set_skill("tianyu-qijian",350);
	set_skill("yueying-wubu",350);
	set_skill("bahuang-gong", 350);
	set_skill("ruyi-dao", 350);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	map_skill("blade", "ruyi-dao");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	set("inquiry", ([
		"生死符" : (: ask_shengsi :),
		"job" : (: ask_job :),
		"工作" : (: ask_job :),
		"放弃" : (: ask_escape :), 
		"干不了" : (: ask_escape :), 
		"escape" : (: ask_escape :), 
	]));

	set("lingjiu/shengsi",1);

	create_family("灵鹫宫",1,"主人");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/city/npc/obj/doupeng")->wear();
	carry_object("/d/city/obj/jiudai");
	carry_object("/d/city/obj/jiudai");
	carry_object("/d/city/obj/jiudai");
}

void attempt_apprentice(object ob)
{
        	mapping fam = ob->query("family");

		if (ob->query("gender") != "女性") {
			command("say 你找死啊!");
			return; 
		}
		if (!fam || fam["family_name"] != "灵鹫宫"){
                	command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                	return;
                }
		if((int)ob->query_skill("force", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                	return;
                }  
		if((int)ob->query_skill("bahuang-gong", 1) < 180) {
			command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
                	return;
                }  
		if((int)ob->query_skill("dodge", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("yueying-wubu", 1) < 180 || (int)ob->query_skill("lingbo-weibu", 1) < 180 ) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("sword", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                	return;
                }
		if((int)ob->query_skill("tianyu-qijian", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                	return;
                }
		if (ob->query_con() < 34) {
			command("say 本门功法极为难练,你的根骨似乎不够.");
			return;
		}
		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say 我灵鹫宫虽不是名门正派，但也绝不于奸邪之人为伍。");
                	command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
        		return;
		}
		command("say 嗯，看你还是个学武的料，我就收下你吧！");
        	command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
}

string ask_job()
{
	mapping fam , namelist;
	object ob;
	int i ;
	int start_time;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";

	if((this_player()->query("job_status"))==2)
		return "你还没有完成我给你的工作，又来问什么？\n";


	command( "say 丁春秋这个小贼实在可恶，整天在我眼皮底下大吹法螺。");

	i=(int)this_player()->query("combat_exp",1);
	if(i>1000000)
		i=3;
	else if(i>500000)
		i=2;
	else if(i>100000)
		i=1;
	else 
		i=0;

	namelist=query_namelist(i);

	command( "say 你去把" +namelist["name"]+ "的尸体拿来见我，必有重赏！");

	this_player()->set("job_status", 2);
	this_player()->set("namelist", namelist);
	
	return "快去！！\n";

}

int accept_object(object who, object ob)
{
	int bonus, exp, pot;
	mapping namelist;
	int possible_pot;
	int now_pot, i, j;
	object me;

	
	if(!(namelist =  who->query("namelist")))
	{
		command("hmm");
		command("say 你胆敢欺师灭祖！当我灵鹫宫是什么地方！");
		return 1;
	}

	if( ob->query("victim_name") != namelist["name"])
	{
		command("hmm");
		command("say 你胆敢欺师灭祖！当我灵鹫宫是什么地方！");
		return 1;
	}

	if ( ob->query("my_killer") != who->query("id") ) {
	command("hmm");
	command("say 你居然贪图别人的功劳，当我灵鹫宫是什么地方！");
	message_vision("$N说着运起内功一掌拍向$n的天灵盖。\n", this_object(), who);
//	who->receive_wound("qi", who->query("max_qi")+100, "被天山童老杀死了");
	COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
	return 1;
	}
		command("say 很好！看丁春秋这个小贼还能猖狂到几时！");
		exp = namelist["exp_bonus"]/2 + random(namelist["exp_bonus"]/2);
		pot = namelist["pot_bonus"]/2 + random(namelist["pot_bonus"]/2);


		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		who->add("potential", pot);
		if ( who->query("potential") > who->query("max_potential") )
			who->set("potential", who->query("max_potential"));

		who->set("namelist", 0);
		who->set("job_status", 0 );

	return 1;
}



mapping *namelist = ({
	      ([      "name":          "星宿派钹手",
		"exp_bonus":            80,
		"pot_bonus":           60
	]),

	([      "name":                "星宿派号手",
		"exp_bonus":            80,
		"pot_bonus":           70
	]),

		 ([      "name":                "星宿派鼓手",
		"exp_bonus":       100,
		"pot_bonus":         80
	 ]),

       ([      "name":                "阿紫",
		"exp_bonus":           110,
		"pot_bonus":            90
		
	]),

	 ([      "name":                "出尘子",
		"exp_bonus":          120,
		"pot_bonus":           120
		
	]),

	([      "name":                "天狼子",
		"exp_bonus":         120,
		"pot_bonus":           120
		
	]),

	    ([      "name":                "狮吼子",
		"exp_bonus":         250,
		"pot_bonus":           200
		
	]),

		([      "name":                "摘星子",
		"exp_bonus":            350,
		"pot_bonus":            320
		
	]),
	
		([      "name":                "丁春秋",
		"exp_bonus":            800,
		"pot_bonus":            450
		
	]),
});

mapping query_namelist(int i)
{
	switch(i)
	{
	case 0:
	return namelist[random(3)];
	case 1:
	//	return namelist[random(5)+3];
		return namelist[random(3)+2];
	case 2:
		return namelist[random(5)+3];
	default:
		return namelist[random(2)+7];
	}
	return 0;
}

int ask_shengsi()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "灵鹫宫") {
                command("say 这是我灵鹫宫法的绝学。");
                return 1;
        }
	if (ob->query("family/master_name") != "天山童姥") {
                command("say 这手种符驱符的绝技我只传给我的嫡传弟子。");
		return 1;
		}     
        if (ob->query("lingjiu/shengsi") > 0 ) {
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if (ob->query_skill("strike",1) < 120) {
                command("say 要使用这样的绝招需要高深的掌法，你还是多练习练习再说吧。");
                return 1;
        }
        if (ob->query_skill("liuyang-zhang",1) < 120) {
                command("say 要使用这样的绝招需要高深的掌法，你还是多练习练习“天山六阳掌”再说吧。");
                return 1;
        }
        	command("say 你既然是灵鹫宫的弟子，我就教你一招“生死符”吧！\n");

        ob->set("lingjiu/shengsi", 1);
        return 1;
}

string ask_escape()
{
	mapping fam;
	object ob;

	ob=this_player();
	if (!(fam = ob->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？";

	if((ob->query("job_status"))==2)
	{
		command("say 哼，看你也完不成我的任务。");
		add("job_count", -2);
		ob->set("job_status",0);
	}
	else  
		command( "say 我又没吩咐你去做事，这话从何说起？");
		
	return "今后要好好干！\n";
}

#include "/kungfu/class/lingjiu/auto_perform.h"