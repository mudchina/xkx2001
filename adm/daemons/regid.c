//Cracked by Kafei
// regi.c	翔少爷 (registrator)
//change email register to online register for Mudos under win32 by lbc
#ifndef QUEUEDIR
#define QUEUEDIR "/queue/"
#endif
#define REGDATA QUEUEDIR + "register"
#define LOCKDATA QUEUEDIR + "register.lock"

inherit F_DBASE;

string *banned_string = ({
//	"usa.net",
//	"geocities",
//	"bbs",
//	"hotmail",
//	"nc.jx.cn",
	"hotmail"
});

int is_banned_email(string str)
{
	int i;
	string cstr = lower_case(str);

	// if email containing "."
	if (strsrch(cstr, ".") == -1)
		return 1;
	// if email containing "@"
	if (strsrch(cstr, "@") == -1)
		return 1;

	// if email contains invalid strings
       for (i = 0; i < sizeof(banned_string); i++)
                if (strsrch(cstr, banned_string[i]) != -1)
                        return 2;

	if (REGBAN_D->is_banned(cstr) == 1)
		return 2;

        return 0;
}

int register_char(string who, string where);
int change_password(string who, string what);

void create()
{
	seteuid(getuid());
	set("channel_id", "注册精灵");
}

void save_data(string who, string where, string what)
{
	write_file(REGDATA, who + ":" + where + ":" + what + "\n");
}
string random_password()
{
	return sprintf("%c%c%c%c%c", 97 + random(26), 
		97 + random(26), 97 + random(26),
		97 + random(26), 97 + random(26));
}

int register_char(string who, string where)
{
	object ob, body;
	string pass;

	ob = new(LOGIN_OB);
	ob->set("id", who);
	if (!ob->restore())
		return notify_fail("你要给谁登记？\n");
	if (SECURITY_D->get_status(who) != "(player)")
		return notify_fail("登记失败。\n");
//	if (!wizardp(this_player()) && ob->query("registered") == "yes")
//		return notify_fail(who + "已经登记过了。\n");
        if (file_size(LOCKDATA) != -1)
                return notify_fail("请等一会儿再来登记！\n");
	ob->set("email", where);
	ob->set("password", crypt(pass = random_password(), 0));
	ob->set("registered", "yes");
	save_data(ob->query("id"), where, pass);
	CHANNEL_D->do_channel(this_object(), "sys", sprintf("%s(%s)完成注册，电子邮件地址：%s", ob->query("name"), who, where));
	if (objectp(body = find_player(who)) && geteuid(body) == who) {
		log_file("REGISTER", sprintf("[%s] %s registered as %s from %s.\n", 
			ctime(time()), body->query("id"), where, query_ip_name(body)));
		tell_object(body, "您的新密码是"+pass+"\n请用新的密码连线：）\n");
		body->set("registered", "yes");
		body->save();
		destruct(body);
	}
	ob->save();
	destruct(ob);
	return 1;
}

int change_password(string who, string what)
{
	object ob;
        ob = find_player(who);
	if (ob && geteuid(ob) == who) ob = ob->query_temp("link_ob");
	else ob = 0;
	if (!ob) ob = new(LOGIN_OB);
        ob->set("id", who);
        if (!ob->restore())
               	return notify_fail("你要改谁的密码？\n");
        ob->set("password", crypt(what, 0));
    	ob->save();
        write("密码改换成功！\n");
	return 1;
}

int change_name(string who, string what)
{
	object ob;
        ob = find_player(who);
	if (ob && geteuid(ob) == who) ob = ob->query_temp("link_ob");
	else ob = 0;
	if (!ob) ob = new(LOGIN_OB);
        ob->set("id", who);
        if (!ob->restore())
               	return notify_fail("你要改谁的原来姓名？\n");
        ob->set("name", what);
    	ob->save();
        write("姓名改换成功！\n");
	return 1;
}

int change_id(string who, string what)
{
	object ob1, ob2, ob3;
	ob1 = new(LOGIN_OB);
        ob1->set("id", who);
	ob2 = new(USER_OB);
	ob2->set("id", who);
        if (!ob1->restore() || !ob2->restore()) {
		destruct(ob1);
		destruct(ob2);
               	return notify_fail("你要改谁的英文名字？\n");
	}
	ob3 = new(LOGIN_OB);
	ob3->set("id", what);
	if (ob3->restore()) {
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		return notify_fail("已有人使用此英文名字");
	}
	if (SECURITY_D->get_status(who) != "(player)"
	 || SECURITY_D->get_status(what) != "(player)" ) {
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		return notify_fail("指令失败。\n");
	}
	ob1->set("id", what);
	ob2->set("id", what);
	ob1->save();
	ob2->save();
        rm(DATA_DIR + "login/" + who[0..0] + "/" + who + SAVE_EXTENSION);
        rm(DATA_DIR + "user/" + who[0..0] + "/" + who + SAVE_EXTENSION);
	destruct(ob1);
	destruct(ob2);
	destruct(ob3);

        write("改换成功！\n");
	return 1;
}
