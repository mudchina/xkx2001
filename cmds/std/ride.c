//Cracked by Roath
// ride.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("你要骑什么？\n");

	if (me->query_busy())
                return notify_fail("你正忙着呢！\n");

	if( !ob->is_character() || ob->query("race") == "人类")
		return notify_fail("你不能这么干！\n");

	if( !ob->query("ridable") )
		return notify_fail("这东西不能骑！\n");

	if (!living(ob))
		return notify_fail("先等它醒过来在说吧。\n");

	if( ob->query_lord() == me ) 
	{
		if( !me->query("rided") )
		{
			if( !ob->query("rider") || ob->query("rider") == me)  
			{
				me->set("rided", ob);
				ob->set("rider", me);
				ob->set_leader(me);

				message_vision("\n$N一纵身，威风凛凛地骑在了" + ob->name() +"身上。\n", me);
				return 1;
			}
			else    return notify_fail( (ob->query("rider"))->name() + "已经骑在它身上了！\n");
		}
		else	return notify_fail("你已经骑在" + (me->query("rided"))->name() + "上了！\n");
	}
	else return notify_fail("你不是它的主人！\n");

	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : ride|qi <某动物>
 
这个指令可以让你骑上某一动物，如牛，马，虎等，加快行走速度。
 
HELP
	);
	return 1;
}
