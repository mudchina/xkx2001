// Change by Server
// color.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
//int i;
	string cn;

	if( me->query("combat_exp") < 500000)
		return notify_fail("你的名声还不够响亮，没有资格上色。\n");
	cn = me->query("colorname");
	if( cn &&  cn[7..strlen(cn)-8] == me->query("name"))
		return notify_fail("你的名字已经有颜色了。\n");

	if( !arg ) return notify_fail("你要给自己的名字上什么色？\n");

	if( arg == "RED") me->set_color("$RED$");
	if( arg == "GRN") me->set_color("$GRN$");
	if( arg == "YEL") me->set_color("$YEL$");
	if( arg == "BLU") me->set_color("$BLU$");
	if( arg == "MAG") me->set_color("$MAG$");
	if( arg == "CYN") me->set_color("$CYN$");
	if( arg == "WHT") me->set_color("$WHT$");
	if( arg == "HIR") me->set_color("$HIR$");
	if( arg == "HIG") me->set_color("$HIG$");
	if( arg == "HIY") me->set_color("$HIY$");
	if( arg == "HIB") me->set_color("$HIB$");
	if( arg == "HIM") me->set_color("$HIM$");
	if( arg == "HIC") me->set_color("$HIC$");
	if( arg == "HIW") me->set_color("$HIW$");

	else if(!me->query("colorname"))
	return notify_fail("你要给自己的名字上什么色？\n");

	write("现在你的名字漂亮多了。\n");
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : color <颜色>
 
如果你有五十万经验，那么你可以给你自己响亮的名字加上一个颜色。
请选择以下颜色：
（注意！！！颜色一旦加上就不能更改，除非你更换了名字！！！）

RED - 红色		HIR - 亮红色
GRN - 绿色		HIG - 亮绿色
YEL - 土黄色		HIY - 黄色
BLU - 深蓝色		HIB - 蓝色
MAG - 浅紫色		HIM - 粉红色
CYN - 蓝绿色		HIC - 天青色
WHT - 浅灰色		HIW - 白色

HELP
        );
        return 1;
}
