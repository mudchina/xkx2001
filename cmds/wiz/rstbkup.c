// Change by Server
// restorebackup.c
// restore player's data from backup
// by sdong , 11/18/98

#include <ansi.h>
#include <combat.h>
#ifndef QUEUEDIR
#define QUEUEDIR "/queue/" #endif #define RESTOREDATA QUEUEDIR + "restore" #define LOCKDATA QUEUEDIR + "restore.lock"  inherit F_DBASE; inherit F_CLEAN_UP;  
int main(object me, string arg)
{
		 object obj;
       string name,number;

		 if( wizhood(me) != "(caretaker)" && wizhood(me) != "(wizard)" &&
			  wizhood(me) != "(arch)" && wizhood(me) != "(admin)"
		  ) return notify_fail("什么？\n");

		 if (!arg) return notify_fail("指令格式：rstbkup player #backup.\n");
		 if(sscanf(arg, "%s %s", name, number) != 2)return notify_fail("指令格式：rstbkup player #backup.\n");

		  seteuid(ROOT_UID);
		  write_file(RESTOREDATA, name + ":" + number + "\n");


        tell_object(me,"恢复"+name+"备份"+number+"指令执行了。\n");
		 return 1; } 

int help(object me)
{
write(@HELP
指令格式：rstbkup player #bakcup

用来从备份中恢复玩家数据
HELP
	 );
	 return 1;
}

