//Cracked by Roath
// shout.c

inherit F_CLEAN_UP;

#define SHOUT_LIST	({ })
int main(object me, string arg)
{
//	if( !wizardp(me) && me->query("id") != "sad" &&
//	me->query("id") != "long" )
	if (!wizardp(me) && member_array(me->query("id"), SHOUT_LIST) == -1)
		return notify_fail("目前暂不开放玩家 shout。\n");
	if (!arg) return notify_fail("你想要大叫什么？\n");
	shout( me->name() + "纵声长啸：" + arg + "\n");
	write("你纵声长啸：" + arg + "\n");
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
HELP
    );
    return 1;
}
 
