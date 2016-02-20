//Cracked by Roath
// cat.c
// modified by sdong for more security 11/02/98

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个档案。\n");
		file = base_name(ob) + ".c";
	}

	if(!SECURITY_D-> valid_read(file, this_object(), "read_file") && me->query("id") != "sdong" )return notify_fail("对不起，你没有读这个档案的权力。\n");

	me->start_more( read_file(file));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : more <档案>|<物件名>
 
分页显示档案内容。
 
more 模式下的指令:
q      : 离开 more.
b      : 显示前一页的内容.
[ENTER]: 显示下一页的内容.

HELP
    );
    return 1;
}
