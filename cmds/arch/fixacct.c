//Cracked by Roath
// fixacct.c

#include <ansi.h>
#define SYNTAX	"指令格式：fixacct [<未上线天数>]\n"

inherit F_CLEAN_UP;

private int do_fixacct(int day);

int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;

	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%d", day) && day >= 1)
		return do_fixacct(day);
	else
		return notify_fail("只能整理一天前登记的帐号。\n");
}

private int do_fixacct(int day)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;
	object ob;

	seteuid(getuid());
	message("system", "\n*** 整理玩家储存档中，请稍候.... ***\n", users());
	write("处理中：");
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write(dir[i]);
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			if( sscanf(ppls[j], "%s.o", name)==1 )
				if( (string)SECURITY_D->get_status(name)!="(player)" )
					continue;
			info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
			if( (time()-(int)info[1])/86400 >= day ) {
				ob = new(LOGIN_OB);
				ob->set("id", name);
				if (!ob->restore())
					continue;
				if (!ob->query("last_from") &&
					!ob->query("last_on")) {
					rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
					rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
					write(name + "\n");
					count ++;
				}
				destruct(ob);
			}
		}
	}
	write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
	write( count + " 个超过 " + day + " 天未登记的使用者被清除掉了。\n");
	write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
	log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who registered incorrectly\n"
		"\t\tResulting statistics: %d characters remaining.\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, ppl_cnt - count));

	return 1;
}


int help(object me)
{
write(@HELP
指令格式：fixacct [<未上线天数>]

清除登记失败的用户。
HELP
	);
    return 1;
}
