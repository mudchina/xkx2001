//Cracked by Roath

#include "mingjiao_npc.c"
#include "mingjiao_job.h"
#include <ansi.h>


string ask_job();

void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;
        set_name("庄铮",({"zhuang zheng","zhuang"}));
        set("title", "明教锐金旗掌旗使");
        set("long", "有待添加。\n");
        set("age", 37);
        set("attitude", "peaceful");
        set("shen", 1000000);
        create_family("明教",37,"掌旗使");

		Skill_name=({"guangming-xinfa","wuxing-bu","bagua-dao",
			     "riyue-shenzhang","shenghuo-quan"});
		I_inquiry["name"]="在下就是明教锐金旗掌旗使庄铮，不知阁下有何指教。";
		I_inquiry["任务"]=(: ask_job :);
		I_inquiry["job"]=(: ask_job :);
		I_inquiry["放弃"]=(: ask_abandon :);
		I_inquiry["abandon"]=(: ask_abandon :);
		Set_Inquiry(I_inquiry,Skill_name);
		Set_Npcattrib(23,5,2000,300,4000,400,4000,300,3000,1000,700000,50000);

//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["dodge"]="wuxing-bu";
//	S_skills["parry"]="bagua-dao";
//	S_skills["blade"]="bagua-dao";
//	S_skills["strike"]="riyue-shenzhang";
//	S_skills["cuff"]="shenghuo-quan";
//	set_skill("guangming-xinfa",100+random(20));
	set_skill("literate",100+random(20));
	
		
//	Set_Npcskills(100,20,S_skills);

//	prepare_skill("cuff","shenghuo-quan");
//	prepare_skill("strike","riyue-shenzhang");
        
	setup();
	carry_object(OBJ_PATH"/changpao")->wear();
	carry_object(OBJ_PATH"/blade")->wield();	
}


string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,qiao;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
        return "这位"+RANK_D->query_respect(player)+"并非我教弟兄，那敢在下那敢分派阁下什么任务呢。\n";

	if(!objectp(ling = present("tieyan ling", player)) )
		return "这位"+RANK_D->query_respect(player)+"没有我教信物铁焰令，我如何记录奖赏过失？\n";

//	if (fam["generation"] <37)
//		 return "这位"+RANK_D->query_respect(player)+"已贵为我教"+fam["title"]+"，岂敢劳烦大架。\n";

	if(player->query("mingjiao/job"))
		return judge_jobmsg(player,0);

	command("nod "+player->query("id"));

	player->set("mingjiao/job","jin_caikuang");
	
	qiao=new(OBJ_PATH"/qiao");
	qiao->move(player);
	tell_object(player,"庄铮给你一把铁锹。\n");
	
	return "我锐金旗在教内负责采矿炼铁，最近上等精铁快用完了，你去\n"
		"附近的山上找些铁矿，然后到精练场将矿石炼制成精铁。\n"
		"附近山上常有猛兽出没，你自己多加小心。\n";


		 
}   






