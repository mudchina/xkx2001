//Change by Server (7/26/2001)
///d/wulin/center.c

#include <ansi.h>
inherit ROOM;
/////////add by wzfeng 2000 7 1
#define JOB_DIR "/clone/obj/job/"
int JOB_TICK=5;
int JOB_PRODUCE=120;
int PRODUCE_TEMP=0;
//////////////////////////////
string copyright=HBBLU+HIY+"游戏主动性任务察看器1.0版     Server 2001年7月     \n"NOR;
string show_word();
#include "/clone/obj/job/default_data.h"
#include "/clone/obj/job/lpc_math.h"

#define MAPDB "/clone/obj/mapdb"
#define TRAVERSER  "/clone/obj/traverser"
#define JOB_DIR "/clone/obj/job/"

void create()
{
	set("short", HIR"武林幻境"NOR);
	set("long", HIC
"这里是武林中各个门派任务系统的控制中心，在这里可以控制整个游戏\n"
"的强制性任务系统。此地乃虚空之地，不存在于江湖实境中。四周一片\n"
"虚无，言语无法描述其万一。\n"+NOR
HIY+"\t上方虚空处漂浮着金光闪闪的几行小字(gold word)。\n"+NOR
	);
        set("outdoors", "虚无飘渺");

	set("exits", ([
		"kd" : "/d/city/kedian",
        
	]));
		set ("item_desc", ([
				"gold word" : (: show_word :),
				]));

/*        set("objects", ([
                __DIR__"npc/dizi3" : 1,
        ]));
		*/
		set("no_refresh",1);
	setup();

}
/*int start_check_job_player_place()
{
	object obj_temp;
	
	if(!(obj_temp=find_object("/clone/obj/job/job_produce")))
	{
		if(!obj_temp=new("/clone/obj/job/job_produce"))
			return notify_fail("/clone/obj/job/job_produce.c初始化错误。\n");
	}
	obj_temp->check_player_place();
	
	remove_call_out("start_check_job_player_place");
	call_out( "start_check_job_player_place",5); 

	return 1;
}
*/
string show_word()
{
	return HIW"武林幻境控制大法：\n"NOR
		HIC"\t命令\t\t\t解释\n"NOR
		HIY"\tstart_system\t\t"NOR+HIG"启动任务系统\n"NOR
		HIY"\tclose_system\t\t"NOR+HIG"启动任务系统\n"NOR
		HIY"\tjob_start\t\t"NOR+HIG"发布一次任务\n"NOR
		HIY"\tjob_stop\t\t"NOR+HIG"停止武林幻境任务系统\n"NOR
		HIY"\tjob_check\t\t"NOR+HIG"查询武林任务系统各种状态\n"NOR
		HIY"\tjob_setorg_default\t"NOR+HIG"将各个门派参数设置为缺省\n"NOR
		HIY"\tjob_setorgluck\t\t"NOR+HIG"修改某个门派的幸运数值\n"NOR
		HIY"\tjob_setorgmoney\t\t"NOR+HIG"修改某个门派的金钱系数\n"NOR
		HIY"\tjob_setorgstrategy\t"NOR+HIG"修改某个门派的策略系数\n"NOR
		HIY"\tjob_setorgpower\t\t"NOR+HIG"修改某个门派的势力\n"NOR
		HIY"\tset_contribute\t\t"NOR+HIG"修改某个门派的贡献度\n"NOR
		HIY"\tdo_check_player\t\t"NOR+HIG"查找某个玩家的任务执行情况\n"NOR
		HIY"\tjob_cut\t\t\t"NOR+HIG"删除某个玩家的任务信息\n"NOR
		HIY"\tcheck_do_job\t\t"NOR+HIG"查找目前所有在线玩家的任务执行情况\n"NOR
		HIY"\tchange_rate\t\t"NOR+HIG"修改目前任务的分配比率\n"NOR
		HIY"\tcheck_menpai_job\t"NOR+HIG"察看目前门派的任务完成情况\n"NOR
		HIY"\tcheck_menpai_assess\t"NOR+HIG"察看门派的贡献度情况\n"NOR
		

		

		HIR"\n\n\t\t\t\t\t\慎用\n"NOR
		;
}
void init()
{
	object ob;

	add_action("do_start", "job_start");
	add_action("do_check_player", "do_check_player");
	add_action("do_stop", "job_stop");	
	add_action("do_check", "job_check");
	add_action("do_setorg_default", "job_setorg_default");
	add_action("do_setorg_luck", "job_setorgluck");
	add_action("do_setorg_money", "job_setorgmoney");
	add_action("do_setorg_strategy", "job_setorgstrategy");
	add_action("do_setorg_pwoer", "job_setorgpower");
	add_action("do_set_job_contribute", "set_contribute");
	add_action("do_cut_job", "job_cut");
	add_action("do_check_do_job", "check_do_job");
	add_action("do_change_rate", "change_rate");
	add_action("do_check_menpai_job", "check_menpai_job");
	add_action("do_start_system", "start_system");
	add_action("do_close_system", "close_system");
	add_action("do_check_menpai_assess", "check_menpai_assess");

	

	
	
	
}


