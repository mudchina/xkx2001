// Change by Server
// destroy.c
// destroy object
// by sdong , 11/18/98

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
		 object obj;


		 if( wizhood(me) != "(caretaker)" && wizhood(me) != "(wizard)" &&
			  wizhood(me) != "(arch)" && wizhood(me) != "(admin)"
		  ) return notify_fail("什么？\n");

		 if (!arg) return notify_fail("指令格式：destroy object.\n");

		 if(!objectp(obj = present(arg, environment(this_player()))))
					 return notify_fail("这里没有这个人。\n");  		  if (!obj) obj = present(arg, me); 		  if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) ); 		  if (!obj) return notify_fail("没有这样物件....。\n");  		  message_vision(CYN"$N掏出一把激光枪，对准$n嘭的开了一枪，把$p打成一片硝烟消失了！”\n"NOR, 							  me,obj);  		  seteuid(ROOT_UID); 		  destruct(obj); 		  if(obj){ write("你无法将这个物件摧毁。\n"); return;}  		 return 1; } 

int help(object me)
{
write(@HELP
指令格式：destroy object.

用来清除垃圾
HELP
	 );
	 return 1;
}

