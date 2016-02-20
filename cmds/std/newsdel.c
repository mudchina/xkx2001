//Cracked by Roath
//newsdel.c
//wzfeng@xkx 2000 7
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int news_num;
	string *option;
	object news_ob;
	seteuid(geteuid(me));
	if(!wizardp(me))
		return notify_fail ("你不是巫师，不能使用这个命令。\n");
	if(!news_ob=find_object("/clone/obj/news_b"))
		news_ob=new("/clone/obj/news_b");
	if(!objectp(news_ob)) return 0;
	news_ob->restore();
	write(news_ob->do_discard(arg));
	
	if(news_ob)
		destruct(news_ob);
	

	return 1;
	

}
int help(object me)
{
        write(@HELP
指令格式 : newsdel <新闻编号>
 
删除新闻。
 
HELP
    );
    return 1;
}
