//Cracked by Roath
//cloneusr.c

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object user, where;
	string msg;
	if (!arg) return notify_fail("什么？\n");
	me = this_player();

	where = environment(me);

	seteuid(arg);
	if (getuid() == ROOT_UID)
		user = new(USER_OB);
	else
		user = new("/kungfu/skill/yanxing-dao/copy/user.c");
	user->set("id", arg);
	user->set("master_id", arg);
	if (!user->restore())
		return notify_fail("没有这个玩家。\n");;
	export_uid(user);
	seteuid(getuid());
	user->set_name(user->name(), ({arg}));
	user->setup();
	if( !stringp(msg = me->query("env/msg_clone")) )
		if ( where->query("outdoors") )
                	msg = "$n快步走了过来。\n";
		else
			msg = "$n走了过来。\n";

	message_vision(msg + "\n", me, user);
	user->move(where);
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式：cloneusr [id]

这条命令是用来复制一个玩家的ｃｏｐｙ。
请记住使用过后务必把ｃｏｐｙ　ｄｅｓｔ 掉。
HELP
        );
        return 1;
}
