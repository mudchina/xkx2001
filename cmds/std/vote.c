//Cracked by Roath
// vote.c 
// by Marz, 04/18/96

#include <net/dns.h>
#include <ansi.h>

inherit F_CLEAN_UP;

// int valid_voters(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name;
	string file;
	object file_ob;

	if (((int)me->query("age")<16) && !wizardp(me))
	{
		return notify_fail("民主不是儿戏！小孩子一边玩去！\n");
	}
	
	/**	
	if ((int)me->query("xkx_jail"))
	{
		return notify_fail("你还是老老实实做完牢再说吧！\n");
	}
	**/	

	if ((int)me->query("vote/deprived"))
	{
		return notify_fail("你想起当初玩弄民主、被剥夺投票权的事，追悔莫急。\n");
	}

	if (!arg || sscanf(arg, "%s %s", act_name, victim_name) != 2
	    || !stringp(file = (string)"/cmds/std/vote/"+act_name)
   	    || file_size(file + ".c") <= 0 )
    	{
		return notify_fail("这神圣的一票，要想清楚了才能投。\n");
    	}
    
	victim = LOGIN_D->find_body(victim_name);
	if (!victim || !me->visible(victim)) return notify_fail("你要投谁的票？\n");

/*	if ( wizardp(victim) ) {
		return notify_fail("\n你胡乱投票，企图捣乱，小心被处死！\n");
	}
*/		
	if ( !(file_ob = find_object(file)) ) file_ob = load_object(file);
	
	if ((int)file_ob->vote(me, victim) <= 0)
	{
		if ((int)me->query("vote/abuse")> 50)
		{
			write( HIG "你因为胡乱投票，投票权被剥夺了！\n" NOR);

//			me->set("xkx_jail", 1);
			me->set("vote/deprived", 1);
			me->apply_condition("vote_suspension", 120);
			me->delete("vote/abuse");
// 			me->move("/d/city/jail");
		}	
		
		return 0;
		
	};
	
	return 1;
}


int valid_voters(object me)
{
	object *list;
	int d = 0;
	int j;

	list = users();
	j = sizeof(list);
	while( j-- )
	{
		// Skip those users in login limbo.
		if( !environment(list[j]) ) continue;
//		if( !me->visible(list[j]) ) continue;
		if (((int)list[j]->query("age")<16) && !wizardp(list[j])) continue;
		if ((int)list[j]->query("vote/deprived")) continue;
		
		d++;
	}
	
	return d;
}


int help(object me)
{
write(@HELP
指令格式 : vote <动议> <某人> 

此命令提议对某人采取行动，由大家投票决定。可是如果五分钟内没有人附议，
投票会自动取消。但不是每个玩家都可以投票的，要到十六岁才能有投票权。

当前可以有如下<动议>：

chblk: 关闭某人交谈频道，需三票以上的简单多数同意。
unchblk: 打开某人交谈频道，需三票以上的三分之一票数同意。

HELP
    );
    return 1;
}

/**
future motion (not implemented yet):
eject: 驱逐某人，需三票以上的简单多数同意。
jail: 将某人送进监狱，需三票以上的简单多数同意。
**/
