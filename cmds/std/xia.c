//Cracked by Roath
// unride.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;

	if( !arg 
	|| !objectp(ob = present(arg, environment(me)))
	|| ob != me->query("rided")
	|| ob->query("rider") != me)
		return notify_fail("你要干什么？\n");

	me->delete("rided");
	ob->delete("rider" );
	message_vision("\n$N一纵身，从" + ob->name() +"身上跃了下来。\n", me);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : unride|buqi <某动物>
 
这个指令可以让你从所骑某一动物身上跳下来，如牛，马，虎等。
 
HELP
	);
	return 1;
}
