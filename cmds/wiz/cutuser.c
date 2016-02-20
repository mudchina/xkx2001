// Change by Server
// cutuser.c

#include <ansi.h>
#define DATA_DIR "/data/user/"
#define debug printf

#define SYNTAX  "指令格式：cutuser [-es] <user id> [cut percentage]\n"+\
		"          -s: cut skill, e.g. -s taiji-shengong\n"+\
		"          -e: cut combat_exp (default)\n"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string id, skill_name=0, err, *arg_list;
    int    i, amount, type, tmp, cloned;
    object user;

    if ( me!=this_player(1)
	 || wiz_level(me) < wiz_level(wizhood(me)) )
	    return notify_fail("你没有权力使用这个指令。\n");

    if (!arg ) return notify_fail(SYNTAX);

    type = 1;	// default is cut exp
    arg_list = explode(arg, " ");
    for (i=0; i<sizeof(arg_list); i++) {
	if (arg_list[i] == "-e") type = 1;
	else  if (arg_list[i] == "-s") {
	    type = 0;
	    if (i == sizeof(arg_list)-1) return notify_fail(SYNTAX);
	    skill_name = arg_list[++i];
	}else  if (arg_list[i] == "-") break;
  	else if (arg_list[i][0] != '-') break;
    }

    if (i >= sizeof(arg_list)) 
	return notify_fail("Please at least say who you want to cut.\n");
    id = arg_list[i];

    i++;
    amount = 30;	// cut 30% by default
    if (i < sizeof(arg_list)){
	if (sscanf(arg_list[i], "%d", amount)!=1)
	    return notify_fail("Cut percentage must be a number.\n");
    }
    if (amount < 0 || amount > 100)
	return notify_fail("cut percentage must be 0-100.\n");

    seteuid(getuid());

    cloned = 0;
    user = LOGIN_D->find_body(id);
    // cut even if the player is not online
    if (! objectp(user)) {
	user = new ("/clone/obj/dummy");
	cloned = 1;
    }
    if (!objectp(user))  return notify_fail("User object clone failed.\n");
    if (cloned) {
	user->set("id", id);
	err = catch(user->restore());
	if (err) {
	    destruct(user);
	    printf("Failed to restore user data.  File corrupted?\n");
	    return 1;
	}
    }

    if (type == 1) { // cut exp
	tmp = user->query("combat_exp");
	tmp = tmp * (100-amount) / 100;
	user->set("combat_exp", tmp);
    }else if (type == 0) { // cut skill
  	tmp = user->query_skill(skill_name, 1);
	if (tmp > 0) {
	    tmp = tmp * (100-amount) / 100;
	    user->set_skill(skill_name, tmp);
	}
    }
    user->save();
    log_file("CutUser", sprintf("%s: %s(%s) cut %s(%s) %s for %d %%\n",
			ctime(time()),
			this_player()->name(1),
			this_player()->query("id"),
			user->name(1),
			id,
			type?"combat exp":skill_name,
			amount));
    printf("You cut %s(%s) %s for %d %%\n",
	    user->name(1),
	    id,
	    type?"combat exp":skill_name, amount);
    if (cloned) {
	destruct(user);
    }
    return 1;
}

int help(object me) {
    write (@HELP

指令格式：

cutuser [-es] <user id> [cut percentage]
          -s: cut skill, e.g. -s taiji-shengong
          -e: cut combat_exp (default)

Note 1: cut percentage between 0-100 indicating the amount to be cut
Note 2: can cut offline user or online user
Note 3: default is to cut exp by 30%.  i.e. cutuser <id> == cutuser -e <id> 30

More Info: contact chu@xkx
Related Files: /clone/obj/dummy
HELP
    );
    return 1;
}
