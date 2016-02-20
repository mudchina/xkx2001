//Cracked by Roath
//finger 加强工具，利于查找robot和多重登陆
// WriteBy wzfeng 99-2-2
#include <net/dns.h>
#include <ansi.h>
inherit ITEM;
int filter_time(object ob,int a)
{
        if(interactive(ob))
			if((int)query_idle(ob)>=(int)a*60)
        return 1;
        return 0;
}
string finger_idle(int a)
{
	object *ob;
	string msg, fip;
	int i;
	ob = filter_array(objects(), (: userp :));
	ob = filter_array(ob, (: filter_time :),a);
	if(!sizeof(ob))
		return "没有这样的玩家";
	msg="";
	for (i=0;i<sizeof(ob);i++)
			if (this_player()->visible(ob[i])) break;
		msg += sprintf("%-13s%-14s%-14s%-14s\n",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"断线中":query_idle(ob[i])/60 + "分钟"),
			query_ip_name(ob[i]));
			
		for(i=i+1; i<sizeof(ob); i++) {
			if( !this_player()->visible(ob[i]) ) continue;
		msg += sprintf("%-13s%-14s%-14s%-14s\n",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"断线中":query_idle(ob[i])/60 + "分钟"),
			query_ip_number(ob[i]) && query_ip_number(ob[i]) == query_ip_number(ob[i-1])?
				"地址同上":query_ip_name(ob[i]));
			
		}
		return 
		"———————————————————————————————————————\n"
		" 姓名         帐号          发呆          连线地址   \n" +
		"———————————————————————————————————————\n"
		+ msg +
		"———————————————————————————————————————\n"
		"* 表示登录中\n";
}

string finger_all()
{
	object *ob;
	string msg, fip;
	int i;

	ob = filter_array(objects(), (: userp :));
	msg="";
		for (i=0;i<sizeof(ob);i++)
			if (this_player()->visible(ob[i])) break;
		msg += sprintf("%s%-13s%-14s%-14s%-14s\n",
			environment(ob[i])?" ":"*",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"断线中":query_idle(ob[i])/60 + "分钟"),
			query_ip_name(ob[i]));
		for(i=i+1; i<sizeof(ob); i++) {
			if( !this_player()->visible(ob[i]) ) continue;
			msg += sprintf("%s%-13s%-14s%-14s%-14s\n",
			environment(ob[i])?" ":"*",
			ob[i]->query("name"), ob[i]->query("id"),
			(!interactive(ob[i])?"断线中":query_idle(ob[i])/60 + "分钟"),
			query_ip_number(ob[i]) && query_ip_number(ob[i]) == query_ip_number(ob[i-1])?
				"地址同上":query_ip_name(ob[i]));
		
		}
		return 
		"———————————————————————————————————————\n"
		" 姓名         帐号          发呆          连线地址   \n" +
		"———————————————————————————————————————\n"
		+ msg +
		"———————————————————————————————————————\n"
		"* 表示登录中\n";
		

}

void create() 
{
	set_name(HIW"巫师查找工具"NOR, ({"finger tool"}));
    set("long",
		"查找玩家发呆时间和多重登陆玩家列表的工具。\n"
		"指令cha_ip显示所有在线的玩家的详细资料，相同地址的会标记出来。\n"
		"指令cha_idle < a 时间(分钟)>列出发呆超过a分钟的玩家。\n"

		);
    set("unit", "个");
    set("value", 100000);
    set("weight", 10);
    setup();
	
}
void init ()
{
		if(wizardp(this_player()))
        add_action ("do_cha_ip", "cha_ip");
		add_action ("do_cha_idle", "cha_idle");
          	
}
int do_cha_ip()
{
	
	this_player()->start_more(finger_all());
	return 1;

}
int do_cha_idle(string arg)
{
	int a;
	if( !arg || !sscanf(arg, "%d", a) )
		return notify_fail("请输入最少发呆时间。\n");
		printf("发呆超过%d分钟的玩家有：\n",a);
	
	this_player()->start_more(finger_idle(a));
	return 1;

}



