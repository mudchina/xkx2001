// Change by Server
// rename.c
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string id, name;

	if (!arg || sscanf(arg, "%s %s", id, name) != 2) 
		return notify_fail("指令格式: rename <id> <new chinese name>\n");
	
	ob = present(id, environment(me));
	if (!ob) return notify_fail("找不到这个生物.\n");
	
	message_vision("$N把$n的名字改为"+name+"。\n",me,ob);
	ob -> set("name",name);
	return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: rename <id> <中文名字>
 
更改玩家中文姓名。

HELP
   );
   return 1;
}
