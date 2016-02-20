// Change by Server
// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	if( !arg || arg=="" ) return help();

	me->delete("env/" + arg);
	write("环境变量删除了。\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：unset <变量名>

这个指令让你删除环境变量的设定。

修改或增加变量设定请用 set 指令。
TEXT
	);
	return 1;
}
