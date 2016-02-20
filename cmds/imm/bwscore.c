//Cracked by Roath
// bwscore.c
// exam player's bwdh data
// by sdong , 8/8/1999
// Modified by xQin 04/01 to disable the possibility for players to use this cmd to check whether
// an invisible wiz is online.


#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void print_info(object usr);

int main(object me, string arg)
{
  object usr;
  object square;


  if ( !arg )
  {
	  square = find_object("/d/bwdh/sjsz/square.c");
	  if( !square || !objectp(square) )
		 square = new("/d/bwdh/sjsz/square.c");

	  return notify_fail(square->long_desc() +
			"\n\n指令格式：bwscore or bwscore player\n" );
	}
	

  usr = present(arg, environment(me));
  
  
  if (!usr) usr = present(arg, me);
  if (!usr) usr = find_player(arg);
  if (usr) {
  	if( !wizardp(me) && wizardp(usr) )
        return notify_fail("没有这个玩家。\n");
	 return print_info(usr);
  }
  else 
  return notify_fail("没有这个玩家。\n");

  print_info(usr);
  destruct(usr);
  return 1;
}

int print_info(object target)
{
	string msg;
	int i;
	mapping record;
	string *players;

	if ( !objectp(target) ) return notify_fail("并无此人！\n");

	msg =  sprintf( BOLD " %s" NOR "%s\n\n", RANK_D->query_rank(target), target->short(1) );

	if( (record = target->query("bwdh")) )
	{
		msg += "个人赛胜利次数：" + target->query("bwdh/win") + "\n";
		msg += "个人赛失败次数：" + target->query("bwdh/defeated") + "\n";
		players = keys(record);
		for(i=0;i<sizeof(players);i++)
		{
			if( players[i] != "win" && players[i] != "defeated"  && players[i] != "fighting" &&
				players[i] != "once" )
	msg += "交战过：           " + players[i] + " 胜 " + target->query("bwdh/"+players[i]+"/win") + " 负  " + target->query("bwdh/"+players[i]+"/lose") + "\n";
		}

	}

	msg += "\n队名：             " + target->query("sjsz/team_name")+"\n";
	msg += "总成绩：           " + target->query("sjsz/bw_score")+"\n";
	msg += "总比武经验：       " + target->query("sjsz/exp")+"\n";
	msg += "总抢旗次数：       " + target->query("sjsz/flag")+"\n\n";
	msg += "本次成绩：         " + target->query("sjsz/this_score")+"\n";
	msg += "本次比武经验：     " + target->query("sjsz/this_exp")+"\n";
	msg += "本次抢旗次数：     " + target->query("sjsz/this_flag")+"\n\n";
	if( target->query("sjsz/red") || target->query("sjsz/white") )
		msg += "正在比武中。\n";

	return notify_fail(msg);
}





int help(object me)
{
write(@HELP
指令格式：bwscore or bwscore player.

用来检查玩家比武数据
HELP
	 );
	 return 1;
}

