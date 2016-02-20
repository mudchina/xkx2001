// Change by Server
// finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 50);
		me->start_more( FINGER_D->finger_all() );
	} else {
		if( (int)me->query("jing") < 15 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 15);
		write( FINGER_D->finger_user(arg) );
	}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : finger [使用者姓名]
 
这个指令, 如果没有指定使用者姓明, 会显示出所有正在线上玩家
的连线资料. 反之, 则可显示有关某个玩家的连线, 权限等资料.
如使用者姓名后有站点名称，则可显示有关某个玩家在该站点的资
料。
 
范例： finger server, finger server@ln
相关指令： who, locate, mudlist
HELP
    );
    return 1;
}
 
