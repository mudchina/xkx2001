//Cracked by Roath

#include <ansi.h>
#include "mingjiao_npc.c"
#include "mingjiao_job.h"

string ask_job();
int get_jingtie_num();
string ask_jingtie();
string ask_jingtie_num();
void dest_ob(object);

void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;

        set_name("吴劲草", ({ "wu jincao","wu"}) );
        set("title", "明教锐金旗掌旗副使");
        create_family("明教",37,"掌旗使");
        set("gender", "男性");
        set("age",35);
        set("long", "
待添
\n");
        set("attitude", "peaceful");
        set("shen", 1000000);
        
	I_inquiry["name"]="在下就是明教锐金旗掌旗副使吴劲草，不知阁下有何指教。";
	Skill_name=({"shenghuo-xuanming","wuxing-bu","duoming-bi",
		     "riyue-shenzhang","shenghuo-quan","guangming-xinfa"});

		I_inquiry["打铁"]=(: ask_job :);
		I_inquiry["datie"]=(: ask_job :);
		I_inquiry["精铁储藏"]=(: ask_jingtie_num :);
		I_inquiry["reserve"]=(: ask_jingtie_num :);
		I_inquiry["精铁"]=(: ask_jingtie :);
		I_inquiry["jingtie"]=(: ask_jingtie :);

	Set_Inquiry(I_inquiry,Skill_name);

	Set_Npcattrib(23,5,2000,300,4000,400,4000,300,3000,1000,700000,50000);

//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["dodge"]="wuxing-bu";
//	S_skills["parry"]="duoming-bi";
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
	carry_object(OBJ_PATH"/panguan-bi")->wield();

}

string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,chui,qiao;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
        return "这位"+RANK_D->query_respect(player)+"并非我教弟兄，那敢在下那敢分派阁下什么任务呢。\n";

	if(!objectp(ling = present("tieyan ling", player)) )
		return "这位"+RANK_D->query_respect(player)+"没有我教信物铁焰令，我如何记录奖赏过失？\n";

//	if (fam["generation"] <37)
//		 return "这位"+RANK_D->query_respect(player)+"已贵为我教"+fam["title"]+"，岂敢劳烦大架。\n";

	if(player->query("mingjiao/job") != "jin_caikuang")
		return judge_jobmsg(player,0);

	if( !present("wujin kuangshi",player ) )
		return "你并未采来矿石，如何打铁？\n";

// remove tie qiao from this player.
	qiao=present("tie qiao",player );
	if (qiao) destruct(qiao);
	tell_object(player,"你把铁锹交给吴劲草。\n\n");	

	command("nod "+player->query("id"));

	chui=new(OBJ_PATH"/tiechui");
	chui->move(player);
	tell_object(player,"吴劲草给你一把铁锤。\n");
	
	return "好！快去把采来的矿石炼成精铁吧。\n";
		 
}   

int accept_object(object me, object ob)
{
	string name;
	string job_flg;
	object room,tool;


	name = ob->query("id");	
	if ( name != "jing tie")
		return 0;

	job_flg = judge_jobmsg(me,1);

	if ( job_flg !=  "采集铁矿" ) 
	{
		command("hmm "+me->query("id"));
		command("say 没有这项工作，就不要胡乱开采！");
		return 0;
	}
	else
	{
		command("thumb "+this_player()->query("id"));
		command("say 这位兄弟辛苦了!下去好好休息休息！");
	        tool=present("tie chui",me );
		if (tool) destruct(tool);
		remove_call_out("dest_ob");
		call_out("dest_ob",1,ob);
	        if (!(room = find_object("/d/kunlun/mj_center.c")))
			room = load_object("/d/kunlun/mj_center.c");
		room->add("jingtie",1);
		remove_call_out("reward");
		call_out("reward",1,this_player(),job_flg);
		return 1;
	}
	
	return 0;

}


int get_jingtie_num()
{
        int num;
        object room;
        
        if (!(room = find_object("/d/kunlun/mj_center.c")))
		room = load_object("/d/kunlun/mj_center.c");
        num = room->query("jingtie");

	return num;

}

string ask_jingtie_num()
{
	return "现在还有"+chinese_number(get_jingtie_num())+"块精铁。\n";
}

string ask_jingtie()
{
	int num;
	object me=this_player();
	object jingtie,room;
	string job_flg;

	job_flg = judge_jobmsg(me,1);
	if (job_flg != "打造火枪")
		return "这位"+RANK_D->query_respect(me)+"好象没有造火枪的任务吧。\n";
	
	if (present("jing tie",me) )
	{
		command("hmm "+me->query("id"));
		return "你不是已经有一块了吗？还想要，真是贪得无厌。\n";
	}

	if ( get_jingtie_num() <= 0 )
		return "对不起，我这里已经没有精铁了。\n";

	command("nod "+me->query("id"));
	message_vision("吴劲草拿了一块精铁给$N\n",me);
        if (!(room = find_object("/d/kunlun/mj_center.c")))
		room = load_object("/d/kunlun/mj_center.c");
	room->add("jingtie",-1);

	jingtie=new(OBJ_PATH"/jingtie");
	jingtie->move(me);

	return "这是兄弟们辛辛苦苦炼出来的精铁，你要用它好好打造兵器。\n";
}

void dest_ob(object ob) { destruct(ob);}