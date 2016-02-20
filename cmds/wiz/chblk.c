//Cracked by Roath
// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
    
    if (sscanf(arg, "%s %s", who, ch_name) != 2)
    {
        ch_name = "";
        if (sscanf(arg, "%s", who) != 1)
        {
        return  notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
        }   
    }

	if (who == "rumor")
	{
		CHANNEL_D->set_block("rumor", 1);
		CHANNEL_D->do_channel(me, "sys", "谣言频道关闭了。\n");
		return 1;
	}

	if (who == "chat")
	{
		CHANNEL_D->set_block("chat", 1);
		CHANNEL_D->do_channel(me, "sys", "聊天频道关闭了。\n");
		return 1;
	}

	if (who == "xkx")
	{
		CHANNEL_D->set_block("xkx", 1);
		CHANNEL_D->do_channel(me, "sys", "侠客行频道关闭了。\n");
		return 1;
	}


	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("这个人不在！\n");
	if (wizardp(ob)) return notify_fail("不能关闭巫师的频道。\n");

	if (ch_name == "" || ch_name == " ")
	{
		if ( ob->query("chblk_on") || ob->query("chblk_rumor") )
		{
			tell_object(me, (string)ob->query("name")+"的谣言频道是关闭的。\n");
		}
		if ( ob->query("chblk_on") || ob->query("chblk_chat") )
		{
			tell_object(me, (string)ob->query("name")+"的聊天频道是关闭的。\n");
		}
		if (!(ob->query("chblk_on")||ob->query("chblk_rumor")||ob->query("chblk_chat")))
		{
			tell_object(me, (string)ob->query("name")+"没有被关闭的频道。\n");
		}
	} else if (ch_name == "rumor")
	{
		if ( ob->query("chblk_on") || ob->query("chblk_rumor") )
		{
			tell_object(me, (string)ob->query("name")+"的谣言频道已经是关闭的了。\n");
		} else
		{
			if ( ob->query("chblk_chat") )
			{
				ob->delete("chblk_chat");
				ob->set("chblk_on", 1);
			} else {
				ob->set("chblk_rumor", 1);
			}
			tell_object(me, (string)ob->query("name")+"的谣言频道被关闭了。\n");
		 }
	} else if (ch_name == "all")
	{
		if ( ob->query("chblk_on") )
		{
			tell_object(me, (string)ob->query("name")+"的频道已经是关闭的了。\n");
		} else
		{
			ob->set("chblk_on", 1);
			ob->delete("chblk_rumor");
			ob->delete("chblk_chat");
			ob->delete("chblk_xkx");
			tell_object(me, (string)ob->query("name")+"的频道被关闭了。\n");
		}
	} else if (ch_name == "chat")
	{
		if ( ob->query("chblk_on") || ob->query("chblk_chat") )
		{
			tell_object(me, (string)ob->query("name")+"的聊天频道已经是关闭的了。\n");
		} else
		{
			if ( ob->query("chblk_rumor") )
			{
				ob->delete("chblk_rumor");
				ob->set("chblk_on", 1);
			} else {
				ob->set("chblk_chat", 1);
			}
			tell_object(me, (string)ob->query("name")+"的聊天频道被关闭了。\n");
		}
	}
	else if (ch_name == "xkx")
	{
		if ( ob->query("chblk_on") || ob->query("chblk_xkx") )
		{
			tell_object(me, (string)ob->query("name")+"的聊天频道已经是关闭的了。\n");
		} else
		{
			if ( ob->query("chblk_xkx") )
			{
				ob->delete("chblk_xkx");
				ob->set("chblk_on", 1);
			} else {
				ob->set("chblk_xkx", 1);
			}
			tell_object(me, (string)ob->query("name")+"的聊天频道被关闭了。\n");
		}
	}
	else
	{
		return notify_fail("<Syntax>: chblk <player id> <channel name>\n");
	}

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : chblk <某人> <频道名>

此命令将关闭某人的某个频道。
<频道名>：可以是rumor、chat或all。如果不提供频道名，则显示某人当前的频道状态。 

并且：
chblk rumor 将关闭谣言频道。
chblk chat 将关闭聊天频道。

HELP
    );
    return 1;
}
