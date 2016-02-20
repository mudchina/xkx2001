//Cracked by Roath
// where.c
// 06-14-95

inherit F_CLEAN_UP;

int env_cmp(object o1, object o2)
{
	string env1, env2;
	object where;
	env1 = (where = environment(o1)) ? base_name(where) : "none";
	env2 = (where = environment(o2)) ? base_name(where) : "none";
	return strcmp(env1, env2);
}
int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;

	if (!str) {
		string msg;
		ob_list = sort_array(users(), (: env_cmp :));
		msg = "";
		foreach(ob in ob_list) {
			where = environment(ob);
			msg += sprintf("%-20s%-20s%-20s\n", ob->name()+
				"("+ob->query("id")+")",
				where ? where->query("short") : "不详",
				where ? base_name(where) : "none");
		}
		me->start_more(msg);	
		return 1;
	}

	ob = find_player(str);
	if( !ob ) ob = find_living(str);
	if( !ob || !me->visible(ob)) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return notify_fail("现在没这个人。\n");
	}
	if (!ob) return notify_fail("现在没这个人.\n");
	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在那里耶...\n");
	printf("%s(%s)现在在%s(%s).\n",
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"),
		(string)file_name(where));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: where <玩家的 ID>

这个指令是用来得知玩家目前所在的位置, 若不加 id 则会列出所有
玩家的所在位置。

HELP
	);
	return 1;
}

