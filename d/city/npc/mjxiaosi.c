//Cracked by Roath
//mjxiaosi.c
//Remake And Bug fix at 2000,Nov,18 by Mantian

#include <ansi.h>
inherit NPC;
#define MJ_DATA "/data/mj_data.o"
#define END 286
#define START 0
void check_flower(mapping who);
int to_say_play();
int to_say_rule();
int do_dump(string str,object me);
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str);
int check_hu(string strW);
int set_mjdata(object me,int *winner);
int *get_mjdata(string id);
int get_tc(mapping who);
varargs int do_autodump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gang(string str,object me);
varargs int do_peng(string str,object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
mixed do_check_num(string str,int flag);
//牌只资料
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9seasowenojofabaf1f2f3f4f5f6f7f8";
string *MjC = ({"",
				"一万","二万","三万","四万","伍万","六万","七万","八万","九万",
				"一筒","二筒","三筒","四筒","伍筒","六筒","七筒","八筒","九筒",
				"一索","二索","三索","四索","伍索","六索","七索","八索","九索",
				"东风","南风","西风","北风","红中","青发","白板",
				"1 春","2 夏","3 秋","4 冬","1 梅","2 兰","3 竹","4 菊","暗杠"
				});
string* TossPic = ({
"　　"HBWHT BLK"╭━━━╮"NOR,"　　"HBWHT BLK"╭━━━╮"NOR,"　　"HBWHT BLK"╭━━━╮"NOR,
"　　"HBWHT BLK"╰━━━╯"NOR,"　　"HBWHT BLK"╰━━━╯"NOR,"　　"HBWHT BLK"╰━━━╯"NOR,
"　",
"　　"HBWHT BLK"┃　　　┃"NOR,"　　"HBWHT BLK"┃　"HIR"●　"BLK"┃"NOR,"　　"HBWHT BLK"┃　　　┃"NOR,
"　　"HBWHT BLK"┃　●　┃"NOR,"　　"HBWHT BLK"┃　　　┃"NOR,"　　"HBWHT BLK"┃　●　┃"NOR,
"　　"HBWHT BLK"┃●　　┃"NOR,"　　"HBWHT BLK"┃　●　┃"NOR,"　　"HBWHT BLK"┃　　●┃"NOR,
"　　"HBWHT BLK"┃"HIR"●　●"BLK"┃"NOR,"　　"HBWHT BLK"┃　　　┃"NOR,"　　"HBWHT BLK"┃"HIR"●　●"BLK"┃"NOR,
"　　"HBWHT BLK"┃●　●┃"NOR,"　　"HBWHT BLK"┃　●　┃"NOR,"　　"HBWHT BLK"┃●　●┃"NOR,
"　　"HBWHT BLK"┃●　●┃"NOR,"　　"HBWHT BLK"┃●　●┃"NOR,"　　"HBWHT BLK"┃●　●┃"NOR,
	});

int K;
string Tc = "";
//资料
int Auto;
int Auto_Ting;
int Auto_Gang;
int Auto_Peng;
int Count;
int count;
int end;
int Ganged;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "","","","" });
string *NowPlayerName = ({ "","","","" });
string LastDumpId="";
string LastDumpName="";
string LastDump="";
string KaiMen="";
string Dump="";
 
mapping P1Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
mapping P2Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
mapping P3Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGang": "","OutPeng": "",
"OutFlower": "","Auto": "","AutoTing": "","AutoGang": "","AutoPeng": "","Dump": ""
               ]);
