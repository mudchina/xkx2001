// Change by Server
// searchuser.c

#include <ansi.h>
#define DATA_DIR "/data/user/"
#define debug printf

#define SYNTAX  "指令格式：searchuser [-sln] <property> <value>\n"+\
		"          -s: stop current search\n"+\
		"          -i: initial character to start from\n"+\
		"          -l: use login database (for email, last_from)\n"+\
		"          -r: using regular expression pattern matching\n"+\
		"          -n: negative (a != b.  default is a==b)\n"

inherit F_CLEAN_UP;


void do_search(object user, string name, int ival, string sval,
		int type, int eq, mixed *dir, int i);

int use_login, use_regexp;

int main(object me, string arg)
{
    string name, value, sval, *arg_list, init;
    mixed *dir;
    int i, type, eq, ival;
    object user;

    if ( me!=this_player(1)
	 || wiz_level(me) < wiz_level(wizhood(me)) )
	    return notify_fail("你没有权力使用这个指令。\n");

    if (!arg ) return notify_fail(SYNTAX);

    eq = 1;
    use_login = 0;
    use_regexp = 0;
    init = "a";

    arg_list = explode(arg, " ");
    for (i=0; i<sizeof(arg_list); i++) {
	if (arg_list[i] == "-l") use_login = 1;
	else if (arg_list[i] == "-r") use_regexp = 1;
        else if (arg_list[i] == "-n") eq = 0;
        else if (arg_list[i] == "-s") {
	    remove_call_out("do_search");
	    user = me->query_temp("search_user");
	    if (objectp(user)) destruct(user);
	    me->delete_temp("search_user");
	    printf("search stopped.\n");
	    return 1;
	}else  if (arg_list[i] == "-i") {
	    if (i == sizeof(arg_list)-1) return notify_fail(SYNTAX);
	    init = arg_list[++i];
	}else  if (arg_list[i] == "-") break;
  	else if (arg_list[i][0] != '-') break;
    }

    if (i+2 < sizeof(arg_list)) return notify_fail(SYNTAX);
    name = arg_list[i];
    value = arg_list[i+1];
    debug("DEBUG: name=%s, value=%s, login=%d, equality=%d, regexp=%d\n", 
	   name, value, use_login, eq, use_regexp);

    type = 1;
    sval = value;
    if (!use_regexp && sscanf(value, "%d", ival) == 1) {
	type = 0;
    }

    seteuid(getuid());
    dir = get_dir(DATA_DIR);

    user = new ("/clone/obj/dummy");
    if (!objectp(user)) 
	return notify_fail("User object clone failed.\n");

    me->set_temp("search_user", user);
    for (i=0; i<sizeof(dir); i++)  if (dir[i] >= init) break;
    do_search(user, name, ival, sval, type, eq, dir, i);
    return 1;
}

void do_search(object user, string name, int ival, string sval,
		int type, int eq, mixed *dir, int i) {
    mixed *ppls, tmp;
    string id, stmp;
    int itmp, j, res;

    if (i >= sizeof(dir)) {
	printf("Searching Done.\n");
	destruct(user);
	return;
    }

    printf("start searching users starting %s...\n", dir[i]);
    ppls = get_dir(DATA_DIR + dir[i] + "/");

    for(j=0; j<sizeof(ppls); j++) {
	if( sscanf(ppls[j], "%s.o", id)!=1) continue;

	if (j % 100 == 0) reset_eval_cost();

	user->set("id", id);
  	if (use_login) user->set_login_flag();
	stmp = catch(user->restore());
	if (stmp) {
	    // user files could be corrupted.  We prevent that
	    // from crashing this program
	    printf("\tERR! %s restore failed\n", id);
	    continue;
	}
	tmp=user->query(name);
	if (type == 0) {
	    itmp = (int) tmp;
	    res = (itmp == ival);
	}else {
	    stmp=(string)tmp;
	    if (stringp(stmp)) {
		if (use_regexp) {
		    res = regexp(stmp, sval);
		}else {
		    res = (stmp == sval);
		}
	    }else {
		res = 0;
	    }
	}

	if (eq == res) {
	    printf("\tYES! %s(%s): %s = %O\n", 
		user->query("name"), id, name, tmp);
	}
    }

    printf("finished searching users starting %s. Wait 3 seconds...\n", dir[i]);
    call_out("do_search", 3, user, name, ival, sval, type, eq, dir, i+1);
    return;
}

int help(object me) {
    write (@HELP

General:

This command can be used to search the whole user database for
equality (==) or non-equality (!=) conditions.

指令格式：

searchuser [-slrn] [-i letter] <property> <value>

-s: stop a current search (see comments below)
-l: use login database (see comments below)
-r: using regular expression pattern matching
-n: search non-equality
-i: initial letter to start from

Examples:

searchuser str 19 --> list all users with str == 19
searchuser -n str 19 --> list users with str != 19
searchuser -l email foo@bar.com --> list all users whose email == foo@bar.com
searchuser -l -r last_from 128.59.* --> list all users from 128.59.*
searchuser -i k str 19 -->list all users whose name starts from k-z && str == 19

Note 1: registered email and last_from are in login database, and
	cannot be found in regular user database.
        "-l" specifies that the search should be in the login database.

Note 2: We have a lot of users, and the search takes a long time.
        In order to avoid big lags, the whole search is broken into 
	smaller pieces, sleeping 3 seconds between each piece.  
	If you want to abort an on-going search, use searchuser -s to 
	stop it.

More Info: contact chu@xkx
Related Files: /clone/obj/dummy
HELP
    );
    return 1;
}