//judge this system who can use it?
int can_used()
{
		object me;
		me=this_player();

		if(this_player()->query("id")!="server"&&
			this_player()->query("id")!="poke"&&
            this_player()->query("id")!="xuanyuan"
			)
			return notify_fail ("任务控制系统目前只能由高级巫师来控制。\n");
		if(!wizardp(me))
			return notify_fail ("你还没有获得神仙的法力，无法控制这里。\n");
		return 1;

}
int do_check_menpai_assess()
{
	object menpai_ob,job_data;
	mapping *family_do_datas,*menpai,temp_map,temp1_map;
	string *family_name;
	int i;
	if(!can_used())
		return 0;
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	if(!objectp(menpai_ob)) return 0;
	menpai_ob->restore();
	menpai=menpai_ob->query_familys();
	if(!pointerp(menpai))
		return notify_fail ("menpai_data error!!!\n");

	
	family_name=get_array_map("family_name",menpai);

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();

	family_do_datas=job_data->query_familys_job_data();
	if(!pointerp(family_do_datas))
		return notify_fail ("family_do_datas\n");
	write(copyright);
	
	for(i=0;i<sizeof(family_name);i++)
	{
		//printf("%s\n",family_name[i]);
		temp_map=job_data->query_family_job_data(family_name[i]);
		if(!mapp(temp_map)
		||temp_map["job_contribute"]<=0||undefinedp(temp_map["job_contribute"]))
		{
			temp_map=([]);
			temp_map["job_contribute"]=0;
		}
	
		//continue;
		temp1_map=get_mapping(family_name[i],"family_name",menpai);
		if(!mapp(temp1_map)
		||temp1_map["family_assess_num"]<=0
		||undefinedp(temp1_map["family_assess_num"]))
		{
		temp1_map = ([]);
		temp1_map["family_assess_num"]=0;
		}

		printf("%|10s当前的贡献度为%d\t贡献度基数为%d\n",family_name[i],temp_map["job_contribute"],temp1_map["family_assess_num"]);


	}


		return 1;
	

}
int do_check_menpai_job(string arg)
{
	string *option,msg,*member;
	object job_data;
	int wudang,xingxiu,huashan,taohua,gaibang,emei,baituo,quanzhen,xueshan,dali,shaolin,i;
	if(!arg)
	return notify_fail("格式check_menpai_job -menpai_name。\n");
	if(!can_used())
		return 0;

	msg="";
	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
			case "-wudang": wudang = 1; break;
			case "-xingxiu": xingxiu = 1; break;
			case "-huashan": huashan = 1; break;
			case "-taohua": taohua = 1; break;
			case "-gaibang": gaibang = 1; break;
			case "-emei": emei = 1; break;
			case "-baituo": baituo = 1; break;
			case "-quanzhen": quanzhen = 1; break;
			case "-xueshan": xueshan = 1; break;
			case "-dali": dali = 1; break;
			case "-shaolin": shaolin = 1; break;

		default:
					return notify_fail("你要查什么门派?\n");
		}
	}

		if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
		if(!objectp(job_data)) return 0;
		job_data->restore();
		msg+=copyright;
		if(wudang)
		{
			msg+=job_data->query_family_jobdata("武当派");
			member=job_data->choose_of_player("武当派","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("武当派","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}

		if(xingxiu)
		{
			msg+=job_data->query_family_jobdata("星宿派");
			member=job_data->choose_of_player("星宿派","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("星宿派","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(huashan)
		{
			msg+=job_data->query_family_jobdata("华山派");
			member=job_data->choose_of_player("华山派","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("华山派","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(taohua)
		{
			msg+=job_data->query_family_jobdata("桃花岛");
			member=job_data->choose_of_player("桃花岛","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("桃花岛","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(gaibang)
		{
			msg+=job_data->query_family_jobdata("丐帮");
			member=job_data->choose_of_player("丐帮","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("丐帮","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(emei)
		{
			msg+=job_data->query_family_jobdata("峨嵋派");
			member=job_data->choose_of_player("峨嵋派","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("峨嵋派","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(baituo)
		{
			msg+=job_data->query_family_jobdata("白驼山");
			member=job_data->choose_of_player("白驼山","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("白驼山","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(quanzhen)
		{
			msg+=job_data->query_family_jobdata("全真教");
			member=job_data->choose_of_player("全真教","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("全真教","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(xueshan)
		{
			msg+=job_data->query_family_jobdata("雪山派");
			member=job_data->choose_of_player("雪山派","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("雪山派","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(dali)
		{
			msg+=job_data->query_family_jobdata("大理段家");
			member=job_data->choose_of_player("大理段家","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("大理段家","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
		if(shaolin)
		{
			msg+=job_data->query_family_jobdata("少林派");
			member=job_data->choose_of_player("少林派","good");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="这个门派有数个贡献度最高的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="这个门派贡献度最高的玩家是：\n";
					msg+=member[0]+"\n";
				}
			member=job_data->choose_of_player("少林派","bad");
			if(!sizeof(member))
				msg+=HIR"这个门派没有完成任务的完家。\n"NOR;
			else
				if(sizeof(member)!=1)
				{
					msg+="\n这个门派有数个贡献度最低的玩家，他们分别是：\n";
					for(i=0;i<sizeof(member);i++)
						msg+=member[i]+"\t";
				}
				else
				{
					msg+="\n这个门派贡献度最低的玩家是：\n";
					msg+=member[0]+"\n";
				}
			this_player()->start_more(msg);
		}
	
		

		return 1;

}
int do_start_system()
{
	object job_data,job_system;
	if(!wizardp(this_player()))
			return notify_fail ("你还没有获得神仙的法力，无法开启主动性任务系统。\n");
	
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return notify_fail ("数据库程序编译出错。\n");
	job_data->restore();

	if(!find_object(JOB_DIR+"job_system"))
		if(!load_object(JOB_DIR+"job_system"))
			return notify_fail ("job_system编译出错。\n");
		if(job_data->query_job_start())
			return notify_fail ("主动性任务系统已经开启。\n");

	job_data->set_job_start();
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将任务系统开启"+
		" on " 	+ ctime(time()) + "。\n" );
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将任务系统开启了。\n");
	return 1;
}
int do_close_system()
{
	object job_data,job_system;
	if(!wizardp(this_player()))
			return notify_fail ("你还没有获得神仙的法力，无法关闭主动性任务系统。\n");
	
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return notify_fail ("数据库程序编译出错。\n");
	job_data->restore();

	if(!find_object(JOB_DIR+"job_system"))
		if(!load_object(JOB_DIR+"job_system"))
			return notify_fail ("job_system编译出错。\n");
		if(!job_data->query_job_start())
			return notify_fail ("主动性任务系统已经关闭。\n");

	job_data->set_close_start();
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将任务系统关闭"+
		" on " 	+ ctime(time()) + "。\n" );
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将任务系统关闭了。\n");
	return 1;
}


int do_cut_job(string arg)
{
	object job_data;
	mapping job_map;
	string player_name,msg;
	msg="";
	if (!can_used())
	return 0;
	if(!arg)
		return notify_fail("job_cut player_name。\n");
	if( sscanf(arg, "%s", player_name)!=1 ) 
		return notify_fail("job_cut player_name。\n");
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");


	job_data->restore();
	if(player_name=="all")
		job_data->reset();
	else
	{
		msg+=copyright;
		msg+="你现在删除"+arg+"所有的任务\n";
		job_map=get_mapping(player_name,"job_player",job_data->query_job_data());
		msg+=(p_map(job_map));
		job_data->detract_job_data(player_name);
	}
	write(msg);
	job_data->save();
	return 1;


}
int do_set_job_contribute(string arg)
{
	object obj_temp;
	string menpai;
	int num;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("格式set_contribute menpai_name num。\n");
	if( sscanf(arg, "%s %d", menpai, num)!=2 ) 
		return notify_fail("格式set_contribute menpai_name num。\n");
	if(num>100000)
		return notify_fail("比率值最大不能超过100000。\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("没有"+menpai+"这个门派。\n");
	obj_temp->do_set_assess_num(menpai,num);
	obj_temp->save();

	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将"+menpai+"的贡献度设置成" +num+
		" on " 	+ ctime(time()) + "。\n" );
	write(HIY+this_player()->query("name")+"突的双眼异彩暴闪，四周光芒大增”。\n"NOR);
	write("你将"+obj_temp->con_name(menpai,2)+"的贡献度设置成"+num+"\n");
	//write(HIR"区域势力的修改必须要能保持相对的平衡，否则天下大乱。\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将"+obj_temp->con_name(menpai,2)+"的贡献度设置成"+num+"。\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}
int do_change_rate(string arg)
{
	object obj_temp;
	string menpai;
	int rate;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("格式change_rate menpai_name rate。\n");
	if( sscanf(arg, "%s %d", menpai, rate)!=2 ) 
		return notify_fail("格式change_rate menpai_name rate。\n");
	if(rate>100)
		return notify_fail("比率值最大不能超过100。\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("没有"+menpai+"这个门派。\n");
	obj_temp->do_set_rate(menpai,rate);
	obj_temp->save();

	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将"+menpai+"的任务出现比率设置成" +rate+
		" on " 	+ ctime(time()) + "。\n" );
	write(HIY+this_player()->query("name")+"突的双眼异彩暴闪，四周光芒大增”。\n"NOR);
	write("你将"+obj_temp->con_name(menpai,2)+"的任务出现几率设置成"+rate+"\n");
	//write(HIR"区域势力的修改必须要能保持相对的平衡，否则天下大乱。\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将"+obj_temp->con_name(menpai,2)+"的任务出现几率设置成"+rate+"。\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}

int do_check_player(string arg)
{
	object job_data;
	mapping job_map;
	string player_name,msg;
	msg=" ";
	if(!arg)
		return notify_fail("do_check_player player_name。\n");
	if( sscanf(arg, "%s", player_name)!=1 ) 
		return notify_fail("do_check_player player_name。\n");
	
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");

	job_data->restore();
	job_map=get_mapping(player_name,"job_player",job_data->query_job_data());
	msg+=copyright;
	if(!sizeof(job_map))
	{
		msg+="没有这个player的信息。\n";
		write(msg);
		return 1;
	}
	msg+=(p_map(job_map));
	write(msg);

	return 1;
}
int is_online(string name)
{
	if(!find_player(name))
		return 0;
	return 1;
}
int do_check_do_job()
{
	object job_data,*ob;
	mapping job_map;
	string player_name,*ask_job,*oppose_job,*finish_job,msg;
	int i;
	msg="";
	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	job_data->restore();
	finish_job=job_data->query_list("finish_job");
	if(pointerp(finish_job))
	finish_job=filter_array(finish_job, (:is_online:));
	ask_job=job_data->query_list("ask_job");
	if(pointerp(ask_job))
	ask_job=filter_array(ask_job, (:is_online:));
	oppose_job=job_data->query_list("oppose_pker");
	if(pointerp(oppose_job))
	oppose_job=filter_array(oppose_job, (:is_online:));	
	msg+=copyright;
	msg+="现在已经得到任务的人有:\n";

	for(i=0;i<sizeof(ask_job);i++)
		msg+=ask_job[i]+"\n";
	msg+="现在正在执行任务的人有:\n";
	
	for(i=0;i<sizeof(oppose_job);i++)
		msg+=oppose_job[i]+"\n";
	msg+="现在已经完成任务的人有:\n";

	for(i=0;i<sizeof(finish_job);i++)
		msg+=finish_job[i]+"\n";
	write(msg);
	return 1;

}
int do_start(string arg)
{
	object obj_temp;
	string player_name;
	if (!can_used())
	return 0;
/*	if(query("job_start"))
		return notify_fail ("武林幻境任务系统已经在运行了。\n");


	write(HIY+this_player()->query("name")+"闭目聚神，双手已诡异形态变化，口中念念有词......。\n"NOR);
	write(HIY+this_player()->query("name")+"突的大喝一声：开！！！\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间突然风雨变色，电闪雷鸣。随着一道金光划过天际，刹那间又恢复平静......");
	CHANNEL_D->do_channel(this_player(), "sys", "我将武林幻境任务系统开启。\n");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将武林幻境任务系统开启" +
		" on " 	+ ctime(time()) + "。\n" );
	set("job_start",1);
	*/
	if(!arg)
	{
		if(!(obj_temp=find_object("/clone/obj/job/job_produce")))
			if(!obj_temp=new("/clone/obj/job/job_produce"))
				return notify_fail("/clone/obj/job/job_produce.c初始化错误。\n");
			obj_temp->restore();
			obj_temp->produce_job(0);
			return 1;

	}

	if( sscanf(arg, "%s", player_name)!=1 ) 
		return notify_fail("格式job_start player_name。\n");

	if(!(obj_temp=find_object("/clone/obj/job/job_produce")))
		if(!obj_temp=new("/clone/obj/job/job_produce"))
			return notify_fail("/clone/obj/job/job_produce.c初始化错误。\n");
		obj_temp->restore();
		if(!find_player(player_name))
			return notify_fail("没有这个玩家。\n");
		obj_temp->produce_job(player_name);
	return 1;
}

int do_setorg_pwoer(string arg)
{
	object obj_temp;
	string menpai,area;
	int num;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("格式set_orgpwoer menpai_name area area_num。\n");
	if( sscanf(arg, "%s %s %d", menpai, area,num)!=3 ) 
		return notify_fail("格式set_orgpwoer menpai_name area area_num。\n");
	if(num>100)
		return notify_fail("策略值最大不能超过100。\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("没有"+menpai+"这个门派。\n");
	if(!obj_temp->have_power(menpai,area,num))
	return notify_fail("没有"+area+"这个区域。\n");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将"+menpai+"的"+area+"的势力设置成" +num+
		" on " 	+ ctime(time()) + "。\n" );
	write(HIY+this_player()->query("name")+"突的双眼异彩暴闪，四周光芒大增”。\n"NOR);
	write("你将"+obj_temp->con_name(menpai,2)+"的"+area+"的势力设置成"+num+"\n");
	write(HIR"区域势力的修改必须要能保持相对的平衡，否则天下大乱。\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将"+obj_temp->con_name(menpai,2)+"的"+area+"的势力设置成"+num+"。\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}

int do_setorg_strategy(string arg)
{
	object obj_temp;
	string menpai,strategy;
	int num;
	if (!can_used())
	return 0;

	if(!arg)
		return notify_fail("格式set_orgstrategy menpai_name strategy strategy_num。\n");
	if( sscanf(arg, "%s %s %d", menpai, strategy,num)!=3 ) 
		return notify_fail("格式set_orgstrategy menpai_name strategy strategy_num。\n");
	if(num>100)
		return notify_fail("策略值最大不能超过100。\n");


	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
	return notify_fail("没有"+menpai+"这个门派。\n");
	if(!obj_temp->have_strategy(menpai,strategy,num))
	return notify_fail("没有"+strategy+"这个策略。\n");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将"+menpai+"的"+strategy+"策略数值设置成" +num+
		" on " 	+ ctime(time()) + "。\n" );
	write(HIY+this_player()->query("name")+"突的双眼异彩暴闪，四周光芒大增”。\n"NOR);
	write("你将"+obj_temp->con_name(menpai,2)+"的"+strategy+"策略数值设置成"+num+"\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将"+obj_temp->con_name(menpai,2)+"的"+strategy+"策略数值设置成"+num+"。\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;

}
int do_setorg_luck(string arg)
{
	object obj_temp;
	string menpai;
	int num;
	if (!can_used())
	return 0;
	if(!arg)
		return notify_fail("格式set_orgluck menpai_name luck_num。\n");
	if( sscanf(arg, "%s %d", menpai, num)!=2 ) 
		return notify_fail("格式set_orgluck menpai_name luck_num。\n");
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
		return notify_fail("没有"+menpai+"这个门派。\n");
	if(num>10)
		return notify_fail("幸运值最多为10。\n");
	obj_temp->do_set_luck(menpai,num);
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将"+menpai+"的幸运指数设置成" +num+
		" on " 	+ ctime(time()) + "。\n" );
	write(HIY+this_player()->query("name")+"突的双眼异彩暴闪，四周光芒大增”。\n"NOR);
	write("你将"+obj_temp->con_name(menpai,2)+"的幸运指数改成"+num+"\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将"+obj_temp->con_name(menpai,2)+"的幸运指数设置成"+num+"。\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;
}

int do_setorg_money(string arg)
{
	object obj_temp;
	string menpai;
	int num;
	if (!can_used())
	return 0;
	if(!arg)
		return notify_fail("格式set_orgmoney menpai_name money_num。\n");
	if( sscanf(arg, "%s %d", menpai, num)!=2 ) 
		return notify_fail("格式set_orgmoney menpai_name money_num。\n");
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	obj_temp->restore();
	if(!obj_temp->have_menpai(menpai))
		return notify_fail("没有"+menpai+"这个门派。\n");

	obj_temp->do_set_money(menpai,num);
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将"+menpai+"的金钱系数设置成" +num+
		" on " 	+ ctime(time()) + "。\n" );
	write(HIY+this_player()->query("name")+"突的双眼异彩暴闪，四周光芒大增”。\n"NOR);
	write("你将"+obj_temp->con_name(menpai,2)+"的金钱系数改成"+num+"\n");
	write(HIY"金钱系数的修改必须要能保持和其它门派的相对的平衡，否则天下经济崩溃。\n"NOR);
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间微微颤动，似乎预示着什么玄机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将"+obj_temp->con_name(menpai,2)+"的金钱系数设置成"+num+"。\n");
	if(obj_temp)
	destruct(obj_temp);
	return 1;
}


int do_setorg_default(string arg)
{
	object obj_temp;
	string menpai;
		if (!can_used())
		return 0;
	if (!arg) 
		return notify_fail("job_setorg_default all全部门派初始化设置。\n"
		"job_setorg_default menpai_name指定门派初始化设置。\n");

	if( sscanf(arg, "%s", menpai)!=1 ) 
		return notify_fail("job_setorg_default all全部门派初始化设置。\n"
		"job_setorg_default menpai_name指定门派初始化设置。\n");

	
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	
	obj_temp->restore();
	if(arg=="all")
	{
	obj_temp->set_default();
	obj_temp->add_orgdata("武当派",strategy_wd,luck_wd,money_wd,luck_wdrate,power_wd,assess_wd);
	obj_temp->add_orgdata("星宿派",strategy_xx,luck_xx,money_xx,luck_xxrate,power_xx,assess_xx);
	obj_temp->add_orgdata("华山派",strategy_hs,luck_hs,money_hs,luck_hsrate,power_hs,assess_hs);
	obj_temp->add_orgdata("桃花岛",strategy_th,luck_th,money_th,luck_thrate,power_th,assess_th);
	obj_temp->add_orgdata("丐帮",strategy_gb,luck_gb,money_gb,luck_gbrate,power_gb,assess_gb);
	obj_temp->add_orgdata("峨嵋派",strategy_em,luck_em,money_em,luck_emrate,power_em,assess_em);
	obj_temp->add_orgdata("白驼山",strategy_bt,luck_bt,money_bt,luck_btrate,power_bt,assess_bt);
	obj_temp->add_orgdata("全真教",strategy_qz,luck_qz,money_qz,luck_qzrate,power_qz,assess_qz);
	obj_temp->add_orgdata("雪山派",strategy_xs,luck_xs,money_xs,luck_xsrate,power_xs,assess_xs);
	obj_temp->add_orgdata("大理段家",strategy_dl,luck_dl,money_dl,luck_dlrate,power_dl,assess_dl);
	obj_temp->add_orgdata("少林派",strategy_sl,luck_sl,money_sl,luck_slrate,power_sl,assess_sl);
	write("你将武林幻境的各门派参数设置为却省数值。\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间发出一丝丝颤动，似乎预示着什么天机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将各门派的系统参数设置成却省值。");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将各门派的系统参数设置成却省值" +
		" on " 	+ ctime(time()) + "。\n" );
	return 1;
	}

	switch(arg) {
		case "wudang":
			obj_temp->change_orgdata("武当派",strategy_wd,luck_wd,money_wd,power_wd);
			break;
		case "xingxiu":
			obj_temp->change_orgdata("星宿派",strategy_wd,luck_wd,money_wd,power_wd);
			break;

			default:
				return notify_fail("目前武林幻境任务系统不支持"+arg+"门派\n");
		}
	write(HIW+this_player()->query("name")+"聚集精神，双手合成一浑圆，大喝一生“呔！”。\n"NOR);
	
	CHANNEL_D->do_channel(this_object(), "rumor", "天地间发出微微颤动，似乎预示着什么神机。");
	CHANNEL_D->do_channel(this_player(), "sys", "我将"+obj_temp->con_name(arg,2)+"的系统参数设置成却省值。");
	log_file( "test/job_system_set",
		this_player()->query("name")+
		"("+this_player()->query("id")+")将"+obj_temp->con_name(arg,2)+"的系统参数设置成却省值" +
		" on " 	+ ctime(time()) + "。\n" );


	obj_temp->save();
	if(obj_temp)
	destruct(obj_temp);


	return 1;
//int add_orgdata(string family_name,mapping strategy,int luck,int money,mapping power)


}
int do_check(string arg)
{
	object me,obj_temp;
	string *option,help_message;
	int i,menpai,help,luck,money,strategy,wudang,xingxiu,huashan,taohua,gaibang,emei,baituo,
		quanzhen,xueshan,dali,shaolin,rate;
	me=this_player();
	
	if (!arg) 
		return notify_fail("你要查什么？如果要获得job_check帮助请输入job_check -help \n");
	//查询门派的相关信息

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
			case "-menpai": menpai = 1; break;
			case "-help": help = 1; break;
			case "-luck": luck = 1; break;
			case "-money": money = 1; break;
			case "-strategy": strategy = 1; break;
			case "-wudang": wudang = 1; break;
			case "-xingxiu": xingxiu = 1; break;
			case "-huashan": huashan = 1; break;
			case "-taohua": taohua = 1; break;
			case "-gaibang": gaibang = 1; break;
			case "-emei": emei = 1; break;
			case "-baituo": baituo = 1; break;
			case "-quanzhen": quanzhen = 1; break;
			case "-xueshan": xueshan = 1; break;
			case "-dali": dali = 1; break;
			case "-shaolin": shaolin = 1; break;
			case "-rate": rate=1;break;
		default:
					return notify_fail("你要查什么？如果要获得job_check帮助请输入job_check -help \n");
		}
	}
	if(help)
	{
		
		write(copyright);
		help_message = "-menpai\t\t获得门派相关信息。\n" ;
		help_message += "-luck\t\t获得门派幸运数值列表。\n" ;
		help_message += "-money\t\t获得门派金钱系数列表。\n" ;
		//help_message += "-strategy\t获得门派策略一览列表。\n" ;
		help_message += "-menpai_name\t获得门派完全详细列表。\n" ;
		help_message += "-rate\t获得门派任务产生比率。\n" ;
		me->start_more(help_message);
		return 1;



	}
	write(copyright);
	if(wudang)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("wudang"))
		return notify_fail("没有"+"wudang"+"这个门派。\n");


	obj_temp->query_full_menpaidata("wudang");
	}
	if(xingxiu)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("xingxiu"))
		return notify_fail("没有"+"xingxiu"+"这个门派。\n");
	obj_temp->query_full_menpaidata("xingxiu");
	}

	if(huashan)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("huashan"))
		return notify_fail("没有"+"huashan"+"这个门派。\n");
	obj_temp->query_full_menpaidata("huashan");
	}
	if(taohua)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("taohua"))
		return notify_fail("没有"+"taohua"+"这个门派。\n");
	obj_temp->query_full_menpaidata("taohua");
	}
	if(gaibang)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("gaibang"))
		return notify_fail("没有"+"gaibang"+"这个门派。\n");
	obj_temp->query_full_menpaidata("gaibang");
	}
	if(emei)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("emei"))
		return notify_fail("没有"+"emei"+"这个门派。\n");
	obj_temp->query_full_menpaidata("emei");
	}
	if(baituo)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("baituo"))
		return notify_fail("没有"+"baituo"+"这个门派。\n");
	obj_temp->query_full_menpaidata("baituo");
	}
	if(quanzhen)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("quanzhen"))
		return notify_fail("没有"+"quanzhen"+"这个门派。\n");
	obj_temp->query_full_menpaidata("quanzhen");
	}
	if(xueshan)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("xueshan"))
		return notify_fail("没有"+"xueshan"+"这个门派。\n");
	obj_temp->query_full_menpaidata("xueshan");
	}
	if(dali)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("dali"))
		return notify_fail("没有"+"dali"+"这个门派。\n");
	obj_temp->query_full_menpaidata("dali");
	}
	if(shaolin)
	{
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");
	if(!obj_temp->have_menpai("shaolin"))
		return notify_fail("没有"+"shaolin"+"这个门派。\n");
	obj_temp->query_full_menpaidata("shaolin");
	}


	if(luck)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");

	obj_temp->query_luck_list();
	}
	if(money)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");

	obj_temp->query_money_list();
	}
	if(menpai)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");

	obj_temp->query_menpai_list();
	}
	if(rate)
	{
		
	if(!obj_temp=new("/clone/obj/job/job_menpai"))
		return notify_fail("/clone/obj/job/job_menpai初始化错误。\n");
	if(!obj_temp->restore())
		return notify_fail("初始化job_menpai错误，请重新设置。\n");

	obj_temp->query_rate_list();
	}
	if(obj_temp)
	destruct(obj_temp);
	
	
	return 1;

}
