// logind.c
// added mirror stuff, 12/19/98

#include <ansi.h>
#include <command.h>
#include <login.h>

#define SUICIDE_LIST "/log/static/SUICIDE.c"
#define MAX_USERS 230

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
	"你", "你", "我", "他", "她", "它", "它",
	"韦小宝", "某人", "您", "谣言", "蒙面人",
	"金庸", 
});

private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
private void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_login(object me);
object find_body(string name);
int check_legal_id(string arg,object ob);
string check_legal_name(string arg,object ob);


private void write_ob(object ob,string msg)
{
	if( objectp(ob) && ob->query("language") == "BIG5")
		msg = "/adm/daemons/languaged"->toBig5(msg);

	write(msg);
}


private void random_gift(mapping my)
{
	int i;
	int tmpstr, tmpint, tmpcon, tmpdex,tmpend;
	tmpstr = tmpint = tmpcon = tmpdex = tmpend = 10;

	for (i = 0; i < 50; i++) {
		switch (random(5)) {
		case 0: tmpstr++; break;
		case 1: tmpint++; break;
		case 2: tmpcon++; break;
		case 3: tmpdex++; break;
		case 4: tmpend++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;

	my["end"] = 100 - my["dex"] - my["str"] - my["int"] - my["con"];

	// next 2 are randomly selected
	my["kar"] = 10 + random(21);
	my["pat"] = 10 + random(21);
	my["per"] = 60 - my["kar"] - my["pat"];
}

void create()
{
	seteuid(getuid());
	set("channel_id", "连线精灵");
}

private void confirm_big5(string arg, object ob)
{
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt;
	object ppl;
	string msg;


	arg = lower_case(arg);

	if( arg == "y" || arg == "yes")
	{
		ob->set("language","BIG5");
		write_ob(ob,"Ok, use BIG5 code.\n\n");
	}
	else
	{
		ob->set("language","GB");
		write_ob(ob,"Ok, use GB code.\n\n");
	}

	usr = users();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	for(i=0; i<sizeof(usr); i++) {
		if( !environment(usr[i]) ) login_cnt++;
		else if( wizardp(usr[i]) ) wiz_cnt++;
		else ppl_cnt++;
	}


	msg = "目前本站共有" + (string)chinese_number(wiz_cnt) + "位巫师、" + (string)chinese_number(ppl_cnt);
	msg += "位玩家在线上，以及" + (string)chinese_number(login_cnt) + "位使用者尝试连线中。\n";
	msg += "您的英文名字（新玩家可选一喜欢的名字）：";

	write_ob(ob,msg);

	input_to( (: get_id :), ob );
}

void logon(object ob)
{
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt;

	if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
		write_ob(ob,"你的地址在本 MUD 不受欢迎。Your IP not welcome in this MUD.\n");
		destruct(ob);
		return;
	}

#ifdef MAX_USERS
	if( sizeof(users()) >= MAX_USERS - 4 ) {
			write_ob(ob,"对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
			destruct(ob);
			return;
	}
#endif


	cat(WELCOME);
	MUDLIST_CMD->main(this_object(), "");
	//UPTIME_CMD->main();

	write_ob(ob,"\nDo you want to use BIG5 code?(y/n)\n");
	input_to("confirm_big5", ob);
}

private void get_id(string arg, object ob)
{
	object ppl;
	string language;

	arg = lower_case(arg);
	if( !check_legal_id(arg,ob)) {
		write_ob(ob,"您的英文名字：");
		input_to("get_id", ob);
		return;
	}

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
	&& sizeof(users()) >= MAX_USERS - 4) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write_ob(ob,"对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
			destruct(ob);
			return;
		}
	}
#endif


	if( wiz_level(arg) && !SECURITY_D->valid_wiz_login(arg, query_ip_number(ob)) ) {
		write_ob(ob,"对不起，请从登记的地址使用巫师帐号。\n");
		log_file("WIZ_LOGIN", sprintf("%s: Attempting login %s from %s\n", ctime(time()), arg, query_ip_name(ob)));
		destruct(ob);
		return;
	}


	/*write_ob(ob,"\n侠客行现在的地址是：202.96.91.22 5555\n\n\n");
	if (wiz_level(arg) == 0) {
		destruct(ob);
		return;
	}*/

	if( wiz_level(arg) < wiz_lock_level ) {
		write_ob(ob,"对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
			+ " 以上的人才能连线。\n");
		destruct(ob);
		return;
	}

	if( (string)ob->set("id", arg) != arg ) {
		write_ob(ob,"Failed setting user name.\n");
		destruct(ob);
		return;
	}

//	if( arg=="guest" ) {
//		// If guest, let them create the character.
//		confirm_id("Yes", ob);
//		return;
//	} else

	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		language = ob->query("language");
		if( ob->restore() ) {
			ob->set("language",language);
			write_ob(ob,"请输入密码：");
			input_to("get_passwd", 1, ob);
			return;
		}
		write_ob(ob,"您的人物储存挡出了一些问题，请利用 guest 人物通知巫师处理。\n");
		destruct(ob);
		return;
	} else { // check if someone is already trying to create this id
		if( find_login(ob) ) {
			write_ob(ob,"有人也在创造这个人物，请选用其他英文名字。\n");
			write_ob(ob,"您的英文名字：");
			input_to("get_id", ob);
			return;
		}
	}

