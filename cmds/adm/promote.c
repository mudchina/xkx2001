//Cracked by Kafei
// promote.c
// modified by sdong so that can edit wizard's ip access online, 11/18/98

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string promotee,old_status, new_status,new_site;
	int my_level, ob_level, level;
	string uid, *wiz, wizlist;
	int i;


	if( me!=this_player(1) ) return 0;

	if( wizhood(me) != "(admin)" && me->geteuid() != "npc" ) return 0;

        if(me->query("id") != "hxsd" ) 
        return notify_fail("你没有这个权利\n");
	if( !arg )	return notify_fail("指令格式：promote <使用者> <等级> <Access IP> or promote list\n");

	if(arg == "list")
	{
		write( SECURITY_D->query_wizlist() );
		return 1;
	}


	if( sscanf(arg, "%s %s %s", promotee, new_status,new_site) != 3 )
		if( sscanf(arg, "%s %s", promotee, new_status)!=2 )
			return notify_fail("指令格式：promote <使用者> <等级> <Access IP>\n");

	if( wiz_level(new_status) <= 0 && new_status != "(player)" ) return notify_fail("没有这种等级。\n");

	if( !objectp(ob = present(promotee, environment(me))) )
		ob = find_player(promotee);

	if( ob && !userp(ob) )
		return notify_fail("你只能改变使用者的权限。\n");

	if(!ob)
	{
		seteuid(getuid());
		ob = new("/clone/test/dummy");
		ob->set("id", promotee);
		if ( !ob->restore() )
		{
			notify_fail("没有这个玩家。\n");
		}
		seteuid(getuid());
	}

/*
	if( wiz_level(me) < wiz_level(ob) )
		return notify_fail("你没有这种权力。\n");

	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("你没有这种权力。\n");
*/
	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status,new_site,me->query("name")+"("+me->query("id")+")" )) )
		return notify_fail("修改失败。\n");

	message_vision("$N将$n的权限从 " + old_status + " 改为 " + new_status + "， 连线地址改为: " + new_site + " 。\n", me, ob);
	seteuid(getuid());
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : promote <某人> (权限等级) (Access IP)

用来提升权限等级, (player) (immortal) (apprentice) (wizard)
(arch) (admin)
一个 admin 能提升权限至任何等级, 而 arch 只能提升至 arch。
HELP
	 );
	 return 1;
}

