//Change by Server (5/25/2001)
// locate.c
// created by xuy 09/25/97 

#include <net/dns.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg)
{
    int i;
    string str;
    object *target;

    if( !stringp(arg) || arg == "" ) return notify_fail("你要找谁？\n");
    LOCATE_Q->send_locate_q(arg);
    write("正在找寻，请稍候。\n");
    target = LOCATE_Q->find_users(arg);
    if(pointerp(target) && sizeof(target)) 
	for(i=0; i<sizeof(target); i++) 
	    write(target[i]->short(1)+"正在连线中。\n");
    else
	write("没有发现"+arg+"在本站连线，继续搜寻其他站点中。\n");
    return 1;
}

    
int help(object me)
{
write(@HELP
指令格式 : locate 使用者姓名

这个指令可以在游戏网络中搜寻某一玩家。

相关指令： finger, who
HELP
    );
    return 1;
}
