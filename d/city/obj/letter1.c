//Cracked by Roath
// Write by Wzfeng 4/1/1998
//注意，阴历的年份算法我没有做，生加上去的，请在每一年的头一天
//修改string chinese_time(int date)函数



#include <ansi.h>
#include <localtime.h>

inherit ITEM;
static string *sym_di = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });
string chinese_time(int date)
{
	mixed *local;
	int i;

	local = localtime(date);
	i = (local[LT_HOUR]+1) % 2 * 2 + local[LT_MIN] / 30;
	return sprintf("戊寅年%s月%s日%s时%s",
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY]),
                sym_di[((local[LT_HOUR] + 1) % 24) / 2],
		i?chinese_number((local[LT_HOUR]+1) % 2 * 2 + 
		local[LT_MIN] / 30 ) + "刻":"正");
}

void create()
{       
        set_name("信", ({"letter","xin"}));
		set("long", "一封已经写好的信，你可用读(read)来看它的内容。\n");
		set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("unit", "封");
                }
		set("can_read_letter1",1);
}

void init ()
{
        add_action("do_read", "read");
}


int do_read(string arg)
{
         object ob_letter;
          int i;
         mapping letter;


        if(!arg) return notify_fail("你要读什么信件？\n");
           ob_letter = present(arg, this_player());

		if(!ob_letter)
                return notify_fail("你身上好像并没有这封信件？\n");
        if(!ob_letter->query("can_read_letter1"))
                return notify_fail("对不起！你无法从这里面读到任何东西。\n");
	
		letter=ob_letter->query("letter");
        printf("【书信标题】：%s\n【收信人】：%s\n【信件内容】：\n%s\n\t\t%s写于%s\n\n\n",
        letter["title"],
	letter["to"],
        letter["text"],
	letter["from"],
	chinese_time((letter["time"]))
		);
		 return 1;
}

