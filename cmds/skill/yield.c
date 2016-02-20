//Cracked by Roath
// yield.c
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
	if( me != this_player(1) ) return 0;
 
	if( !arg || arg=="" )
		return notify_fail("你决定战斗中只挨打不还手？YES表示只挨打，NO表示可以还手。\n");

	if( arg=="yes" ) {
		write("你决定打架时只挨打不还手。\n");
		me->set_temp("yield",1);
		return 1;
	}
 
	if( arg=="no" ) {
		write("你决定打架时可以还手反击。\n");
		me->set_temp("yield",0);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：yield <yes/no>
 
这个指令让你决定打架时只挨打不还手，虽然损气伤身，但却能直接提高
招架和闪躲方面的技能。
 
TEXT
	);
	return 1;
}
