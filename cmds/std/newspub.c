//Cracked by Roath
//news.c
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
	if( !arg ) 
		return notify_fail("指令格式newspub title(请输入您要发布的新闻名称:)\n");
	if(!news_ob=find_object("/clone/obj/news_b"))
		news_ob=new("/clone/obj/news_b");
	if(!objectp(news_ob)) return 0;
	news_ob->restore();
	news_ob->input_news_name(arg,me);
	return 1;
	

}
int help(object me)
{
        write(@HELP
指令格式 : newspub <新闻题目>
 
发布新闻。
 
HELP
    );
    return 1;
}

