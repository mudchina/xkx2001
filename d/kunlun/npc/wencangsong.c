//Cracked by Roath

#include <ansi.h>
#include "mingjiao_npc.c"
#include "mingjiao_job.h"

string ask_job();

void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;

        set_name("闻苍松", ({ "wen cangsong","wen"}) );
        set("title", "明教巨木旗掌旗使");
        create_family("明教",37,"掌旗使");
        set("gender", "男性");
        set("age",36);
        set("long", "
待添
\n");
        set("attitude", "peaceful");
        set("shen", 1000000);
        
	I_inquiry["name"]="在下就是明教巨木旗掌旗使闻苍松，不知阁下有何指教。";
	I_inquiry["任务"]=(: ask_job :);
	I_inquiry["job"]=(: ask_job :);
	I_inquiry["放弃"]=(: ask_abandon :);
	I_inquiry["abandon"]=(: ask_abandon :);

	Skill_name=({"shenghuo-xuanming","wuxing-bu","duoming-bi",
		     "riyue-shenzhang","shenghuo-quan","guangming-xinfa"});

	Set_Inquiry(I_inquiry,Skill_name);

	Set_Npcattrib(23,5,2000,300,4000,400,4000,300,3000,1000,700000,50000);

//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["dodge"]="wuxing-bu";
//	S_skills["parry"]="shenghuo-quan";
//	S_skills["stroke"]="duoming-bi";
//	S_skills["strike"]="riyue-shenzhang";
//	S_skills["cuff"]="shenghuo-quan";
//	set_skill("guangming-xinfa",100+random(20));
	set_skill("literate",100+random(20));
	
//	Set_Npcskills(100,20,S_skills);
	
//	prepare_skill("cuff","shenghuo-quan");
//	prepare_skill("strike","riyue-shenzhang");

        setup();

	carry_object(OBJ_PATH"/changpao")->wear();


}

string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,axe,shugan;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
        return "这位"+RANK_D->query_respect(player)+"并非我教弟兄，那敢在下那敢分派阁下什么任务呢。\n";

	if(!objectp(ling = present("tieyan ling", player)) )
		return "这位"+RANK_D->query_respect(player)+"没有我教信物铁焰令，我如何记录奖赏过失？\n";

//	if (fam["generation"] <37)
//		 return "这位"+RANK_D->query_respect(player)+"已贵为我教"+fam["title"]+"，岂敢劳烦大架。\n";

	if ( player->query("mingjiao/job")=="mu_kanshu" && shugan=present("shu gan",player) )
	{
		if (shugan->query("owner")==player->query("id"))
		{
			command("pat "+player->query("id"));
			if (axe=present("axe",player))
				destruct(axe);
			message_vision("闻苍松叫来一名教众，把$N的树干接了过去。\n",player);
			destruct(shugan);
			player->delete_temp("apply/short");
			remove_call_out("reward");
			call_out("reward",1,this_player(),"砍树");
			return player->query("name")+"干得不错！下去好好休息休息。\n";
		}
		else
			return "这好象不是你砍的吧。想偷懒？\n";
	}

	if(player->query("mingjiao/job"))
		return judge_jobmsg(player,0);

	command("nod "+player->query("id"));

	player->set("mingjiao/job","mu_kanshu");
	
	axe=new(OBJ_PATH"/axe");
	axe->move(player);
	tell_object(player,"闻苍松给你一把斧头。\n");
	
	return "你来的正好，兄弟们演练阵法，巨木不够了，你去树林里砍些树干扛回来。\n";

}   


