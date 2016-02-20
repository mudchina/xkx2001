//Cracked by Roath
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"侠客行风云榜"NOR, ({"xkx list"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一张侠客行玩家的风云榜，可以用(readlist)来查看。\n");
                set("unit", "张");
                set("value", 1000000);
        }
}

void init()
{
    add_action("do_readlist", "readlist");
    add_action("do_sell", "sell");
}

int do_readlist(string arg)
{
	mapping *lists;
	int k, num;
		
	lists = this_object()->query("data");
	
	if( !lists ) return notify_fail("你这张侠客行风云榜是偷来的吧？\n");
	
	num = sizeof(lists);
	if ( num > 100 ) num = 100;
	
	write("侠客行风云榜：\n");
	for(int i = 0; i < num; i++)
	{
		k = i+1;
		write("第"+ chinese_number(k) + "名：" + lists[i]["name"] + "(" + lists[i]["id"] + "): 经验 " + lists[i]["exp"] + "。年龄：" + chinese_number(lists[i]["age"]) + "岁。\n");
	}
	return 1;
}

int do_sell(string arg)
{
	object me = this_player();
	object ob = this_object();
	
	if(arg == "xkx list" && me->query("env/wiz_tester") != 1) {
		ob->set("value", 100);
		call_out("change_value", 1, me, ob);
	}
	return 0;
}

void change_value(object me, object ob)
{
	if(me && !present(ob, me)) {
		tell_object(me, "可惜二手的侠客行风云榜只值几十个铜钱。\n");
		ob->set("value", 1000000);
	}
}