// dts: check reg-ban setting
	if (REGBAN_D->is_banned(query_ip_name(ob)) == 1) {
		write_ob(ob,"本 MUD 不欢迎你创造新的人物。");
		destruct(ob);
		return;
	}

	write_ob(ob,"使用 " + (string)ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
	input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
	string my_pass, file, *tmp;
	object user;
	int cnt;

	write_ob(ob,"\n");
	my_pass = ob->query("password");
	if( crypt(pass, my_pass) != my_pass ) {
		write_ob(ob,"密码错误！\n");
		if( wiz_level(ob->query("id")) )
			log_file("WIZ_LOGIN", sprintf("%s: Failed login %s from %s\n",
				ctime(time()), ob->query("id"), query_ip_name(ob)));
		destruct(ob);
		return;
	}

	// Check if this player has already suicided before.
	file = read_file(SUICIDE_LIST);
	if ( sizeof(file) > 0 ) {
	   tmp = explode(file, "\n");
		
	   for( cnt=0; cnt < sizeof(tmp); cnt++ ) {
                if( tmp[cnt][0] == '#' || tmp[cnt][0] == '\n' || tmp[cnt] == "" )
                        continue;
                else if ( strsrch( tmp[cnt], "*"+ob->query("id")+" commits" ) >= 0 ) {
			write_ob(ob,"你已经自杀了！怎么能够还魂呢？\n");
			destruct(ob);
	                return;
        	}
	    }
	}

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
		 user->set("language",ob->query("language"));
		if( user->query_temp("netdead") ) {
			reconnect(ob, user);
			return;
		}
		write_ob(ob,"您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( objectp(user = make_body(ob)) ) {
		if( user->restore() ) {
		   user->set("language",ob->query("language"));
			log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"), user->query("id"),
				query_ip_name(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write_ob(ob,"请您重新创造这个人物。\n");
	confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write_ob(ob,"您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write_ob(ob,"好吧，欢迎下次再来。\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "有人从别处( " + query_ip_number(ob)
			+ " )连线取代你所控制的人物。\n");
		log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n", user->query("name"), user->query("id"),
			query_ip_name(ob), ctime(time()) ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link ) {
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);
}

private void confirm_id(string yn, object ob)
{
	if( yn=="" ) {
		write_ob(ob,"使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
		input_to("confirm_id", ob);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write_ob(ob,"好吧，那么请重新输入您的英文名字：");
		input_to("get_id", ob);
		return;
	}
	write_ob(ob, @TEXT

请输入您的高姓大名，由于这个名字代表你的人物，而且以后不能更改，
务必慎重择名（不雅观的姓名将被本游戏拒绝登陆）。

TEXT
	);
	write_ob(ob,"您的中文名字：");
	input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
	if( !(arg = check_legal_name(arg,ob) )) {
		write_ob(ob,"您的中文名字：");
		input_to("get_name", ob);
		return;
	}
	//write_ob(ob,"%O\n", ob);
	if( objectp(ob) && ob->query("language") == "BIG5")
		arg = "/adm/daemons/languaged"->toGB(arg);
	ob->set("name", arg);

	write_ob(ob,"请设定您的密码：");
	input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
	write_ob(ob,"\n");
	if( strlen(pass)<5 ) {
		write_ob(ob,"密码的长度至少要五个字元，请重设您的密码：");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write_ob(ob,"请再输入一次您的密码，以确认您没记错：");
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	mapping my;
	string old_pass;
	write_ob(ob,"\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write_ob(ob,"您两次输入的密码并不一样，请重新设定一次密码：");
		input_to("new_password", 1, ob);
		return;
	}

	write_ob(ob,@TEXT

一个人物的天赋对于他或她所修习的武艺息息相关。侠客行中的人物大多具有
以下四项天赋：

	膂力：影响攻击能力及负荷量的大小。
	悟性：影响学习武功秘籍的速度及理解师傅的能力。
	根骨：影响体力恢复的速度及升级后所增加的体力。
	身法：影响防御及躲避的能力。
	耐力：影响作战和工作的耐久力。

TEXT);
	my = ([]);
	random_gift(my);
	write_ob(ob,sprintf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]， 耐力[%d]\n",
					 my["str"], my["int"], my["con"], my["dex"], my["end"]) );

  write_ob(ob,"您接受这一组天赋吗？");
  input_to("get_gift", ob, my);
}

private void get_gift(string yn, object ob, mapping my)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my);
		write_ob(ob,sprintf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]， 耐力[%d]\n",
					 my["str"], my["int"], my["con"], my["dex"], my["end"]) );

		write_ob(ob,"您同意这一组天赋吗？");
		input_to("get_gift", ob, my);
	}
	if (yn[0] == 'y' || yn[0] == 'Y') {
				write_ob(ob,"\n您的电子邮件地址：");
			input_to("get_email", ob, my);
	}
}

