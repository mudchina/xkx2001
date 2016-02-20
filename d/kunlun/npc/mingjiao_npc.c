//Cracked by Roath
#include <ansi.h>
#define OBJ_PATH "/d/kunlun/obj"
#define MINGJIAO "/d/kunlun"
#include "/d/kunlun/obj/time_all.h"
inherit NPC;


string ask_tyling()
{
	object player=this_player();
	object ling;
    mapping fam ;
	int comexp;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
		return "这位"+RANK_D->query_respect(player)+"并非我明教弟兄，打听这个干嘛。\n";


	if(objectp(ling = present("tieyan ling", player)) )
		return "铁焰令乃我明教信物，每个教众在入教时都会由我教光明使者发派一块。凭此\n"
		"令，可以向教中兄弟请教武功，凡是功过奖赏，都会记录在这块铁焰令上。这铁令关系重\n"
		"大，"+RANK_D->query_respect(player)+"切莫丢失，令在人在，令亡人亡。\n";
	else
		if(query("id")=="leng qian"&&query("name")=="冷谦")
		{
			comexp=player->query("mingjiao/credit");
			if(comexp)
				comexp=comexp-comexp/50;
			if(comexp<=0)
				comexp=0;
			command("say 丢了铁焰令，该当受罚。\n");
			tell_object(player,HIB"你的明教声望下降了。\n"NOR);
			player->set("mingjiao/credit",comexp);
			
			ling = new("/d/kunlun/obj/tieyanling");
			ling->move(player);

			message_vision("$N从身上拿出一块铁焰令交给$n。\n",this_object(),player);
			return player->query("name")+"！收好，不可再丢。\n";
		}
		
		else
			return "铁焰令乃我明教信物，"+RANK_D->query_respect(player)+"怎可丢失？快去向冷执法禀明过失。\n";


}

void attempt_apprentice(object ob)
{
		command("say 我光明圣教向来没有师徒之别，只有等级之分，教众之间可以相互传授武艺。这是我教历来的规矩。" + RANK_D->query_respect(ob) +"想要学武的话，可向教中有名望的兄弟请教。\n");
		
		return;
}


void Set_Inquiry(mapping I_inquiry,mixed Skill_name)
{
	int i;
	string str_skill;
	mapping I_inquiryS;
	if(sizeof(I_inquiry))
		I_inquiryS=I_inquiry;
	str_skill="";

	if(i=sizeof(Skill_name))
	{
		set("teach_skillsname",Skill_name);
		for(i=0;i<sizeof(Skill_name);i++)
		{
			str_skill=str_skill+to_chinese(Skill_name[i])+"("+Skill_name[i]+")"+"\n";
			
		}
	
		I_inquiryS["武功"]="在下不才，能传授给阁下的武功有\n"+str_skill+"\n如阁下想学，只需向我请教( qingjiao <某人> <技能> [次数])，就可以了。\n";
	}
	else
		I_inquiryS["武功"]="在下武功低微，恐怕不能传授阁下什么武功，阁下请另请高明。\n";

	I_inquiryS["铁焰令"]=(: ask_tyling :);
	set("inquiry",I_inquiryS);

	
	return;
}

int Set_Action()
{
	object ob=this_object();
	if(ob->query("teach_skillsname"))
	{
		add_action ("do_qingjiao", "qingjiao");

	}
}


void Set_Npcattrib(int Basic_Attrib,int Random_var,
				   int Maxqi,int Random_Maxqi,
				   int Maxjing,int Random_Maxjing,
				   int Maxjingli,int Random_Maxjingli,
				   int Maxneili,int Random_Maxneili,
				   int Exp,int Random_Exp)
				  				  
{
	int Mneili=Maxneili+random(Random_Maxneili);
	set("str", Basic_Attrib+random(Random_var));
	set("int", Basic_Attrib+random(Random_var));
	set("con", Basic_Attrib+random(Random_var));
	set("dex", Basic_Attrib+random(Random_var));
	set("max_qi", Maxqi+random(Random_Maxqi));
	set("max_jing", Maxjing+random(Random_Maxjing));
	set("eff_jingli", Maxjingli+random(Random_Maxjingli));
	set("max_neili", Mneili);
	set("neili",Mneili);
	set("combat_exp", Exp+random(Random_Exp));
	return;
}

void Set_Npcskills(int Basic_skill,int Random_skill,mapping S_skills)
{
	int i;
	mixed S_name;
	
	if(i=sizeof(S_skills))
	{
		S_name=keys(S_skills);
		for(i=0;i<sizeof(S_name);i++)
		{
			set_skill(S_name[i], Basic_skill+random(Random_skill) );
			set_skill(S_skills[S_name[i]], Basic_skill+random(Random_skill) );
			map_skill(S_name[i],S_skills[S_name[i]]);
		}
	}

	set("jiali",(Basic_skill+Basic_skill/2)/2);
	return;
}


int prevent_learn(object me, string skill)
{
	return 0;
}

void set_title(object player, int generation)
{
	string title;

	switch(generation)
	{
		case 33:
			title = "教主";
			break;
		case 34:
			title = "光明使者";
			break;
		case 35:
			title = "护教法王";
			break;
		case 36:
			title = "散人";
			break;
		case 37:
			title = "掌旗使";
			break;
		case 38:
			title = "教众";
			break;
		default:
			title = "教众";
	}

	player->set("title","明教"+title);

}