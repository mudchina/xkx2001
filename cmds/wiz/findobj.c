// Change by Server
// findobj.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string file)
{
	object *obs, ob, where;
	string msg;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("你要寻找什么物件？\n");

	file = resolve_path(me->query("cwd"), file);

	if( file_size(file+".c") < 0 )
		return notify_fail("没有这个档案(" + file + ")。\n");

	obs = filter_array(children(file), (: clonep :));

	if (sizeof(obs) == 0)
		return notify_fail("找不到这样物件的复制件。\n");

	msg = sprintf("总共找到了%s个复制件\n", chinese_number(sizeof(obs)));
	foreach(ob in obs) {
		where = environment(ob);
		msg += sprintf("%-40s\t%s(%s)\n", sprintf("%s(%O)", ob->name(),ob),
			where ? (living(where) ? where->name() : where->query("short")) : "不详",
			where ? (living(where) ? where->query("id") : base_name(where)) : "none");
	}
	me->start_more(msg);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : findobj <物件之文件名>

此指令列出所有物件的复制件。
HELP
    );
    return 1;
}
