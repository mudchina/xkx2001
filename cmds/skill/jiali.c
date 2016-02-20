//Cracked by Roath
// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
		return notify_fail("指令格式：enforce|jiali <使出几点内力伤敌>|none");

	if( !me->query_skill_mapped("force") )
		return notify_fail("你必须先 enable 一种内功。\n");

	if( arg=="none" )
		me->delete("jiali");
	else {
		if( pts < 0 )
			return notify_fail("你只能用 none 表示不运内力，或数字表示每一击用几点内力。\n");
		if( pts > (int)me->query_skill("force") / 2 )
			return notify_fail("你的内功火侯还加不了那么大力。\n");
		me->set("jiali", pts);
	}

	write("从现在起你用" + chinese_number(pts)+"点内力伤敌。\n");
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enforce|jiali <使出几点内力伤敌>|none
 
这个指令让你指定每次击中敌人时，要发出几点内力伤敌。

enforce none 则表示你不使用内力。 

See Also: enable
HELP
        );
        return 1;
}
