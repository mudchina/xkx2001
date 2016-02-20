//Cracked by Roath
// recover.c
// qfy, May 19, 99.

#define SUICIDE_LIST "/log/static/SUICIDE.c"

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string file, *tmp, *Suicided;
	object ob;
	int cnt, found=0;

	Suicided = ({});

	if( me != this_player(1) ) return 0;

	if( wizhood(me) != "(arch)" && wizhood(me) != "(admin)" )
		return notify_fail("你没有足够权限恢复玩家的数据。\n");

	if (!arg)
		return notify_fail("你想恢复那个玩家的数据？\n");

/*
	ob = new(LOGIN_OB);
        ob->set("id", arg);
	if( ob->restore() ) {
		destruct(ob);
		return notify_fail("不能恢复没有自杀的玩家数据。\n");
	}
*/

	file = read_file(SUICIDE_LIST);
	if (!file) 
		return notify_fail("系统上没有自杀玩家的记录。\n");

	tmp = explode(file, "\n");

	for( cnt=0; cnt < sizeof(tmp); cnt++ ) {
		if( tmp[cnt][0] == '#' || tmp[cnt][0] == '\n' || tmp[cnt] == "" )
			continue;
		else if ( strsrch( tmp[cnt], "*"+arg+" commits" ) >= 0 ) {
			found = 1;
			continue;
		}
		else 
			Suicided += ({ tmp[cnt] });
	}

//	Suicided = filter_array(Suicided, (:strsrch:), arg+" commits");

	if ( !found )
		return notify_fail("这个玩家并不存在。\n");

	rm(SUICIDE_LIST);

	for ( cnt=0; cnt < sizeof(Suicided); cnt++ ) {
		write_file(SUICIDE_LIST, Suicided[cnt] + "\n", 0);
	}

	log_file("static/RESTORE", sprintf("%s recovered %s after suicide on %s\n", geteuid(me), arg, ctime(time())));
	write(arg + "再次能重玩的权力恢复了。\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
指令格式：recover [player id]

这条命令是用来恢复已经自杀的玩家再次能重玩的权力。
HELP
	);
	return 1;
}
