//Cracked by Roath
// /cmds/war/trick.c
// by jun@SIA

#include "/tmp/mpfight/war_include/war_temp.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string file, target, jimou;
    
    seteuid(getuid());
    
    if( !me->query_temp("war/war")) return notify_fail("你并不是在打仗！\n");
    
    if( me->query_temp("in_war/is_hunluan") ) 
        return notify_fail("你的军中太混乱了，你没有办法使用计谋！\n");

    if( me->is_busy() )
	return notify_fail("你正忙于别的事情呢。\n");

    if( me->query_temp("in_war/trick_amount") == 0)
        return notify_fail("你已经江郎才尽，黔驴技穷了。。。\n");

    if( me->query_temp("in_war/is_tricking") )
    	return notify_fail("你已经在使用计谋了。\n");

    if(sizeof(all_inventory(environment(me))) > 1 ) 
        return notify_fail("你的军队正在打仗呢。\n");
        	
    if( !arg ) return notify_fail("你要用什么计谋？？\n");
    
    if( sscanf(arg, "%s %s", jimou, target)==2 ) {}
    else jimou = arg;         
    	
    if( !stringp(file = TRICK_D(jimou) ) 
	|| file_size(file + ".c") <= 0 )
	    return notify_fail("没有这种计谋。\n");
    return (int)call_other( TRICK_D(jimou), "trick", me, target);
}

int help (object me)
{
// later maybe add 对象 - 指令格式：trick <计谋名称> [<施用对象>]
    write(@HELP
这是在战场上用计谋的指令。
指令格式：  tricky <计谋名称>
	or  tricky <计谋名称> <施用对象>
	or  tricky <计谋名称> <参数>

    如：tricky fire	使用火计。
        tricky recover or tricky recover <id>	
HELP);
    return 1;
}
