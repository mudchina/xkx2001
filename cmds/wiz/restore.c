// Change by Server
// restore.c
// restore player's data
// by sdong ,  11/18/98

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
		 object obj;

		 if (!arg) return notify_fail("指令格式：restore player.\n"); 		 if(!objectp(obj = present(arg, environment(this_player())))) 					 return notify_fail("这里没有这个人。\n");  		  if (!obj) obj = present(arg, me); 		  if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) ); 		  if (!obj) return notify_fail("没有这样物件....。\n");  		  obj->restore(); 		  message_vision(CYN"$N对着$n口念真诀，$p的身影越来越清晰，最复原了！”\n"NOR, 							  me,obj); 		 return 1; } 

int help(object me)
{
write(@HELP
指令格式：exam player.

用来恢复玩家数据
HELP
	 );
	 return 1;
}

