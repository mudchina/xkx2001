// Change by Server
// clear.c 
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
	if (str != "off") {
		me->set_temp("block_msg/all", 1);
    		printf(CLR);
    		return 1;
	}
	me->set_temp("block_msg/all", 0);
	return 1;
}
 
int help(object me)
{
    write(@HELP
指令格式: clear [off]
 
清屏幕。
 
HELP
    );
}
 
