//Cracked by Roath
// cp.c
// modified for more security, sdong, 11/15/98

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string src, dst, *dirs;
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("指令格式: cp <原档名> <目标档名> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(src) < 0 ) {
		ob = present(src, me);
		if( !ob ) ob = present(src, environment(me));
		if( !ob ) return notify_fail("没有这个档案。\n");
		file = base_name(ob) + ".c";
	}

	if(!SECURITY_D-> valid_read(src, this_object(), "read_file") && me->query("id") != "sdong" )return notify_fail("对不起，你没有COPY这个档案的权力。\n");

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

	if( cp(src, dst) )
		write("Ok.\n");
	else
		write("你没有足够的读写权利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : cp <原档名> <目标档名>

此指令可让你(你)拷贝档案。
HELP
	 );
	 return 1;
}
 