private void get_email(string email, object ob, mapping my)
{
	object user;

	write_ob(ob,"\n");
	if (email == "" || strsrch(email, "@") == -1) {
		write_ob(ob,"电子邮件地址需要是 id@address 的格式。\n");
		write_ob(ob,"您的电子邮件地址：");
		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", "no");

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	ob->set("registered", "no");
	user->set("registered", "no");

	write_ob(ob,"您要扮演男性(m)的角色或女性(f)的角色？");
	input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	write_ob(ob,"\n");
	if( gender=="" ) {
		write_ob(ob,"您要扮演男性(m)的角色或女性(f)的角色？");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "男性");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "女性" );
	else {
		write_ob(ob,"对不起，您只能选择男性(m)或女性(f)的角色：");
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob, user);
	write_ob(ob,"\n");
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

	user = new(ob->query("body"));
	if(!user) {
		write_ob(ob,"现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
		write_ob(ob,err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set("language", ob->query("language"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

private void init_new_player(object user)
{
	object money;

	user->set("title", "普通百姓");
	user->set("birthday", time() );
	user->set("potential", 99);
        user->set("max_neili", 400);
        user->set("eff_jingli", 300);
        user->set("max_jingli", 300);

	user->set("channels", ({ "chat", "rumor", "gchat" }) );
	user->create_human_body();

//	money=new("/clone/money/silver");
//	money->set_amount(10);
//	money->move(user);

	// In case of new player, we save them here right aftre setup
//	user->move("/adm/register/reg_room");
//	user->set("startroom", "/adm/register/reg_room");
//	user->save();
	// compeleted.
}


varargs void enter_world(object ob, object user, int silent)
{
	object cloth, room;
	mapping skill_status, my;
	string startroom, family, clas;
	string *sname;
	int select, i, level;
	float exper;

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered", ob->query("registered"));
	exec(user, ob);

	user->set("language", ob->query("language"));
	write_ob(user,"\n目前权限：" + wizhood(user) + "\n");

	user->setup();

	ob->save();

	if( MARRY_D->validate_marriage(user) )
		new("/d/city/obj/pring")->move(user);

	// general user data login check, like combat_exp, balance, clothing.
	UPDATE_D->login_check(user);

	// Menpai specific user data check
	// should have been moved into UPDATE_D if random_gift() were not used.
	if ( user->query("yijin_wan") && user->query("yijin_wan") < user->query("age") - 14 )
	{
		//user->add("max_neili",  -10);
		//user->add("eff_jingli", -10);
		//if (user->query("eff_jingli") < 0) user->set("eff_jingli",0);
		//if (user->query("max_neili") < 0) user->set("max_neili",0);

		my = ([]);
		random_gift(my);
		user->set("str", my["str"] - random(user->query("yijin_wan") - user->query("age") + 14));
		user->set("dex", my["dex"] - random(user->query("yijin_wan") - user->query("age") + 14));
		user->set("con", my["con"] - random(user->query("yijin_wan") - user->query("age") + 14));
		user->set("int", my["int"] - random(user->query("yijin_wan") - user->query("age") + 14));
		//user->set("yijin_wan", user->query("age") - 13);

		tell_object(user, HIR "你一年内未服豹胎易筋丸，功力大损！！！\n"NOR);
	}

	user->save();

	if( !silent ) {
		if (ob->query("registered") == 0)
		{
			//cat(UNREG_MOTD);
write("－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
＊      注意！！！

		  您还没有注册，一部分的命令将只有在注册后才能使用。

		  注册的步骤很简单，您需要给任何大巫师或神寄一封电子
		  邮件（ＥＭＡＩＬ），快则几分钟，慢则一天，就行了。
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n");
		}
		else
{
			//cat(MOTD);
			write(
"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
＊　　　请玩家连线进入本站以后，切勿忘了HELP RULES看一下本站的规则，不要忽视
　　这非常重要的一点，这都是为了本站能在一个健康良好的氛围下发展，也给大家提
　　供一个更美好的环境，所以请大家务必牢记，避免出现不愉快之场面。
＊　　　记住随时存档。由于当机造成的游戏进度损失，本游戏概不负责。
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n");

}
		write(sprintf( HIR"上次连线地址：\t%s( %s )\n\n"NOR,
			ob->query("last_from"),
			ctime(ob->query("last_on") )
		) );

		write(
HIG"
     *********************************************************************
     *                                                                　 *
     *  本游戏致力于发展中文网络文字游戏，希望得到广大ＭＵＤ爱好者的支持 *
     *                                                                　 *
     *********************************************************************

"NOR);


	if( strsrch(ctime(time()), "Dec 24") != -1
		|| strsrch(ctime(time()), "Dec 25") != -1
		|| strsrch(ctime(time()), "Dec 26") != -1
		)
	{
	  cat("/adm/etc/welcome_christmas");
	}

	if( strsrch(ctime(time()), "Jan 1") != -1
		|| strsrch(ctime(time()), "Dec 30") != -1
		|| strsrch(ctime(time()), "Dec 31") != -1
		|| strsrch(ctime(time()), "Jan 2") != -1
		|| strsrch(ctime(time()), "Jan 3") != -1
	)
	{
	  cat("/adm/etc/welcome_newyear");
	}


		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else if( !stringp(startroom = user->query("startroom"))
			|| !user->query("family") && user->query("combat_exp") < 1)
		startroom = "/d/xiakedao/shatan";
/*			select = random(6);
			if( select == 0 ) startroom = "/d/city/kedian";
			if( select == 1 ) startroom = "/d/quanzhou/wgdamen";
			if( select == 2 ) startroom = "/d/shaolin/nanyang";
			if( select == 3 ) startroom = "/d/xingxiu/beijiang";
			if( select == 4 ) startroom = "/d/qilian/yangguan";
			if( select == 5 ) startroom = "/d/dali/wangfu1";
								if( select == 5 ) startroom = "/d/hangzhou/kedian";
*/
		if ((user->query("registered") != "yes" ||
			REGI_D->is_banned_email(ob->query("email"))) &&
			wizhood(user) == "(player)")
//			user->move("/adm/register/reg_room");
			user->move("/d/xiakedao/shatan1");
		else if( user->query("death_count") > 200 && user->query("combat_exp") < 50000 )
			user->move("/d/death/block.c");
		else if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
			({user}));
	}
	if (!user->query_temp("cursed"))
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)由%s连线进入。", user->name(),user->query("id"), query_ip_name(user)) );
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);

	user->reconnect();
	if( !silent ) {
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
		({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)由%s重新连线进入。", user->query("name"),user->query("id"), query_ip_name(user)) );
}

int check_legal_id(string id,object ob)
{
	int i;

	i = strlen(id);

	if( (strlen(id) < 3) || (strlen(id) > 8 )
	  && (string)SECURITY_D->get_status(id) == "(player)" ) {
		write_ob(ob,"对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write_ob(ob,"对不起，你的英文名字只能用英文字母。\n");
			return 0;
		}

	return 1;
}

string check_legal_name(string name,object ob)
{
	int i,j;

	i = strlen(name);

	if( (strlen(name) < 2) || (strlen(name) > 8 ) || i % 2) {
		write_ob(ob,"对不起，你的中文名字必须是 1 到 4 个中文字。\n");
		return 0;
	}
	for (j = 0; j < i; j++) {
//		if( name[i]<=' ' ) {
//			write_ob(ob,"对不起，你的中文名字不能用控制字元。\n");
//			return 0;
//		}
		if( j%2==0 && !is_chinese(name[j..j+1]) ) {
			name[j]+=128; name[j+1]+=128;
//			write_ob(ob,"对不起，请您用「中文」取名字。\n");
//			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write_ob(ob,"对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}

	return name;
}

object find_login(object me)
{
	object ob, *login;
	string id;
	
	if( !objectp(me) || !stringp(id = me->query("id")) )
		return 0;
	login = children(LOGIN_OB);
	for(int i=0; i<sizeof(login); i++)
		if( clonep(login[i]) && login[i] != me &&
		    login[i]->query("id") == id ) 
			return login[i];

	return 0;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&	getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
