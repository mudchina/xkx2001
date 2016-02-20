// Change by Server
// tail.c
// modified by sdong for more security 11/02/98

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return help(me);
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
	if(!SECURITY_D-> valid_read(file, this_object(), "read_file") )return notify_fail("对不起，你没有读这个档案的权力。\n");
	tail(file);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : tail <档案>

此指令可让你(你)直接读取某档案最末尾的几行。
HELP
    );
    return 1;
}
