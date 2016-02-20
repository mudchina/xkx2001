//Cracked by Roath
// arthurgu 1999.10

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
	write(CLR);
	if(!arg)
	{
		msg = "                                              
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		                                                    ";
		write(msg);
	me->set_temp("block_msg/all",1);
	return 1;}
	else if( arg == "leave")
	{
        me->delete_temp("block_msg/all");
	write(CLR);
	write("欢迎您重回xkx世界！\n");
	
      return 1;
        }
}

int help(object me)
{
     write(@HELP
指令格式: boss | boss leave

这个指令让你在领导出现前瞬间将屏幕上所有的中文消除，
并不再收到xkx的讯息。直到你输入boss leave恢复。


HELP
    );
    return 1;
}