void create()
{
	set_name(MAG"小厮"NOR,({"xiao si" , "xiaosi"}));
	set("gender", "男性");
	set("age", 18);
	set_weight(1);
	set("long", "他是麻将馆打杂的小厮，如果你对麻将的玩法还不熟悉的话，\n可以试着问问他玩法与规则。\n");
	set("inquiry",([
		"段正淳": "我家王爷生性风流。",
		"mj": "请用help mj来了解麻将的历史",
		"麻将": "请用help mj来了解麻将的历史",
		"玩法": "请用help playmj来了解如何运用指令",
		"play": "请用help playmj来了解如何运用指令",
		"规则": (: to_say_rule :),
		"rule": (: to_say_rule :),
	]));
	setup();
	seteuid(getuid());
}
void init()
{
	add_action("do_addin","jiaru");
	add_action("do_addin","addin");
	add_action("do_dump","dump");
	add_action("do_dump","da");
	add_action("do_eat","chi");
	add_action("do_eat","eat");
	add_action("do_gang","gang");
	add_action("do_gang","g");
	add_action("do_win","hu");
	add_action("do_help","help");
	add_action("do_look","look");
	add_action("do_touch","mo");
	add_action("do_peng","peng");
	add_action("do_peng","p");
	add_action("do_restart","restart");
	add_action("wash_mj","wash");
	add_action("do_setmj","setmj");
	add_action("show_score","mjscore");
}
int do_addin()
{
	object me=this_player();
	if (me->query("id")==P1Data["Id"]
		||  me->query("id")==P2Data["Id"]
		||  me->query("id")==P3Data["Id"]
		||  me->query("id")==P4Data["Id"])
	{
		if (!Playing) message_vision(HIY"$N敲着麻将桌心想「怎么还不开始呢。」\n"NOR,me);
		else switch (random(6))
		{
			case 0: message_vision("\n$N对着大家说：「今天让我自摸"+chinese_number(random(12)+1)+"次就好。」\n",me); break;
			case 1: message_vision("\n$N掐指一算奸笑着说：「嘿～嘿～嘿～我算到今天我会连庄"+chinese_number(random(7)+5)+"次。」\n",me);
					message_vision(HIY"突然$N醒悟到庄连越多次放炮输的也越........呜～呜～呜～呜～～～～\n"NOR,me); break;
			case 2: message_vision("\n$N对着"+NowPlayerName[NowPlayer]+"说：「打出来放炮啦，这么慢！」\n",this_object()); break;
			case 3: message_vision(HIY"\n$N想着「随便胡个大三元，大四喜，混一色，五暗刻，碰碰胡，加一加就每人输我"+chinese_number(40)+"台。」\n"NOR,me); break;
			case 4: message_vision("\n$N对着"+NowPlayerName[NowPlayer]+"说道：「你是在摸牌还是在摸鱼？」\n",me); break;
			case 5: message_vision("\n$N对着大家哀求道：「我上有八十老母，下有儿女成群，求你们让我赢。」\n",me); break;
			case 6: message_vision("\n$N心地说：「吃了上家喂下家，想要胡牌就相公，最惨还是我一家烤肉三家香。」\n",me); break;
		}
		return 1;
	}
	if (Playing)
	{
		switch (random(5))
		{
			case 0: message_vision("\n$N哭哭啼啼的说：「我也要玩啦.....。」\n",me); break;
			case 1: message_vision("\n$N大家愤愤的说：「不让我玩我就～～～～我就～～～～我就死给你们看！」\n"NOR,me); break;
			case 2: message_vision("\n$N对着$n说：「你先出去转个几圈再来吧。」\n",this_object(),me); break;
			case 3: message_vision("\n$N说：「我一天不摸麻将就浑身不舒服。」\n",me); break;
			case 4: message_vision("\n$N对着$n说道：「牌局正在进行中，请到旁边坐一下。」\n",this_object(),me); break;
			case 5: message_vision("\n$N对着大家说：「你们要吃什么？我给你们买去。」\n",me); break;
		}
		return 1;
	}
	if (!P1Data["Id"] || P1Data["Id"]=="")
	{
		P1Data["Id"]=me->query("id");
		P1Data["Name"]=me->query("name");
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		message_vision("\n「$N」加入了这场牌局。\n",me);
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"打麻将中的"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("打麻将中", 1);
		Play++;
		Times=0;
		LookP+="在前面有"+me->name()+"，";
		return 1;
	}
	else if (!P2Data["Id"] || P2Data["Id"]=="")
	{
		P2Data["Id"]=me->query("id");
		P2Data["Name"]=me->query("name");
		message_vision("\n「$N」加入了这场牌局。\n",me);
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"打麻将中的"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("打麻将中", 1);
		Play++;
		Times=0;
		LookP+=me->name()+"，";
		return 1;
	}
	else if (!P3Data["Id"] || P3Data["Id"]=="")
	{
		P3Data["Id"]=me->query("id");
		P3Data["Name"]=me->query("name");
		message_vision("\n「$N」加入了这场牌局。\n",me);
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"打麻将中的"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("打麻将中", 1);
		Play++;
		Times=0;
		LookP+=me->name()+"，";
		return 1;
	}
	else if (!P4Data["Id"] || P4Data["Id"]=="")
	{
		P4Data["Id"]=me->query("id");
		P4Data["Name"]=me->query("name");
		message_vision("\n「$N」加入了这场牌局。\n",me);
		NowPlayerId[Play]=me->query("id");
		NowPlayerName[Play]=me->query("name");
		if (me->query_temp("apply/short")) me->set_temp("mj/short", me->query_temp("apply/short"));
		me->set_temp("apply/short", ({"打麻将中的"+me->query("name")+"("+me->query("id")+")"}));
		me->set_temp("打麻将中", 1);
		Play++;
		Times=0;
		LookP+=me->name();
		message_vision("\n\n$N"CYN"说道：「人数已足，请洗牌"NOR RED"<wash>"NOR CYN"。」\n"NOR,this_object());
		return 1;
	}
	return notify_fail(HIW"人数已足。\n"NOR);
}
int do_autodump(string str,object me)
{
	int check,i;
	int *winner=({0,0,0,0});
	string pengid;
	mapping who;
	object met;
 
	if (Ganged==5)
	{
		message_vision("\n「"HIR"五杠合牌"NOR"」，请再重新开始"RED"<start>"NOR"。\n",this_object());
		Playing=0;
		Count++;
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
					if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
					winner[0]++;
					set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	NO_HU=0;
	HU_F=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	check=do_check_Mj(MjE,str);
	if (check==0) return notify_fail(HIW"没有「"NOR HIY+str+NOR HIW"」这种代码。\n"NOR);
	check=do_check_Mj(who["Mj"],str);
	if (check==0) return notify_fail(HIW"你没「"NOR HIY+do_check_num(str,0)+NOR HIW"」这张牌。\n"NOR);
	message_vision("\n$N说道：「"MAG+do_check_num(str,0)+NOR"」\n",me);
	who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	LastDump=str;
	who["Dump"]+=str;
	LastDumpId=who["Id"];
	LastDumpName=who["Name"];
	Touched=0;
	NowPlayer++;
	NowPlayer%=Play;
	message_vision("\n现在轮到「"HIY+NowPlayerName[NowPlayer]+NOR"」摸牌。\n",this_object());
	if (Auto_Ting)
	{
		pengid=check_id(str,"ting");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			return do_win(str,me);
		}
	}
	if (Auto_Gang)
	{
		pengid=check_id(str,"gang");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_gang(str,me);
		}
	}
	if (Auto_Peng)
	{
		pengid=check_id(str,"peng");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_peng(str,me);
		}
	}
	if (count==(end-16-Ganged))
	{
		Playing=0;
		Count++;
		message_vision("\n「"RED"流局"NOR"」请再重新开始 "HIR"<start>"NOR" 。\n",this_object());
		str="所剩下的牌只有：「"+show_mj(List[count..end],2)+"」\n";
		tell_room(environment(this_object()),str);
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
				if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
				winner[0]++;
				set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	if (Auto)
	{
		if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
		else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
		else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
		else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
		if (who["Auto"]=="auto")
		{
			me=present(NowPlayerId[NowPlayer], environment(this_object()));
			if (!me) me=find_player(NowPlayerId[NowPlayer]);
			if (!me) return 1;
			call_out("do_touch",4,"AUTO",me);
		}
	}
	return 1;
}
int do_dump(string str,object me)
{
	int check,i;
	int *winner=({0,0,0,0});
	string pengid;
	mapping who;
	object met;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"这牌局跟你没关系。\n"NOR);
	if (!Playing) return notify_fail(HIW"这牌局跟你没关系。\n"NOR);
	if (!str) return notify_fail(HIW"指令：da <代码>\n"NOR);
	if (me->query("id")!=NowPlayerId[NowPlayer])
	{
		message_vision("现在是轮到「"HIY+NowPlayerName[NowPlayer]+NOR"」\n",me);
		return notify_fail(HIW"作弊啊？现在是轮到「"NOR HIY+NowPlayerName[NowPlayer]+NOR HIW"」不是你，想偷打牌！！\n"NOR);
	}
	if (!Touched) return notify_fail(HIW"你还没摸牌！！\n"NOR);
	if (Ganged==5)
	{
		message_vision("\n「"HIR"五杠合牌"NOR"」，请再重新开始"RED"<start>"NOR"。\n",this_object());
		Playing=0;
		Count++;
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
					if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
					winner[0]++;
					set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	NO_HU=0;
	HU_F=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return notify_fail(HIW"听牌後，不可自己打牌。\n"NOR);
	if (who["Auto"]=="dump") who["Auto"]="auto";
	check=do_check_Mj(MjE,str);
	if (check==0) return notify_fail(HIW"没有「"NOR HIY+str+NOR HIW"」这种代码。\n"NOR);
	check=do_check_Mj(who["Mj"],str);
	if (check==0) return notify_fail(HIW"你没「"NOR HIY+do_check_num(str,0)+NOR HIW"」这张牌。\n"NOR);
	message_vision("\n$N说道：「"MAG+do_check_num(str,0)+NOR"」\n",me);
	who["Mj"]=do_delete_Mj(who["Mj"],str,1);
	LastDump=str;
	who["Dump"]+=str;
	LastDumpId=who["Id"];
	LastDumpName=who["Name"];
	Touched=0;
	NowPlayer++;
	NowPlayer%=Play;
	message_vision("\n现在轮到「"HIY+NowPlayerName[NowPlayer]+NOR"」摸牌。\n",this_object());
	if (Auto_Ting)
	{
		pengid=check_id(str,"ting");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			return do_win(str,me);
		}
	}
	if (Auto_Gang)
	{
		pengid=check_id(str,"gang");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_gang(str,me);
		}
	}
	if (Auto_Peng)
	{
		pengid=check_id(str,"peng");
		if (pengid!="")
		{
			me=present(pengid, environment(this_object()));
			if (!me) me=find_player(pengid);
			if (!me) return 1;
			do_peng(str,me);
		}
	}
	if (count==(end-16-Ganged))
	{
		Playing=0;
		Count++;
		message_vision("\n「"RED"流局"NOR"」请再重新开始 "HIR"<start>"NOR" 。\n",this_object());
		str="所剩下的牌只有：「"+show_mj(List[count..end],2)+"」\n";
		tell_room(environment(this_object()),str);
		if (Play==4)
		{
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
				if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
				winner[0]++;
				set_mjdata(met,winner);
				}
			}
		}
		return 1;
	}
	if (Auto)
	{
		if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
		else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
		else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
		else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
		if (who["Auto"]=="auto")
		{
			me=present(NowPlayerId[NowPlayer], environment(this_object()));
			if (!me) me=find_player(NowPlayerId[NowPlayer]);
			if (!me) return 1;
			call_out("do_touch",4,"AUTO",me);
		}
	}
	return 1;
}
int do_eat(string str)
{
	int LastDumpMan,i;
	string num1,num2;
	object me=this_player();
	mapping who;
 
	if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
	if (check_id(me->query("id"),"player")!="");
	else
	{
		tell_object(me,HIW"这牌局跟你没关系。\n"NOR);
		return 1;
	}
	if (!Playing)
	{
		tell_object(me,HIW"牌局还没开始。\n"NOR);
		return 1;
	}
	if (me->query("id")!=NowPlayerId[NowPlayer])
	{
		tell_object(me,HIW"还没轮到你！现在是轮到「"NOR HIY+NowPlayerName[NowPlayer]+NOR HIW"」。\n"NOR);
		return 1;
	}
	if (!LastDump || LastDump=="")
	{
		tell_object(me,HIW"摸牌吧。\n"NOR);
		return 1;
	}
	if (Touched)
	{
		tell_object(me,HIW"打牌啦！！\n"NOR);
		return 1;
	}
	if (do_check_eat(num1,num2,LastDump)==0)
	{
		tell_object(me,HIW"你眼睛花了啊！！这样也能吃。\n"NOR);
		return 1;
	}
	if (num1==num2)
	{
		tell_object(me,HIW"相同的牌不能吃。\n"NOR);
		return 1;
	}	
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	LastDumpMan=do_check_Mj(MjE,num1);
	if (LastDumpMan==0) return notify_fail(HIW"没有「"NOR HIY+num1+NOR HIW"」这种代码。\n"NOR);
	LastDumpMan=do_check_Mj(MjE,num2);
	if (LastDumpMan==0) return notify_fail(HIW"没有「"NOR HIY+num2+NOR HIW"」这种代码。\n"NOR);
	LastDumpMan=do_check_Mj(who["Mj"],num1);
	if (LastDumpMan==0) return notify_fail(HIW"你没「"NOR HIY+do_check_num(num1,0)+NOR HIW"」这张牌。\n"NOR);
	LastDumpMan=do_check_Mj(who["Mj"],num2);
	if (LastDumpMan==0) return notify_fail(HIW"你没「"NOR HIY+do_check_num(num2,0)+NOR HIW"」这张牌。\n"NOR);
	message_vision("\n$N拿出了一张「"YEL+do_check_num(num1,0)+NOR"」与一张「"HIY+do_check_num(num2,0)+NOR"」吃下了「"HIR+do_check_num(LastDump,0)+NOR"」。\n\n",me);
	who["Out"]+=num2;
	who["Out"]+=LastDump;
	who["Out"]+=num1;
	who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
	who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
	Touched=1;
	NO_HU=1;
	NO_GON=1;
	i=0;
	if (who["Show"]=="代码") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	return delete_last_dump(who["Id"]);
}
int do_gang(string str,object me)
{
	int i;
	mapping who;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"这牌局跟你没关系。\n"NOR);
	if (!Playing) return notify_fail(HIW"牌局还没开始！！\n"NOR);
	if (LastDumpId==me->query("id")) return notify_fail(HIW"那张牌是你自己打的！\n"NOR);
	if (Touched && NowPlayerId[NowPlayer]!=me->query("id")) return notify_fail(HIW"别人没打牌你怎麽杠？\n"NOR);
	
	if (!str) str=LastDump;
 	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==1)
	{
		if (!Touched) return notify_fail(HIW"你还没摸牌。\n"NOR);
		i=do_check_Mj(who["OutPeng"],str);
		if (!i) return notify_fail(HIW"你只有一张不能杠。\n"NOR);
		if (NO_GON) return notify_fail(HIW"这样无法杠牌。\n"NOR);
		switch (random(5))
		{
			case 0: message_vision("\n$N大叫：「"HIB"木工"NOR WHT"～～～～～～"NOR"」\n\n",me); break;
			case 1: message_vision("\n$N大叫：「"HIB"木贡"NOR WHT"～～～～～～"NOR"」\n\n",me); break;
			case 2: message_vision("\n$N喜道：「这种牌也给我摸到，"WHT"口圭口列～～～"NOR HIB"木工！！！"NOR"」\n\n",me); break;
			case 3: message_vision("\n$N喜道：「这种牌也给我摸到，"WHT"口圭口列～～～"NOR HIB"木贡！！！"NOR"」\n\n",me); break;
			case 4: message_vision("\n$N奸笑道：「"HIB"木工"NOR WHT"～～～～～～"NOR"看我杠上开花」\n\n",me); break;
			case 5: message_vision("\n$N奸笑道：「"HIB"木贡"NOR WHT"～～～～～～"NOR"看我杠上开花」\n\n",me); break;
		}
		who["Mj"]=do_delete_Mj(who["Mj"],str,1);
		sort_data(who["OutPeng"]+=str);
		str=List[end..end+1];
		end-=2;
		Ganged++;
		message_vision("\n$N从後面补了一张牌。\n\n",me);
		tell_object(me,"你补到一张「"HIY+do_check_num(str,0)+NOR"」\n");
		i=0;
		if (who["Show"]=="代码") i=3;
		if (who["Show"]=="color") i=5;
		who["Mj"]+=str;
		check_flower(who);
		tell_object(me,show_mj(who["Mj"],i));
		Touched=1;
		return 1;
	}
	if (i < 3) return notify_fail(HIW"你手中要有三张「"NOR HIY+do_check_num(str,0)+NOR HIW"」才能杠。\n"NOR);
	if (!Touched)
	{
		if (str!=LastDump) return notify_fail("这样无法杠。\n");
	}
	else if (i < 4) return notify_fail(HIW"你手中要有四张「"NOR HIY+do_check_num(str,0)+NOR HIW"」才能暗杠。\n"NOR);
	for (i=0;i<Play;i++)
	{
		if (NowPlayerId[NowPlayer]==me->query("id")) break;
		NowPlayer++;
		NowPlayer%=Play;
	}
	who["Mj"]=do_delete_Mj(who["Mj"],str,3);
	if (Touched && NowPlayerId[NowPlayer]==me->query("id"))
	{
		NO_HU=0;
		switch (random(5))
		{
			case 0: message_vision("\n$N脸上露出邪恶的笑容说道：「"HIR"日音木贡～～"NOR HIC"　口黑口黑～～"NOR"」\n\n",me); break;
			case 1: message_vision("\n$N脸上露出邪恶的笑容说道：「"HIR"日音木工～～"NOR HIC"　口黑口黑～～"NOR"」\n\n",me); break;
			case 2: message_vision("\n$N内疚的说道：「希望你们听的不是这一只，我　"HIR"日音木贡～～"NOR"」\n\n",me); break;
			case 3: message_vision("\n$N内疚的说道：「希望你们听的不是这一只，我　"HIR"日音木工～～"NOR"」\n\n",me); break;
			case 4: message_vision("\n$N惊讶的叫道：「"MAG"口圭口合！"NOR"我多一台！"HIR"　日音木贡～～"NOR"」\n\n",me); break;
			case 5: message_vision("\n$N惊讶的叫道：「"MAG"口圭口合！"NOR"我多一台！"HIR"　日音木工～～"NOR"」\n\n",me); break;
		}
		who["Mj"]=do_delete_Mj(who["Mj"],str,1);
		for (i=0;i<4;i++) who["Out"]+="xx";
		for (i=0;i<4;i++) who["OutGang"]+=str;
	}
	else
	{
		NO_HU=1;
		switch (random(5))
		{
			case 0: message_vision("\n$N很大声的说道：「"GRN+do_check_num(str,0)+"！！"NOR HIW+"　木贡～～～"NOR"」\n\n",me); break;
			case 1: message_vision("\n$N很大声的说道：「"GRN+do_check_num(str,0)+"！！"NOR HIW+"　木工～～～"NOR"」\n\n",me); break;
			case 2: message_vision("\n$N叫道：「"WHT"口圭口列～～～"NOR GRN+do_check_num(str,0)+NOR"！！"HIW+"　木贡～～～"NOR"」\n\n",me); break;
			case 3: message_vision("\n$N叫道：「"WHT"口圭口列～～～"NOR GRN+do_check_num(str,0)+NOR"！！"HIW+"　木工～～～"NOR"」\n\n",me); break;
			case 4: message_vision("\n$N急道：「"GRN+do_check_num(str,0)+NOR"我　"HIW+"木贡～～～"NOR"」\n\n",me); break;
			case 5: message_vision("\n$N急道：「"GRN+do_check_num(str,0)+NOR"我　"HIW+"木工～～～"NOR"」\n\n",me); break;
		}
		for (i=0;i<4;i++) who["Out"]+=str;
	}
	str=List[end..end+1];
	end-=2;
	Ganged++;
	message_vision("$N从後面补了一张牌。\n",me);
	tell_object(me,"你补到一张「"HIY+do_check_num(str,0)+NOR"」\n");
	who["Mj"]+=str;
	check_flower(who);
	i=0;
	if (who["Show"]=="代码") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	if (Touched) return 1;
	Touched=1;
	return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
	int i,j;
	int *winner=({0,0,0,0});
	string Mj="";
	mapping who;
	object met, room=find_object("/u/mantian/mjroom.c");

	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"这牌局跟你没关系。\n"NOR);
	if (!Playing) return notify_fail(HIW"牌局还没开始！！\n"NOR);
	if (NO_HU || LastDumpId==me->query("id")) return notify_fail(HIW"这样不能胡牌。\n"NOR);
	if (LastDump==""&&Touched) message_vision("\n$N大叫：「"WHT"天～～～～～～胡～～～～～～"NOR"」\n\n",me);
	else message_vision("$N大叫：「"WHT"我～～～～胡～～～～啦～～～～～～～～～～"NOR"」\n\n",me);
	if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
	message_vision("$N说道：「胡家"+me->name()+HIM"自摸"NOR"～～～～～～～」\n",this_object());
	else command("say "+me->name()+"胡了");
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (sizeof(who["OutFlower"]) ==16) i=1;
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
	if (!HU_F) i=0;
	if (i)
	{
		Mj+="胡家的花牌是：\n";
		Mj+=show_mj(who["OutFlower"],1);
		if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="胡家花胡自摸\n";
		else
		{
			if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
			else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
			else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
			else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
			Mj+="\n花牌放枪者：「"HIB+LastDumpName+NOR"」\n";
		}
	}
	else
	{
		Mj+="胡家的牌是：\n";
		if (who["OutGang"]!="")
		{
			Mj+="暗杠的有：\n";
			Mj+=show_mj(who["OutGang"],0);
		}
		Mj+=who["Id"]+"：手中的牌有：\n";
		if (!Touched)
		{
			who["Mj"]+=LastDump;
			who["Mj"]=sort_data(who["Mj"]);
			Mj+=show_mj(who["Mj"],0);
			Mj+="所胡的牌是：「"HIR+do_check_num(LastDump,0)+NOR"」";
			Mj+="\n放枪者：「"HIB+LastDumpName+NOR"」\n";
		}
		else
		{
			Mj+=show_mj(who["Mj"],0);
			if (str) Mj+="所自摸的牌是：「"HIR+do_check_num(str,0)+NOR"」\n";
		}
	}
	Playing=0;
	tell_room(environment(this_object()),Mj);
	Tc="";
	if (do_check_win(who["Mj"])==1||i==1)
	{
//算台///////////////////////////////////
	mixed MjT = ([
	"@1" : ({ "庄家", 1 }),	"@2" : ({ "自摸", 1 }),	"@3" : ({ "花牌", 1 }),	"@4" : ({ "门清", 1 }),
	"@5" : ({ "东风", 1 }),	"@6" : ({ "南风", 1 }),	"@7" : ({ "西风", 1 }),	"@8" : ({ "北风", 1 }),
	"@9" : ({ "红中", 1 }),	"@0" : ({ "青发", 1 }),	"@a" : ({ "白板", 1 }),	"@G" : ({ "一丕口", 1 }),
	"@b" : ({ "海底捞月", 1 }),	"@c" : ({ "海底", 1 }),	"@d" : ({ "平胡", 2 }),	"@e" : ({ "东风东", 2 }),
	"@f" : ({ "南风南", 2 }),	"@g" : ({ "西风西", 2 }),	"@h" : ({ "北风北", 2 }),	"@i" : ({ "全求人", 2 }),
	"@j" : ({ "三暗刻", 2 }),	"@H" : ({ "二丕口", 2 }),	"@k" : ({ "三杠子", 2 }),	"@B" : ({ "春夏秋冬", 2 }),
	"@C" : ({ "梅兰菊竹", 2 }),	"@l" : ({ "门清自摸", 3 }),	"@m" : ({ "碰碰胡", 4 }),	"@n" : ({ "混一色", 4 }),
	"@o" : ({ "小三元", 4 }),	"@p" : ({ "四暗刻", 5 }),	"@q" : ({ "清一色", 8 }),	"@r" : ({ "字一色", 8 }),
	"@s" : ({ "七对子", 8 }),	"@t" : ({ "大三元", 8 }),	"@u" : ({ "五暗刻", 8 }),	"@F" : ({ "小四喜", 8 }),
	"@D" : ({ "七抢一", 8 }),	"@E" : ({ "绿一色", 8 }),	"@v" : ({ "大四喜", 16 }),	"@w" : ({ "天胡", 16 }),
	"@x" : ({ "地胡", 16 }),	"@y" : ({ "人胡", 16 }),	"@z" : ({ "国士无双", 16 }),
	"@A" : ({ "八仙过海", 8 }),	"@J" : ({ "清老头", 8 }),	"@I" : ({ "混老头", 4 }),
	]);//H
	get_tc(who);
////////////////
		str="\t\t\t≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n";
		for (i=0;i<sizeof(Tc);i+=2)
		{
			str+=sprintf("\t\t\t%-12s%8s 台\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
			j+=MjT[Tc[i..i+1]][1];
		}
		if (Count)
		{
			str+=sprintf("\t\t\t%-12s%8s 台\n","连"+chinese_number(Count)+"拉"+chinese_number(Count),chinese_number(Count*2));
			j+=Count*2;
		}
		str+=sprintf("\t\t\t%20s\n","总台数："+chinese_number(j+5)+" 台");
		str+="\t\t\t≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n";
		tell_room(environment(this_player()),str);
/////////////
		if (!Touched)
		{
			if (Play==4)
			{
				if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
				winner[1]+=j;
				set_mjdata(me,winner);
				met=present(LastDumpId, environment(this_object()));
				if (!met) met=find_player(LastDumpId);
				if (!met);
				else
				{
					if (!winner=get_mjdata(LastDumpId)) winner=({0,0,0,0});
					winner[1]-=j;//战绩
					winner[3]++;//放枪
					set_mjdata(met,winner);
				}
				for (i=0;i<Play;i++)
				{
					met=present(NowPlayerId[i], environment(this_object()));
					if (!met) met=find_player(NowPlayerId[i]);
					if (!met);
					else
					{
						if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
						winner[0]++;//局数
						set_mjdata(met,winner);
					}
				}
			}
		}
		else
		{
			if (Play==4)
			{
				if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
				winner[0]++;
				winner[1]+=(j*3);
				winner[2]++;
				set_mjdata(me,winner);
				for (i=0;i<Play;i++)
				{
					if (NowPlayerId[i]==me->query("id")) continue;
					met=present(NowPlayerId[i], environment(this_object()));
					if (!met) met=find_player(NowPlayerId[i]);
					if (!met);
					else
					{
						if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
						winner[0]++;
						winner[1]-=j;
						set_mjdata(met,winner);
					}
				}
			}
		}
		if (NowPlayerId[0]==who["Id"]) Count++;
		else
		{
			Times++;
			Count=0;
		}
	}
	else
	{
		command("sigh "+who["Id"]);
		message_vision(CYN"$N说道：「玩家 ["NOR HIR+who["Id"]+NOR CYN"]　　言乍～ 古月～～～。」\n"NOR,this_object());
		Times++;
		Count=0;
		if (Play==4)
		{
			if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
			if (NowPlayerId[NowPlayer]==who["Id"]&&Touched)
			{
				if (who["Out"]==""&&who["OutPeng"]=="")
				{
					winner[1]-=24;
					j=-24;
				}
				else
				{
					winner[1]-=18;
					j=-18;
				}
			}
			else
			{
				if (who["Out"]==""&&who["OutPeng"]=="")
				{
					winner[1]-=6;
					j=-6;
				}
				else
				{
					winner[1]-=5;
					j=-5;
				}
			}
////////////////
			str="\t\t\t≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n";
			str+=sprintf("\t\t\t%-12s%8s 台\n","诈胡",chinese_number(j));
			str+=sprintf("\t\t\t%20s\n","总台数："+chinese_number((j+5)*3)+" 台");
			str+="\t\t\t≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n";
			tell_room(environment(this_player()),str);
/////////////
			set_mjdata(me,winner);
			for (i=0;i<Play;i++)
			{
				met=present(NowPlayerId[i], environment(this_object()));
				if (!met) met=find_player(NowPlayerId[i]);
				if (!met);
				else
				{
					if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
					winner[0]++;
					set_mjdata(met,winner);
				}
			}
		}
	}
	Mj="\n  ";
	for (i=0; i<26; i++) Mj+="  ";
	Mj+="  \n";
	Mj+="　　　　"HIW"中文名字　已玩局数　总战迹　自摸次数　放枪次数　\n";
	for (i=0;i<Play;i++)
	{
		if (Play==4) winner=get_mjdata(NowPlayerId[i]);
		Mj+=sprintf("　　%12s　%8d　%6d　%8d　%8d  \n",
		NowPlayerId[i],winner[0],winner[1],winner[2],winner[3]);
	}
	Mj+="  ";
	for (i=0; i<26; i++) Mj+="  ";
	Mj+="＼\n";
	if (Play==4) tell_room(environment(this_object()),Mj);
	room->delete_temp("mjstart", 1);
	message_vision("\n$N"CYN"说道：「牌局结束，请洗牌"NOR RED"<wash>"NOR CYN"进行下一局。」\n"NOR,this_object());
	return 1;
}
int do_check_win(string str)
{
	int size=strlen(str),i,check;
	int t,k,W,T,S,Sp;
	string tempW="",tempT="",tempS="",tempB="";
	string Special="1w9w1s9s1t9teasowenojofaba";
 
	K=0;
	if (size > 33)
	{
		if (do_check_Mj(str,"ea")&&do_check_Mj(str,"so")&&do_check_Mj(str,"we")&&do_check_Mj(str,"no")&&
			do_check_Mj(str,"jo")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&do_check_Mj(str,"1w")&&
			do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&
			do_check_Mj(str,"9t"))
		{//先删掉13只
			for (i=0;i<sizeof(Special);i+=2)
			{
				if (do_check_Mj(str,Special[i..i+1]))
				{
					str=do_delete_Mj(str,Special[i..i+1],1);
				}
			}//查还有没13么中的牌只
			for (i=0;i<sizeof(Special);i+=2)
			{
				if (do_check_Mj(str,Special[i..i+1]))
				{
					Sp++;
				}
			}
			if (Sp==1)
			{
				for (i=0;i<sizeof(Special);i+=2)
				{
				if (do_check_Mj(str,Special[i..i+1]))
					{
						str=do_delete_Mj(str,Special[i..i+1],1);
						t++;
						Tc+="@z";//13么
					}
				}
			}
			else if (Sp==2)
			{
				for (i=0;i<sizeof(str);i+=2)
				{
				if (do_check_Mj(str,str[i..i+1])==2)
					{
						str=do_delete_Mj(str,str[i..i+1],1);
						Sp=0;
						t++;
					}
				}
				if (Sp!=0)
				{
					if (str[0..1]+1==str[2..3])
					{
						str=do_delete_Mj(str,str[6..7],1);
						t++;
					}
					else
					{
						str=do_delete_Mj(str,str[0..1],1);
						t++;
					}
				}
			}
		}
		else
		{
			for (i=0;i<sizeof(str);i+=2)
			{
				if (do_check_Mj(str,str[i..i+1])==2) Sp++;
				else if (do_check_Mj(str,str[i..i+1])==3) check++;
				else if (do_check_Mj(str,str[i..i+1])==4) Sp++;
			}
			if (Sp==14&&check==3)
			{
				for (i=0;i<sizeof(str);i+=2)
				{
					if (do_check_Mj(str,str[i..i+1])==2)
					{
						str=do_delete_Mj(str,str[i..i+1],2);
						i=-2;
					}
					else if (do_check_Mj(str,str[i..i+1])==4)
					{
						str=do_delete_Mj(str,str[i..i+1],4);
						i=-2;
					}
					else if (do_check_Mj(str,str[i..i+1])==3) t++;
				}
				t=1;
				Tc+="@s";//7对子
			}
		}
	}
	while(size--)
	{
		size--;
		if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
		else tempB+=str[size..size+1];
	}
	if (tempB!="")
	{
		for (i=0;i<strlen(tempB);i+=2)
		{//
			check=do_check_Mj(tempB,tempB[i..i+1]);
			if (check==1) return 0;
			else if (check==2)
			{
				tempB=do_delete_Mj(tempB,tempB[i..i+1],2);
				t++;
				i=-2;
			}
			else if (check==3)
			{
				tempB=do_delete_Mj(tempB,tempB[i..i+1],3);
				K++;
				i=-2;
			}
		}//
	}
	if (tempW!="") W=check_hu(tempW);
	if (tempT!="") T=check_hu(tempT);
	if (tempS!="") S=check_hu(tempS);
	if (K==3) Tc+="@j";//三暗刻
	else if (K==4) Tc+="@p";//四暗刻
	else if (K==5) Tc+="@u";//五暗刻
	if (W+T+S+t==1) return 1;
	return 0;
}
int check_hu(string strW)
{
	int i,j,check;
	int k,t;
	int A,B,C,D,E,F;
	for (i=0;i<sizeof(strW);i+=2)
	{//再把顺子删掉
		A=do_check_num(strW[i..i+1],2);
		B=do_check_num(strW[i+2..i+3],2);
		C=do_check_num(strW[i+4..i+5],2);
		D=do_check_num(strW[i+6..i+7],2);
		E=do_check_num(strW[i+8..i+9],2);
		F=do_check_num(strW[i+10..i+11],2);
		if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
			||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F)
		{
			if (A==B&&B+1==C&&C==D&&D+1==E&&E==F)
			{
				if (do_check_Mj(Tc,"@G")==1)
				{
					Tc=do_delete_Mj(Tc,"@H",1);
					Tc+="@H";
				}
				else Tc+="@G";
			}
			for (j=0;j<6;j++)
			{//删掉顺子1 22 33 4 && 22 33 44
				strW=do_delete_Mj(strW,strW[i..i+1],1);
			}
			i=-2;
		}
		else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F)
		{
			for (j=0;j<2;j++)
			{//删掉顺子1 2 2 2 2 3
				strW=do_delete_Mj(strW,strW[i..i+1],1);
			}
			strW=do_delete_Mj(strW,strW[i+6..i+7],1);
			i=-2;
		}
		else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E)
		{//删掉顺子12223中的1 2 3
			strW=do_delete_Mj(strW,strW[i..i+1],1);
			strW=do_delete_Mj(strW,strW[i..i+1],1);
			strW=do_delete_Mj(strW,strW[i+4..i+5],1);
			i=-2;
		}
		else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E)
		{
			for (j=0;j<3;j++)
			{//删掉顺子11234中的2 3 4
				strW=do_delete_Mj(strW,strW[i+4..i+5],1);
			}
			i=-2;
		}
		else if (sizeof(strW) > 5 && A+1==B&&B+1==C)
		{
			for (j=0;j<3;j++)
			{//删掉顺子123中的1 2 3
				strW=do_delete_Mj(strW,strW[i..i+1],1);
			}
			i=-2;
		}
	}
	if (sizeof(strW) > 5)
	{
		for (i=0;i<sizeof(strW);i+=2)
		{//再把刻删掉
			check=do_check_Mj(strW,strW[i..i+1]);
			if (check==3)
			{
				K++;
				strW=do_delete_Mj(strW,strW[i..i+1],3);
				i=-2;
			}
		}
	}
	for (i=0;i<sizeof(strW);i+=2)
	{//再把对删掉
		check=do_check_Mj(strW,strW[i..i+1]);
		if (check==2)
		{
			t++;
			strW=do_delete_Mj(strW,strW[i..i+1],2);
			i=-2;
		}
	}
	if (strW!="") return 99;
	return t;
}
int do_touch(string str,object me)
{
	int i,check;
	string pengid;
	mapping who;

	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"这牌局跟你没关系。\n"NOR);
	if (!Playing) return notify_fail(HIW"牌局还没开始你要摸牌去藏起来啊？\n"NOR);	
	if (me->query("id")!=NowPlayerId[NowPlayer])
	{
		message_vision("现在是轮到「"HIY+NowPlayerName[NowPlayer]+NOR"」\n",me);
		return notify_fail(HIW"想偷牌？没那麽容易！！现在是轮到「"NOR HIY+NowPlayerName[NowPlayer]+NOR HIW"」不是你。\n"NOR);
	}
	if (Touched) return notify_fail(HIW"打牌啦！！\n"NOR);	

	NO_HU=0;
	NO_GON=0;
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto")
	{
		if (str=="AUTO");
		else
		{
			write(HIW"\n听牌後，不可自己摸牌。\n"NOR);
			return 1;
		}
	}
	Touched=1;
	str=List[count..count+1];
	count+=2;
	message_vision("\n$N摸了一张牌。\n\n",me);
	tell_object(me,"你摸到一张「"HIY+do_check_num(str,0)+NOR"」\n");
	if (who["Auto"]=="auto")
	{
		if (do_check_num(str,1) > 34)
		{
			for (i=0;i<1;i++)
			{
				who["OutFlower"]+=str;
				HU_F=1;
				message_vision("\n$N说道：「"WHT"花牌"NOR"　补花！！\n\n$N往後面补了一张牌。\n\n",me);
				str=List[end..end+1];
				end-=2;
				tell_object(me,"你补到一张「"HIY+do_check_num(str,0)+NOR"」\n");
				if (do_check_num(str,1) > 34) i--;
			}
		}
		check=do_check_Mj(who["AutoTing"],str);
		if (check!=0)
		{
			who["Mj"]+=str;
			who["Mj"]=sort_data(who["Mj"]);
			return do_win(str,me);
		}
		if (Auto_Gang)
		{
			pengid=check_id(str,"gang");
			if (pengid!="")
			{
				me=present(pengid, environment(this_object()));
				if (!me) me=find_player(pengid);
				if (!me) return 1;
				do_gang(str,me);
			}
		}
		call_out("do_autodump",0,str,me);
	}
	who["Mj"]+=str;
	check_flower(who);
	i=0;
	if (who["Show"]=="代码") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	return 1;
}
int do_peng(string str,object me)
{
	int i;
	mapping who;
 
	if (!me) me=this_player();
	if (check_id(me->query("id"),"player")!="");
	else return notify_fail(HIW"这牌局跟你没关系。\n"NOR);
	if (!Playing) return notify_fail(HIW"牌局还没开始！！碰你的头啦！！\n"NOR);	
	if (Touched) return notify_fail(HIW"别人没打牌你怎麽碰。\n"NOR);
	if (LastDumpId==me->query("id")) return notify_fail(HIW"那张牌是你自己打的！\n"NOR);

	if (!str) str=LastDump;
	else if (str!=LastDump) return notify_fail(HIW"那张「"NOR HIY+do_check_num(str,0)+HIW"」已经过期了。\n"NOR);
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	if (who["Auto"]=="auto") return 1;
	i=do_check_Mj(who["Mj"],str);
	if (i==0) return notify_fail(HIW"你没「"NOR HIY+do_check_num(str,0)+NOR HIW"」这张牌要怎麽碰。\n"NOR);
	if (i < 2) return notify_fail(HIW"你手中要有两张「"NOR HIY+do_check_num(str,0)+NOR HIW"」才能碰。\n"NOR);
	switch (random(2))
	{
		case 0: message_vision("\n$N大叫：「"HIM+do_check_num(str,0)+"～～"NOR HIW"石并～～～"NOR"」\n\n",me); break;
		case 1: message_vision("\n$N急道：「等...等...等一下～～～我...我...我要　"HIW"石并　"NOR HIM+do_check_num(str,0)+"～～～"NOR"」\n\n",me); break;
		case 2: message_vision("\n就看$N快手的把"HIM+do_check_num(str,0)+NOR"抓到跟前然后得意的说：「"HIW"石并～～～"NOR"」\n\n",me); break;
	}
	for (i=0;i<Play;i++)
	{
		if (NowPlayerId[NowPlayer]==me->query("id")) break;
		NowPlayer++;
		NowPlayer%=Play;
	}
	for (i=0;i<3;i++) who["OutPeng"]+=str;
	who["Mj"]=do_delete_Mj(who["Mj"],str,2);
	who["AutoPeng"]=do_delete_Mj(who["AutoPeng"],str,1);
	NO_HU=1;
	NO_GON=1;
	Touched=1;
	i=0;
	if (who["Show"]=="代码") i=3;
	if (who["Show"]=="color") i=5;
	tell_object(me,show_mj(who["Mj"],i));
	return delete_last_dump(who["Id"]);
}
int do_restart(string str)
{
	object who, room, me=this_player();
	room=environment(this_object());
	if (me->query("id")=="guest") return 0;
	if (str!="mj"||str=="mj")
	{
		if (check_id(me->query("id"),"player")!="");
		else return notify_fail(HIW"这牌局跟你没关系。\n"NOR);
	}
	if (Times >= 1 && Times <= 3) return notify_fail(HIW"一圈都没打完就想重来？\n"NOR);
	if (Times >= 12 && Times <=15) return notify_fail(HIW"都北风圈了，打完它吧。\n"NOR);

	if (P1Data["Id"]!="")
	{
		who = present(P1Data["Id"], environment(this_object()));
		who->delete_temp("打麻将中");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	if (P2Data["Id"]!="")
	{
		who = present(P2Data["Id"], environment(this_object()));
		who->delete_temp("打麻将中");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	if (P3Data["Id"]!="")
	{
		who = present(P3Data["Id"], environment(this_object()));
		who->delete_temp("打麻将中");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	if (P4Data["Id"]!="")
	{
		who = present(P4Data["Id"], environment(this_object()));
		who->delete_temp("打麻将中");
		who->delete_temp("apply/short");
		if (who->query_temp("mj/short")) me->set_temp("apply/short", me->query_temp("mj/short"));
	}
	room->delete_temp("mjstart", 1);
	message_vision("$N把牌局重新设定。\n",me);
	message_vision("$N"CYN"说道：牌局重新设定请用"NOR HIR"<jiaru>"NOR CYN"加入牌局。\n"NOR,this_object());
	NowPlayerId[0]="";
	NowPlayerId[1]="";
	NowPlayerId[2]="";
	NowPlayerId[3]="";
	NowPlayerName[0]="";
	NowPlayerName[1]="";
	NowPlayerName[2]="";
	NowPlayerName[3]="";
	P1Data["Id"]="";
	P2Data["Id"]="";
	P3Data["Id"]="";
	P4Data["Id"]="";
	P1Data["Name"]="";
	P2Data["Name"]="";
	P3Data["Name"]="";
	P4Data["Name"]="";
	Count=0;
	LookP ="";
	Play=START;
	Times=START;
	end=END;
	count=START;
	Playing=START;
	return 1;
}
int wash_mj(int amount)
{
	int i,x,num,num1,num2,num3;
	string str,toss,countstr="";
	object room=environment(this_object());
	mixed *X,MjE_Data = ([
	"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" : 0,
	"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" : 0,
	"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" : 0,
	"ea" : 0,"so" : 0,"we" : 0,"no" : 0,"jo" : 0,"fa" : 0,"ba" : 0,
	"f1" : 0,"f2" : 0,"f3" : 0,"f4" : 0,"f5" : 0,"f6" : 0,"f7" : 0,"f8" : 0
	]);
	if (!Play) return notify_fail(HIW"没有玩家无法开局还！！\n"NOR);	
	if (Playing) return notify_fail(HIW"牌局正在进行中，别想毁局！！\n"NOR);	
	if (Play==1) return notify_fail(HIW"一个人自己打？不太好吧。\n"NOR);
	if (Play==3)
	{
		command("say 三缺一，再找一个人来凑数吧。");
		return 1;
	}
	if (Times/Play == 4)
	{
		command("say 四圈已经打完，请用"RED"<restart>"NOR CYN"起新的牌局。");
		return 1;
	}
	if (Play==2) message_vision("两人玩所以不计分。\n",this_object());
	P1Data["Mj"]="";
	P1Data["OutGang"]="";
	P1Data["Out"]="";
	P1Data["OutPeng"]="";
	P1Data["OutFlower"]="";
	P1Data["Auto"]="";
	P1Data["AutoTing"]="";
	P1Data["AutoGang"]="";
	P1Data["AutoPeng"]="";
	P1Data["Dump"]="";
	
	P2Data["Mj"]="";
	P2Data["OutGang"]="";
	P2Data["Out"]="";
	P2Data["OutPeng"]="";
	P2Data["OutFlower"]="";
	P2Data["Auto"]="";
	P2Data["AutoTing"]="";
	P2Data["AutoGang"]="";
	P2Data["AutoPeng"]="";
	P2Data["Dump"]="";
	
	P3Data["Mj"]="";
	P3Data["OutGang"]="";
	P3Data["Out"]="";
	P3Data["OutPeng"]="";
	P3Data["OutFlower"]="";
	P3Data["Auto"]="";
	P3Data["AutoTing"]="";
	P3Data["AutoGang"]="";
	P3Data["AutoPeng"]="";
	P3Data["Dump"]="";
	
	P4Data["Mj"]="";
	P4Data["OutGang"]="";
	P4Data["Out"]="";
	P4Data["OutPeng"]="";
	P4Data["OutFlower"]="";
	P4Data["Auto"]="";
	P4Data["AutoTing"]="";
	P4Data["AutoGang"]="";
	P4Data["AutoPeng"]="";
	P4Data["Dump"]="";
	
	end=END;
	NO_HU=START;
	NO_GON=START;
	count=START;
	Playing=START;
	List="";
	NowPlayer=START;
	Touched=START;
	Auto=START;
	Auto_Ting=START;
	Auto_Gang=START;
	Auto_Peng=START;
	Ganged=START;
	LastDump="";
	LastDumpId="";
	LastDumpName="";
	KaiMen="";
	Dump="";
	X = keys(MjE_Data);
	for (i=0;i<144;i++)
	{
		x = random(sizeof(X));
		if (X[x]=="f1"||X[x]=="f2"||X[x]=="f3"||X[x]=="f4"||X[x]=="f5"||X[x]=="f6"||X[x]=="f7"||X[x]=="f8")
		{
			if (MjE_Data[X[x]] < 1)
			{
	           MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
				List += X[x];
			}
			else i--;
		}
		else
		{
			if (MjE_Data[X[x]] < 4)
			{
				MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
				List += X[x];
			}
			else i--;
		}
	}
	
//	for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
	if (Count) countstr="[连庄"+chinese_number(Count)+"]";
	if (!Times);
	else
	{
		if (Count);
		else
		{
			str=NowPlayerName[0];
			if (Play>1) NowPlayerName[0]=NowPlayerName[1];
			if (Play>2) NowPlayerName[1]=NowPlayerName[2];
			if (Play>3) NowPlayerName[2]=NowPlayerName[3];
			NowPlayerName[Play-1]=str;
			str=NowPlayerId[0];
			if (Play>1) NowPlayerId[0]=NowPlayerId[1];
			if (Play>2) NowPlayerId[1]=NowPlayerId[2];
			if (Play>3) NowPlayerId[2]=NowPlayerId[3];
			NowPlayerId[Play-1]=str;
		}
	}
//	if (Times/Play == 4) Times=0;
	if (Times/Play == 3) str=HIW+"北风"+NOR;
	if (Times/Play == 2) str=HIY+"西风"+NOR;
	if (Times/Play == 1) str=HIR+"南风"+NOR;
	if (Times/Play == 0) str=HIG+"东风"+NOR;
	i=Times;
	i%=Play;
	i++;
	num1 = random(6);
	num2 = random(6);
	num3 = random(6);
	if (num1 == 0) num1 = 1;
	if (num2 == 0) num2 = 1;
	if (num3 == 0) num3 = 1;
	num = num1+num2+num3;
	if (num1 == 1) num1 = 7;
	if (num2 == 1) num2 = 7;
	if (num3 == 1) num3 = 7;
	if (num1 == 2) num1 = 10;
	if (num2 == 2) num2 = 10;
	if (num3 == 2) num3 = 10;
	if (num1 == 3) num1 = 13;
	if (num2 == 3) num2 = 13;
	if (num3 == 3) num3 = 13;
	if (num1 == 4) num1 = 16;
	if (num2 == 4) num2 = 16;
	if (num3 == 4) num3 = 16;
	if (num1 == 5) num1 = 19;
	if (num2 == 5) num2 = 19;
	if (num3 == 5) num3 = 19;
	if (num1 == 6) num1 = 22;
	if (num2 == 6) num2 = 22;
	if (num3 == 6) num3 = 22;
	toss = "["+str+chinese_number(i)+"]牌局开始：庄家"HIY+NowPlayerName[0]+HIR+countstr+NOR"掷出骰子\n";
	toss +=	TossPic[0]+"\n"+TossPic[num1]+"\n"+TossPic[num1+1]+TossPic[1]+"\n"+TossPic[num1+2]+TossPic[num2]+"\n"
			+TossPic[3]+TossPic[num2+1]+TossPic[2]+"\n　　　　　　　"+TossPic[num2+2]+TossPic[num3]+"\n　　　　　　　"
			+TossPic[4]+TossPic[num3+1]+"\n　　　　　　　　　　　　　　"
			+TossPic[num3+2]+"\n　　　　　　　　　　　　　　"+TossPic[5];
	toss += "\n「"WHT+chinese_number(i=num)+NOR "」点，";
	if (num == 3 || num == 7 || num == 11 || num == 15)
	{
		if (num == 3) toss += "对家开门，数三抓二。\n";
		if (num == 7) toss += "对家开门，数七抓二。\n";
		if (num == 11) toss += "对家开门，抓二剩五。\n";
		if (num == 15) toss += "对家开门，抓二剩一。\n";
		KaiMen="";
	}
	if (num == 4 || num == 8 || num == 12 || num == 16)
	{
		if (num == 4) toss += "上家开门，数四抓二。\n";
		if (num == 8) toss += "上家开门，正中抓二。\n";
		if (num == 12) toss += "上家开门，抓二剩四。\n";
		if (num == 16) toss += "上家开门，抓尾二。\n";
		KaiMen="";
	}
	if (num == 5 || num == 9 || num == 13 || num == 17)
	{
		if (num == 5) toss += "庄家门前开，数五抓二。\n";
		if (num == 9) toss += "庄家门前开，抓二剩七。\n";
		if (num == 13) toss += "庄家门前开，抓二剩三。\n";
		if (num == 17) toss += "庄家门前开，抓尾一上家头一。\n";
		KaiMen="";
	}
	if (num == 6 || num == 10 || num == 14 || num == 18)
	{
		if (num == 6) toss += "下家开门，数六抓二。\n";
		if (num == 10) toss += "下家开门，抓二剩六。\n";
		if (num == 14) toss += "下家开门，抓二剩二。\n";
		if (num == 18) toss += "下家开门，抓自家门前头二。\n";
		KaiMen="";
	}
	message_vision("\n"+toss+"\n",this_object());

//玩家取牌一次取16只：Q
	if (Play>0) P1Data["Mj"]=List[0..31];
	if (Play>1) P2Data["Mj"]=List[32..63];
	if (Play>2) P3Data["Mj"]=List[64..95];
	if (Play>3) P4Data["Mj"]=List[96..127];
	count=(Play*2*16);
	if (Play>0) check_flower(P1Data);
	if (Play>1) check_flower(P2Data);
	if (Play>2) check_flower(P3Data);
	if (Play>3) check_flower(P4Data);
	Playing=1;
	room->set_temp("mjstart", 1);
	message_vision("$N"CYN"说道：庄家"NOR HIY+NowPlayerName[0]+NOR CYN"请抓门牌。\n"NOR,this_object());
	return 1;
}
int do_setmj(string str)
{
	int check;
	string numstr;
	mapping who;
	object me=this_player();
	
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 1;
	if (!str)
	{
		numstr = "你设定的有：\n";
		numstr += HIM"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR;
		if (who["AutoTing"]!="") numstr += sprintf("%s┃%s遇到「%s%18s%s」时会自动%s「胡牌」%s。　　　　　%s┃%s\n",HIM,NOR,HIB,show_mj(who["AutoTing"],2),NOR,HIB,NOR,HIM,NOR);
		if (who["AutoGang"]!="") numstr += sprintf("%s┃%s遇到「%s%18s%s」时会自动%s「杠牌」%s。　　　　　%s┃%s\n",HIM,NOR,HIY,show_mj(who["AutoGang"],2),NOR,HIY,NOR,HIM,NOR);
		if (who["AutoPeng"]!="") numstr += sprintf("%s┃%s遇到「%s%18s%s」时会自动%s「碰牌」%s。　　　　　%s┃%s\n",HIM,NOR,HIG,show_mj(who["AutoPeng"],2),NOR,HIG,NOR,HIM,NOR);
		if (who["Show"]=="代码") numstr += HIM"┃"NOR"显示方式为"HIY"「代码」"NOR"方式。　　　　　　　　　　　　　　　"HIM"┃\n"NOR;
		if (who["Show"]=="color") numstr += HIM"┃"NOR"显示方式为"HIG"「彩色」"NOR"。　　　　　　　　　　　　　　　　　"HIM"┃\n"NOR;
		if (who["Auto"]=="auto") numstr += HIM"┃"NOR"你设定"HIR"「自动听牌」"NOR"。　　　　　　　　　　　　　　　　　"HIM"┃\n"NOR;
		if (who["AutoTing"]==""&&who["AutoGang"]==""&&who["AutoPeng"]==""&&who["Show"]==""&&who["Auto"]=="") numstr += HIM"┃"NOR"你没有任何设定。　　　　　　　　　　　　　　　　　　　"HIM"┃\n"NOR;
		numstr += HIM"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR;
		tell_object(me,numstr);
		return 1;
	}
	if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail(HIW"指令：setmj <ting>&<gang>&<peng> <代码>\n"NOR);
	if (str=="ting")
	{
		if (who["Auto"]=="auto") return notify_fail(HIW"听牌後，无法更改或取消自动胡牌设定。\n"NOR);
		if (numstr=="none")
		{
			who["AutoTing"]="";
			return notify_fail(HIW"你取消自动胡牌设定。\n"NOR);
		}
		check=do_check_Mj(MjE,numstr);
		if (check!=1) return notify_fail(HIW"没有「"NOR HIY+numstr+NOR HIW"」这种牌。\n"NOR);
		check=do_check_Mj(who["AutoTing"],numstr);
		if (check)
		{
			who["AutoTing"]=do_delete_Mj(who["AutoTing"],numstr,1);
			return notify_fail(HIW"你"NOR HIR"删掉了"NOR HIW"遇到「"NOR HIY+do_check_num(numstr,0)+NOR HIW"」会自动胡牌的设定。\n"NOR);
		}
		who["AutoTing"]+=numstr;
		Auto_Ting=1;
		write(HIM"你设定遇到「"NOR HIY+do_check_num(numstr,0)+NOR HIM"」时会自动胡牌。\n"NOR);
		return 1;
	}
	else if (str=="gang")
	{
		if (numstr=="none")
		{
			who["AutoGang"]="";
			return notify_fail(HIW"你取消自动杠牌设定。\n"NOR);
		}
		check=do_check_Mj(who["Mj"],numstr);
		if (check==0) return notify_fail(HIW"你没「"NOR HIY+do_check_num(numstr,0)+NOR HIW"」这张牌。\n"NOR);
		if (check < 3) return notify_fail(HIW"你手中要有三张「"NOR HIY+do_check_num(numstr,0)+NOR HIW"」才能设定杠此牌。\n"NOR);
		check=do_check_Mj(who["AutoGang"],numstr);
		if (check)
		{
			who["AutoGang"]=do_delete_Mj(who["AutoGang"],numstr,1);
			return notify_fail(HIW"你"NOR HIR"删掉了"NOR HIW"遇到「"NOR HIY+do_check_num(numstr,0)+NOR HIW"」会自动杠牌的设定。\n"NOR);
		}
		who["AutoGang"]+=numstr;
		Auto_Gang=1;
		write(HIM"你设定遇到「"NOR HIM+do_check_num(numstr,0)+NOR HIM"」时会自动杠牌。\n"NOR);
		return 1;
	}
	else if (str=="peng")
	{
		if (numstr=="none")
		{
			who["AutoPeng"]="";
			return notify_fail(HIW"你取消自动碰牌设定。\n"NOR);
		}
		if (who["Auto"]=="auto") return notify_fail(HIW"听牌後，无法再设定自动碰牌。\n"NOR);
		check=do_check_Mj(who["Mj"],numstr);
		if (check==0) return notify_fail(HIW"你没「"NOR HIY+do_check_num(numstr,0)+NOR HIW"」这张牌。\n"NOR);
		if (check < 2) return notify_fail(HIW"你手中要有两张「"NOR HIY+do_check_num(numstr,0)+NOR HIW"」才能设定碰此牌。\n"NOR);
		check=do_check_Mj(who["AutoPeng"],numstr);
		if (check)
		{
			who["AutoPeng"]=do_delete_Mj(who["AutoPeng"],numstr,1);
			return notify_fail(HIW"你"NOR HIR"删掉了"NOR HIW"遇到「"NOR HIY+do_check_num(numstr,0)+NOR HIW"」会自动碰牌的设定。\n"NOR);
		}
		who["AutoPeng"]+=numstr;
		Auto_Peng=1;
		write(HIM"你设定遇到「"NOR HIY+do_check_num(numstr,0)+NOR HIM"」时会自动碰牌。\n"NOR);
		return 1;
	}
	else if (str=="show")
	{
		if (numstr=="none"||numstr=="1")
		{
			who["Show"]="";
			return notify_fail(HIW"你取消显示设定。\n"NOR);
		}
		if (numstr=="代码"||numstr=="3")
		{
			numstr="代码";
			write(HIM"你设定只显示代码。\n"NOR);
		}
		else if (numstr=="color"||numstr=="2")
		{
			numstr="color";
			write(HIM"你设定彩色显示。\n"NOR);
		}
		else return 1;
		who["Show"]=numstr;
		return 1;
	}
	else if (str=="auto")
	{
		if (who["Id"]!=NowPlayerId[NowPlayer]) return notify_fail(HIW"还没轮到你，不能作此设定。\n"NOR);
		if (numstr=="none")	return notify_fail(HIW"不能取消自动听牌，要是设定错误等着诈胡吧！！。\n"NOR);
		if (who["AutoTing"]=="") return notify_fail(HIW"请先设定要听的牌。\n"NOR);
		if (!Touched) return notify_fail(HIW"请先摸牌再作此设定。\n"NOR);
		if (numstr=="ting") write(HIW"你设定自动听牌。\n"NOR);
		else return 1;
		message_vision("\n$N大叫一声：「"WHT"我　　口斤　　啦～～～"NOR"」\n\n",me);
		Auto=1;
		who["AutoPeng"]="";
		who["Auto"]="dump";
		return 1;
	}
	else return notify_fail(HIW"没有这种设定。\n"NOR);
}
int do_check_eat(string num1,string num2,string LastDump)
{
	int A,B,C;
	A=do_check_num(num1,1);
	B=do_check_num(num2,1);
	C=do_check_num(LastDump,1);
	if (A<=9)
	{
		if (B>=10||C>=10) return 0;
	}
	else if (A<=18&&A>=10)
	{
		if (B>=19||C>=19||B<=9||C<=9) return 0;
	}
	else if (A<=27&&A>=19)
	{
		if (B<=18||C<=18||B>=28||C>=28) return 0;
	}
	A=do_check_num(num1,2);
	B=do_check_num(num2,2);
	C=do_check_num(LastDump,2);
	if (A > 9 || B > 9 || C > 9) return 0;
	if ((A+B)%2!=0)
	{
		if (A > B)
		{
			if (C==(A+1) || C==(A-2)) return 1;
		}
		else
		{
			if (C==(B+1) || C==(B-2)) return 1;
		}
		return 0;
	}
	else
	{
		if (A > B)
		{
			if (C==(A-1) || C==(B+1)) return 1;
		}
		else
		{
			if (C==(B-1) || C==(A+1)) return 1;
		}
		return 0;
	}
}
string show_mj(string str,int flag)
{
	string Mj="",Mj1="";
	int size=strlen(str)+2,a,b;
	if (!str||str=="") return "";
	if (flag!=3)
	{
		while(size--)
		{
			size--;
			Mj+=do_check_num(str[size..size+1],0);
		}
		if (flag==2) Mj1=Mj;
		else
		{
			size=strlen(Mj);
			Mj1="┏";
			for (a=0;a<(size/2)-1;a++)
			{
				if (a%2==0) Mj1+="━";
				else Mj1+="┳";
			}
			Mj1+="┓\n┃";
			for (a=0;a<size-1;a++)
			{
				if (flag==5 || flag==6)
				{
					if (Mj[a+2..a+3]=="万") Mj1+=HIR;
					else if (Mj[a+2..a+3]=="筒") Mj1+=HIC;
					else if (Mj[a+2..a+3]=="索") Mj1+=HIG;
					else if (Mj[a+2..a+3]=="风") Mj1+=HIM;
					else if (Mj[a+2..a+3]=="中") Mj1+=HIR;
					else if (Mj[a+2..a+3]=="发") Mj1+=HIG;
					else if (Mj[a+2..a+3]=="板") Mj1+=HIW;
					else if (Mj[a+2..a+3]=="春"
							||  Mj[a+2..a+3]=="夏"
							||  Mj[a+2..a+3]=="秋"
							||  Mj[a+2..a+3]=="冬") Mj1+=HIR;
					else if (Mj[a+2..a+3]=="梅"
							||  Mj[a+2..a+3]=="兰"
							||  Mj[a+2..a+3]=="竹"
							||  Mj[a+2..a+3]=="菊") Mj1+="";
				}
				Mj1+=Mj[a..a+1];
				a++;a++;a++;
				Mj1+=NOR+"┃";
			}
			Mj1+="\n┃";
			for (a=2;a<size;a++)
			{
				if (flag==5 || flag==6)
				{
					if (Mj[a..a+1]=="万") Mj1+=RED;
					else if (Mj[a..a+1]=="索") Mj1+=GRN;
					else if (Mj[a..a+1]=="筒") Mj1+=CYN;
					else if (Mj[a..a+1]=="风") Mj1+=MAG;
					else if (Mj[a..a+1]=="中") Mj1+=HIR;
					else if (Mj[a..a+1]=="发") Mj1+=HIG;
					else if (Mj[a..a+1]=="白") Mj1+=HIW;
					else if (Mj[a..a+1]=="春") Mj1+=HIG;
					else if (Mj[a..a+1]=="夏") Mj1+=HIB;
					else if (Mj[a..a+1]=="秋") Mj1+=HIY;
					else if (Mj[a..a+1]=="冬") Mj1+=HIW;
					else if (Mj[a..a+1]=="梅") Mj1+=HIW;
					else if (Mj[a..a+1]=="兰") Mj1+=HIR;
					else if (Mj[a..a+1]=="竹") Mj1+=HIG;
					else if (Mj[a..a+1]=="菊") Mj1+=HIY;
				}
				Mj1+=Mj[a..a+1];
				a++;a++;a++;
				Mj1+=NOR+"┃";
			}
			Mj1+="\n┗";
			for (a=(size/2)-1;a>0;a--)
			{
				if (a%2!=0)
				{
					if (flag==0 || flag==5) Mj1+=str[a-1..a];
					else Mj1+="━";
				}
				else Mj1+="┻";
			}
			Mj1+="┛\n";
		}
		return Mj1;
	}
	else
	{
		size*=2;
		for (a=(size/2)-1;a>0;a--)
		{
			if (a%2!=0) Mj1+=str[a-1..a];
			else Mj1+=" ";
		}
		Mj1+="\n";
	}
	return Mj1;
}
string check_id(string str,string kind)
{
	int check,i;
	if (!str) return "";
	if (kind=="ting")
	{
		check=NowPlayer;
		for (i=0;i<Play-1;i++)
		{
			if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTing"],str)!=0) return P1Data["Id"];
			if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTing"],str)!=0) return P2Data["Id"];
			if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTing"],str)!=0) return P3Data["Id"];
			if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTing"],str)!=0) return P4Data["Id"];
			check++;
			check%=Play;
		}
		return "";
	}
	if (kind=="gang")
	{
		check=do_check_Mj(P1Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 3) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 3) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 3) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoGang"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 3) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="peng")
	{
		check=do_check_Mj(P1Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P1Data["Mj"],str);
			if (check < 2) return "";
			else return P1Data["Id"];
		}
		check=do_check_Mj(P2Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P2Data["Mj"],str);
			if (check < 2) return "";
			else return P2Data["Id"];
		}
		check=do_check_Mj(P3Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P3Data["Mj"],str);
			if (check < 2) return "";
			else return P3Data["Id"];
		}
		check=do_check_Mj(P4Data["AutoPeng"],str);
		if (check!=0)
		{
			check=do_check_Mj(P4Data["Mj"],str);
			if (check < 2) return "";
			else return P4Data["Id"];
		}
		return "";
	}
	if (kind=="player")
	{
		for (i=0;i<Play;i++)
		{
			if (NowPlayerId[i]==str) check=1;
		}
		if (check) return "Y";
		return "";
	}
}
int delete_last_dump(string whoId)
{
	mapping who;
	if (LastDumpId==P1Data["Id"]) who=P1Data;
	else if (LastDumpId==P2Data["Id"]) who=P2Data;
	else if (LastDumpId==P3Data["Id"]) who=P3Data;
	else if (LastDumpId==P4Data["Id"]) who=P4Data;
	if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
	return 1;
}
//把英文字转为代码 or 中文 flag 1 就是转为代码 flag 2 转为1..9
mixed do_check_num(string str,int flag)
{
	int number;
	
	if (!str) return MjC[0];
	sscanf(str,"%d%s",number,str);
	if (number == 0)
	{
		if (str=="ea") number=28;
		else if (str=="so") number=29;
		else if (str=="we") number=30;
		else if (str=="no") number=31;
		else if (str=="jo") number=32;
		else if (str=="fa") number=33;
		else if (str=="ba") number=34;
		else if (str=="f1") number=35;
		else if (str=="f2") number=36;
		else if (str=="f3") number=37;
		else if (str=="f4") number=38;
		else if (str=="f5") number=39;
		else if (str=="f6") number=40;
		else if (str=="f7") number=41;
		else if (str=="f8") number=42;
		else if (str=="xx") number=43;
	}
	else
	{
		if (str=="w") number=0+number;
		else if (str=="t") number=9+number;
		else if (str=="s") number=18+number;
		if (flag==2)
		{
			number%=9;
			if (number==0) number=9;
		}
	}
	if (!flag) return MjC[number];
	else return number;
}
void check_flower(mapping who)
{
	string newstr = "",str=who["Mj"],temp,temp1;
	int i = strlen(str),j;
	
	while(i--)
	{
		i--;
		temp=str[i..i+1];
		if (temp=="f1"||temp=="f2"||temp=="f3"||temp=="f4"||temp=="f5"||temp=="f6"||temp=="f7"||temp=="f8")
		{
			if (Playing)
			{
				message_vision("\n$N说道：「"WHT"花牌"NOR"　补花！！\n\n$N往後面补了一张牌。\n\n",this_player());
				tell_object(this_player(),"你摸到了一张「"HIY+do_check_num(List[end..end+1],0)+NOR"」\n");
			}
			HU_F=1;
			who["OutFlower"]+=temp;
			str[i..i+1]=List[end..end+1];
			end-=2;
			i+=2;
			continue;
		}
		else newstr+=temp;
	}
	who["Mj"]=sort_data(newstr);
}
int do_check_Mj(string datastr,string str)
{
	int size=strlen(datastr),check=0;
	while(size--)
	{
		size--;
		if (datastr[size..size+1]==str) check++;
	}
	return check;
}
string do_delete_Mj(string datastr,string str,int amount)//把某牌去掉
{
	int size=strlen(datastr),check;
	string temp="";
	while(size--)
	{
		size--;
		if (datastr[size..size+1]==str && amount!=0) amount--;
		else temp+=datastr[size..size+1];
	}
	size=strlen(temp);
	datastr=temp;
	temp="";
	while(size--)
	{
		size--;
		temp+=datastr[size..size+1];
	}
	return temp;
}
string sort_data(string str)
{
	int i = strlen(str),a,b,c,d;
	string newstr="",temp="";
	for (a=-1;a<i;a++)
	{
		a++;
		for (b=a+2;b<i;b++)
		{
			b++;
			c=do_check_num(str[a..a+1],1);
			d=do_check_num(str[b-1..b],1);
			if (c < d)
			{
				temp=str[a..a+1];
				str[a..a+1]=str[b-1..b];
				str[b-1..b]=temp;
			}
		}
	}
	return str;
}
int do_look(string arg)
{
	int i,l;
	object me=this_player();
	string Mj="",p1o="",p2o="",p3o="",p4o="";
	mapping who;
	
	if (arg=="player1"||arg=="player2"||arg=="player3"||arg=="player4"||arg=="allmj"||arg=="table"||arg=="end"||arg=="dump"||arg=="mj");
	else return 0;
	if (arg=="table")
	{
		Mj = HIM"一张麻将桌。\n\n"NOR;
		if (Playing)
		{
			Mj += LookP+"正认真的坐在那打牌\n";
			Mj += "还剩下"+sprintf("「%s」",chinese_number((end-count-16-Ganged)/2))+"只牌就流局了。\n";
			if (LastDump!="") Mj += LastDumpName+"刚刚打出了"+show_mj(LastDump,2)+"\n";
			if (Count) Mj += NowPlayerId[0]+"：连庄"+chinese_number(Count)+"\n";
			if (P1Data["Out"]=="" && P1Data["OutPeng"]=="") p1o=HIY+"门清"+NOR;
			if (P2Data["Out"]=="" && P2Data["OutPeng"]=="") p2o=HIY+"门清"+NOR;
			if (P3Data["Out"]=="" && P3Data["OutPeng"]=="") p3o=HIY+"门清"+NOR;
			if (P4Data["Out"]=="" && P4Data["OutPeng"]=="") p4o=HIY+"门清"+NOR;
			Mj += "1.东家是："+NowPlayerName[0]+p1o+"\n2.南家是："+NowPlayerName[1]+p2o+"\n";
			Mj += "3.西家是："+NowPlayerName[2]+p3o+"\n4.北家是："+NowPlayerName[3]+p4o+"\n";
		}
		else if (NowPlayerId[0]!="") Mj += LookP+"正在等人打牌\n";
		else Mj += "桌前空荡荡的，你可以加入(jiaru)牌局。\n";
		printf("%s\n",Mj);
		return 1;
	}
	if (arg=="all")
	{
		if (Playing)
		{
			i=5;
			Mj+=P1Data["Name"]+"：摆\在外面的牌有：\n";
			Mj+=show_mj(P1Data["Out"]+P1Data["OutPeng"]+P1Data["OutFlower"],i+1);
			Mj+=P1Data["Name"]+"：打过的牌有：\n";
			Mj+=show_mj(P1Data["Dump"],2)+"\n";
			Mj+=P2Data["Name"]+"：摆\在外面的牌有：\n";
			Mj+=show_mj(P2Data["Out"]+P2Data["OutPeng"]+P2Data["OutFlower"],i+1);
			Mj+=P2Data["Name"]+"：打过的牌有：\n";
			Mj+=show_mj(P2Data["Dump"],2)+"\n";
			if (Play==4)
			{
				Mj+=P3Data["Name"]+"：摆\在外面的牌有：\n";
				Mj+=show_mj(P3Data["Out"]+P3Data["OutPeng"]+P3Data["OutFlower"],i+1);
				Mj+=P3Data["Name"]+"：打过的牌有：\n";
				Mj+=show_mj(P3Data["Dump"],2)+"\n";
				Mj+=P4Data["Name"]+"：摆\在外面的牌有：\n";
				Mj+=show_mj(P4Data["Out"]+P4Data["OutPeng"]+P4Data["OutFlower"],i+1);
				Mj+=P4Data["Name"]+"：打过的牌有：\n";
				Mj+=show_mj(P4Data["Dump"],2)+"\n";
			}
		}
		else Mj = "对不起游戏还没开始。";
		printf("%s\n",Mj);
		return 1;
	}
	if (arg=="end")
	{
		if (Playing)
		{
			Mj="还有「"+chinese_number((end-count-16-Ganged)/2)+"」只牌就流局了\n";
		}
		else Mj = "对不起游戏还没开始。";
		printf("%s\n",Mj);
		return 1;
	}
	if (arg=="dump")
	{
		if (Playing)
		{
			Mj = LastDumpName+"刚刚打出了「"+show_mj(LastDump,2)+"」\n";
		}
		else Mj = "对不起游戏还没开始。";
		printf("%s\n",Mj);
		return 1;
	}
	if (me->query("id")==P1Data["Id"]) who=P1Data;
	else if (me->query("id")==P2Data["Id"]) who=P2Data;
	else if (me->query("id")==P3Data["Id"]) who=P3Data;
	else if (me->query("id")==P4Data["Id"]) who=P4Data;
	else return 0;
	if (who["Auto"]=="auto") l=1;
	if (arg=="player1") who=P1Data;
	if (arg=="player2") who=P2Data;
	if (arg=="player3") who=P3Data;
	if (arg=="player4") who=P4Data;
	if (arg=="player1"||arg=="player2"||arg=="player3"||arg=="player4")
	{
		i=0;
		if (who["Show"]=="代码") i=3;
		if (who["Show"]=="color") i=5;
		if (!Playing||check_id(me->query("id"),"player")==""||l==1)
		{
			if (who["OutGang"]!="")
			{
				Mj+=who["Name"]+"：暗杠的牌有：\n";
				Mj+=show_mj(who["OutGang"],i+1);
			}
			Mj+=who["Name"]+"：手中的牌有：\n";
			Mj+=show_mj(who["Mj"],i);
		}
		Mj+=who["Name"]+"：摆\在外面的牌有：\n";
		Mj+=show_mj(who["Out"]+who["OutPeng"]+who["OutFlower"],i+1);
		Mj+=who["Name"]+"：打过的牌：\n";
		Mj+=show_mj(who["Dump"],2);
	}
	else if (arg=="mj")
	{
		if (!Playing) return 0;
		if (who["OutGang"]!="")
		{
			Mj+="你的暗杠的牌有：\n";
			Mj+=show_mj(who["OutGang"],1);
		}
		if (who["Show"]=="代码") i=3;
		if (who["Show"]=="color") i=5;
		Mj+="你摆\在外面的牌有：\n";
		Mj+=show_mj(who["Out"]+who["OutPeng"]+who["OutFlower"],i+1);
		Mj+="你手中的牌有：\n";
		Mj+=show_mj(who["Mj"],i);
		Mj+="你的设定有：";
		if (who["AutoTing"]!="") Mj+="遇到「"+show_mj(who["AutoTing"],2)+"」会自动胡牌、";
		if (who["AutoGang"]!="") Mj+="遇到「"+show_mj(who["AutoGang"],2)+"」会自动杠牌、";
		if (who["AutoPeng"]!="") Mj+="遇到「"+show_mj(who["AutoPeng"],2)+"」会自动碰牌。";
		if (who["Show"]=="代码") Mj+="显示方式为代码方式。";
		if (who["Show"]=="color") Mj+="显示方式为彩色。";
		if (who["Auto"]=="auto") Mj+="你设定自动听牌。";
		if (who["AutoTing"]==""&&who["AutoGang"]==""&&who["AutoPeng"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="你没有任何设定。\n";
	}
	else return 0;
	printf("%s\n",Mj);
	return 1;
}
int do_help(string str)
{
	if (str=="mj")
	{
write(
"\n\n中国的国粹 - 麻将"

"\n麻将，是中国人最喜欢玩的一种牌戏。关於麻将的起源，历史并没有明确的"
"\n记载。有人认为是在春秋战国时代，也有人认为是明朝万历年间，更有人说"
"\n麻将其实是宋朝司马光发明的，可是也没有确实的根据。其实，一种游戏流"
"\n传的时间久了，一定经过了若干程度的改进，修正与变化，鲜少是由某一人"
"\n一开始就发明出某种游戏。麻将原称「麻雀」，民国初年由大陆传入台湾，"
"\n慢慢地从广东的十三张，演变成台湾的十六张玩法。"
"\n\n虽然打麻将会使人与赌博产生联想，什麽『玩物丧志』，『倾家荡产』不好"
"\n的字眼，相伴而生。但是面对全球时下将近十二亿中国人，这个中国人悠久"
"\n的传统娱乐，实在应该坦然面对阳光，使有心人士能够正视他。麻将最能表"
"\n现中国人的智慧的一种娱乐，的确，麻将的确是一种高深莫测的学问，比起"
"\n挢牌，十三张，骰子啦，要有趣的多了，只是被一些不肖的人拿来当成敛财"
"\n的工具。"
"\n\n试想，一百四十四张所分配出来的牌局，几乎没有一把是相同的，玩者必须"
"\n运筹帷幄，才能蠃得最後的胜利，一般而言，四人打完三将（１２圈），技"
"\n术与运气比例应该是三十五比六十五，但是别看这小小的三十五，当运气差"
"\n不多时，它往往是获得大胜的关键。不过要切记，小赌可以怡心养神，大赌"
"\n会倾家荡产，麻将客切勿留连於方城之战，而忽略了正当的职业，才是明智"
"\n之举，也不辜负了此种美好的牌戏。"
"\n\n如果打牌中你发现麻将的格式出了问题，而线条或字体并未对齐，请把zmud"
"\n字型设置为courier，大小设置为十二，将能解决问题。"
"\n\n请参阅相关帮助档案help playmj，help setmj。\n\n"
);
	return 1;
	}
	if (str=="playmj")
	{
write(
"\n\n　　　"WHT"指　　　令"NOR"　　　　　　　"GRN"例　　　　　　子"NOR"　　　　　　"WHT"说　　明"NOR
"\n　　"HIM"┏━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━┓"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR"　　　　　　　　　　　　　　　　　　　"HIM"┃"NOR"　　　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　jiaru　 "HIM"┃"NOR" ------------------------------------ "HIM"┃"NOR"加入牌局"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　look　　"HIM"┃"NOR" l mj看自己牌，l all看在桌面上的牌，　"HIM"┃"NOR" 　　　 "HIM"┃"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR" l end看剩下的牌数，　　　　　　　　　"HIM"┃"NOR"　　　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR" l dump上一张被打出去的牌。　　　　　 "HIM"┃"NOR"　　　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR" l player1看1号玩家打过的牌及翻开的牌 "HIM"┃"NOR"　　　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR" (在宣布听牌后能看其玩家手中拥有的牌) "HIM"┃"NOR"看牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　mo　　　"HIM"┃"NOR" ------------------------------------ "HIM"┃"NOR"摸牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　da　　　"HIM"┃"NOR" da <代码> 或 dump <代码>。　　　　　 "HIM"┃"NOR"打牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　chi　　 "HIM"┃"NOR" chi <代码1> <代码2> 或 eat。　　　　 "HIM"┃"NOR"吃牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR" (以代码1和代码2吃上家所打的牌)　　　 "HIM"┃"NOR"吃牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　peng　　"HIM"┃"NOR" peng 或 p 。　　　　　　　　　　　　 "HIM"┃"NOR"碰牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　gang　　"HIM"┃"NOR" gang 或 g，gang <代码>(暗杠用)。　　 "HIM"┃"NOR"杠牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　hu　　　"HIM"┃"NOR" ------------------------------------ "HIM"┃"NOR"胡牌　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　setmj　 "HIM"┃"NOR" 请读相应说明档 help setmj。　　　　　"HIM"┃"NOR"设定参数"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　wash　　"HIM"┃"NOR" ------------------------------------ "HIM"┃"NOR"牌局开始"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　restart "HIM"┃"NOR" restart 或 restart mj。　　　　　　　"HIM"┃"NOR"　　　　"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR" (进行完一局牌局后最少需要打完一圈)　 "HIM"┃"NOR"重新开始"HIM"┃"NOR
"\n　　"HIM"┃"NOR"　　　　　"HIM"┃"NOR"　　　　　　　　　　　　　　　　　　　"HIM"┃"NOR"　　　　"HIM"┃"NOR
"\n　　"HIM"┣━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━┫"NOR
"\n　　"HIM"┃"NOR" 如果打牌中你发现麻将的格式出了问题，而线条或字体并未对齐， "HIM"┃"NOR
"\n　　"HIM"┃"NOR" 请把zmud字型设置为courier，大小设置为十二，将能解决问题。　"HIM"┃"NOR
"\n　　"HIM"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"NOR
);
	return 1;
	}
	if (str=="setmj")
	{
write(
"\n\n　　　　　　　　　　　"GRN"基  本  设  定"NOR
"\n 　　　"WHT"setmj 可用的有自动胡、杠、碰、听、显式方法。"NOR
HIM"\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"NOR
HIM"\n┃"NOR"　setmj peng <代码>　　　设定自动碰牌。　　　　　　　　　 "HIM"┃"NOR
HIM"\n┃"NOR"　setmj peng none　　　　取消会自动碰牌设定。　　　　　　 "HIM"┃"NOR
HIM"\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫"NOR
HIM"\n┃"NOR"　setmj gang <代码>　　　设定自动杠牌。　　　　　　　　　 "HIM"┃"NOR
HIM"\n┃"NOR"　setmj gang none　　　　取消会自动杠牌设定。　　　　　　 "HIM"┃"NOR
HIM"\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫"NOR
HIM"\n┃"NOR"　setmj ting <代码>　　　设定会自动胡牌。　　　　　　　　 "HIM"┃"NOR
HIM"\n┃"NOR"　setmj ting none　　　　取消会自动胡牌设定。　　　　　　 "HIM"┃"NOR
HIM"\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫"NOR
HIM"\n┃"NOR"　setmj show 代码　　　　设定为只显示代码。　　　　　　　 "HIM"┃"NOR
HIM"\n┃"NOR"　setmj show color　　　 设定为彩色图形显示。　　　　　　 "HIM"┃"NOR
HIM"\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫"NOR
HIM"\n┃"NOR"　setmj auto ting　　　　宣布听牌。　　　　　　　　　　　 "HIM"┃"NOR
HIM"\n┃　　　　　　　　　　　　　　　　　　　　　　　　　　　　　┃"NOR
HIM"\n┃"NOR"　当你作出听牌宣言后可看其他三家手中的牌。为防作弊一切将　"HIM"┃"NOR
HIM"\n┃"NOR"　自动化，摸牌，打牌。且将无法再吃，碰，或杠牌。　　　　　"HIM"┃"NOR
HIM"\n┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫"NOR
HIM"\n┃"NOR"　例子：　　　　　　　　　　　　　　　　　　　　　　　　　"HIM"┃"NOR
HIM"\n┃"NOR"　setmj peng 1w　　　　　当别人打出一万时会自动碰一万。　 "HIM"┃"NOR
HIM"\n┃"NOR"　setmj gang 1w　　　　　当别人打出一万时会自动杠一万。　 "HIM"┃"NOR
HIM"\n┃"NOR"　setmj ting 1w　　　　　当别人打出一万时会自动胡一万。　 "HIM"┃"NOR
HIM"\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"NOR
);
	return 1;
	}
	return 0;
}
int to_say_rule()
{
write(@HELP
　　游戏规则以台湾十六张打法为基础。
HELP);
	return 1;
}
int show_score(string str)
{
	int i,check,a,b,c,d,e;
	string *temp=({"","","","","",""});
	string show="";
	mixed *MjData;
	
	if (!str) str=this_player()->query("id");
	else if (str=="-lp"||str=="-pl"||str=="-l") str="all1";
	else if (str=="-lw"||str=="-wl") str="all2";
	else if (str=="-lh"||str=="-hl") str="all3";
	else if (str=="-ld"||str=="-dl") str="all4";
	if (file_size(MJ_DATA)==-1) return notify_fail(HIW"资料档没没有找到。\n"NOR);
	MjData=explode(read_file(MJ_DATA),",");
	if (str=="all1") e=2;
	else if (str=="all2") e=3;
	else if (str=="all3") e=4;
	else if (str=="all4") e=5;
	if (str=="all1"||str=="all2"||str=="all3"||str=="all4") str="all";
	if (str=="-p") e=2;
	else if (str=="-w") e=3;
	else if (str=="-h") e=4;
	else if (str=="-d") e=5;
	if (str=="all"||str=="-p"||str=="-w"||str=="-h"||str=="-d")
	{
		for (a=0;a<sizeof(MjData);a+=6)
		{
			for (b=a+6;b<sizeof(MjData);b+=6)
			{
				sscanf(MjData[a+e],"%d",c);
				sscanf(MjData[b+e],"%d",d);
				if (d > c)
				{
					for (i=0;i<6;i++)temp[i]=MjData[a+i];
					for (i=0;i<6;i++) MjData[a+i]=MjData[b+i];
					for (i=0;i<6;i++) MjData[b+i]=temp[i];
				}
			}
		}
	}
	show=HBBLU"\n　";
	for (i=0; i<40; i++) show+="　";
	show+=HBBLU"　\n";
	show+="　"NOR HBGRN"　"NOR HBGRN BLK"英文名字　"NOR HBGRN RED"┃　"NOR HBGRN WHT"中文名字　"NOR HBGRN RED"┃　"NOR HBGRN BLK"已玩局数　"NOR HBGRN RED"┃　"NOR HBGRN WHT"总战迹　"NOR HBGRN RED"┃　"NOR HBGRN BLK"自摸次数　"NOR HBGRN RED"┃　"NOR HBGRN WHT"放枪次数  "NOR HBBLU"　\n";
	if (str=="all")
	{
		for (i=0; i<sizeof(MjData); i+=6)
		{///
			show+="　"NOR HBGRN RED;
			show+=sprintf("%10s　┃%10s　┃%10s　┃%8s　┃%10s　┃%10s  ",
							MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
			show+=NOR HBBLU"　\n";
		}
	}
	else if (str=="-p"||str=="-w"||str=="-h"||str=="-d")
	{
		if (sizeof(MjData) < 60) d=sizeof(MjData);
		else d=60;
		for (i=0; i<d; i+=6)
		{///
		show+="　"NOR HBGRN RED;
		show+=sprintf("%10s　┃%10s　┃%10s　┃%8s　┃%10s　┃%10s  ",
						MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
		show+=NOR HBBLU"　\n";
		}
	}
	else
	{
		for (i=0; i<sizeof(MjData); i+=6)
		{
			if (MjData[i]==str)
			{
				check=1;
				break;
			}
		}
		if (check==1)
		{
			show+="　"NOR HBGRN RED;
			show+=sprintf("%10s　┃%10s　┃%10s　┃%8s　┃%10s　┃%10s  ",
							MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
			show+=NOR HBBLU"　\n";
		}
		else return notify_fail(HIW"没有这个人的资料。\n"NOR);
	}
	show+=NOR HBBLU"　";
	for (i=0; i<40; i++) show+="　";
	show+=HBBLU"　"NOR"\n";
	printf("%s\n",show);
	return 1;
}
int set_mjdata(object me,int *winner)
{
	int i,check;
	string str="";
	mixed *MjData;
 
	if (!me||!winner) return 0;
	if (file_size(MJ_DATA)==-1);
	else
	{
		MjData=explode(read_file(MJ_DATA),",");
		for (i=0; i<sizeof(MjData); i+=6)
		{
			if (MjData[i]==me->query("id"))
			{
				check=1;
				break;
			}
		}
	}
	if (check==1)
	{
		MjData[i+2]=sprintf("%d",winner[0]);
		MjData[i+3]=sprintf("%d",winner[1]);
		MjData[i+4]=sprintf("%d",winner[2]);
		MjData[i+5]=sprintf("%d",winner[3]);
		for (i=0; i<sizeof(MjData); i++) str+=MjData[i]+",";
		write_file(MJ_DATA,str,1);
	}
	else
	{
		str=me->query("id")+",";
		str+=me->name()+",";
		str+=winner[0]+",";
		str+=winner[1]+",";
		str+=winner[2]+",";
		str+=winner[3]+",";
		write_file(MJ_DATA,str,0);
	}
	return 1;
}
int *get_mjdata(string Id)
{
	int i,check,*winner=({0,0,0,0});
	string str="";
	mixed *MjData;
 
	if (!Id) return 0;
	if (file_size(MJ_DATA)==-1) return 0;
	MjData=explode(read_file(MJ_DATA),",");
	for (i=0; i<sizeof(MjData); i+=6)
	{
		if (MjData[i]==Id)
		{
			check=1;
			break;
		}
	}
	if (check==1)
	{
		sscanf(MjData[i+2],"%d",winner[0]);
		sscanf(MjData[i+3],"%d",winner[1]);
		sscanf(MjData[i+4],"%d",winner[2]);
		sscanf(MjData[i+5],"%d",winner[3]);
	}
	return winner;
}
int get_tc(mapping who)
{
	int size,i,check;
	string str,tempW="",tempT="",tempS="",tempB="";
	str=who["Mj"]+who["Out"]+who["OutPeng"]+who["OutGang"];
    
	//庄家
	if (NowPlayerId[0]==who["Id"]) Tc+="@1";
	//门清&自摸
	if (who["Out"]==""&&who["OutPeng"]==""&&Touched) Tc+="@l";
	else if (who["Out"]==""&&who["OutPeng"]=="") Tc+="@4";
	else if (Touched) Tc+="@2";
	//全求人
	if (strlen(who["Mj"]) < 5) Tc+="@i";
	size=strlen(str);
	while(size--)
	{
		size--;
		if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
		else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
		else tempB+=str[size..size+1];
	}
	//风牌
	if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@e";
	else if (Times/Play == 0 && do_check_Mj(tempB,"ea") > 2
		||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@5";
	if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@f";
	else if (Times/Play == 1 && do_check_Mj(tempB,"so") > 2
		||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@6";
	if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@g";
	else if (Times/Play == 2 && do_check_Mj(tempB,"we") > 2
		||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@7";
	if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@h";
	else if (Times/Play == 3 && do_check_Mj(tempB,"no") > 2
		||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@8";
	//花牌
	if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//八仙过海
	else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//七抢一
	else if (do_check_Mj(who["OutFlower"],"f1")==1&&do_check_Mj(who["OutFlower"],"f2")==1
		&&  do_check_Mj(who["OutFlower"],"f3")==1&&do_check_Mj(who["OutFlower"],"f4")==1) Tc+="@B";//春夏秋冬
	else if (do_check_Mj(who["OutFlower"],"f5")==1&&do_check_Mj(who["OutFlower"],"f6")==1
		&&  do_check_Mj(who["OutFlower"],"f7")==1&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@C";//梅兰菊竹
	else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f1")==1
		||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f5")==1
		||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f2")==1
		||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f6")==1
		||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f3")==1
		||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f7")==1
		||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f4")==1
		||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@3";
	//清一色跟字一色
	if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
	else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
	//混一色
	if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
	else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
	//绿一色
	else if (tempW==""&&tempT==""&&tempS!=""&&tempB!="")
	{
		if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
			||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
			&& do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
			&& do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
			else Tc+="@n";
	}
	//大三元
	if (do_check_Mj(tempB,"jo") > 2
	&&  do_check_Mj(tempB,"fa") > 2
	&&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
	//小三元
	else if (do_check_Mj(tempB,"jo") > 1
	&&  do_check_Mj(tempB,"fa") > 1
	&&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
	else if (do_check_Mj(tempB,"jo") > 2) Tc+="@9";
	else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
	else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
	//大四喜
	if (do_check_Mj(tempB,"ea") > 2
	&&  do_check_Mj(tempB,"so") > 2
	&&  do_check_Mj(tempB,"we") > 2
	&&  do_check_Mj(tempB,"no") > 2) Tc+="@v";
	//小四喜
	else if (do_check_Mj(tempB,"ea") > 1
	&&  do_check_Mj(tempB,"so") > 1
	&&  do_check_Mj(tempB,"we") > 1
	&&  do_check_Mj(tempB,"no") > 1) Tc+="@F";
 
	for (i=0;i<sizeof(str);i+=2)
	{
		if (str[i..i+1]=="xx") continue;
		if (do_check_Mj(str,str[i..i+1])==3) check++;
		else if (do_check_Mj(str,str[i..i+1])==4) check++;
	}
	//碰碰胡
	if (check>14)
	{
		if (who["Out"]==""&&who["OutPeng"]==""&&do_check_Mj(Tc,"@u")==0) Tc+="@m@u";
		else  Tc+="@m";
	}
	check=0;
	for (i=0;i<sizeof(str);i+=2)
	{
		if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;
	}
	if (check=0&&tempB!="") Tc+="@I";//混老头
	else if (check=0&&tempB="") Tc+="@J";//清老头
	//平胡
	if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTing"])>3) Tc+="@d";
	//海底捞月
	if (count==((end-16-(Ganged*2))-2)&&Touched) Tc+="@b";
	//海底
	if (count==((end-16-(Ganged*2))-2)&&!Touched) Tc+="@c";
	//天胡
	if (LastDump==""&&count==(Play*2*16)+2) Tc+="@w";
	//地胡&人胡
	printf("%d > %d\n",count,((Play*2*16)+(Play*2)));
	if (count < ((Play*2*16)+(Play*2))
		&&P1Data["Out"]==""&&P1Data["PengOut"]==""
		&&P2Data["Out"]==""&&P2Data["PengOut"]==""
		&&P3Data["Out"]==""&&P3Data["PengOut"]==""
		&&P4Data["Out"]==""&&P4Data["PengOut"]=="")
	{
		if (Touched) Tc+="@x";
		else Tc+="@y";
	}
	return 1;
}
