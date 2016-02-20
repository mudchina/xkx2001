//Cracked by Roath
// work-letter1.c 大理晋级用公文
// mantian
#include <ansi.h>

inherit ITEM;
string long_desc();

void create()
{
	set_name(RED "功绩表" NOR, ({"gongji biao", "biao", "book"}));
	set_weight(100);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", (: long_desc :));
//		set("long","这是一本段陉用来记录大理臣子功绩的册子，用以呈报圣上。\n");
		set("no_get", "这样东西不能离开你。\n");
		set("material", "paper");
	}
}

string long_desc()
{
	string descrp;
	object me = this_player();

	descrp = RED"这是一本段陉用来记录大理臣子功绩的册子，用以呈报圣上。\n\n"NOR;
	if (me->query_temp("dali/uprank"))
	{
		descrp += "大理国上府副将"+me->query("name");
		descrp += "，功在社骥，工作勤奋，才堪大用。\n\n";
		descrp += "其功绩如下：\n";
		descrp += RED"功劳点："NOR;
		descrp += chinese_number(me->query_temp("dali/trust"))+"点。\n";
		descrp += HIC"工作量："NOR;
		descrp += chinese_number(me->query_temp("dali/arrestmade"))+"点。\n";
		descrp += MAG"勤劳度："NOR;
		descrp += chinese_number(me->query_temp("dali/jobdone"))+"点。\n\n　　　　　　　";
		descrp += me->query_temp("allowtime");
	}
	return descrp;
}
