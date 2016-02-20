//Cracked by Roath
// apply.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if (me->query_busy())
		return notify_fail("什么？\n");
	if( !arg || arg=="" ) return notify_fail("你要服用什么？\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) return notify_fail("你要服用什么？\n");

	notify_fail("这样东西不能当药服用。\n");
	return ob->cure_ob(me);
}
